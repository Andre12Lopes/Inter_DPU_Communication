#include <dpu>
#include <iomanip>
#include <iostream>
#include <unistd.h>

using namespace dpu;

#define NUM_DPUS 2

static constexpr int32_t BUFFER_SIZE = 5;

void f(DpuSet & s, unsigned u)
{
    std::cout << "CALLBACK" << std::endl;
}

int main(int argc, char **argv) 
{
    std::vector<std::vector<uint32_t>> send_flag(NUM_DPUS, std::vector<uint32_t>(1, 2));
    std::vector<std::vector<uint32_t>> send(BUFFER_SIZE);

    try 
    {
        auto system = DpuSet::allocate(NUM_DPUS);

        system.load("dpu/dpu");

        auto async_system = system.async();

        async_system.exec();        

        // std::function<void(DpuSet &, unsigned)> func = f;
        // async_system.call(func, false, false);

        sleep(1);

        // system.dpus()[0].copy();
        while(1)
        {
            async_system.copy(send_flag, "send_flag");

            for (auto const& i : send_flag)
            {
                for (auto const& j : i)
                {
                    std::cout << j << std::endl;   
                }
            }
        }

        // async_system.sync();


        // async_system.log(std::cout);

    } 
    catch (const DpuError &e) 
    {
        std::cerr << e.what() << std::endl;
    }
}
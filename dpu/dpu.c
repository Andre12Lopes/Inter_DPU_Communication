#include <mram.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#define BUFFER_SIZE 5

__mram_noinit uint32_t recv[BUFFER_SIZE];
__host uint32_t send[BUFFER_SIZE];
__host uint32_t send_flag;


int main() {

    send_flag = 0;

    while(send_flag < 1000) { 
        send_flag++;
    }

    return 0;
}
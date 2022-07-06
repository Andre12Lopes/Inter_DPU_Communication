CC = g++

TARGET = host

CFLAGS += -Wall -Wno-unused-label -Wno-unused-function --std=c++11

all: $(TARGET)

$(TARGET): %: %.cpp
	$(CC) $(CFLAGS) -o $@ $< `dpu-pkg-config --cflags --libs dpu` -g

clean:
	rm -f $(TARGET) *.o
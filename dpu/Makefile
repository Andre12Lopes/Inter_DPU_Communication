CC = dpu-upmem-dpurte-clang
NR_TASKLETS = 2

TARGET = dpu

CFLAGS += -Wall -Wno-unused-label -Wno-unused-function --std=c99

all: $(TARGET)

$(TARGET): %: %.c
	$(CC) -DNR_TASKLETS=$(NR_TASKLETS) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET) *.o
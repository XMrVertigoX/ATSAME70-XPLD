#include <cstddef>

#include <SEGGER_RTT.h>

int _write(int f, char *bytes, int numBytes) {
    SEGGER_RTT_Write(0, bytes, numBytes);
    return numBytes;
}

int _write_r(struct _reent *r, int f, const void *bytes, size_t numBytes) {
    SEGGER_RTT_Write(0, bytes, numBytes);
    return numBytes;
}

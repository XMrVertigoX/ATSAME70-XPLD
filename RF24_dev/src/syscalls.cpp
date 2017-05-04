#include <reent.h>

#include <SEGGER_RTT.h>

extern "C" int _write(int f, char *bytes, size_t numBytes) {
    return (SEGGER_RTT_Write(0, bytes, numBytes));
}

extern "C" int _write_r(struct _reent *r, int f, const void *bytes, size_t numBytes) {
    return (SEGGER_RTT_Write(0, bytes, numBytes));
}

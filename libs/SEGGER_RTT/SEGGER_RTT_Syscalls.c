#include <reent.h>

#include "SEGGER_RTT.h"

#define UNUSED(x) (void)x

int _write(int f, char *bytes, int numBytes) {
    UNUSED(f);

    SEGGER_RTT_Write(0, bytes, numBytes);

    return (numBytes);
}

int _write_r(struct _reent *r, int f, const void *bytes, size_t numBytes) {
    UNUSED(r);
    UNUSED(f);

    SEGGER_RTT_Write(0, bytes, numBytes);

    return (numBytes);
}

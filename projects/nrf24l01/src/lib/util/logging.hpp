#ifndef LOGGING_HPP_
#define LOGGING_HPP_

struct Buffer_t {
    uint8_t *bytes;
    size_t numBytes;
};

void printBuffer(const char *message, Buffer_t buffer);
void printFormat(const char *format, ...);

#ifndef NDEBUG
#define BUFFER(...) printBuffer(__VA_ARGS__)
#define FORMAT(...) printFormat(__VA_ARGS__)
#else
#define BUFFER(...)
#define FORMAT(...)
#endif

#endif  // LOGGING_HPP_

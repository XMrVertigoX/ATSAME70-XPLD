#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#ifndef NDEBUG
#define LOG(...) print(__VA_ARGS__)
#else
#define LOG(...)
#endif

void print(const char *format, ...);

#endif  // LOGGER_HPP_

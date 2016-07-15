#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#ifndef NDEBUG
#define LOG(...) printVisible(__VA_ARGS__)
#else
#define LOG(...)
#endif

void printVisible(const char *format, ...);

#endif  // LOGGER_HPP_

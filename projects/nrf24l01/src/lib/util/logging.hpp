#ifndef LOGGING_HPP_
#define LOGGING_HPP_

/*
 * Follows RFC5424 (https://tools.ietf.org/html/rfc5424)
 */

#define SEVERITY_EMERGENCY 0
#define SEVERITY_ALERT 1
#define SEVERITY_CRITICAL 2
#define SEVERITY_ERROR 3
#define SEVERITY_WARNING 4
#define SEVERITY_NOTICE 5
#define SEVERITY_INFO 6
#define SEVERITY_DEBUG 7

#if !defined(LOG_LEVEL)
#define LOG_LEVEL SEVERITY_WARNING
#endif

#if !defined(NDEBUG) && LOG_LEVEL >= SEVERITY_EMERGENCY
#define EMERGENCY(...) printFormat(__VA_ARGS__)
#else
#define EMERGENCY(...)
#endif

#if !defined(NDEBUG) && LOG_LEVEL >= SEVERITY_ALERT
#define ALERT(...) printFormat(__VA_ARGS__)
#else
#define ALERT(...)
#endif

#if !defined(NDEBUG) && LOG_LEVEL >= SEVERITY_CRITICAL
#define CRITICAL(...) printFormat(__VA_ARGS__)
#else
#define CRITICAL(...)
#endif

#if !defined(NDEBUG) && LOG_LEVEL >= SEVERITY_ERROR
#define ERROR(...) printFormat(__VA_ARGS__)
#else
#define ERROR(...)
#endif

#if !defined(NDEBUG) && LOG_LEVEL >= SEVERITY_WARNING
#define WARNING(...) printFormat(__VA_ARGS__)
#else
#define WARNING(...)
#endif

#if !defined(NDEBUG) && LOG_LEVEL >= SEVERITY_NOTICE
#define NOTICE(...) printFormat(__VA_ARGS__)
#else
#define NOTICE(...)
#endif

#if !defined(NDEBUG) && LOG_LEVEL >= SEVERITY_INFO
#define INFO(...) printFormat(__VA_ARGS__)
#else
#define INFO(...)
#endif

#if !defined(NDEBUG) && LOG_LEVEL >= SEVERITY_DEBUG
#define BUFFER(...) printBuffer(__VA_ARGS__)
#define DEBUG(...) printFormat(__VA_ARGS__)
#else
#define BUFFER(...)
#define DEBUG(...)
#endif

struct Buffer_t {
    uint8_t *bytes;
    size_t numBytes;
};

void printBuffer(const char *message, Buffer_t buffer);
void printFormat(const char *format, ...);

#endif /* LOGGING_HPP_ */

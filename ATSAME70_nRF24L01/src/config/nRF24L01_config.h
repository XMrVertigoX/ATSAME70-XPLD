#ifndef NRF24L01_CONFIG_H_
#define NRF24L01_CONFIG_H_

#include <asf.h>

static inline void delayMs(uint32_t ms) {
    delay_ms(ms);
}

static inline void delayUs(uint32_t us) {
    delay_us(us);
}

#endif  // NRF24L01_CONFIG_H_

#ifndef SPICONTROLLER_HPP_
#define SPICONTROLLER_HPP_

#include <asf.h>

#include <xXx/utils/singleton.hpp>

class SpiController : public Singleton<SpiController> {
    friend class Singleton<SpiController>;

   public:
    ~SpiController() = default;
    void enableMasterMode(Spi *spi, uint32_t delayBetweenChipSelect = 0);

   private:
    SpiController() = default;
    void configurePins(Spi *spi);
};

#endif /* SPICONTROLLER_HPP_ */

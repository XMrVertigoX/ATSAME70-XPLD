#ifndef SPICONTROLLER_HPP_
#define SPICONTROLLER_HPP_

#include <asf.h>

#include <xXx/templates/singleton.hpp>

using namespace xXx;

class SpiController : public Singleton<SpiController> {
    friend class Singleton<SpiController>;

  public:
    void enableMasterMode(Spi *spi, uint32_t delayBetweenChipSelect = 0);

  private:
    SpiController()  = default;
    ~SpiController() = default;

    void configurePins(Spi *spi);
};

#endif /* SPICONTROLLER_HPP_ */

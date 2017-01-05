#ifndef SPIMGR_HPP_
#define SPIMGR_HPP_

#include <asf.h>

#include <xXx/templates/singleton.hpp>

using namespace xXx;

class SpiMgr : public Singleton<SpiMgr> {
    friend class Singleton<SpiMgr>;

  public:
    void enableMasterMode(Spi *spi, uint32_t delayBetweenChipSelect = 0);

  private:
    SpiMgr()  = default;
    ~SpiMgr() = default;

    void configurePins(Spi *spi);
};

#endif /* SPIMGR_HPP_ */

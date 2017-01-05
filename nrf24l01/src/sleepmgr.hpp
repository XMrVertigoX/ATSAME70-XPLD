#ifndef SLEEPMGR_HPP_
#define SLEEPMGR_HPP_

#include <asf.h>

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/templates/singleton.hpp>

using namespace xXx;

class SleepMgr : public Singleton<SleepMgr> {
    friend class Singleton<SleepMgr>;

  public:
    void init();
    uint32_t sleep(TickType_t ticks = 0);

  private:
    SleepMgr()  = default;
    ~SleepMgr() = default;

    TickType_t rtc2rtos(uint32_t ticks);
    uint32_t rtos2rtc(TickType_t ticks);
};

#endif /* SLEEPMGR_HPP_ */

#ifndef SLEEPMANAGER_HPP_
#define SLEEPMANAGER_HPP_

#include <asf.h>

#include <xXx/templates/singleton.hpp>

using namespace xXx;

class SleepManager : public Singleton<SleepManager> {
    friend class Singleton<SleepManager>;

   public:
    void init();

   private:
    SleepManager() = default;
    ~SleepManager() = default;
};

#endif /* SLEEPMANAGER_HPP_ */

#ifndef SLEEPMANAGER_HPP_
#define SLEEPMANAGER_HPP_

#include <asf.h>

#include <xXx/utils/singleton.hpp>

class SleepManager : public Singleton<SleepManager> {
    friend class Singleton<SleepManager>;

   public:
    void init();

   private:
    SleepManager() = default;
    ~SleepManager() = default;
};

#endif /* SLEEPMANAGER_HPP_ */

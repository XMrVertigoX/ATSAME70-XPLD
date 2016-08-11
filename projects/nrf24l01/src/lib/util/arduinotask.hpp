#ifndef IARDUINOTASK_HPP_
#define IARDUINOTASK_HPP_

#define ARDUINO_TASK_FUNCTION                                           \
    [](void *pvParameters) {                                            \
        IArduinoTask *task = static_cast<IArduinoTask *>(pvParameters); \
        task->setup();                                                  \
        for (;;) {                                                      \
            task->loop();                                               \
        }                                                               \
    }

class IArduinoTask {
   public:
    virtual void setup() = 0;
    virtual void loop() = 0;

   protected:
    virtual ~IArduinoTask() {}
};

#endif /* IARDUINOTASK_HPP_ */

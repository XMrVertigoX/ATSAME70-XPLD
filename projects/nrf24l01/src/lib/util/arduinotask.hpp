#ifndef IARDUINOTASK_HPP_
#define IARDUINOTASK_HPP_

#define ARDUINO_TASK_FUNCTION                                         \
    [](void *pvParameters) {                                          \
        ArduinoTask *task = static_cast<ArduinoTask *>(pvParameters); \
        task->setup();                                                \
        for (;;) {                                                    \
            task->loop();                                             \
        }                                                             \
    }

class ArduinoTask {
   public:
    virtual void setup() = 0;
    virtual void loop() = 0;

   protected:
    virtual ~ArduinoTask() {}
};

#endif /* IARDUINOTASK_HPP_ */

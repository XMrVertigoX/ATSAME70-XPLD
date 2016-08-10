#ifndef IARDUINOTASK_HPP_
#define IARDUINOTASK_HPP_

class IArduinoTask {
   public:
    virtual ~IArduinoTask() {}

    // Arduino like task interface
    virtual void setup() = 0;
    virtual void loop() = 0;
};

#endif /* IARDUINOTASK_HPP_ */

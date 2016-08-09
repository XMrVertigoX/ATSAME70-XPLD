#ifndef IARDUINO_HPP_
#define IARDUINO_HPP_

class IArduino {
   public:
    virtual ~IArduino() {}

    // Arduino like task interface
    virtual void setup() = 0;
    virtual void loop() = 0;
};

#endif /* IARDUINO_HPP_ */

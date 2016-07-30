#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_

template <typename TYPE>
class Singleton {
   public:
    static TYPE& Instance();

   protected:
    Singleton() {}
    virtual ~Singleton() {}
};

template <typename TYPE>
TYPE& Singleton<TYPE>::Instance() {
    static TYPE instance;
    return instance;
}

#endif  // SINGLETON_HPP_

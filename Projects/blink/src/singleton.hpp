#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_

template <typename TYPE>
class StaticSingleton {
   public:
    static TYPE& Instance();

   protected:
    StaticSingleton() {}
    virtual ~StaticSingleton() {}
};

template <typename TYPE>
TYPE& StaticSingleton<TYPE>::Instance() {
    static TYPE instance;
    return instance;
}

#endif  // SINGLETON_HPP_

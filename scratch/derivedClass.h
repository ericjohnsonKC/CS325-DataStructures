#include "baseClass.h"

template <class T>
class derivedClass: public baseClass<T>{
    public:
        T getType() const;
        int getNum() const;
};

template <class T>
T derivedClass<T>::getType() const{
    return T;
}

template <class T>
int derivedClass<T>::getNum() const{
    return this->myNum;
}
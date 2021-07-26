#ifndef DYNAMIC_CLASS_DEF
#define DYNAMIC_CLASS_DEF

#include <DynamicArray.h>
#include <stdlib.h>
#include <iostream>

using namespace Scrappers;

template <class T>        
DynamicArray<T>::DynamicArray(int length){
   this->length = length;
   ptr = new T[length];
}
template <class T>        
DynamicArray<T>::~DynamicArray(){
    destroyMemory();
}
template <class T>        
const int DynamicArray<T>::getLength(){
    return length;
}
template <class T>        
T DynamicArray<T>::add(T object){
        if(position < length){
            ptr[position++] = object;
        }else{
            T* delegation = new T[length+1];
            for(int pos = 0; pos < length; pos++){
                delegation[pos] = T();
                delegation[pos] = ptr[pos];
            }
            delegation[position++] = object;
            this->length = length + 1;
        }     
    return object;
}
template <class T>        
T DynamicArray<T>::add(int position, T object){
        if(position < length){
            ptr[position] = object;
        }else{
            T* delegation = new T[length+1];
            for(int pos = 0; pos < length; pos++){
                delegation[pos] = ptr[pos];
            }
            delegation[position] = object;
            this->length = length + 1;
        }     
    return object;
}
template <class T>        
DynamicArray<T>& DynamicArray<T>::operator+(T object){
        add(object);
    return *this;
}
template <class T>        
DynamicArray<T>& DynamicArray<T>::operator-(int position){
        ptr[position] = T();
    return *this;
}
template <class T>        
T DynamicArray<T>::get(int position){ 
    return ptr[position];
}
template <class T>        
T* DynamicArray<T>::remove(T* &object){
       object = nullptr;
    return object;
}
template <class T>        
void DynamicArray<T>::removeAt(int position){
    ptr[position] = T();
}
template <class T>        
void DynamicArray<T>::forEach(){
  for(int position=0; position < length; position++){
        Scrappers::DynamicArray<T>::forEachUpdateDispatcher(ptr[position]);
  }
}
template <class T>        
void DynamicArray<T>::destroyMemory(){
    delete ptr;
    ptr=NULL;
    delete &length;
}
template <class T>        
void DynamicArray<T>::reConstruct(){
    std::cout << "Reconstruct the instance back then" << std::endl;
}
template <class T>        
DynamicArray<T> DynamicArray<T>::shallowCopy(DynamicArray &instance){
    std::cout << "Shallow copy of data" << std::endl;
    return 0;
}
template <class T>        
DynamicArray<T> DynamicArray<T>::deepCopy(DynamicArray &instance){
    std::cout << "DeepCopy of Data" << std::endl;
      return 0;
}
template <class T>        
void DynamicArray<T>::print(){
      std::cout << "print" << std::endl;
}
#else
#endif
       

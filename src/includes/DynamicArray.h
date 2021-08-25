/*a guard macro preprocessor command, to check in this header file only once before compile-time*/
#ifndef DYNAMIC_CLASS_HEADER
#define DYNAMIC_CLASS_HEADER
/*namespace is a code enclosure*/
namespace Scrappers{
    /*using templates or generics for any class displacement*/
    template <class T>        
        class DynamicArray{
            private:
                T* ptr;
                int length;
                int position;
                virtual void destroyMemory();
            public:
                 DynamicArray(int length = 0);
                ~DynamicArray();
                 T add(T object);
                 T add(int position, T object);
                 T& get(int position);
                 T* remove(T* &object);
                 void removeAt(int position);
                 virtual void forEach();
                 void forEachUpdateDispatcher(T currentObj);
                 virtual void reConstruct();
                 DynamicArray shallowCopy(DynamicArray &instance);
                 DynamicArray deepCopy(DynamicArray &instance);
                 DynamicArray& operator+(T object);
                 DynamicArray& operator-(int position);
                 const int& getLength();
                 void print();
        };
};


#endif

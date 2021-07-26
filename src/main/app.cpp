#include <iostream>
#include <string>
#include <stdlib.h>
#include "DynamicArray.cpp"
#include <app.h>


/**
* Redefining the Templated/Generic classes in the form of concrete dataTypes using typedef & enclosing them in a utils struct(short-*  hand-class-utils).
* <br>
* Using length pointer variable to keep track of the length of the DynamicArray as an example of pointers
* <br>
* utils : is a de-referenced pointer instance of the Class Utils, so can be used to access non-static members : *length value
*/
struct Utils{
  public:
        typedef Scrappers::DynamicArray<int> DynamicIntArray;
        typedef Scrappers::DynamicArray<std::string> DynamicStringArray;
        typedef App::Greeter Greeter;
        int* length = new int();
} utils;
/**
* Overriding the member function greeting() of class Greeter, & commands a greeting message.
*/
std::string App::Greeter::greeting() {
    return std::string("Simple Language Coverage : \n")
               .append("\n")
               .append("1)Classes, Abstraction(virtual), Reservedkeywords, OOP\n")
               .append("2)Basic Pointers, value References, address of memmory blocks\n")
               .append("3)Dynamic Arrays\n")
               .append("4)Static Arrays\n")
               .append("5)Base memory address of arrays\n")
               .append("6)Jumping among arrays members using pointers & subscript notations\n")
               .append("7)Functions, Pointer, Value & Reference paramters\n")
               .append("8)Usuage of reference parameters\n")
               .append("9)Shallow & deep copying of variables through the assignment operator\n")
               .append("\n");
}
/** 
* Overrding the dispatcher & using it as interfaces in java
* @param T is an object of type T, as the template provides 
*/
template <class T>        
void Scrappers::DynamicArray<T>::forEachUpdateDispatcher(T object){
    std::cout << object << std::endl;
}
/**
* Commands & run a forEach call to a dynamic array instance 
* @param Scrappers::DynamicArray<T>* pointer instance of that dynamic array
*/
template <class T>  
void command(Scrappers::DynamicArray<T>* dynmArray){
        std::cout <<"For Each Dispatcher started>>>>>>>>" << std::endl;
        dynmArray->forEach();
        
}
/**
* My Code execution unit.
*/
int main () {
        Utils::Greeter* greeter = new Utils::Greeter();
        std::cout << (*greeter).greeting() << std::endl;
        Utils::DynamicStringArray* stringArr = new Utils::DynamicStringArray(3);
        stringArr->add("Welcome to Dynamic Arrays Example Usuage.....>>>>");
        stringArr->add("Cpp codingBootcamp by Scrappers Team >>>>>>");
        stringArr->add("\n");
        command(stringArr);
        
        std::cin >> *(utils.length);
        
        Utils::DynamicIntArray* dynmArray = new Utils::DynamicIntArray(*(utils.length));
        std::cout <<"Length : "<< dynmArray->getLength() << std::endl;
        dynmArray->add(220);
        (*dynmArray) + 500 + 300 + 200;
        command(dynmArray);
 
        (*dynmArray) + 100 - 1;
        command(dynmArray);
        //delete the pointer after program execution, assign the memory address to zero
        delete utils.length;
        utils.length = nullptr;
        //print out concatenated pointers for memory reference
        std::cout << utils.length << "\n" << &utils << "\n" << std::endl;
    return 0;
}

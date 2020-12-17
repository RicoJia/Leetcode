//
// Created by ricojia on 11/23/20.
//
#include <string>
#include <cstring>
#include <stdio.h>
#include <utility>

using std::memcpy;
using std::string;

struct Str{
    Str() = default;    //this is how you declare a default constructor.
    Str(const char *str) {
        size_ = strlen(str);    // best way to get string length
        str_ = new char[size_];     //you need to allocate memory first.
        memcpy(str_, str, size_);   //best way to copy a string. defined in <cstring>
        printf("created \n");
    }
    //copy constructor
    Str(const Str& str){        //you need & in this copy constructor.
        size_ = str.size_;
        str_ = new char[size_];
        memcpy(str_, str.str_, size_);
        printf("copied \n");
    }

//    //move assignment const-rvalue constructor
//    Str(const Str&& str){        //move assignment constructor for const r-value reference
//        size_ = str.size_;
//        str_ = new char[size_];
//        memcpy(str_, str.str_, size_);
//        printf("experiment \n");
//    }

    //move assignment contructor
    Str(Str&& str){
        size_ = str.size_;
        str_ = str.str_;
        str.size_ = 0;
        str.str_ = nullptr;
        printf("moved \n");

    }

    ~Str(){delete [] str_;         printf("deleted \n");
    }    // you need a destructor to free the memory, using delete[]
private:
    char *str_;
    unsigned int size_;     //you need to store the size, since copy constructor needs it.
};

class Entity{
public:
//    Entity(const Str& str): string_(str){} //this is actually calling string_'s copy constructor.
     Entity(const Str& str): string_(std::move(str)){} //this is actually calling string_'s copy constructor as well, std::move(const Str& temp) will create const &&, but if Str does not
    //have a constructor for const r-value, the Str(const Str& ) will be called on std::move(temp), and std::move will create a copy for that.
//    std::move indicate that an object t may be "moved from", and will guarantee to create a r-value reference for the object. However, be careful with const r-value.
     Entity(Str&& str): string_(std::move(str)){}   // therefore, to make universal constructor, we need to pass in the object Str&& as an rvalue from the very beginning.


private:
    Str string_;
};

int main(int argc, char** argv){
    Entity entity(Str("loll")); //temp Str object, then copy temp to Entity's string. THEREFORE CAN WE DIRECTLY "MOVE" TEMP inside?
}


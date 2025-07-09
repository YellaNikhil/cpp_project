#include<iostream>
#include<string>
#include "sdk/cpp/adder.h"
int main(){
    // int count = 1;
    // std::string name;
    // while(count < argc){
    //     name += argv[count++];
    // }
    // name.erase(0, name.find_first_not_of(" \t\n\r\f\v"));
    // name.erase(name.find_last_not_of(" \t\n\r\f\v"));
    // std::cout << name << std::endl;
    std::cout << "Hello World\n";
    std::cout << basicmath::add(2, 2) << std::endl;
    return 0;
}
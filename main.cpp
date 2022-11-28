#include "profile.h"
#include <iostream>

int main(){
    Profile p1("marco", "Marco");    
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)
    return 0;
}
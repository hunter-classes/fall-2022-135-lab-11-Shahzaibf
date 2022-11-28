/*
Author: Shahzaib Fareed
Course: CSCI-135
Instructor: Zamansky
Assignment: Lab 11
    In lab I had to create 2 classes, profile and network.
    Network is an assortment of the profile class.
    Below is the main file with tests for the 3 tasks.
*/
#include "profile.h"
#include "network.h"
#include <string>
#include <iostream>

int main(){
    Profile p1("marco", "Marco");    
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)
    Network nw;
    std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
    std::cout << nw.addUser("luigi", "Luigi") << std::endl;;     // true (1)

    std::cout << nw.addUser("mario", "Mario2") << std::endl;;    // false (0)
    std::cout << nw.addUser("mario 2", "Mario2") << std::endl;;  // false (0)
    std::cout << nw.addUser("mario-2", "Mario2") << std::endl;;  // false (0)

    for(int i = 2; i < 20; i++)
        std::cout << nw.addUser("mario" + std::to_string(i), 
                    "Mario" + std::to_string(i)) << std::endl;;   // true (1)

    std::cout << nw.addUser("yoshi", "Yoshi") << std::endl;;     // false (0)
    Network newnw;
    // add three users
    newnw.addUser("mario", "Mario");
    newnw.addUser("luigi", "Luigi");
    newnw.addUser("yoshi", "Yoshi");

    // make them follow each other
    newnw.follow("mario", "luigi");
    newnw.follow("mario", "yoshi");
    newnw.follow("luigi", "mario");
    newnw.follow("luigi", "yoshi");
    newnw.follow("yoshi", "mario");
    newnw.follow("yoshi", "luigi");

    // add a user who does not follow others
    newnw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        std::string usrn = "mario" + std::to_string(i);
        std::string dspn = "Mario " + std::to_string(i);
        newnw.addUser(usrn, dspn);
        newnw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    newnw.follow("mario2", "luigi");

    newnw.printDot();
    return 0;
}
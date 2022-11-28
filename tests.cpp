#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("Task A"){
    Profile p1("marco", "Marco");
    p1.setDisplayName("Marco Rossi");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco Rossi (@marco)");
    Profile p2("tarma1", "Tarma Roving");
    CHECK(p2.getUsername() == "tarma1");
    CHECK(p2.getFullName() == "Tarma Roving (@tarma1)");
}

TEST_CASE("Task B"){
    Network nw;
    CHECK(nw.addUser("mario", "Mario") == true);
    CHECK(nw.addUser("luigi", "Luigi") == true);
    CHECK(nw.addUser("mario", "Mario2") == false);
    CHECK(nw.addUser("mario 2", "Mario2") == false);
    CHECK(nw.addUser("mario-2", "Mario2") == false);
}

TEST_CASE("Task C"){
    Network newnet;
    newnet.addUser("luigi", "luigi1");
    newnet.addUser("mario", "Mario");
    newnet.addUser("yoshi","Yoshi");

    CHECK(newnet.follow("luigi","yoshi") == true);
    CHECK(newnet.follow("luigi","mario") == true);
    CHECK(newnet.follow("yoshi","mario") == true);
    CHECK(newnet.follow("mario","wario") == false);
    
}
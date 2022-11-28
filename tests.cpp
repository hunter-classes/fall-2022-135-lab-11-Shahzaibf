#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"

TEST_CASE("Task A"){
    Profile p1("marco", "Marco");
    p1.setDisplayName("Marco Rossi");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco Rossi (@marco)");
    Profile p2("tarma1", "Tarma Roving");
    CHECK(p2.getUsername() == "tarma1");
    CHECK(p2.getFullName() == "Tarma Roving (@tarma1)");
}
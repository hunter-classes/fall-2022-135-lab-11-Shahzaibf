#include "network.h"
#include <iostream>
#include <string>

int Network::findID(std::string usrn){
    for(int i = 0;i < MAX_USERS;i++){
        if(profiles[i].getUsername() == usrn){
            return i;
        }
    }
    return -1;
}

Network::Network(){
    numUsers = 0;
    for(int row = 0; row < MAX_USERS;row++){
        for(int col = 0; col < MAX_USERS; col++){
            following[row][col] = false;
        }
    }
}

bool Network::addUser(std::string usrn, std::string dspn){
    bool isalnu = true;
    bool name = true;
    for(int i = 0;i < usrn.length();i++){
        if(!(isalpha(usrn[i])) && !(isdigit(usrn[i]))){
            isalnu = false;
        }
    }
    for(int i = 0; i < MAX_USERS; i++){
        if(profiles[i].getUsername() == usrn){
            name = false;
        }
    }
    if(numUsers < MAX_USERS && usrn != "" && isalnu && name){
        profiles[numUsers] = Profile(usrn, dspn);
        numUsers++;
        return true;
    } else {
        return false;
    }
}

bool Network::follow(std::string usrn1, std::string usrn2){
    if(usrn1 == usrn2 || findID(usrn1) == -1 || findID(usrn2) == -1){
        return false;
    } else {
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }
}

void Network::printDot(){
    std::cout << "digraph {\n";
    for(int i = 0; i < MAX_USERS;i++){
        if(profiles[i].getUsername() != ""){
            std::cout << "  \"@" + profiles[i].getUsername() + "\"\n";
        }
    }
    std::cout << "\n";
    for(int row = 0; row < MAX_USERS; row++){
        for(int col = 0; col < MAX_USERS; col++){
            if(following[row][col]){
                std::cout << "  \"@" + profiles[row].getUsername() + "\" -> \"@" + profiles[col].getUsername() + "\"\n";
            }
        }
    }
    std::cout << "}\n";
}
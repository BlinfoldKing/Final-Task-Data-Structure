#include "userInterface.h"


std::string getString (std::string text) {
    std::cout <<  text;
    std::string res;
    std::cin >> res;
    return res;
}

int multiChoice (std::string choice[], int Nchoice) {
    
    int res;
    
    for( int i = 0; i < Nchoice; i++) {
        std::cout << i + 1 << ". " << choice[i] << '\n';
    }

    std::cout << "\n[input]> ";
    std::cin >> res;

    return res;
}
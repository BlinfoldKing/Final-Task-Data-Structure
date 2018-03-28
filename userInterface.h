#include "header.h"
#include <string>

std::string getString () ;
int getNum ();

int multiChoice (std::string choice[], int Nchoice);

void Follow (addressFollower F, addressCeleb C);
void ShowFollower (addressFollower F);
void ShowCelebs (addressCeleb C);

void ShowCelebFollower (addressCeleb C);
void ShowFollowerFollowing (addressFollower F);



#include "header.h"
#include "userInterface.h"
#include "clrscr.h"

using namespace std;


listCelebs L_C;
listFollowers L_F;

addressCeleb currCeleb;
addressFollower currFollower;

int state = 0;
/*
    -1 : exit
     0  : select mode
     1  : celeb mode [signup]
     2  : follower mode [signup]
     3  : celeb logged
*/


void init () {
    CreateListCeleb(L_C);
    CreateListFollower(L_F);
}





int main () {

    init();
    
    return 0;
}

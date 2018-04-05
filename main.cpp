#include "header.h"
#include "userInterface.h"
#include "clrscr.h"

using namespace std;

int state = 0;
/*
    -1 : exit
     0  : select mode
     1  : celeb mode [signup]
     2  : follower mode [signup]
*/

void showMenu () {
    cout << "==============Welcome==============\n\n";
    string choice[5] = {
        "Signup as Celeb", 
        "Signup as Follower",
        "Login as Celeb",
        "Login as Follower",
        "Exit"
        };

    state = multiChoice(choice, 5);
    if (state == 5) state = -1;
    clrscr();
}

void CelebSignUp () {
    cout << "===================================\n\n";
    
}

int main () {


    while(state != -1) {
        cout << '\n';
        switch (state) {
            case 0:
                showMenu();
                
                break;
            case 1:
                cout << "this is celeb signup";
                break;
            default:
                state = -1;
                break;
        }
    }

    return 0;
}
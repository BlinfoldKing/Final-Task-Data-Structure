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

void showData (char mode) {
    char k = 'x';
    switch (mode) {
        case 'F':
            viewAllFollower(L_F);
            break;
        case 'C':
            viewAllCeleb(L_C);
            break;
        default :
            k = '0';
            break;
    }

    
    cout << "\nEnter 0 to continue : ";
    while ( k != '0' && (state == 5 || state == 6)){
         cin >> k;
         state = 0;
    }

}

void showInfo (char mode, string username) {
    switch (mode) {
        case 'C':
            viewCeleb(L_C, username);
            break;
        case 'F':
            viewFollower(L_F, username);
            break;
    }

    char k = 'x';
    cout << "\nEnter 0 to continue : ";
    while ( k != '0' && (state == 5 || state == 6)){
         cin >> k;
         state = 0;
    }

}


void init () {
    CreateListCeleb(L_C);
    CreateListFollower(L_F);
}

void showMenu () {
    cout << "=========CelebgramCMS admin========\n\n";
    string choice[7] = {
        "Add new Celeb",
        "Add new Follower",
        "Manage a Celeb data",
        "Manage a Follower data",
        "Show all Celeb",
        "Show all Follower",
        "Exit"
        };

    state = multiChoice(choice, 7);
    if (state >= 7) state = -1;
    clrscr();
}

void CelebSignUp () {
    cout << "=============New Celeb==============\n\n";
    InsertLastCeleb(L_C,  AllocateCeleb(getString("Enter new Username : ")));
    clrscr();
    cout << "new Celeb : "<< info(last(L_C)).username << " added\n";
    state = 0;
}


void FollowerSignUp () {
    cout << "=============New Follower===========\n\n";
    InsertLastFollower(L_F, AllocateFollower(getString("Enter new Username : ")));
    clrscr();
    cout << "new Follower : "<< info(last(L_F)).username << " added\n";
    state = 0;
}

int CelebMenu () {
    string choice[2] = {"Show Followers", "Delete this Account"};
    return multiChoice(choice, 2);
}


void Celeblogged () {
    int substate = 0;
    char c = 'x';

    currCeleb = GetCeleb (L_C, getString("find username : "));
    if (currCeleb != nullptr) {

        while(substate != -1) {
            cout << "current celeb :" << info(currCeleb).username;
            cout << '\n';
            switch (substate) {
                case 0:
                    substate = CelebMenu();
                    break;
                case 1:
                    viewCeleb(L_C, info(currCeleb).username);
                    break;
                case 2:
                    DeallocateCeleb(DeleteCeleb(L_C, currCeleb));
                    break;
                default:
                    substate = -1;
                    break;
            }


            if (substate == 2){
                clrscr();
                substate = -1;
            } else if (substate != -1)
                substate = 0;


        }

    } else {
        cout << "username not found";
    }

    state = 0;

}


int main () {

    init();

    while(state != -1) {

        switch (state) {
            case 0:
                showMenu();

                break;
            case 1:
                CelebSignUp();
                break;
            case 2:
                FollowerSignUp();
                break;
            case 3:
                Celeblogged();
                break;
            case 5: 
                showData('C');
              break;
            case 6:
                showData('D');
              break;
            default:
                state = 0;
                break;
        }
        

    }
    return 0;
}

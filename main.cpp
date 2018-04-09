#include "header.h"
#include "userInterface.h"
#include "clrscr.h"
#include <stdio.h>

using namespace std;


listCelebs L_C;
listFollowers L_F;

addressCeleb currCeleb;
addressFollower currFollower;

int state = 0;

void init () {
    CreateListCeleb(L_C);
    CreateListFollower(L_F);
}

void Follow (string Celeb, string Follower) {
    addressCeleb C = GetCeleb(L_C, Celeb);
    addressFollower F = GetFollower(L_F, Follower);

    if (C != nullptr && F != nullptr) {
        if (GetFollower(info(C).Followers, Follower) == nullptr) { 
            InsertLastFollower(info(C).Followers, AllocateFollower(Follower));
            info(C).numberOfFollowers++;
            sortCeleb(L_C);
        } else
            cout << "username has already existed";

        if (GetCeleb(info(F).Following, Celeb) == nullptr) { 
            InsertLastCeleb(info(F).Following, AllocateCeleb(Celeb));
            info(F).numberofFollowing++;
            sortFollower(L_F);
        } else
            cout << "username has already existed";
    }

}

void Unfollow (string Celeb, string Follower) {
    addressCeleb C = GetCeleb(L_C, Celeb);
    addressFollower F = GetFollower(L_F, Follower);

    if (C != nullptr && F != nullptr) {
        if (GetFollower(info(C).Followers, Follower) != nullptr) { 
            DeleteCeleb(info(C).Followers, GetFollower(info(C).Followers, Follower));
            info(C).numberOfFollowers--;
        } else
            cout << "username doesn't exist";

        if (GetCeleb(info(F).Following, Celeb) != nullptr) { 
            DeleteFollower(info(F).Following, GetCeleb(info(F).Following, Celeb));
            info(F).numberofFollowing--;
        } else
            cout << "username doesn't exits";
    }

}
void Continue() {
    char k;
    cout << "\nEnter 0 continue >";
    while( k != '0') {
        cin >> k;
    }
}

int main () {
    clrscr();
    init();
    string menu[4] = {
        "Celebrity Mode",
        "Follower Mode",
        "Admin Mode",
        "Exit"
    };
    cout << "Choose the mode\n";
    state = multiChoice(menu, 4);

    while (state != -1) {
        
        if (state == 0){
            cout << "Choose the mode\n";
            state = multiChoice(menu, 4);
        }else
        if (state == 1) {
            clrscr();
            string submenu[3] = {
                "Sign Up",
                "Remove Account",
                "Exit"
            };
            int substate = multiChoice(submenu, 3);
            clrscr();
            while(substate != -1) {
                if (substate == 0) {
                    substate = multiChoice(submenu, 3);
                }
                if (substate == 1) {
                    InsertLastCeleb (L_C, AllocateCeleb(getString("Masukan username celeb baru : ")));
                    substate = 0;
                } else
                if (substate == 2) {
                    string username = getString("masukan username celeb yang akan dihapus : ");
                    DeleteCeleb(L_C, GetCeleb(L_C, username));
                    addressFollower P = first (L_F);
                    while (P != nullptr) {
                        DeleteCeleb(info(P).Following, GetCeleb(info(P).Following, username));    
                        P = next(P);            
                    }
                    substate = 0;
                } else if (substate == 3) {
                    substate = -1;
                } else substate = 0;
            }
                    
            state = 0;
        } else 
        if (state == 2) {
            clrscr();
            string submenu[5] = {
                "Sign Up",
                "Follow a Celebrity",
                "Unfollow a Celebrity",
                "Remove Account",
                "Exit"
            };
            int substate = multiChoice(submenu, 5);
            clrscr();
            while(substate != -1) {
                if (substate == 0) {
                    substate = multiChoice(submenu, 5);
                }
                if (substate == 1) {
                    InsertLastFollower (L_F, AllocateFollower(getString("Masukan username follower baru : ")));
                    substate = 0;
                } else
                if (substate == 2) {
                    Follow(getString("masukan username celeb : "), getString("masukan username follower : "));
                    substate = 0;
                } else
                if (substate == 3) {
                    Unfollow(getString("masukan username celeb : "), getString("masukan username follower : "));
                    substate = 0;
                } else
                if (substate == 4) {
                    tring username = getString("masukan username follower yang akan dihapus : ");
                    DeleteFollower(L_F, GetFollower(L_F, username));
                    addressCeleb P = first (L_C);
                    while (P != nullptr) {
                        DeleteFollower(info(P).Followers, GetFollower(info(P).Followers, username));    
                        P = next(P);            
                    }
                    substate = 0;
                } else if (substate == 5) {
                    substate = -1;
                } else substate = 0;
            }
                    
            state = 0;
        } else
        if (state == 3) {
            clrscr();
            string submenu[5] = {
                "Show all Celebrities and its Followers",
                "Show a certain Celebrity and its Followers",
                "Show top Celebrity and its Followers",
                "Show all Followers and its Following",
                "Show a certain Follower and its Following",
                "Show Followers with Following more than 3",
                "Exit"
            };
            int substate = multiChoice(submenu, 7);
            clrscr();
            while(substate != -1) {
                if (substate == 0) {
                    substate = multiChoice(submenu, 7);
                } else
                if (substate == 1) {
                    viewAllCeleb(L_C);
                    Continue();
                    substate = 0;
                } else
                if (substate == 2) {
                    viewCeleb(L_C, getString("enter the follower username : "));
                    Continue();
                    substate = 0;
                } else
                if (substate == 3) {
                    viewCeleb(L_C, info(last(L_C)).username);
                    Continue();
                    substate = 0;
                } else
                if (substate == 4) {
                    viewAllFollower(L_F);
                    Continue();
                    substate = 0;
                } else
                if (substate == 5) {
                    viewFollower(L_F, getString("enter the follower username : "));
                    Continue();
                    substate = 0;
                } else
                if (substate == 6) {
                addressFollower F = first(L_F);

                while (F != nullptr) {

                    if(info(F).numberofFollowing > 3) {
                        cout << info(F).username;
                    }

                    F = next(F);
                }   
                Continue();
                state = 0;     
                } else if (substate == 7) {
                    substate = -1;
                } else substate = 0;
            }
        } else
        if (state == 4){
            state = -1;
        } 

        clrscr();
    
    }

    return 0;
}

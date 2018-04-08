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

void Follow (string Follower, string Celeb) {
    addressFollower F = GetFollower(L_F, Follower);
    addressCeleb C = GetCeleb(L_C, Celeb);

    if (F != nullptr && C != nullptr) {
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

void Unfollow (string Follower, string Celeb) {
    addressFollower F = GetFollower(L_F, Follower);
    addressCeleb C = GetCeleb(L_C, Celeb);

    if (F != nullptr && C != nullptr) {
        if (GetFollower(info(C).Followers, Follower) != nullptr) {
            DeleteFollower(info(C).Followers, Follower);
            info(C).numberOfFollowers--;
        } else
            cout << "Username doesn't exist";
        if (GetCeleb(info(F).Following, Celeb) != nullptr) {
            DeleteCeleb(info(F).Following, Celeb);
            info(F).numberofFollowing--;
        }
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
        "Admin Mode"
        "Exit"
    };
    cout << "Choose the mode\n";
    state = multiChoice (menu, 4);

    while (state != -1) {

        if (state == 0) {
            cout << "Choose the mode\n";
            state = multiChoice (menu, 4);
        } else
        if (state == 1) {
            string submenu[3] = {
                "Sign Up",
                "Remove Account",
                "Exit"
            };
            
            int substate = multiChoice (submenu, 3);
            clrscr();
            while (substate != -1) {
                if (substate == 0) {
                    substate = multiChoice (submenu, 3);
                } else
                if (substate == 1) {
                    InsertLastCeleb (L_C, AllocateCeleb(getString("Masukkan username Anda untuk mendaftar : ")));
                    substate = 0;
                } else 
                if (substate == 2) {
                    string username = getString("Masukkan username Anda untuk menghapus :")
                    DeleteCeleb(L_C, GetCeleb(L_C, username));
                    addressFollower P = first (L_F);
                    while (P != nullptr) {
                        DeleteCeleb(info(P).Following, GetCeleb(info(P).Following, username));    
                        P = next(P);            
                    }
                    substate = 0;
                } else 
                if (substate == 2) {
                    substate = -1;
                } else
                    substate = 0;
            }
            state = 0;
        } else
        if (state == 2) {
            string submenu[5] = {
                "Sign Up",
                "Follow a Celebrity",
                "Unfollow a Celebrity",
                "Remove Account",
                "Exit"
            };
            
            int substate = multiChoice (submenu, 5);
            clrscr();
            while (substate != -1) {
                if (substate == 0) {
                    substate = multiChoice (submenu, 5);
                } else
                if (substate == 1) {
                    InsertLastFollower (L_F, AllocateFollower(getString("Masukan username Anda untuk mendaftar : ")));
                    substate = 0;
                } else
                if (substate == 2) {
                    Follow(getString("Masukkan username Anda: "), getString("Masukkan username celebrity yang ingin Anda follow : "))
                    substate = 0;
                } else
                if (substate == 3) {
                    Unfollow(getString("Masukkan username Anda: "), getString("Masukkan username celebrity yang ingin Anda follow : "))
                    substate = 0;
                } else
                if (substate == 4) {
                    string username = getString("Masukkan username Anda untuk menghapus : ");
                    DeleteFollower(L_F, GetFollower(L_F, username));
                    addressCeleb P = first (L_C);
                    while (P != nullptr) {
                        DeleteFollower(info(P).Followers, GetFollower(info(P).Followers, username));    
                        P = next(P);            
                    }
                    substate = 0;
                } else
                if (substate == 5)
                    substate = -1;
                else
                    substate = 0;
         } else
        if (state == 3) {
            string submenu[5] = {
                "Show All Celebrities with its Follower(s)",
                "Show A Certain Celebrity with its Follower(s)",
                "Show Top Celeberity with its Follower(s)",
                "Show All Followers with its Following",
                "Show a Certain Follower with its Following",
                "Show a Follower who Follow more than 3 Celebrities and its Following";
            };
                
            int substate = multiChoice (submenu, 5);
            clrscr();
            while (substate != -1) {
                if (substate == 0) {
                    substate = multiChoice (submenu, 5);
                } else
                if (substate == 1) {
                    viewAllCeleb(L_C);
                    Continue();
                    state = 0;
                } else
                if (substate == 2) {
                    addressCeleb C = GetCeleb(L_C, getString("enter the celeb username : "));
                    addressFollower F = GetFollower(info(C).Followers, getString("enter the follower name : "));
                    if (F == nullptr) 
                        cout << "Follower not found  ";
                    else {
                        viewFollower (info(C).Followers, info(F).username);
                    }
                    Continue();
                    state = 0;
                } else
                if (substate == 3) {
                    viewFollower(L_F);
                    Continue();
                    state = 0;
                } else
                if (substate == 4) {
                    viewCeleb (L_C, info(last(L_C)).username);
                    continue();
                    state = 0;
                } else
                if (substate == 5) {
                    addressFollower F = first(L_F);

                    while (F != nullptr) {

                        if(info(F).numberofFollowing > 3) {
                            cout << info(F).username;
                        }

                        F = next(F);
                    }   
                    Continue();
                    state = 0; 
                } else
                if (substate == 6)
                    substate = -1;
                else
                    substate = 0;
        }
    }

    return 0;
}
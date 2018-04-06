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
    string menu[9] = {
        "Add new Celeb",
        "Delete a Celeb",
        "Show all Celeb",
        "Search A Follower",
        "Top Celeb",
        "Add new Follower",
        "Select Follower to follow Celeb",
        "Show Follower with more than 3 celebs",
        "Exit"
    };
    cout << "Choose the mode\n";
    state = multiChoice(menu, 9);

    while (state != -1) {
        
        if (state == 0){
            cout << "Choose the mode\n";
            state = multiChoice(menu, 9);
        }else
        if (state == 1) {
            InsertLastCeleb (L_C, AllocateCeleb(getString("Masukan username celeb baru : ")));        
            state = 0;
        } else 
        if (state == 2) {
            string username = getString("masukan username celeb yang akan dihapus : ");
            DeleteCeleb(L_C, GetCeleb(L_C, username));
            addressFollower P = first (L_F);
            while (P != nullptr) {
                DeleteCeleb(info(P).Following, GetCeleb(info(P).Following, username));    
                P = next(P);            
            }
            state = 0;    
        } else
        if (state == 3) {
            viewAllCeleb(L_C);
            Continue();
            state = 0;
        } else
        if (state == 4) {
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
        if (state == 5) {
            viewCeleb(L_C, info(last(L_C)).username);
            Continue();
            state = 0;
        }
        if (state == 6) {
            InsertLastFollower (L_F, AllocateFollower(getString("Masukan username follower baru : ")));        
            state = 0;   
        }
        if (state == 7) {
            Follow(getString("masukan username celeb : "), getString("masukan username follower : "));
            state = 0;
        } else 
        if (state == 8) {
            addressFollower F = first(L_F);

            while (F != nullptr) {

                if(info(F).numberofFollowing > 3) {
                    viewFollower(L_F, info(F).username);
                }

                F = next(F);
            }   
            Continue();
            state = 0;            
        }
        if (state == 9){
            state = -1;
        } 






        clrscr();
    
    }

    return 0;
}

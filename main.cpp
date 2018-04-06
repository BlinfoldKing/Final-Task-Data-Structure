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

void Follow (string Celeb, string Follower) {
    addressCeleb C = GetCeleb(L_C, Celeb);
    addressFollower F = GetFollower(L_F, Follower);

    if (C != nullptr && F != nullptr) {
        if (GetFollower(info(C).Followers, Follower) == nullptr) { 
            InsertLastFollower(info(C).Followers, AllocateFollower(Follower));
            info(C).numberOfFollowers++;
        } else
            cout << "username has already existed";

        if (GetCeleb(info(F).Following, Celeb) == nullptr) { 
            InsertLastCeleb(info(F).Following, AllocateCeleb(Celeb));
            info(F).numberofFollowing++;
        } else
            cout << "username has already existed";
    }

}

void Continue() {
    char k;
    cout << "Enter 0 continue\n";
    while( k != '0') {
        cin >> k;
    }
}

int main () {

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
            state = multiChoice(menu, 7);
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
            addressFollower F = GetFollower(info(GetCeleb(L_C, getString("enter the celeb username : "))).Followers, getString("enter the follower name : "));
            if (F == nullptr) 
                cout << "Follower not found  ";
            else {
                cout << "username    : " << info(F).username;
                cout << "celeb count : " << info(F).numberofFollowing;
                cout << "Followers   : ";
                viewAllCeleb (info(F).Following);
            }
            Continue();
            state = 0;
        } else 
        if (state == 5) {
            
        }
        if (state == 6) {
            
        }
        if (state == 7) {
            
        } else 
        if (state == 9){
            state = -1;
        } 






        clrscr();
    
    }


    // addressCeleb C = AllocateCeleb("danu");
    // addressFollower F = AllocateFollower("jancok");
    // addressFollower F2 = AllocateFollower("jancok");

    // addNewFollower(C, F);
    // addNewFollower(C, F2);
    // viewAllFollower(info(C).Followers);
    // addNewFollowing(F, C);
    // viewAllCeleb(info(F).Following);

    //cout << info(last(info(C).Followers)).username;

    return 0;
}

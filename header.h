#ifndef STD_HEADER
#define STD_HEADER

#include <iostream>
#include <string>

// Macros

#define first(L) (L).first
#define last(L)  (L).last
#define next(P)  (P)->next
#define prev(P)  (P)->prev
#define info(P)  (P)->info

// List Declaration

typedef struct Follower *addressFollower;
typedef struct Celeb *addressCeleb;

struct listFollowers {
    addressFollower first;
    addressFollower last;
};


struct listCelebs {
    addressCeleb first;
    addressCeleb last;
};

// Celebrity Data Structure

struct infotypeCeleb {
    std::string username;
    int numberOfFollowers;
    listFollowers Followers;
};

struct Celeb {
    infotypeCeleb info;
    addressCeleb next;
    addressCeleb prev; 
};

addressCeleb AllocateCeleb (std::string username);
addressCeleb GetCeleb (listCelebs &L, std::string username);
addressCeleb DeleteFirstCeleb (listCelebs &L);
addressCeleb DeleteLastCeleb (listCelebs &L);
addressCeleb DeleteCeleb (listCelebs &L, addressCeleb C);

void CreateListCeleb (listCelebs &L);
void DeallocateCeleb (addressCeleb C);
void InserFirstCeleb (listCelebs &L, addressCeleb C);
void InsertLastCeleb (listCelebs &L, addressCeleb C);
void InsertAfterCeleb (listCelebs &L, addressCeleb Prec, addressCeleb C);
void sortCeleb (listCelebs &L1);
void viewAllCeleb (listCelebs L);
void viewCeleb (listCelebs L, std::string username);

// Followers Data Structure

struct infotypeFollower {
    std::string username;
    int numberofFollowing; 
    struct listCelebs Following;
};

struct Follower {
    infotypeFollower info;
    addressFollower next; 
    addressFollower prev;
};

addressFollower AllocateFollower (std::string username);
addressFollower GetFollower (listFollowers &Followers, std::string username);
addressFollower DeleteFollower (listFollowers &L, addressFollower C);
addressFollower DeleteFirstFollower (listFollowers &L);
addressFollower DeleteLastFollower (listFollowers &L);

void CreateListFollower (listFollowers &L);
void DeallocateFollower (addressFollower F);
void InsertFirstFollower (listFollowers &L, addressFollower F);
void InsertLastFollower (listFollowers &L, addressFollower F);
void InsertAfterFollower (listFollowers &L, addressFollower Prec, addressFollower F);
void sortFollower (listFollowers L1);
void viewAllFollower (listFollowers L);
void viewFollower (listFollowers L, std::string username);


#endif
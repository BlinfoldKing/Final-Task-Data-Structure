#ifndef STD_HEADER
#define STD_HEADER

// Celebrity Data Structure

#include <string>

#define first(L) (L).first
#define last(L)  (L).last
#define next(P)  (P)->next
#define prev(P)  (P)->prev
#define info(P)  (P)->info
// list declaration

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

//----------------------------------
struct infotypeCeleb {
    std::string username;
    listFollowers Followers;
};

struct Celeb {
    infotypeCeleb info;
     addressCeleb next; 
};

addressCeleb AllocateCeleb (std::string username);
addressCeleb GetCeleb (listCelebs Celebs, addressCeleb);
addressCeleb DeleteCeleb (listCelebs Celebs, addressCeleb);

void DeallocateCeleb (std::string username);
void InsertCeleb (listCelebs Celebs, addressCeleb);
void CreateListCeleb (listCelebs);

// Followers Data Structure
struct infotypeFollower {
    std::string username;
    struct listCelebs Following;
};
struct Follower {
    infotypeFollower info;
    addressFollower next; 
};

#endif
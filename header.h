#include <string>


// Celebrity Data Structure

#define first(L) (L).first
#define last(L)  (L).last
#define next(P)  (P)->next
#define prev(P)  (P)->prev

struct infotypeCeleb {
    std::string username;
    listFollowers Follower;
};

typedef struct Celeb *addressCeleb;
struct Celeb {
    infotypeCeleb info;
    addressCeleb next; 
};

typedef struct listCelebs {
    addressCeleb first;
    addressCeleb last;
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
    listCelebs Following;
};

typedef struct Follower *addressFollower;
struct Follower {
    infotypeFollower info;
    addressFollower next; 
};

typedef struct listFollowers {
    addressFollower first;
    addressFollower last;
};


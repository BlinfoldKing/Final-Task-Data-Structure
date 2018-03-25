#include <string>

// Celebrity Data Structure

#define first(L) (L).first
#define last(L)  (L).last
#define next(P)  (P)->next
#define prev(P)  (P)->prev
#define info(P)  (P)->info

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


#include <string>


// Celebrity Data Structure

struct infotypeCeleb {
    std::string username;
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


// Followers Data Structure

struct infotypeFollower {
    std::string username;
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


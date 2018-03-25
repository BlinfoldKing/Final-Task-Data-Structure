#include <string>
#include "celebs.h"
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


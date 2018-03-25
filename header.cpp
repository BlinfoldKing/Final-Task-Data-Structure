#include "celebs.h"
#include "followers.h"

addressCeleb AllocateCeleb (std::string username) {
    addressCeleb p = new addressCeleb;
    info(p).username = username;

    return p;
}
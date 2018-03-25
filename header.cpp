#include "header.h"

addressCeleb AllocateCeleb (std::string username) {
    addressCeleb p;
    info(p).username = username;
    next(P) = nullptr;
    prev(P) = nullptr;

    return p;
}

void CreateListCeleb (listCelebs L) {
    first (L) = nullptr;
    last (L) = nullptr;
}

addressCeleb GetCeleb (listCelebs L, std::username) {

    addressCeleb P = first (L);

    while (P != nullptr || info(P).username == username)
        P = next (P);

    return P; 

}

addressCeleb DeleteFirstCeleb (listCelebs L) {

    addressCeleb P = first (L);

    if (P != nullptr) {
        if (next (P) == nullptr)
            last(L)  = nullptr;
            first(L) = nullptr;
        else {
            prev (next (P)) = nullptr;
            next (P) = nullptr;
        }
    }

    return P;
}

addressCeleb DeleteLastCeleb (listCelebs L) {

    addressCeleb P = last (L);

    if (P != nullptr) {
        if (last (P) == first (P)) {
            last(L)  = nullptr;
            first(L) = nullptr;
        }
        else {
            next (prev (P)) = nullptr;
            prev (P) = nullptr;
        }
    }

    return P;
}

addressCeleb DeleteCeleb (listCelebs L, addressCeleb C) {

    address P = GetCeleb (info(C).username);

    if (P != nullptr) {
        if (P == first(L)) {
            P = DeleteFirstCeleb (L);
        } else if (P == last(L)) {
            P = DeletelastCeleb (L);
        } else {
            prev (next (P)) = prev(P);
            next (prev (P)) = next(P);
            next (P) = nullptr;
            prev (P) = nullptr
        }
    }

    return P;

}

void addNewFollower (addressCeleb C, addressFollower F) {
    
    listFollowers L = info(C).Followers;
    P = GetFollower(L, info(F).username);

    if (P != nullptr)
        InsertLastFollower(L, F);
    else
        cout << "username has already existed";
        
}
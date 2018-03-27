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

void InsertLastCeleb (listCelebs L, addressCeleb C) {
    if (last (L) == nullptr)
        last (L) = C;
    else {
        next (last (L)) = C;
        prev (C) = last (L);
        last (L) = C;
    }
}

void addNewFollower (addressCeleb C, addressFollower F) {
    
    listFollowers L = info(C).Followers;
    P = GetFollower(L, info(F).username);

    if (P != nullptr)
        InsertLastFollower(L, F);
    else
        cout << "username has already existed";
        
}

// Followers Implementation

addressFollower AllocateFollower (std::string username) {
    addressFollower P;
    P = new Follower;
    info(P).username = username;
    next(P) = nullptr;
    prev(P) = nullptr;

    return p;
}


addressFollower GetFollower (listFollowers Followers, std::string username) {
    addressFollower P = first (L);

    while (P != nullptr && info(P).username != username)
        P = next (P);

    return P; 
}

addressFollower DeleteFollower (listFollowers L, addressFollower F) {
    address P = GetFollower (info(F).username);

    if (P != nullptr) {
        if (P == first(L)) {
            P = DeleteFirstFollower (L);
        } else if (P == last(L)) {
            P = DeleteLastFollower (L);
        } else {
            prev (next (P)) = prev(P);
            next (prev (P)) = next(P);
            next (P) = nullptr;
            prev (P) = nullptr
        }
    }

    return P;
}

addressFollower DeleteFirstFollower (listFollowers L) {
    
    addressFollower P = first (L);

    if (P != nullptr) {
        if (P == last(L)) {
            last(L)  = nullptr;
            first(L) = nullptr;
        } else {
            first(L) = next(first(L));
            next(P) = nullptr;
            prev(first(L)) = nullptr;
        }
    }

    return P;
}

addressFollower DeleteLastFollower (listFollowers L) {

    addressFollower P = last (L);

    if (P != nullptr) {
        if (P == first(L)) {
            last(L)  = nullptr;
            first(L) = nullptr;
        }
        else {
            last(L) = prev(P);
            prev(P) = nullptr;
            next(last(L)) = nullptr;
        }
    }

    return P;

}

void DeallocateFollower (addressFollower P) {
    delete P;
    P = nullptr;
}

void InsertLastFollower (listFollowers L, addressFollower F) {
    if (last(L) == nullptr)
        last(L) = F;
    else {
        next(last(L)) = F;
        prev(F) = last (L);
        last(L) = F;
    }
}

void CreateListFollower (listFollowers L){
    first (L) = nullptr;
    last (L) = nullptr;
}

void addNewFollowing (addressFollower F, addressCeleb C){
    listCelebs L = info(F).Following;
    P = GetCeleb(L, info(C).username);

    if (P != nullptr)
        InsertLastCeleb(L, C);
    else
        cout << "username has already existed";
}
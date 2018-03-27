#include "header.h"

addressCeleb AllocateCeleb (std::string username) {
    
    addressCeleb P;

    P = new Celeb;
    info(P).username = username;
    info(P).numberOfFollowers = 0;
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

    while (P != nullptr && info(P).username == username)
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

void InserFirstCeleb (listCelebs L, addressCeleb C) {

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

void InsertAfterCeleb (listCelebs L, addressCeleb Prec, addressCeleb C) {

}

void sortFollowing (listCelebs L1){
    listCelebs L2;
    CreateListCeleb(L2);
    while(first(L1) != nullptr) {
        addressCeleb P = DeletelastCeleb(L1);
        if (first(L2) == nullptr) {
            InsertFirstCeleb(L2, P);
        } else if (info(P).numberOfFollowers <= info(first(L2)).numberOfFollowers) {
            InsertFirstCeleb(L2, P);
        } else if (info(P).numberOfFollowers >= info(first(L2)).numberOfFollowers) {
            InsertLastCeleb(L2, P);
        } else {
            addressFollower Q = first(L2);
            while(info(next(Q)).numberOfFollowers < info(P).numberOfFollowers) {
                Q = next(Q);
            }
            InsertAfterCeleb(L2, Q, P);
        }
    }
    L1 = L2;
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
    info(P).numberofFollowing = 0;
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

void InsertFirstFollower (listFollowers L, addressFollower F) {

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

void InsertAfterFollower (listFollowers L, addressFollower Prec, addressFollower F) {
    
}

void CreateListFollower (listFollowers L){
    first (L) = nullptr;
    last (L) = nullptr;
}

void sortFollower (listFollowers L1){
    listFollowers L2;
    CreateListFollower(L2);
    while(first(L1) != nullptr) {
        addressFollower P = DeleteLastFollower(L1);
        if (first(L2) == nullptr) {
            InsertFirstFollower(L2, P);
        } else if (info(P).numberofFollowing <= info(first(L2)).numberofFollowing) {
            InsertFirstFollower(L2, P);
        } else if (info(P).numberofFollowing >= info(first(L2)).numberofFollowing) {
            InsertLastFollower(L2, P);
        } else {
            addressFollower Q = first(L2);
            while(info(next(Q)).numberofFollowing < info(P).numberofFollowing) {
                Q = next(Q);
            }
            InsertAfterFollower(L2, Q, P);
        }
    }
    L1 = L2;
}


void addNewFollowing (addressFollower F, addressCeleb C){
    
    listCelebs L = info(F).Following;
    P = GetCeleb(L, info(C).username);

    if (P != nullptr)
        InsertLastCeleb(L, C);
    else
        cout << "username has already existed";

}
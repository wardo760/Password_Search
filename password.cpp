#include "password.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// constructors
Password::Password()
{
    plaintext = "";
    rank = -1;
    hash = "";
}
Password::Password(string p, int r, string h)
{
    plaintext = p;
    rank = r;
    hash = h;
}
Password::Password(const Password & copy)
{
    plaintext = copy.plaintext;
    rank = copy.rank;
    hash = copy.hash;
}
Password::~Password()
{
    
}

// getter
string Password::getPlaintext() const
{
    return plaintext; 
}
int Password::getRank() const
{
    return rank;
}
string Password::getHash() const
{
    return hash;
}

//setters
void Password::setPlaintext(string p)
{
    plaintext = p;
}
void Password::setRank(int r)
{
    rank = r;
}
void Password::setHash(string h)
{
    hash = h;
}

//print
void Password::print()
{
    cout << plaintext << ", " << rank << ", " << hash << endl;
}
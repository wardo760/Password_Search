#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Password
{
    public:
        //constructor
        Password();
        Password(string p, int r, string h);
        Password(const Password & copy);
        ~Password();

        // getter
        string getPlaintext() const;
        int getRank() const;
        string getHash() const;

        // setter
        void setPlaintext(string p);
        void setRank(int r);
        void setHash(string h);

        // print
        void print();

    private:
        string plaintext;
        int rank;
        string hash;
};

#endif
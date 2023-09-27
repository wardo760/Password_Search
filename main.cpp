//----------------------------------------------
// Purpose: Starter code for homework 3 - you should use this code 
// to read in your files instead of starting from scratch!
//----------------------------------------------

#include "password.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <sstream>
using namespace std;

// PROVIDED
bool readFile(string filename, vector<Password> &list)
{
    string password;
    string rank;
    string hash;

    ifstream din;
    din.open(filename);
    if(din.fail()){
        cout << "Error in opening file.\n";
        return 0;
    }
    while(getline(din, password, ','))
    {
        getline(din, rank, ',');
        getline(din, hash);
        Password temp (password,stoi(rank),hash);
        list.push_back(temp);
    }
    din.close();
    return 1;
}
// PROVIDED
bool readFile_given_hashes(string filename, vector<string> &list)
{
    string hash;

    ifstream din;
    din.open(filename);
    if(din.fail()){
        cout << "Error in opening file.\n";
        return 0;
    }
    while(getline(din,hash)){
        list.push_back(hash);
    }
    return 1;
}
// ADD SEARCH FUNCTIONS HERE!!
int search_range(string str1, string str2, int min, int max, vector<Password> pass)
{
    if(str1 > str2)
    {
        cout << "switch strings" << endl;
        string temp;
        temp = str1;
        str1 = str2;
        str2 = temp;
    }
    int midIndex = ((max+min)/2);
    if(pass[midIndex].getPlaintext() == str1)
    {
        while(pass[midIndex].getPlaintext() != str2)
        {
            pass[midIndex].print();
            midIndex++;
        }
        pass[midIndex].print();
        return 0;
    }
    else if(str1 > pass[midIndex].getPlaintext())
    {
        return search_range(str1, str2, midIndex + 1, max, pass);
    }
    else if(str1 < pass[midIndex].getPlaintext())
    {
        return search_range(str1, str2, min, midIndex - 1, pass);
    }
    return 0;
}
Password search_password(string str, int min, int max, vector<Password> pass)
{
    int midIndex = ((max+min)/2);
    if(pass[midIndex].getPlaintext() == str)
    {
        return pass[midIndex];
    }
    if(min > max)
    {
        return Password();
    }
    else if(str > pass[midIndex].getPlaintext())
    {
        return search_password(str, midIndex + 1, max, pass);
    }
    else if(str < pass[midIndex].getPlaintext())
    {
        return search_password(str, min, midIndex - 1, pass);
    }
    return Password();
}
int search_hashes(vector<string> g_h, int min, int max, vector<Password> h, int index)
{
    int midIndex = (max+min)/2;
    if(stoi(g_h[index], 0, 16) == stoi(h[midIndex].getHash(), 0, 16))
    {
        h[midIndex].print();
        if(index == g_h.size() - 1)
        {
            return 0;
        }
        else
        {
            index++;
            return search_hashes(g_h, 0, h.size(), h, index);
        }
    }
    if(min > max)
    {
        if(index == g_h.size() - 1)
        {
            return 0;
        }
        else
        {
            cout << "Password doesn't exist" << endl;
            index++;
            return search_hashes(g_h, 0, h.size(), h, index);
        }
    }
    else if(stoi(g_h[index], 0, 16) > stoi(h[midIndex].getHash(), 0, 16))
    {
        return search_hashes(g_h, midIndex + 1, max, h, index);
    }
    else if(stoi(g_h[index], 0, 16) < stoi(h[midIndex].getHash(), 0, 16))
    {
        return search_hashes(g_h, min, midIndex - 1, h, index);
    }
    return 0;
}
Password linear_search_password(string key, vector<Password> pass)
{
    for(int i = 0; i < pass.size(); i++)
    {
        if(key == pass[i].getPlaintext())
        {
            return pass[i];
        }
    }
    return Password();
}
int iterative_search_password(string key, vector<Password> pass)
{
    int min = 0;
    int max = pass.size() - 1;
    while(min <= max)
    {
        int mid = min + (max-min)/2;
        if(key == pass[mid].getPlaintext())
        {
            pass[mid].print();
            return 0;
        }
        else if(key < pass[mid].getPlaintext())
        {
            max = mid - 1;
        }
        else if(key > pass[mid].getPlaintext())
        {
            min = mid + 1;
        }
    }
    cout << "password doesn't exist" << endl;
    return 0;
}
//----------------------------------------------
int main()
{
    //vector for hash sorted file
    vector<Password> hash;
    //vector for password sorted file
    vector<Password> password;
    //vector for hashes to search for
    vector<string> given_hashes;

    readFile("sorted_hash_indexed_list.txt",hash);
    readFile("sorted_password_indexed_list.txt",password);
    readFile_given_hashes("hashes_to_search.txt",given_hashes);

    // ADD YOUR MENU, USER CHOICE, AND IMPLEMENT MENU OPTIONS HERE
    int menu;
    string pass, pass1, pass2;
    while(menu != 6)
    {
        cout << "----------------------------------------------" << endl;
        cout << "Select Menu Option in form of a number:" << endl;
        cout << "1.) Search recursively two passwords and pull all the passwords between them" << endl;
        cout << "2.) Search recursively by password" << endl;
        cout << "3.) Search recursively of given file by hash" << endl;
        cout << "4.) Compare linear and binary search" << endl;
        cout << "5.) Iterative binary search for password" << endl;
        cout << "6.) exit" << endl;
        cout << ":";
        cin >> menu;
        cout << "----------------------------------------------" << endl;
        if(menu == 1)
        {
            cout << "First password:" << endl;
            cout << "-";
            getline(cin >> ws, pass1);
            cout << "Second password:" << endl;
            cout << "-";
            getline(cin >> ws, pass2);
            
            cout << "Password, Rank, Hash" << endl;
            search_range(pass1, pass2, 0, password.size() - 1, password);
        }
        
        else if(menu == 2)
        {
            cout << "Password:" << endl;
            cout << "-";
            getline(cin >> ws, pass);
            
            if(search_password(pass, 0, password.size() - 1, password).getPlaintext() != "")
                search_password(pass, 0, password.size() - 1, password).print();
            else
                cout << "Password doesdn't exist." << endl;
        }
        
        else if(menu == 3)
        {
            search_hashes(given_hashes, 0, hash.size(), hash, 0);
        }
        
        else if(menu == 4)
        {
            cout << "Password to compare:" << endl;
            cout << "-";
            getline(cin >> ws, pass);
            
            clock_t r_time1=clock();
            for(int i =0; i < 1000; i++)
            {
                search_password(pass, 0, password.size() - 1, password);
            }
            clock_t r_time2=clock();
            float recTime = (r_time2-r_time1)/(double)CLOCKS_PER_SEC;
            
            clock_t l_time1=clock();
            for(int i = 0; i < 1000; i++)
            {
                linear_search_password(pass, password);
            }
            clock_t l_time2=clock();
            float linTime = (l_time2-l_time1)/(double)CLOCKS_PER_SEC;
            
            if(recTime < linTime)
            {
                cout << "Recursive search was " << linTime/recTime << " times faster than linear search." << endl;
            }
            
            else if(recTime > linTime)
            {
                cout << "Linear search was " << recTime/linTime << " times faster than recursive search." << endl;
            }
            
            else if(recTime == linTime)
            {
                cout << "Both recursive and linear search took the same amount of time." << endl;
            }
        }
        
        else if(menu == 5)
        {
            cout << "Password:" << endl;
            cout << "-";
            getline(cin >> ws, pass);
            
            cout << "Password, Rank, Hash" << endl;
            iterative_search_password(pass, password);
        }
        
        else if(menu == 6)
        {
            cout << "End of program" << endl;
        }
        
        else if(menu > 6 || menu < 1)
        {
            cout << "Not a viable menu selection" << endl;
        }
    }
}


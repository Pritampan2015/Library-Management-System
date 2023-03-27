#include<bits/stdc++.h>

using namespace std;


class Library{
    string userName;
    string password;
public:
    Library();
    Library(string,string);
    void set_username_and_password(string,string);
    bool password_cheaker(string,string);

};
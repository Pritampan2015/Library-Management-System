#include<bits/stdc++.h>
using namespace std;

class BOOK{
    int book_id;
    string book_title;
    string book_author;
    string book_publisher;
    string book_edition;
    double book_price;
    int no_of_pages;
    int no_of_book_available;
public:
    BOOK();
    BOOK(int,string,string,string,string,double,int,int);
    //getter functions
    int get_book_id();
    string get_book_title();
    string get_book_author();
    string get_book_publisher();
    string get_book_edition();
    double get_book_price();
    int get_no_of_pages();
    int get_no_of_book_available();

    //setter functions
    void  set_book_id(int );
    void  set_book_title(string);
    void  set_book_author(string);
    void  set_book_publisher(string);
    void  set_book_edition(string);
    void  set_book_price(double);
    void  set_no_of_pages(int);
    void  set_no_of_book_available(int);

    // basic function
    void Accept();
    void Display();
    void Update();


    //Destructor
  //  ~BOOK();
};
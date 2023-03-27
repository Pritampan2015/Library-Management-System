#include"Book.h"
#define clrscr ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

BOOK::BOOK(){
    //Default constructor initialization
    book_id=0;
    book_title="Default";
    book_author="Default";
    book_publisher="Default";
    book_edition="Default";
    book_price=0.0;
    no_of_pages=0;
    no_of_book_available=0;
}

BOOK::BOOK(int a,string b,string c,string d,string e,double f,int g,int h){
    //Parameterized constructor initialization
    book_id=a;
    book_title=b;
    book_author=c;
    book_publisher=d;
    book_edition=e;
    book_price=f;
    no_of_pages=g;
    no_of_book_available=h;
}

//getter functions initialization

int BOOK::get_book_id(){
    return book_id;
}

string BOOK::get_book_title(){
    return book_title;
}

string BOOK::get_book_author(){
    return book_author;
}

string BOOK::get_book_publisher(){
    return book_publisher;
}

string BOOK::get_book_edition(){
    return book_edition;
}

double BOOK::get_book_price(){
    return book_price;
}

int BOOK::get_no_of_pages(){
    return no_of_pages;

}

int BOOK::get_no_of_book_available(){
    return no_of_book_available;

}



//setter function initialization

void BOOK::set_book_id(int a){
    book_id=a;
}

void BOOK::set_book_title(string b){
    book_title=b;
}

void BOOK::set_book_author(string c){
    book_author=c;
}

void BOOK::set_book_publisher(string d){
    book_publisher=d;
}

void BOOK::set_book_edition(string e){
    book_edition=e;
}

void BOOK::set_book_price(double f){
    book_price=f;
}

void BOOK::set_no_of_pages(int g){
    no_of_pages=g;

}

void BOOK::set_no_of_book_available(int h){
    no_of_book_available=h;

}


//basic functions

void BOOK::Accept(){
    cout<<"\n\tEnter Book Id: ";
    cin>>book_id;
    cout<<"\n\tEnter Book Name: ";
    cin.sync();
    getline(cin,book_title);
    cout<<"\n\tEnter Book Author: ";
    cin.sync();
    getline(cin,book_author);
    cout<<"\n\tEnter Book Publisher: ";
    cin>>book_publisher;
    cout<<"\n\tEnter Book Edition: ";
    cin>>book_edition;
    cout<<"\n\tEnter Book Price: ";
    cin>>book_price;
    cout<<"\n\tEnter Total No Of Pages: ";
    cin>>no_of_pages;
    cout<<"\n\tEnter No of Book Available: ";
    cin>>no_of_book_available;
}

// book display functon
void BOOK::Display(){
    cout<<"\n\tBOOK ID:\t"<<book_id;
    cout<<"\n\tBOOK NAME:\t"<<book_title;
    cout<<"\n\tBOOK AUTHOR:\t"<<book_author;
    cout<<"\n\tBOOK PUBLISHER:\t"<<book_publisher;
    cout<<"\n\tBOOK EDITION:\t"<<book_edition;
    cout<<"\n\tBOOK PRICE:\t"<<book_price;
    cout<<"\n\tTOTAL PAGES OF THE BOOK:\t"<<no_of_pages;
    cout<<"\n\tTOTAL OF THE BOOK AVAILABLE:\t"<<no_of_book_available;
}










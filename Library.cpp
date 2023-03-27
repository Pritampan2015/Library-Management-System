#include<bits/stdc++.h>
#include"Library.h"
#include"Book.cpp"
#include"Student.cpp"

vector<BOOK>book_database;
vector<Student>student_database;


//library default constructor
Library::Library(){
    userName="admin";
    password="admin";
}

//library parameterized constructor
Library::Library(string a,string b){
    userName=a;
    password=b;
}

//basic functions
void Library::set_username_and_password(string a,string b){
    userName=a;
    password=b;
}
//password cheaaker function
bool Library::password_cheaker(string user,string pwd){
    return ((userName==user) and (pwd==password));
}


 
unordered_map<int,string>book_allocation;  //unique student id , book Name
unordered_map<string,int>mp_id_pos;  //book_name, db pos;

//book name and id indexing function
void mp_id_pos_function(){
    int j=0;
    for(BOOK bk:book_database){
        mp_id_pos.insert({bk.get_book_title(),j});
        j++;
    }
}


// file handeling function for book allocation
void update_final_issued_book_to_file(){
    ofstream out;
    out.open("book_allocation.txt");
    for(auto it:book_allocation){
        out<<it.first<<"\n";
        out<<it.second<<"\n";
    }
    out.close();
}



// book allocation function
bool book_allocation_function(){
    cout<<"\n\tENTER THE STUDENT ID FOR TAKING BOOK: ";
    int std_id;cin>>std_id;
    if(book_allocation.find(std_id)!=book_allocation.end()){
        cout<<"\n\tALREADY "<<book_allocation[std_id]<<" BOOK HAS BEEN TAKEN PLEASE RETURN TO ISSUE ANOTHER BOOK";
        return false;
    }
    cout<<"\n\tENTER BOOK NAME FOR ISSUE :";
    string issued_book_name;
    cin.sync();
    getline(cin,issued_book_name);
    ofstream out;
    out.open("book_allocation.txt");
    for(int i=0;i<book_database.size();i++){
        if(book_database[i].get_book_title()==issued_book_name){
            if(book_database[i].get_no_of_book_available()>0){
                book_allocation.insert({std_id,issued_book_name});
                out<<std_id<<"\n";
                out<<issued_book_name<<"\n";
                int available_books=book_database[i].get_no_of_book_available()-1;
                //cout<<"[]"<<available_books<<"[]"<<"\n";
                book_database[i].set_no_of_book_available(available_books);
                out.close();
                return true;
            }
            else {
                cout<<"\n\t\t\t\tBOOK IS NOT IN THE STOCK CONTACT LETTER";
                out.close();
                return false;
            }
        }

    }
            cout<<"\n\t\t\t\tBOOK IS NOT AVAILABLE IN THE LIBRARY";
            out.close();
            return false;
}



//book deposit function
bool book_deposit_function(){
     cout<<"\n\tENTER THE STUDENT ID FOR DEPOSIT BOOK: ";
    int std_id;cin>>std_id;
    if(book_allocation.find(std_id)!=book_allocation.end()){
        int db_pos=mp_id_pos[book_allocation[std_id]];
        book_allocation.erase(std_id);
        book_database[db_pos].set_no_of_book_available(book_database[db_pos].get_no_of_book_available()+1);
        update_final_issued_book_to_file();
        cout<<"\n\t\t\t\t\t\tBOOK DEPOSIT COMPLETED";
        //book updation problem
        return true;
    }
    else{
        cout<<"\n\t\t\t\t\t\tTHIS STUDENT HAVE NOT TAKEN ANY BOOK";
        return false;
    }

}


//Library display function
void display_student_issued_book_details(){
    cout<<"\n\t\t\t\tBOOK_NAME"<<"\t\t\t\t"<<"STUDENT NAME\n";
    for(auto it:book_allocation){
        for(Student st:student_database){
            if(it.first==st.get_card_no()){
                cout<<"\t\t\t\t"<<it.second<<"\t\t\t\t\t"<<st.get_student_name()<<"\n";
            }
        }
    }
}

//string to int conversion
int stoii(string str){
    stringstream ss(str);
    int x;
    ss>>x;
    return x;
}

//file handeling functions for library 
void book_input_from_file(){
    ifstream in;
    in.open("book.txt");
    string x; getline(in,x);
    int n=stoii(x);
    //cout<<x<<" "<<sizeof(x);
    for(int i=0;i<n;i++){
        string a,b,c,d,e,f,g,h;
        getline(in,a);
        getline(in,b);
        getline(in,c);
        getline(in,d);
        getline(in,e);
        getline(in,f);
        getline(in,g);
        getline(in,h);
       int p1=stoii(a);
       int p2=stoii(f);
       int p3=stoii(g);
       int p4=stoii(h);
        BOOK bk(p1,b,c,d,e,p2,p3,p4);
        book_database.push_back(bk);
        
    }
    in.close();
}


void student_input_from_file(){
    ifstream in;
    in.open("student.txt");
    string x;
    getline(in,x);
    int n=stoii(x);
    for(int i=0;i<n;i++){
        string a,b,c,d,e;
        getline(in,a);
        getline(in,b);
        getline(in,c);
        getline(in,d);
        getline(in,e);
        int s1=stoii(a);
        int s2=stoii(e);
        Student st(b,c,d,s2,s1);
        student_database.push_back(st);
    }
    in.close();
}


void issued_book_from_file(){
    ifstream in;
    in.open("book_allocation.txt");
    string student_id,issue_book_name;
    while(!in.eof()){
    getline(in,student_id);
    getline(in,issue_book_name);
    int id=stoii(student_id);
    book_allocation.insert({id,issue_book_name});
    }
    in.close();
}




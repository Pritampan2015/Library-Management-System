#include<bits/stdc++.h>
//#include"Book.cpp"
//#include"Student.cpp"
#include"Library.cpp"
using namespace std;



void take_book_input(){
    cout<<"\nENTER NO OF BOOKS YOU WANT TO ENTER :\t";
    int n;cin>>n;
    for(int i=0;i<n;i++){
        BOOK b1;
        cout<<"\nENTER THE "<<i+1<<" BOOK DETAILS:\t";
        b1.Accept();
        book_database.push_back(b1);
    }
    mp_id_pos_function();
}

void show_book_output(){
    cout<<"\n\t\t\t\t\t\t\t\tSHOWING BOOKS\t\n";
    for(BOOK bk:book_database){
        bk.Display();
        cout<<"\n";
    }
}


void take_student_input(){
    cout<<"\nENTER NO OF STUDENT INFORMATION YOU WANT TO ENTER :\t";
    int n;cin>>n;
    for(int i=0;i<n;i++){
        Student st1;
        cout<<"\nENTER THE "<<i+1<<" STUDENT DETAILS:\t";
        st1.Accept();
        student_database.push_back(st1);
    }
}


void show_student_output(){
    cout<<"\n\t\t\t\t\t\t\t\tSHOWING STUDENT DETAILS\t\n";
    for(Student st:student_database){
        st.Display();
        cout<<"\n";
    }
}

void store_book_details(){
    ofstream out;
    out.open("book.txt");
    out<<book_database.size()<<"\n";
    for(int i=0;i<book_database.size();i++){
        out<<book_database[i].get_book_id()<<"\n";
        out<<book_database[i].get_book_title()<<"\n";
        out<<book_database[i].get_book_author()<<"\n";
        out<<book_database[i].get_book_publisher()<<"\n";
        out<<book_database[i].get_book_edition()<<"\n";
        out<<book_database[i].get_book_price()<<"\n";
        out<<book_database[i].get_no_of_pages()<<"\n";
        out<<book_database[i].get_no_of_book_available()<<"\n";
    }
    out.close();
}

void store_student_details(){
    ofstream out;
    out.open("student.txt");
    out<<student_database.size()<<"\n";
    for(int i=0;i<student_database.size();i++){
    out<<student_database[i].get_card_no()<<"\n";
    out<<student_database[i].get_student_name()<<"\n";
    out<<student_database[i].get_college_name()<<"\n";
    out<<student_database[i].get_student_dept()<<"\n";
    out<<student_database[i].get_student_roll_no()<<"\n";
    }
    out.close();
}


//main function
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cout<<"\t\t\t\t\t\t\t WELCOME TO LIBRARY \t\t\t"<<"\n";
    cout<<"\n\t\t\t\t\t\t   PLEASE ENTER YOUR CREDENTIALS\n\n";
    Library lb;
    cout<<"\n\t\t\t\t\t\t\tENTER YOUR USER ID: ";
    string userid;cin>>userid;
    cout<<"\n\t\t\t\t\t\t\tENTER YOUR PASSWORD: ";
    string pwd;cin>>pwd;
    if(lb.password_cheaker(userid,pwd)==true){
        cout<<"\n\t\t\t\t\t\t\t\tWELCOME ADMIN"<<"\n";
        book_input_from_file();
        student_input_from_file();
        issued_book_from_file();
        while(1){
            cout<<"\n1.Enter New Student \n2.Enter New Book Collection \n3.Show Book Collection ";
            cout<<"\n4.Show Student Database \n5.Book Allocation \n6.Book Submission \n7.Taken Books ";
            cout<<"\n8.Exit\n";
            cout<<"Enter Your Choice: ";
            int test;cin>>test;
            switch (test){
             case 1: take_student_input();
                break;
             case 2: take_book_input();
                break;
             case 3: show_book_output();
                break;
             case 4: show_student_output();
                break;
             case 5: book_allocation_function();
                break;
             case 6: book_deposit_function();
                break;
             case 7: display_student_issued_book_details();
                break;
             case 8: {  store_book_details();
                        store_student_details();
                        update_final_issued_book_to_file();
                        exit(1);
                        }
                break;
             default: cout<<"\nWRONG INPUT\n";
                break;
            }
        }

    }
    else cout<<"\n\t\t\t\t\t\t\tWRONG USER ID OR PASSWORD       "<<"\n";
    return 0;
}
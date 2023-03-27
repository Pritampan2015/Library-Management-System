
#include"Student.h"
using namespace std;
//#define clrscr ios::sync_with_stdio(0);cin.tie(0);
int global_var=11111;

//default constructor
Student::Student(){
    student_name="Default";
    student_dept="AA";
    college_name="Default";
    student_roll_no=1000;
    unique_card_no=111111; 
}

//parameterized constructor 
Student::Student(string a,string b,string c,int d, int e){
    student_name=a;
    student_dept=b;
    college_name=c;
    student_roll_no=d;
    unique_card_no=e;
}


//getter function
int Student::get_card_no(){
    return unique_card_no;
}

string Student::get_student_name(){
    return student_name;
}

string Student::get_college_name(){
    return college_name;
}
    
string Student::get_student_dept(){
    return student_dept;
}
    
int Student::get_student_roll_no(){
    return student_roll_no;
}


//setter function
void Student::set_card_no(int a){
    unique_card_no=a;
}

void Student::set_student_name(string b){
    student_name=b;
}

void Student::set_college_name(string c){
    college_name=c;
}

void Student::set_student_dept(string d){
    student_dept=d;
}

void Student::set_student_roll_no(int e){
    student_roll_no=e;
}


//basic public functions
void Student::Accept(){
    cout<<"\n\tEnter Roll No: ";
    cin>>student_roll_no;
    cout<<"\n\tEnter Student Name: ";
    cin.sync();
    getline(cin,student_name);
    cout<<"\n\tEnter Student Depertment: ";
    cin>>student_dept;
    cout<<"\n\tEnter College Name: ";
    cin.sync();
    getline(cin,college_name);
    cout<<"\n\t\tCard No will Be Generated Automatically.";
    unique_card_no=global_var++;
}


void Student::Display(){
    cout<<"\n\tCard No:\t"<<unique_card_no;
    cout<<"\n\tStudent Name:\t"<<student_name;
    cout<<"\n\tStudent Roll No:\t"<<student_roll_no;
    cout<<"\n\tStudent Department:\t"<<student_dept;
    cout<<"\n\tStudent College Name:\t"<<college_name;
}




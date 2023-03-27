#include<bits/stdc++.h>

using namespace std;


class Student{
    string student_name;
    string college_name;
    string student_dept;
    int student_roll_no;
    int unique_card_no;
public:
    Student();
    Student(string,string,string,int,int);
    //getter
    int get_card_no();
    string get_student_name();
    string get_college_name();
    string get_student_dept();
    int get_student_roll_no();

    //setter
    void set_card_no(int);
    void set_student_name(string);
    void set_college_name(string);
    void set_student_dept(string);
    void set_student_roll_no(int);
    
    //basic function
    void Accept();
    void Display();
    void Update();
    
};

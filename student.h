#pragma once
#include<iostream>
#include<fstream>
#include "test.h"
using namespace std;

struct DETAIL{
    char name[20];
    char rollno[20];
};

class student{
private:
    DETAIL detail;
    fstream sfile;
    test exm;
public:
    student();
};

student::student(){
    cout<<"\t\t\t\t********Welcome Students********\n";
    cout<<"\nPlease Enter your name and roll no to start the exam\n";

    sfile.open("details.txt",ios::in|ios::out);
    sfile.seekp(0L,ios::beg);

    cout<<"\nEnter your name:";
    fflush(stdin);
    gets(detail.name);

    cout<<"\nEnter your rollno:";
    fflush(stdin);
    gets(detail.rollno);

    sfile.write((char *)&detail,sizeof(detail));
    sfile.close();

    cout<<"\n\t\t\t\t******All the Best for the Exam******\n";

    exm.start();
}

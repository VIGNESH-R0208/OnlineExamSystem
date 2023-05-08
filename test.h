#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class test
{
private:
    char ch;
    fstream testfile;
    QUESTION question;
public:
    void start();
    void takeexam();
    //void returntime();
};

void test::start()
{
    cout<<"\nDo you wish to take the start the exam(y/n):";
    cin>>ch;
    if(ch=='y')
    {
        takeexam();
    }
    else
    {
        cout<<"\n\nPlease Be Prepared next time!Bye!\n";
    }
}

void test::takeexam()
{
    int ch,p=0,cnt,c;
    testfile.open("exam.txt",ios::binary|ios::in|ios::out);
    testfile.seekg(0L,ios::beg);
    cout<<"\n**********";
    cout<<"All The Best";
    cout<<"**********\n";
    while(testfile.read((char *)&question,sizeof(question)))
    {
        cnt=0;
        cout<<"\n"<<question.que<<"\n";
        cout<<"1*)"<<question.fians;
        cout<<"\n2*)"<<question.sans;
        cout<<"\n3*)"<<question.tans;
        cout<<"\n4*)"<<question.foans;
        cout<<"\n5*)"<<question.nans;
        for(int i=0;i<5;i++)
        {
            ++cnt;
            if(question.ans[i]==1)
            {
                c=cnt;
            }
        }
        cout<<"\n enter your ans no:";
        cin>>ch;
        if(ch==c)
        {
            cout<<"\n Correct answer!Congrats!!!\n";
            ++p;
        }
        else
        {
            cout<<"\n Wrong answer!!\n Answer:"<<c<<"\n";
        }
        cout<<"\n**********";
        cout<<"X******X";
        cout<<"**********\n";
    }
    cout<<"\n You got "<<p<<" Answers Correct!!";
    cout<<"\n See you Next time!Bye!!\n";
    testfile.close();
}

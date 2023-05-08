#pragma once
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include "questions.h"
using namespace std;

struct SECURITY{
    char username[20];
    char password[20];
};

class admin{
private:
    SECURITY security;
    fstream file;
    int ch,flag;
    questions q;
public:
    admin();
    void Register();
    int login();
};

//Constructor Definition
admin::admin(){
    cout<<"\t\t\t\t********Welcome To the Administrator Section********\n";
    cout<<"\n1-Register\n2-Login\nEnter:";
    cin>>ch;
    if(ch==1)
    {
        Register();
    }
    else if(ch==2)
    {
        flag=login();
        if(flag)
        {
            cout<<"\nLogin successful!!\n";
            q.ques();
        }
        else
        {
            cout<<"\nIncorrect Username or Password!!\nRegister to change Username & Password\n\n";
        }
    }
    else
    {
        cout<<"\nGood Bye!!\n";
    }
}

//Register Function Definition
void admin::Register()
{
    file.open("security.txt",ios::binary|ios::in|ios::out);
    file.seekp(0L,ios::beg);
    cout<<"\nEnter new Username:";
    fflush(stdin);
    gets(security.username);
    //file.write((char *)&security,sizeof(security));
    cout<<"\nEnter new Password:";
    fflush(stdin);
    gets(security.password);
    file.write((char *)&security,sizeof(security));
    file.close();
    cout<<"\nThank You for registering\n";
}

//Login Function Definition
int admin::login()
{
    char uname[20],passwd[20];
    file.open("security.txt",ios::binary|ios::in|ios::out);
    file.seekg(0L,ios::beg);
    cout<<"\nENTER USERNAME:";
    fflush(stdin);
    gets(uname);
    cout<<"\nENTER PASSWORD:";
    fflush(stdin);
    gets(passwd);
    file.read((char *)&security,sizeof(security));
    if((strcmp(uname,security.username)==0)&&(strcmp(passwd,security.password)==0))
        flag=1;
    else
        flag=0;
    file.close();
    if(flag==1)
        return 1;
    else
        return 0;
}

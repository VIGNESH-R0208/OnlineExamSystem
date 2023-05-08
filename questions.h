#pragma once
#include<iostream>
#include<fstream>
using namespace std;

struct QUESTION
{
char que[500];
char fians[100];
char sans[100];
char tans[100];
char foans[100];
char nans[100];
int ans[5],anss;
};

class questions
{
private:
    QUESTION question;
    fstream file2;
    int c;
public:
    void ques();
    void write_new_exam();
    void add_questions();
    void read_exam();
};

//Constructor Definition
void questions::ques()
{
    cout<<"\n1-To set new exam\n2-Add question to existing exam\n3-View Exam Paper\nEnter:";
    cin>>c;
    if(c==1)
    {
        write_new_exam();
    }
    else if(c==2)
    {
        add_questions();
    }
    else if(c==3)
    {
        read_exam();
    }
    else
    {
        cout<<"\nSee you Next time!bye!\n";
    }
}

//Function definition for write_new_exam
void questions::write_new_exam()
{
    file2.open("exam.txt",ios::binary|ios::in|ios::out);
    file2.seekp(0L,ios::beg);

    cout<<"\n enter the question:";
    fflush(stdin);
    gets(question.que);
    cout<<"\n enter the first ans:";
    fflush(stdin);
    gets(question.fians);
    cout<<"\n is it correct answer if yes press 1 else 2:";
    fflush(stdin);
    cin>>question.ans[0];

    if(question.ans[0]==1)
        question.anss=question.ans[0];

    cout<<"\n enter the second answer:";
    fflush(stdin);
    gets(question.sans);
    cout<<"\n is it correct answer if yes press 1 else 2?:";
    fflush(stdin);
    cin>>question.ans[1];

    if(question.ans[1]==1)
        question.anss=question.ans[1];

    cout<<"\n enter the third answer:";
    fflush(stdin);
    gets(question.tans);
    cout<<"\n is it correct answer if yes press 1 else 2?:";
    fflush(stdin);
    cin>>question.ans[2];

    if(question.ans[2]==1)
        question.anss=question.ans[2];

    cout<<"\n enter the fourth answer:";
    fflush(stdin);
    gets(question.foans);
    cout<<"\n is it correct answer if yes press 1 else 2?:";
    fflush(stdin);
    cin>>question.ans[3];

    if(question.ans[3]==1)
        question.anss=question.ans[3];

    cout<<"\n enter last answer:";
    fflush(stdin);
    gets(question.nans);
    cout<<"\n is it correct answer if yes press 1 else 2?:";
    fflush(stdin);
    cin>>question.ans[4];

    if(question.ans[4]==1)
        question.anss=question.ans[4];

    file2.write((char *)&question,sizeof(question));
    file2.close();
}

//Add Questions Function
void questions::add_questions()
{
    file2.open("exam.txt",ios::binary|ios::in|ios::out);
    file2.seekp(0L,ios::end);

    cout<<"\n enter the question:";
    fflush(stdin);
    gets(question.que);
    cout<<"\n enter the first ans:";
    fflush(stdin);
    gets(question.fians);
    cout<<"\n is it correct answer if yes press 1 else 2:";
    fflush(stdin);
    cin>>question.ans[0];

    if(question.ans[0]==1)
        question.anss=question.ans[0];

    cout<<"\n enter the second answer:";
    fflush(stdin);
    gets(question.sans);
    cout<<"\n is it correct answer if yes press 1 else 2?:";
    fflush(stdin);
    cin>>question.ans[1];

    if(question.ans[1]==1)
        question.anss=question.ans[1];

    cout<<"\n enter the third answer:";
    fflush(stdin);
    gets(question.tans);
    cout<<"\n is it correct answer if yes press 1 else 2?:";
    fflush(stdin);
    cin>>question.ans[2];

    if(question.ans[2]==1)
        question.anss=question.ans[2];

    cout<<"\n enter the fourth answer:";
    fflush(stdin);
    gets(question.foans);
    cout<<"\n is it correct answer if yes press 1 else 2?:";
    fflush(stdin);
    cin>>question.ans[3];

    if(question.ans[3]==1)
        question.anss=question.ans[3];

    cout<<"\n enter last answer:";
    fflush(stdin);
    gets(question.nans);
    cout<<"\n is it correct answer if yes press 1 else 2?:";
    fflush(stdin);
    cin>>question.ans[4];

    if(question.ans[4]==1)
        question.anss=question.ans[4];

    file2.write((char *)&question,sizeof(question));
    file2.close();
}

void questions::read_exam()
{
    cout<<"\n\t\t\t\t*********View Exam Paper*********\n";
    int coun;
    file2.open("exam.txt",ios::binary|ios::in|ios::out);
    file2.seekg(0L,ios::beg);
    while(file2.read((char *)&question,sizeof(question)))
    {
        coun=0;
        cout<<"\n"<<question.que<<"\n";
        cout<<"1*)"<<question.fians;
        cout<<"\n2*)"<<question.sans;
        cout<<"\n3*)"<<question.tans;
        cout<<"\n4*)"<<question.foans;
        cout<<"\n5*)"<<question.nans;
        for(int i=0;i<5;i++)
        {
            ++coun;
            if(question.ans[i]==1)
                cout<<"\nAnswer is:"<<coun;
        }
        cout<<"\n\n**********";
        cout<<"X******X";
        cout<<"**********\n\n";
    }
    file2.close();
}

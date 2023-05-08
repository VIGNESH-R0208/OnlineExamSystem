#include <iostream>
#include <stdlib.h>
#include "admin.h"
#include "student.h"
using namespace std;

int main()
{
    system("CLS");
    int choice;
    do
    {
        cout<<"\t\t\t\t********Exam Management System*********\n";
        cout<<"\n1-Administrator\n2-Student\n0-Exit\nEnter:";
        cin>>choice;
        if(choice==1)
        {
            admin A;
        }
        else if(choice==2)
        {
            student S;
        }
        else if(choice==0)
        {
            cout<<"\nWe Hope to see you next time!!Bye!!\n";
        }
        else
        {
            cout<<"\nYou Entered an Wrong choice!Enter Again!!\n";
        }
    }while(choice);

    cout<<"\n\t\t\tThis OOPs Package was done by Praveen S(19PT18) and Vignesh(19PT36)\n";
    return 0;
}

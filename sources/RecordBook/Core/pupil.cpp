#include "pupil.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

Pupil::Pupil()
{

}

void Pupil::read(student *st)
{

    ifstream ProgressBook;
    ProgressBook.open("../../pupil.txt");

    for (int i=1; i<31; i++){
        ProgressBook>>st[i].surname>>st[i].name>>st[i].mark[russian]>>st[i].mark[literature]>>st[i].mark[algebra]>>st[i].mark[geometry]>>st[i].mark[history]>>st[i].mark[SocialStudies]>>st[i].mark[LSF]>>st[i].mark[PE]>>st[i].mark[biology]>>st[i].mark[geography];
    }
    ProgressBook.close();
}

void Pupil::marks(student *st)
{

    cout<<"Enter your(student) surname and name "<<endl;
    cin>>PupilSurname>>PupilName;
    cout<<"Enter number of half-year "<<endl;
    cin>>half_year;
    int i,a,b,error=0;
    switch (half_year) {
    case 1:{
      a=1;
      b=16;
    break;}
    case 2:{
        a=15;
        b=31;
    break;}
    }
    for (i=a; i<b; i++){
        if ((strcmp(st[i].surname,PupilSurname)==0) and(strcmp(st[i].name,PupilName)==0)){
            cout<<st[i].mark[russian]<<" Russian"<<endl;
            cout<<st[i].mark[literature]<<" Literature"<<endl;
            cout<<st[i].mark[algebra]<<" Algebra"<<endl;
            cout<<st[i].mark[geometry]<<" Geometry"<<endl;
            cout<<st[i].mark[history]<<" History"<<endl;
            cout<<st[i].mark[SocialStudies]<<" Social Studies"<<endl;
            cout<<st[i].mark[LSF]<<" Life Safety Fundamentals"<<endl;
            cout<<st[i].mark[PE]<<" PE"<<endl;
            cout<<st[i].mark[biology]<<" Biology"<<endl;
            cout<<st[i].mark[geography]<<" Geography"<<endl;
            int j;
            int k2=0, k4=0, k5=0,summ=0;
            for (j=0; j<10; j++){
                summ=summ+st[i].mark[j];
                if (st[i].mark[j]==2) k2++;
                if (st[i].mark[j]==4) k4++;
                if (st[i].mark[j]==5) k5++;
            }
            double quality;
            quality=(k4+k5)*10;
            if (k2==0) {cout<<"Quality "<<quality<<"% "<<" Progress 100%"<<" GPA="<<summ/10<<endl;}
            else
            {cout<<"Quality "<<quality<<"% "<<" Progress "<<(10-k2)*10<<"%"<<" GPA="<<summ/10<<endl;}

            i=45;
            error=0;
        }
        else error=1;


    }
    if (error==1) cerr<<"Incorrect name or surname"<<endl;


}



Pupil::~Pupil()
{

}

#include "apupil.h"
#include "pupil.h"
#include "menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
APupil::APupil()
{

}

void APupil::Dmenu()
{
    puts("1. Return to Pupil's choice");
    puts("2. Return to main menu");
    puts("3. Exit");


    int choice;
    cin>>choice;
    switch (choice) {
    case 1:{
        pupil_mark();
        break;}
    case 2:{
        menu mmenu;
        mmenu.main_menu();
        break;}
    case 3:{
        cout<<"Good luck."<<endl;
        break;}
    }

}



void APupil::year_mark()
{
    ifstream ProgressBook;
    student st[30];
    int i =st[1].num;
    ProgressBook.open("../../pupil1.txt");
    for (i=1; i<16; i++){
     ProgressBook>>st[i].surname>>st[i].name>>st[i].mark[russian]>>st[i].mark[literature]>>st[i].mark[algebra]>>st[i].mark[geometry]>>st[i].mark[history]>>st[i].mark[SocialStudies]>>st[i].mark[LSF]>>st[i].mark[PE]>>st[i].mark[biology]>>st[i].mark[geography];
     ProgressBook.close();
}
    ProgressBook.close();
    ProgressBook.open("../../pupil2.txt");

    for (int i=15; i<31; i++){
        ProgressBook>>st[i].surname>>st[i].name>>st[i].mark[russian]>>st[i].mark[literature]>>st[i].mark[algebra]>>st[i].mark[geometry]>>st[i].mark[history]>>st[i].mark[SocialStudies]>>st[i].mark[LSF]>>st[i].mark[PE]>>st[i].mark[biology]>>st[i].mark[geography];
    }
    ProgressBook.close();
    Pupil mPupil;
    mPupil.year_marks(&st[30]);
}

void APupil::ready(student *st)
{

    ifstream ProgressBook;
    ProgressBook.open("../../pupil3.txt");
    int i=st[1].num;

    for (i=1; i<16; i++){
        ProgressBook>>st[i].surname>>st[i].name>>st[i].mark[russian]>>st[i].mark[literature]>>st[i].mark[algebra]>>st[i].mark[geometry]>>st[i].mark[history]>>st[i].mark[SocialStudies]>>st[i].mark[LSF]>>st[i].mark[PE]>>st[i].mark[biology]>>st[i].mark[geography];
    }
    ProgressBook.close();


}

void APupil::pupil_mark()
{

        student st[15];
        read(&st[15]);
        aut(&st[15]);
        Dmenu();


}

void APupil::aut(student *st)
{
    Pupil mPupil;
    cout<<"Enter your(student) surname and name "<<endl;
    cin>>mPupil.PupilSurname>>mPupil.PupilName;
    int error;
    for (int i=1; i<16; i++){
        if ((strcmp(st[i].surname,mPupil.PupilSurname)==0) and(strcmp(st[i].name,mPupil.PupilName)==0)){
            st[1].num=i;
            mPupil.marks(&st[15]);
            print(&st[15]);
            i=45;
            error=0;
        }

        else error=1;

    }

    if (error==1) cerr<<"Incorrect name or surname"<<endl;

}

void APupil::read(student *st)
{

    ifstream ProgressBook;
    cout<<"Enter number of half-year "<<endl;
    int half_year;
    cin>>half_year;
    if (half_year==1)  {ProgressBook.open("../../pupil1.txt");}
    else
        ProgressBook.open("../../pupil2.txt");

    for (int i=1; i<16; i++){
        ProgressBook>>st[i].surname>>st[i].name>>st[i].mark[russian]>>st[i].mark[literature]>>st[i].mark[algebra]>>st[i].mark[geometry]>>st[i].mark[history]>>st[i].mark[SocialStudies]>>st[i].mark[LSF]>>st[i].mark[PE]>>st[i].mark[biology]>>st[i].mark[geography];
    }
    ProgressBook.close();


}

void APupil::print(student *st)
{
    int i=st[1].num;
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
    cout<<"Progress "<<st[i].Progress<<" Quality "<<st[i].Quality<<" GPA "<<st[i].GPA<<endl;
}

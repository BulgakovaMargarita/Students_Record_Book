#include "teacher.h"
#include "pupil.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

Teacher::Teacher()
{

}

void Teacher::eu_main()
{

    char PassChek[20];
    Pupil mPupil;
    student st[30];
    mPupil.read(&st[30]);
    char TeacherSurname[20];
    char TeacherName[20];
    char password[20];


    cout<<"Enter your surname and name "<<endl;
    cin>>TeacherSurname>>TeacherName;

    cout<<"Enter password"<<endl;
    cin>>password;

    ifstream TeacherBook;
    TeacherBook.open("../../teacher.txt");

    int i,error=0;
    char s1[20];
    char s2[20];

    for (i=1; i<10; i++){
        TeacherBook>>s1>>s2>>PassChek;
        if ((strcmp(s1,TeacherSurname)==0) and(strcmp(s2,TeacherName)==0) and (strcmp(password,PassChek)==0)){
            puts("1. Student report card");
            puts("2. Find Excelllent Pupil");
            puts("3. Find Good Pupil");
            puts("4. Find Lagging Pupil");
            puts("5. Performance Calculation");

            int choice;
            cin>>choice;
            switch (choice) {
            case 1:{
                pupil_marks();
                break;}
            case 2:{
                find_excelllent_pupil(&st[30]);
                break;}
            case 3:{
                find_good_pupil(&st[30]);
                break;}
            case 4:{
                find_lagging_pupil(&st[30]);
                break;}
            case 5:{
                performance_calculation(&st[30]);
                break;}
            case 6:{
                change_mark(&st[30]);
                break;}
            }
            i=45;
            error=0;
        }
        else error=1;
    }
    if (error==1) cerr<<"Incorrect login or password"<<endl;
    TeacherBook.close();
}

void Teacher::pupil_marks()
{
    Pupil mPupil;
    student st[30];
    mPupil.read(&st[30]);
    mPupil.marks(&st[30]);

}

void Teacher::find_excelllent_pupil(student *st)
{

    int i,a,b;
    int k=0;
    int half_year;
    cout<<"Enter number of half-year "<<endl;
    cin>>half_year;
    switch (half_year) {
    case 1:{
    a=1;
    b=16;
   break; }
    case 2:{
    a=15;
    b=31;
   break; }
    }
    for (i=a; i<b; i++){
        int j;
        int k5=0;
        for (j=0; j<10; j++){
            if (st[i].mark[j]==5) k5++;
        }
        if (k5==10) {
            cout<<i+1<<". "<<st[i].surname<<" "<<st[i].name<<endl;
            k=k+1;
        }


    }
    cout<<"Number of excelllent pupil = "<<k<<endl;
}

void Teacher::find_good_pupil(student *st)
{

    int i,a,b;
    int k=0;
    int half_year;
    cout<<"Enter number of half-year "<<endl;
    cin>>half_year;
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
        int j;
        int k5=0, k3=0, k2=0;
        for (j=0; j<10; j++){
            if (st[i].mark[j]==5) k5++;
            if (st[i].mark[j]==3) k3++;
            if (st[i].mark[j]==2) k2++;
        }
        if ((k3==0) and (k2==0) and (k5<10)) {
            cout<<i+1<<". "<<st[i].surname<<" "<<st[i].name<<endl;

            k=k+1;
        }


    }
    cout<<"Number of good pupil = "<<k<<endl;


}

void Teacher::find_lagging_pupil(student *st)
{
    int i,a,b;
    int k=0;
    int half_year;
    cout<<"Enter number of half-year "<<endl;
    cin>>half_year;
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
        int j;
        int k5=0, k4=0;
        for (j=0; j<10; j++){
            if (st[i].mark[j]==5) k5++;
            if (st[i].mark[j]==4) k4++;
        }
        if ((k5==0) and (k4==0)) {
            cout<<i+1<<". "<<st[i].surname<<" "<<st[i].name<<endl;

            k=k+1;
        }
    }
    cout<<"Number of lagging pupil = "<<k<<endl;
}

void Teacher::performance_calculation(student *st)
{
    int i,a,b;
    int k2=0, k4=0, k5=0,summ=0;
    int half_year;
    cout<<"Enter number of half-year "<<endl;
    cin>>half_year;
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
        int j;
        for (j=0; j<10; j++){
            summ=summ+st[i].mark[j];
            if (st[i].mark[j]==2) k2++;
            if (st[i].mark[j]==4) k4++;
            if (st[i].mark[j]==5) k5++;
        }}
    double quality;
    quality=(100*(k4+k5))/150;
    if (k2==0) {cout<<"Quality "<<quality<<"% "<<" Progress 100%"<<" GPA="<<summ/150<<endl;}
    else
    {cout<<"Quality "<<quality<<"% "<<" Progress "<<(150-k2)*10<<"%"<<" GPA="<<summ/150<<endl;}

}

void Teacher::change_mark(student *st)
{
    Pupil mPupil;
    char TeacherSurname[20];
    char TeacherName[20];
    char password[20];

    cout<<"Attention! Re-authentication! "<<endl;
    cout<<"Enter your surname and name "<<endl;
    cin>>TeacherSurname>>TeacherName;

    cout<<"Enter password"<<endl;
    cin>>password;

    ifstream TeacherBook;
    TeacherBook.open("../../teacher.txt");

    int i,error=0;
    char s1[20];
    char s2[20];
    char PassChek[20];

    for (i=1; i<10; i++){
        TeacherBook>>s1>>s2>>PassChek;
        if ((strcmp(s1,TeacherSurname)==0) and(strcmp(s2,TeacherName)==0) and (strcmp(password,PassChek)==0)){


            int lenght_pass = strlen(password);
            int new_mark;
            cout<<"Enter student surname and name "<<endl;
            cin>>mPupil.PupilSurname>>mPupil.PupilName;
            cout<<"Enter new mark"<<endl;
            cin>>new_mark;
            for (int i=0; i<16; i++){
                if ((strcmp(st[i].surname,mPupil.PupilSurname)==0) and(strcmp(st[i].name,mPupil.PupilName)==0)){
                    st[i].mark[lenght_pass-1]=new_mark;
                }
            }
        }
    }
    if (error==1) cerr<<"Incorrect login or password"<<endl;
    TeacherBook.close();
    for (i=1; i<16; i++){
        if ((strcmp(st[i].surname,mPupil.PupilSurname)==0) and(strcmp(st[i].name,mPupil.PupilName)==0)){
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
        }
    }
}


Teacher::~Teacher()
{

}

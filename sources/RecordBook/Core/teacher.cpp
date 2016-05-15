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
    char TeacherSurname[20];
    char TeacherName[20];
    char password[20];
    char PassChek[20];

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
            puts("6. Change Mark");

            int choice;
            cin>>choice;
            switch (choice) {
            case 1:{
                pupil_marks();
                break;}
            case 2:{
                find_excelllent_pupil();
                break;}
            case 3:{
                find_good_pupil();
                break;}
            case 4:{
                find_lagging_pupil();
                break;}
            case 5:{
                performance_calculation();
                break;}
            case 6:{
                change_mark();
                break;}
            }
            i=17;
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
    mPupil.marks();
}

void Teacher::find_excelllent_pupil()
{
    ifstream ProgressBook;
    ProgressBook.open("../../pupil.txt");

    int i;
    char s1[20];
    char s2[20];
    int year;
    int k=0;

    for (i=1; i<16; i++){
        ProgressBook>>s1>>s2>>year>>mark[russian]>>mark[literature]>>mark[algebra]>>mark[geometry]>>mark[history]>>mark[SocialStudies]>>mark[LSF]>>mark[PE]>>mark[biology]>>mark[geography];
        int j;
        int k5=0;
        for (j=0; j<10; j++){
            if (mark[j]==5) k5++;
        }
        if (k5==10) {
            cout<<i+1<<". "<<s1<<" "<<s2<<endl;
            k=k+1;
        }


    }
    cout<<"Number of excelllent pupil = "<<k<<endl;
    ProgressBook.close();
}

void Teacher::find_good_pupil()
{
    ifstream ProgressBook;
    ProgressBook.open("../../pupil.txt");

    int i;
    char s1[20];
    char s2[20];
    int year;
    int k=0;

    for (i=1; i<16; i++){
        ProgressBook>>s1>>s2>>year>>mark[russian]>>mark[literature]>>mark[algebra]>>mark[geometry]>>mark[history]>>mark[SocialStudies]>>mark[LSF]>>mark[PE]>>mark[biology]>>mark[geography];
        int j;
        int k5=0, k3=0, k2=0;
        for (j=0; j<10; j++){
            if (mark[j]==5) k5++;
            if (mark[j]==3) k3++;
            if (mark[j]==2) k2++;
        }
        if ((k3==0) and (k2==0) and (k5<10)) {
            cout<<i+1<<". "<<s1<<" "<<s2<<endl;
            k=k+1;
        }


    }
    cout<<"Number of good pupil = "<<k<<endl;
    ProgressBook.close();
}

void Teacher::find_lagging_pupil()
{
    ifstream ProgressBook;
    ProgressBook.open("../../pupil.txt");

    int i;
    char s1[20];
    char s2[20];
    int year;
    int k=0;

    for (i=1; i<16; i++){
        ProgressBook>>s1>>s2>>year>>mark[russian]>>mark[literature]>>mark[algebra]>>mark[geometry]>>mark[history]>>mark[SocialStudies]>>mark[LSF]>>mark[PE]>>mark[biology]>>mark[geography];
        int j;
        int k5=0, k4=0;
        for (j=0; j<10; j++){
            if (mark[j]==5) k5++;
            if (mark[j]==4) k4++;
        }
        if ((k5==0) and (k4==0)) {
            cout<<i+1<<". "<<s1<<" "<<s2<<endl;
            k=k+1;
        }


    }
    cout<<"Number of lagging pupil = "<<k<<endl;
    ProgressBook.close();
}

void Teacher::performance_calculation()
{
    ifstream ProgressBook;
    ProgressBook.open("../../pupil.txt");

    int i;
    char s1[20];
    char s2[20];
    int year;
    int k2=0, k4=0, k5=0,summ=0;

    for (i=1; i<16; i++){
        ProgressBook>>s1>>s2>>year>>mark[russian]>>mark[literature]>>mark[algebra]>>mark[geometry]>>mark[history]>>mark[SocialStudies]>>mark[LSF]>>mark[PE]>>mark[biology]>>mark[geography];
        int j;
        for (j=0; j<10; j++){
            summ=summ+mark[j];
            if (mark[j]==2) k2++;
            if (mark[j]==4) k4++;
            if (mark[j]==5) k5++;
        }}
    double quality;
    quality=(100*(k4+k5))/150;
    if (k2==0) {cout<<"Quality "<<quality<<"% "<<" Progress 100%"<<" GPA="<<summ/150<<endl;}
    else
    {cout<<"Quality "<<quality<<"% "<<" Progress "<<(150-k2)*10<<"%"<<" GPA="<<summ/150<<endl;}
    ProgressBook.close();
}

void Teacher::change_mark()
{

}

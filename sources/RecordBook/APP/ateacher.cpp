#include "ateacher.h"
#include "apupil.h"
#include "teacher.h"
#include "menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

ATeacher::ATeacher()
{

}

void ATeacher::teacher_func()
{
    eu_main();
}

void ATeacher::d_main()
{
    puts("1. Return to Teacher's menu");
    puts("2. Return to main menu");
    puts("3. Exit");


    int choice;
    cin>>choice;
    switch (choice) {
    case 1:{
        eu_main();
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

void ATeacher::eu_main()
{

    char PassChek[20];

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
            puts("6. Reruen to main menu");
            puts("7. Exit");


            int choice;
            cin>>choice;
            switch (choice) {
            case 1:{
                pupil_marks();
                break;}
            case 2:{
                excelllent_pupil();
                break;}
            case 3:{
                good_pupil();
                break;}
            case 4:{
                lagging_pupil();
                break;}
            case 5:{
                performance();
                break;}

            case 6:{
                menu mmenu;
                mmenu.main_menu();

                break;}
            case 7:{
                cout<<"Good luck."<<endl;
                break;}
            }
            i=45;
            error=0;
        }
        else error=1;
    }
    if (error==1){ cerr<<"Incorrect login or password"<<endl; eu_main();};


    TeacherBook.close();
}

void ATeacher::pupil_marks()
{
    APupil mPupil;

    mPupil.pupil_mark();
    d_main();

}

void ATeacher::excelllent_pupil()
{
    Teacher mTeacher;
    APupil mPupil;
    student st[15];
    mPupil.read(&st[15]);
    mTeacher.find_excelllent_pupil(&st[15]);
    d_main();

}

void ATeacher::good_pupil()
{
    Teacher mTeacher;
    student st[15];
    mTeacher.find_good_pupil(&st[15]);
    d_main();
}

void ATeacher::lagging_pupil()
{
    Teacher mTeacher;
    APupil mPupil;
    student st[15];
    mPupil.read(&st[15]);
    mTeacher.find_lagging_pupil(&st[15]);
    d_main();
}

void ATeacher::performance()
{
    Teacher mTeacher;
    APupil mPupil;
    student st[15];
    mPupil.read(&st[15]);
    mTeacher.performance_calculation(&st[15]);
    cout<<"Quality "<<st[1].Quality<<"% "<<" Progress "<<st[1].Progress<<"%"<<" GPA="<<st[1].GPA<<endl;
    d_main();
}

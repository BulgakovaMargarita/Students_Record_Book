#include "menu.h"
#include "apupil.h"
#include "ateacher.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
menu::menu()
{

}

void menu::main_menu()
{
    APupil mPupil;
    ATeacher mTeacher;
    puts("Choose a user");
    puts("1. Pupil");
    puts("2. Teacher");
    puts("3. Exit");
    int choice;
    cin>>choice;
    switch (choice) {
    case 1:{
        mPupil.pupil_mark();
        break;}
    case 2:{
        mTeacher.teacher_func();
        break;}
    case 3:{
        cout<<"Good luck!"<<endl;
    }
    }
}

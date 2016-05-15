#include <iostream>
#include <fstream>
#include <string>
#include "pupil.h"
#include "teacher.h"
using namespace std;

int main()
{
        puts("Choose a user");
        puts("1. Pupil");
        puts("2. Teacher");
        int choice;
        cin>>choice;
        switch (choice) {
        case 1:{
            Pupil mPupil;
            mPupil.marks();
            break;}
        case 2:{
            Teacher mTeacher;
            mTeacher.eu_main();
            break;}

        }
    return 0;
}


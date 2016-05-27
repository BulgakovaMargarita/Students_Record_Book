#include <iostream>
#include <fstream>
#include <string>
#include "api.h"

using namespace std;

int main()
{
    API mAPI;
    puts("Choose a user");
    puts("1. Pupil");
    puts("2. Teacher");
    int choice;
    cin>>choice;
    switch (choice) {
    case 1:{
        mAPI.pupil_mark();
        break;}
    case 2:{
        mAPI.teacher_func();
        break;}

    }
    return 0;
}


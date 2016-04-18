#include <iostream>
#include <fstream>
#include <string>
#include "pupil.h"
using namespace std;

int main()
{
        puts("Choose a user");
        puts("1. Pupil");
        puts("2. Teacher");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            Pupil mPupil;
            mPupil.marks();
            break;
        }
    return 0;
}


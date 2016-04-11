#include <iostream>
#include <fstream>
#include <string>
#include "pupil.h"
using namespace std;

int main()
{
        puts("1. Запрос табеля ученика");
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


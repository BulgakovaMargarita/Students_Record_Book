#include "api.h"
#include "pupil.h"
#include "teacher.h"
#include <iostream>
#include<string.h>

using namespace std;

API::API()
{

}

void API::pupil_mark()
{
     Pupil mPupil;
     student st[30];
     mPupil.read(&st[30]);
     mPupil.marks(&st[30]);

}

void API::teacher_func()
{
    Teacher mTeacher;
    mTeacher.eu_main();
}

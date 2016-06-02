#ifndef APUPIL_H
#define APUPIL_H
#include <iostream>
#include<string.h>
using namespace std;
#include "pupil.h"


class APupil
{
public:
    APupil();
    void pupil_mark();
    void read(student *);
    void aut(student *);
    void print(student *);
    void Dmenu();
    void year_mark();
    void ready(student *);

};

#endif // APUPIL_H

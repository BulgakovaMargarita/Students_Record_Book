#ifndef PUPIL_H
#define PUPIL_H
#include <iostream>
#include<string.h>
using namespace std;

struct student {
    char name[20];
    char surname[20];
    int mark[10];
    float ocenka;
};

enum subject {russian,
              literature,
              algebra,
              geometry,
              history,
              SocialStudies,
              LSF,
              PE,
              biology,
              geography};

class Pupil
{
public:
    Pupil();
    ~Pupil();
    void marks(student *);
    void read(student *);
    void print(student *);
    char PupilSurname[20];
    char PupilName[20];
    int half_year;
};

#endif // PUPIL_H

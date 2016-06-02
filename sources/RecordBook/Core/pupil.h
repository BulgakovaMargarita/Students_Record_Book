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
    int Quality;
    int Progress;
    int num;
    float GPA;
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
    char PupilSurname[20];
    char PupilName[20];
    int half_year;
    void year_marks(student *);
};

#endif // PUPIL_H

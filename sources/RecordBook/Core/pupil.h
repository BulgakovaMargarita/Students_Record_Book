#ifndef PUPIL_H
#define PUPIL_H
#include <iostream>
using namespace std;

enum subject {russian,
              literature,
              algebra,
              geometry,
              history,
              SocialStudies,
              LSF,
              PC,
              biology,
              geography};

class Pupil
{
public:
    Pupil();
    ~Pupil();
    void marks();
    int mark[10];
};

#endif // PUPIL_H

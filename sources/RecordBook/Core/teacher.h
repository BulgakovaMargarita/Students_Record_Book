#ifndef TEACHER_H
#define TEACHER_H
#include "pupil.h"


class Teacher
{
public:
    Teacher();
    void pupil_marks();
    int mark[10];
    void eu_main();
    void find_excelllent_pupil();
    void find_good_pupil();
    void find_lagging_pupil();
    void performance_calculation();
    void change_mark();


};

#endif // TEACHER_H

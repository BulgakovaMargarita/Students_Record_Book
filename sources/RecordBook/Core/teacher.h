#ifndef TEACHER_H
#define TEACHER_H
#include "pupil.h"


class Teacher
{
public:
    Teacher();
    ~Teacher();
    void find_excelllent_pupil(student *);
    void find_good_pupil(student *);
    void find_lagging_pupil(student *);
    void performance_calculation(student *);
    void change_mark(student *);




};

#endif // TEACHER_H

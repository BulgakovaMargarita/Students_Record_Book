#include "pupil.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

Pupil::Pupil()
{

}

void Pupil::year_marks(student *st)
{
    ofstream fout("../../pupil3.txt");
    for (int i=1; i<16; i++){
       for (int j=0; j<11; j++){
           st[i].mark[j]=floor((st[i].mark[j]+st[i+16].mark[j])/2);
       }
       fout<<st[i].surname<<" "<<st[i].name<<" "<<st[i].mark[russian]<<" "<<st[i].mark[literature]<<" "<<st[i].mark[algebra]<<" "<<st[i].mark[geometry]<<" "<<st[i].mark[history]<<" "<<st[i].mark[SocialStudies]<<" "<<st[i].mark[LSF]<<" "<<st[i].mark[PE]<<" "<<st[i].mark[biology]<<" "<<st[i].mark[geography]<<endl;
    }
        fout.close();
}

void Pupil::marks(student *st)
{
            int i=st[1].num;
            int j;
            int k2=0, k4=0, k5=0,summ=0;
            for (j=0; j<10; j++){
                summ=summ+st[i].mark[j];
                if (st[i].mark[j]==2) k2++;
                if (st[i].mark[j]==4) k4++;
                if (st[i].mark[j]==5) k5++;
            }

            st[i].Quality=(k4+k5)*10;
            st[i].Progress=(10-k2)*10;
            st[i].GPA=summ/10;

}



Pupil::~Pupil()
{

}

#include "pupil.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Pupil::Pupil()
{

}

void Pupil::marks()
{
   char PupilSurname[20];
   char PupilName[20];
   cin>>PupilSurname>>PupilName;
   ifstream ProgressBook;
   ProgressBook.open("pupil.txt");
   int i;
   char s1[20];
   char s2[20];
   for (i=1; i<16; i++){
       ProgressBook>>s1>>s2>>mark[russian]>>mark[literature]>>mark[algebra]>>mark[geometry]>>mark[history]>>mark[SocialStudies]>>mark[LSF]>>mark[PC]>>mark[biology]>>mark[geography];
       if ((s1==PupilSurname) and(s2==PupilName)){
         cout<<mark[russian]<<mark[literature]<<mark[algebra]<<mark[geometry]<<mark[history]<<mark[SocialStudies]<<mark[LSF]<<mark[PC]<<mark[biology]<<mark[geography]<<endl;
       }
   }
   ProgressBook.close();
   delete []s1;
   delete []s2;
   delete []PupilSurname;
   delete []PupilName;
}

Pupil::~Pupil()
{

}

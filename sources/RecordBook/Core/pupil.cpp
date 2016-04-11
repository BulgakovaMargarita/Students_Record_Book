#include "pupil.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

Pupil::Pupil()
{

}

void Pupil::marks()
{
   char PupilSurname[20];
   char PupilName[20];
   int password;
   int PassChek;

   cout<<"Введите фамилию и имя ученика"<<endl;
   cin>>PupilSurname>>PupilName;

   cout<<"Введите пароль"<<endl;
   cin>>password;

   ifstream ProgressBook;
   ProgressBook.open("/home/user/Students_Record_Book/sources/RecordBook/pupil.txt");

   int i;
   char s1[20];
   char s2[20];

   for (i=1; i<16; i++){
       ProgressBook>>s1>>s2>>PassChek>>mark[russian]>>mark[literature]>>mark[algebra]>>mark[geometry]>>mark[history]>>mark[SocialStudies]>>mark[LSF]>>mark[PC]>>mark[biology]>>mark[geography];
       if ((strcmp(s1,PupilSurname)==0) and(strcmp(s2,PupilName)==0) and (password==PassChek)){
         cout<<"Russian "<<mark[russian]<<endl;
         cout<<"Literature "<<mark[literature]<<endl;
         cout<<"Algebra "<<mark[algebra]<<endl;
         cout<<"Geometry "<<mark[geometry]<<endl;
         cout<<"Social Studies "<<mark[SocialStudies]<<endl;
         cout<<"Life Safety Fundamentals "<<mark[LSF]<<endl;
         cout<<"Physical Culture "<<mark[PC]<<endl;
         cout<<"biology "<<mark[biology]<<endl;
         cout<<"geography "<<mark[geography]<<endl;
         i=17;
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

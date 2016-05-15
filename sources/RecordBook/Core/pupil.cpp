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

   cout<<"Enter your surname and name "<<endl;
   cin>>PupilSurname>>PupilName;

   cout<<"Enter year"<<endl;
   cin>>password;

   ifstream ProgressBook;
   ProgressBook.open("../../pupil.txt");

   int i,error=0;
   char s1[20];
   char s2[20];

   for (i=1; i<16; i++){
       ProgressBook>>s1>>s2>>PassChek>>mark[russian]>>mark[literature]>>mark[algebra]>>mark[geometry]>>mark[history]>>mark[SocialStudies]>>mark[LSF]>>mark[PE]>>mark[biology]>>mark[geography];
       if ((strcmp(s1,PupilSurname)==0) and(strcmp(s2,PupilName)==0) and (password==PassChek)){
         cout<<mark[russian]<<" Russian"<<endl;
         cout<<mark[literature]<<" Literature"<<endl;
         cout<<mark[algebra]<<" Algebra"<<endl;
         cout<<mark[geometry]<<" Geometry"<<endl;
         cout<<mark[history]<<" History"<<endl;
         cout<<mark[SocialStudies]<<" Social Studies"<<endl;
         cout<<mark[LSF]<<" Life Safety Fundamentals"<<endl;
         cout<<mark[PE]<<" PE"<<endl;
         cout<<mark[biology]<<" Biology"<<endl;
         cout<<mark[geography]<<" Geography"<<endl;

         int j;
         int k2=0, k4=0, k5=0,summ=0;
         for (j=0; j<10; j++){
             summ=summ+mark[j];
             if (mark[j]==2) k2++;
             if (mark[j]==4) k4++;
             if (mark[j]==5) k5++;
         }
         double quality;
         quality=(k4+k5)*10;
         if (k2==0) {cout<<"Quality "<<quality<<"% "<<" Progress 100%"<<" GPA="<<summ/10<<endl;}
                           else
         {cout<<"Quality "<<quality<<"% "<<" Progress "<<(10-k2)*10<<"%"<<" GPA="<<summ/10<<endl;}

         i=17;
         error=0;
       }
       else error=1;


   }
   if (error==1) cerr<<"Incorrect login or password"<<endl;
   ProgressBook.close();

}


Pupil::~Pupil()
{

}

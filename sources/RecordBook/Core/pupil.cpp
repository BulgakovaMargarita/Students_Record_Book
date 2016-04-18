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

   cout<<"Enter password"<<endl;
   cin>>password;

   ifstream ProgressBook;
   ProgressBook.open("../../pupil.txt");

   int i,error=0;
   char s1[20];
   char s2[20];

   for (i=1; i<16; i++){
       ProgressBook>>s1>>s2>>PassChek>>mark[russian]>>mark[literature]>>mark[algebra]>>mark[geometry]>>mark[history]>>mark[SocialStudies]>>mark[LSF]>>mark[PC]>>mark[biology]>>mark[geography];
       if ((strcmp(s1,PupilSurname)==0) and(strcmp(s2,PupilName)==0) and (password==PassChek)){
         cout<<"Russian "<<mark[russian]<<endl;
         cout<<"Literature "<<mark[literature]<<endl;
         cout<<"Algebra "<<mark[algebra]<<endl;
         cout<<"Geometry "<<mark[geometry]<<endl;
         cout<<"History "<<mark[history]<<endl;
         cout<<"Social Studies "<<mark[SocialStudies]<<endl;
         cout<<"Life Safety Fundamentals "<<mark[LSF]<<endl;
         cout<<"Physical Culture "<<mark[PC]<<endl;
         cout<<"Biology "<<mark[biology]<<endl;
         cout<<"Geography "<<mark[geography]<<endl;

         int j;
         int k2=0, k4=0, k5=0;
         for (j=1; i<10; i++){
             if (mark[j]==2) k2++;
             if (mark[j]==4) k4++;
             if (mark[i]==5) k5++;
         }
         double quality;
         quality=100 -(k4+k5)/10;
         if (k2==0) {cout<<"Quality "<<quality<<"% "<<" Progress 100%"<<endl;}
                           else
         {cout<<"Quality "<<quality<<"% "<<" Progress "<<(10-k2)*10<<"%"<<endl;}

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

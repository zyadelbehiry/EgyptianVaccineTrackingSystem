// ConsoleApplication10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<string>
#include<conio.h>
#include"stdlib.h"

#include"C:\Users\AMR SAMI\Desktop\drive-download-20220420T113614Z-001\Vaccine\Data.h"
#include"C:\Users\AMR SAMI\Desktop\drive-download-20220420T113614Z-001\Vaccine\user.h"
#include"C:\Users\AMR SAMI\Desktop\drive-download-20220420T113614Z-001\Vaccine\admin.h"

#define MAX_LEN  60
#define gender_size 1


using namespace std;
void displayScreen();
//void signup();
void login();
int main()
{
   // displayScreen();
    user u1;
    user u2;
    u1.addInformation();
    cin.ignore();
    cout << endl;
    cout << "user number two : " << endl;
    u2.addInformation();
    vector<user> u;
    u.push_back(u1);
    u.push_back(u2);
    admin a;
    cout << "Records Of amr samy" << endl;
    a.viewRecords("amrsamy" ,u);
    cout << endl << endl;
    cout << "Records Of mohamed hisham" << endl;
    a.viewRecords("mohamedhisham", u );
    cout << "after deleting ..... " << endl;
    a.deleteRecords("amrsamy", u);
    a.viewRecords("amrsamy", u);
    
    
}
void displayScreen()
{
    user s;
    cout << "---------------- Welcome to vacccine tracking system ---------------- " << endl;
    cout << " 1- sign up " << endl;
    cout << " 2- login " << endl;
    cout << " 3- exit " << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1 :
        s.addInformation();
        break;
    case 2:
        login();
        break;
    case 3:
        system("pause");
    }
}
void signup()
{
    system("cls"); 
    //user n ; 
    char name[MAX_LEN], country[MAX_LEN], password[MAX_LEN], governorate[MAX_LEN];
    int age;
    bool isVaccined = false ;
    bool fullyVaccined = false;
    bool onWaiting;
    vector<int> nationalId[14];      // should be unique
    char gender;
    cin.ignore();
    cout << "Enter Full Name   : ";    cin.getline(name, MAX_LEN);
    //cin.ignore();
    cout << "Enter password    : ";    cin.getline(password, MAX_LEN);
    //cin.ignore();
    cout << "Enter Country     : ";    cin.getline(country, MAX_LEN);  
   // cin.ignore();
    cout << "Enter governorate : ";    cin.getline(governorate, MAX_LEN);  
   // cin.ignore();
    cout << "Enter gender      : ";    cin >> gender;  // if stattment
    //cin.ignore();
    cout << "Enter age    : ";   cin >> age;
   // cin.ignore();
    cout << endl;
    cout << endl;
    cout << "name :" << name << endl;
    cout << "pass :" << password << endl;
    cout << "country :" << country << endl;
    cout << "governrate :" << governorate << endl;
    cout << "genere :" << gender << endl;
    cout << "age" << age << endl;


    cout << "--------------------------------------------------------------- " << endl;
    cout << "is vaccined Dose 1 ?  select 1  " << endl;;                   // if statment
    cout << "is Fully Vaccined ?   seelct 2  " << endl;                   // if statment
    cout << "not vaccined yet      select 3  " << endl;
    int ch;
    do {
        cin >> ch;     
        switch (ch)
        {
        case 1:
            isVaccined = true;
            break;
        case 2:
            fullyVaccined = true;
            break;
        case 3 :
            break;
        default :
            cout << "Enter valid Number !! " << endl;
        }
    } while (ch >=3 && ch <= 1);
    


   
   

}
void login()
{   
    
}



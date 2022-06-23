#include <iostream>
#include<string>
#include<conio.h>
#include"stdlib.h"
#include<list>
#include"Data.h"
#include"user.h"
#include"admin.h"
#include"Linkedlist.h"
///////////////////////////////// functionës difinitions  //////////////////////////////////
void displayScreen(LinkedList& l, user& u, Data& d, admin& a);
void login(LinkedList& l, user& u, Data& d, admin& a);
void back_to_start();
void user_functions();
void admin_functions();
void choose();
///////////////////////////////// global variables ////////////////////////////////////
user u;
LinkedList l;
Data d;
admin a;
int logged_in_user = 0;  // the linked list index of the user who is login 
#define MAX_LEN  60
#define gender_size 1
/////////////////////////////////////  main  /////////////////////////////////////////////////

using namespace std;
int main()
{
	displayScreen(l, u, d, a);
}

////////////////////////////////////////////////////////////////////////////////

void displayScreen(LinkedList& l, user& u, Data& d, admin& a)
{
	int i;
	char choice[1];
	
	do {
		cout << "--------------------- Welcome To Vaccine Tracking System ---------------------" << endl;
		cout << "1- signup             " << endl;
		cout << "2- login              " << endl;
		cout << "3- exit               " << endl;
		cout << "4- display statistics " << endl;
		cin >> choice;
		system("cls");
		i = atoi(choice);              
		if (i == 1)
		{
////////////////////////////////////////// sign up /////////////////////////////////////////
			cin.ignore();
			u.addInformation();
			//check if the id is unique
			if (!l.find(u.nationalId)) {
				l.Append(u);
				cout <<endl<< "Thank you for signing up ^-^" << endl<<endl;
				system("pause");
				back_to_start();
			}
			else if (l.find(u.nationalId)) {
				cout << "National id is used !" << endl;
				cout << "please sign up again " << endl;

				system("pause");
				back_to_start();
			}

		}
		
		if (i == 2)
/////////////////////////////////////// login ////////////////////////////////////////
			login(l, u, d, a);
		if (i == 3)
/////////////////////////////////////// exit ////////////////////////////////////////
			exit(0);
		if (i == 4)
		{
//////////////////////////////// display statistics ///////////////////////////////
			d.displayStatistics(l);
			cout << endl << endl;
			system("pause");
			back_to_start();
		}

	} while (i > 4 || i < 1);
}

/////////////////////////////////////////////////  login function  ////////////////////////////////////////////////////

void login(LinkedList& l, user& u, Data& d, admin& a)
{
	int choiceLogin=0;
	
	string adminName;
	string adminPassword;
	string nationalId;
	string userPassword;
	do {
		cout << "1 - login as admin " << endl;
		cout << "2-  login as user  " << endl;
		cin >> choiceLogin;
		system("cls");
		switch (choiceLogin)
		{
///////////////////////////////////////   login as an admin   //////////////////////////////////////////////////////
		case 1:
			cout << "Enter admin name     : "; cin >> adminName;
			cout << "Enter admin password : "; cin >> adminPassword;
			system("cls");
			if (adminName == "admin" && adminPassword == "admin")
			{
				//////////// Â«Œœ œÊ· «⁄„· »ÌÂ„ ›«‰ﬂ‘‰  Õ  ⁄‘«‰ «” œ⁄ÌÂ«  «‰Ì Ê„‘ ÂŒ·ÌÂ »Ì„”Õ »⁄œ „Ì⁄„· ›ÌÊ
				admin_functions();
				system("pause");
				back_to_start();
				break;
			}
//////////////////////////////////////// login as an user /////////////////////////////////////////
		case 2:
			cout << "Enter national id     : "; cin >> nationalId;
			cout << "Enter password        : "; cin >> userPassword;
			bool x = true;
			for (int i = 0; i < l.Length(); i++)
			{
				if (nationalId == l.At(i).nationalId && userPassword == l.At(i).password)
				{

					logged_in_user = i; //global variable to save the index of the logged in user
					user_functions();
					break;
					x = false;
				}
			}
			if (x)
			{
				cout << "USER NOT FOUND !" << endl;
				system("pause");
				back_to_start();
			}
			break;
		}
		break;
	} while (choiceLogin > 2 || choiceLogin < 1);
	
}

//////////////////////////////////////  back to start  ////////////////////////////////////////
void back_to_start() {
	
	system("cls");
		displayScreen(l, u, d, a);
 }

//////////////////////////////////////  user functions  //////////////////////////////////////
void user_functions() {
	int ch;
	do {
		system("cls");
		cout << "1 - view my records        " << endl;
		cout << "2 - update my informations " << endl;
		cout << "3 - delte my records       " << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
//////////////// user : view records ///////////////////
			l.At(logged_in_user).displayRecords();
			break;
		case 2:
//////////////// user : update informations ////////////
			d.updateInformation(l,logged_in_user);
			choose();
			break;
		case 3: {
			//////////////// user : delete records ////////////
			if (l.At(logged_in_user).is_egyptian()) {
				if (l.At(logged_in_user).gender == 'f' || l.At(logged_in_user).gender == 'F') {
					d.nOfWomen--;
				}
				else if (l.At(logged_in_user).gender == 'm' || l.At(logged_in_user).gender == 'm') {
					d.nOfMen--;
				}
				if (l.At(logged_in_user).fullyVaccined)
					d.nOfFVaccined--;
				else if (l.At(logged_in_user).isVaccined)
					d.nOfDose1--;
				else if (l.At(logged_in_user).onWaiting) {
					d.nOfWaitingList--;

				}
				d.nOfEgyptians--;
			}
			l.DeleteAt(logged_in_user);
			system("pause");
			back_to_start();
			break;
		}
		default:
			cout << "Enter Valid Value " << endl;
			break;
		}
		break;
	} while (ch > 1 || ch < 3);
	choose();
}

////////////////////////////  choose function  //////////////////////////////////////
void choose() {
	cout << "To back to the last menu press 1\n" << "To back to start menu press 2" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
		user_functions();
	if (choice == 2)
		back_to_start();
	else
		back_to_start();
}
void admin_functions() {
	int choiceInLogin = 0;
	do {
		cout << "1-View Records by ID    " << endl;
		cout << "2-Delete Records by ID  " << endl;
		string id;
		cin >> choiceInLogin;
		system("cls");
		switch (choiceInLogin)
		{
		case 1:
			//////////////// admin : view records ////////////////
			cout << "Please Enter ID : "; cin >> id;
			a.viewRecords(id, l);
			cout << "To delete this user press 1, to back to start menu press any other number" << endl;
			char choice;
			cin >> choice;
			if (choice == '1')
				a.deleteRecords(l);
			else
				back_to_start();
			break;
		case 2:
			//////////////// admin : delete records ////////////////
			cout << "Please Enter ID : "; cin >> id;
			a.deleteRecords(l);
			break;
		default:
			cout << "Enter Valid Value : " << endl;
		}
		break;
	} while (choiceInLogin >= 2 && choiceInLogin <= 1);
	system("pause");
	back_to_start();
}
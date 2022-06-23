#include "admin.h"

void admin::viewRecords(string nId , LinkedList &u)
{
	for (int i = 0; i < u.Length(); i++)
	{
		if (nId == u.At(i).nationalId)
		{
			cout << "Name : " << u.At(i).fullName << endl;
			cout << "Country: " << u.At(i).country << endl;
			if (u.At(i).is_egyptian()) {
				cout << "Governorate : " << u.At(i).governorate << endl;
			}
			cout << "age: " << u.At(i).age << endl;
			cout << "gender : " << u.At(i).gender << endl;
			if (u.At(i).fullyVaccined)
			{
				cout << "Fully Vaccined !" << endl;
			}
			else if (u.At(i).isVaccined)
			{
				cout << "DOSE 1 already Taken ! " << endl;
			}
			else
				cout << "On Waiting list !" << endl;
		}
	}
		
}

void admin::deleteRecords(LinkedList &u)
{
	cout << "To delete user by his id press 1 \nTo delete all users press 2";
	char x;  cin >> x;
	switch (x)
	{
	case '1':
	{
		cout << "Enter user id";
		string id;
		cin >> id;
		for (int i = 0; i < u.Length(); i++) {
			if (id == u.At(i).nationalId)
			{

				cout << "user deleted" << endl;
				u.DeleteAt(i);

			}
			else
			{
				cout << "USER NOT FOUND !" << endl;
			}
		}
		break; 
	}
	case '2':
		for (int j = 0; j < u.Length(); j++) {
			u.DeleteAt(j);

		}
		cout << "Users deleted";
		break;
	default:
		break;
	}
		
}

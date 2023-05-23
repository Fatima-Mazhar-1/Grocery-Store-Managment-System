#include<iostream>
#include"GroceryStore.h"

int main()
{
	User* b;
	cout << "----------------------------------------------------" << endl;
	cout << "******Welcome to Stop and Shop Grocery Store********" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Press 1 Admin: " << endl;
	cout << "Press 2 Manager: " << endl;
	cout << "Press 3 Customer: " << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
		b = new Admin;
		b->Menu();
		break;
	case 2:
		b = new Manager;
		b->Menu();
		break;
	case 3:
		b = new Customer;
		b->Menu();
		break;
	}
	main();
}
#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class User {
	char username[100];
	char password[100];  //user class inherited by admin customer and manager
public:
	User() {
		username[0] = '\0';
		password[0] = '\0';
	}
	void setUsername(string z)
	{
		strcpy_s(username, 100, z.c_str());
	}
	void setPassword(string z)
	{
		strcpy_s(password, 100, z.c_str());
	}
	char* getUsername()
	{
		return username;
	}
	char* getPassword()
	{
		return password;
	}
	virtual void Menu()
	{  // virtual function menu for polymorphism

	}
};
class Feedback {
	char feed[100];   // feedback classs 
public:
	void giveFeedback() {
		cout << "Please give your feedback: "; //give feedback function only available to customer after shopping
		cin >> feed;
	}
	void DeleteFeedback() {
		feed[0] = '\0';   //delete feedback
	}
	void ShowFeedback() {
		cout << feed;               //show feedback function
	}
	Feedback() {
		feed[0] = '\0';
	}
};
class Payment {
	double Totalamt;
public:
	Payment() {
		Totalamt = 0;          //payment class
	}

	virtual void MakePayment() {    // virtual function for polymorphism

	}
	double getTotalamt() {
		return Totalamt;
	}
};

class JazzCash : public Payment { //Jazzcash class used during polymorphism
	long int phone_no;
public:
	JazzCash() {
		phone_no = 0;
	}
	void MakePayment() {
		cout << "****Welcome to jazzCash****" << endl;
		cout << "Please enter your Phone-Number: ";
		cin >> phone_no;
		cout << "Total amount paid: " << getTotalamt() << endl;
		cout << "**Congratulations.Payment is Successfull**";

	}
};

class EasyPaisa : public Payment {
	long int phone_no;
public:                       //Easy paisa class
	EasyPaisa() {
		phone_no = 0;
	}
	void MakePayment() {
		cout << "****Welcome to EasyPaisa****" << endl;   
		cout << "Please enter your Phone-Number: ";
		cin >> phone_no;
		cout << "Total amount paid: " << getTotalamt() << endl;
		cout << "**Congratulations Payment is SuccessfulL**";

	}
};

class CreditCard : public Payment {
	long int CreditCard_No;
	int ccv;            //CreditCard class
	char Expiry_Date[20];
public:
	CreditCard() {
		CreditCard_No = 0;
		ccv = 0;
		Expiry_Date[0] = '\0';
	}
	void MakePayment() {
		cout << "****Welcome to Payment by Card****" << endl;
		cout << "Please enter your Credit-Card-Number: " << endl;
		cin >> CreditCard_No;
		cout << "Please enter your CCV: ";
		cin >> ccv;
		cout << "Please enter the Expiration Date: ";
		cin >> Expiry_Date;
		cout << "Total amount paid: " << getTotalamt() << endl;
		cout << "**Congratulations Payment is SuccessfulL**";

	}
};
class Inventory {                   //Inventory cclass
	char inven[10][50];
	int price[10];
	char measurements[10][20];
public:
	Inventory() {
		for (int i = 0; i < 10; i++) {
			price[i] = 0;
			inven[i][0] = '\0';
			measurements[i][0] = '\0';
		}
	}
	void setInventory() { //Set Inventory Function
		string z;
		cout << "Please set the Product Catalogue: " << endl;
		for (int i = 0; i < 10; i++) {
			cout << "Please enter item: ";
			cin >> z;
			strcpy_s(inven[i], 50, z.c_str());
			cout << "Please enter the price of the item: ";
			cin >> price[i];
			cout << "Please enter the measurement of the product: ";
			cin >> z;
			strcpy_s(measurements[i], 20, z.c_str());
		}
	}
	void DeleteandReplaceItem() {//Delete and replace function
		for (int i = 0; i < 10; i++) {
			cout << "Press " << i + 1 << " to choose " << inven[i] << endl;
		}
		int number = 0;
		cout << "Please enter:  " << number;
		cin >> number;
		if (number >= 1 && number <= 10) {
			cout << "Please enter the Product you want to replace with: ";
			string z;
			cin >> z;
			strcpy_s(inven[number - 1], 50, z.c_str());
			cout << "Please enter the Measurement of the New product: ";
			cin >> z;
			strcpy_s(inven[number - 1], 50, z.c_str());
			cout << "Please enter the price of new Product: ";
			cin >> price[number - 1];
		}
		else {
			cout << "Please enter a valid Product: " << endl;
			cout << "ooh Sorry! please Press 1 to Try again. " << endl;;
			cout << "Press any other number to end: ";
			cin >> number;
			switch (number) {
			case 1:
				DeleteandReplaceItem();
				break;
			default:
				break;
			}
		}
	} 
	void ViewInventory() { //View Inventory Function
		for (int i = 0; i < 10; i++) {
			cout << "Press " << i + 1 << " to choose " << inven[i] << " " << measurements[i] << " Price: " << price[i] << endl;
		}
	}
	int SearchandSelect()
	{//Search and select Function recrusively called until user wants to search and select
		int total = 0;
		for (int i = 0; i < 10; i++) {
			cout << "Press " << i + 1 << " to choose " << inven[i] << " " << measurements[i] << " Price: " << price[i] << endl;
		}
		cout << "Please enter a number: ";
		int number;
		cin >> number;
		if (number >= 1 && number <= 10) {
			total = total + price[number - 1];
			cout << "Press 1 to buy another product.";
			cin >> number;
			switch (number) {
			case 1:
				return SearchandSelect() + price[number - 1];
				break;
			default:
				return price[number - 1];
				break;
			}
		}

		else {
			cout << "Please enter a valid Product: " << endl;
			cout << "Press 1 to try again: " << endl;;
			cout << "Press any other number to end ";
			cin >> number;
			switch (number) {
			case 1:
				return SearchandSelect();
				break;
			default:
				return 0;
				break;
			}
		}

	}
};
class ProductCatalogue {
	char store[5][50];  //Product Catalogue containing 2d array character array

public:
	ProductCatalogue() {
		for (int i = 0; i < 5; i++) {
			store[i][0] = '\0';
		}
	}
	void setProducts() {
		string z;
		cout << "Please enter all Products of your store: ";
		for (int i = 0; i < 5; i++) {
			cin >> z;
			strcpy_s(store[i], 50, z.c_str());

		}
	}

};
class Store {
	char location[100];      //Store class containing feedback Inventory and product catalogue composition
	ProductCatalogue prod;
	Inventory inven;
	Feedback give;
	int revenue;
public:
	Store() {
		revenue = 0;
		location[0] = '\0';
	}
	void setProducts() {
		ifstream file;
		Store b;
		file.open("Store.dat", ios::binary);
		file.read((char*)&b, sizeof(b));
		*this = b;
		file.close();

		prod.setProducts();
		ofstream file1;
		file1.open("Store.dat", ios::binary);
		file1.write((char*)this, sizeof(*this));
	}
	void setInventory() {
		ifstream file;
		Store b;
		file.open("Store.dat", ios::binary);
		file.read((char*)&b, sizeof(b));
		*this = b;
		file.close();
		inven.setInventory();
		ofstream file1("Store.dat", ios::binary);
		file1.write((char*)this, sizeof(*this));
	}
	void ViewInventory() {
		ifstream file;
		Store b;
		file.open("Store.dat", ios::binary);
		file.read((char*)&b, sizeof(b));
		*this = b;
		inven.ViewInventory();
	}
	void DeleteAndReplace() {
		ifstream file;
		Store b;
		file.open("Store.dat", ios::binary);
		file.read((char*)&b, sizeof(b));
		*this = b;
		file.close();
		inven.DeleteandReplaceItem();
		ofstream file1("Store.dat", ios::binary);
		file1.write((char*)this, sizeof(*this));
		file1.close();
	}
	void Shop() {
		ifstream file;
		Store b;
		file.open("Store.dat", ios::binary);
		file.read((char*)&b, sizeof(b));
		char y;
		*this = b;
		double price = 0;
		do {

			price = price + inven.SearchandSelect();

			cout << "Please enter Y to Buy another Product: ";
			cin >> y;
		} while (y == 'Y' || y == 'y');
		revenue = revenue + price;
		cout << "Please make the Payment: ";
		cout << endl << "1.Through JazzCash.";
		cout << endl << "2.Through EasyPaisa.";
		cout << endl << "3.Through CreditCard.";
		int n;
		Payment* a;
		cin >> n;
		switch (n) {
		case 1:
			a = new JazzCash;
			a->MakePayment();
			break;
		case 2:
			a = new EasyPaisa;
			a->MakePayment();
			break;
		case 3:
			a = new CreditCard;
			a->MakePayment();
			break;
		}
		cout << "Thankyou for Shopping.Please come back Later!" << endl;
		GiveFeedback();
		ofstream file1("Store.dat", ios::binary);
		file1.write((char*)this, sizeof(this));
	}
	virtual void saveStore()
	{
		cout << "Hello! ";
	}
	virtual void CustomerMenu()
	{

	}
	void GiveFeedback() {
		cout << "Please give your feedback ";
		give.giveFeedback();
	}
	void ShowRevenue() {
		cout << "Store revenue is equal to " << revenue;
	}
	void DeleteFeedBack() {
		ifstream file;
		file.open("Store.dat", ios::binary);
		file.read((char*)this, sizeof(*this));
		file.close();
		 give.ShowFeedback();
		give.DeleteFeedback();
		ofstream file1;
		file1.open("Store,dat", ios::binary);
		file1.write((char*)this, sizeof(*this));
	}
};

class Islamabad : public Store
{//Islamabad Class used for polymorphism
public:
	void CustomerMenu()
	{
		cout << "****Welcome to Islambad Store****" << endl;
		cout << "1.You want to Shop " << endl;
		cout << "2.Or you want to View " << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			Shop();
		}
	}
	void saveStore()
	{
		ofstream file("Islambad.dat", ios::binary );
		file.write((char*)this, sizeof(*this));
		file.close();
	}
	void ReadStore() {
		ifstream file("Islamabad.dat", ios::binary);
		file.read((char*)this, sizeof(*this));
		file.close();
	}
};

class Karachi : public Store
{//Karachi class used for polymorphism
public:
	void saveStore()
	{
		ofstream file("Karachi.dat", ios::binary );
		file.write((char*)this, sizeof(*this));
		file.close();
	}
	void ReadStore() {
		ifstream file("Karachi.dat", ios::binary);
		file.read((char*)this, sizeof(*this));
		file.close();
	}
};

class Lahore :public Store
{
	//Lahore class used for polymorphism
public:
	void saveStore()
	{
		ofstream file("Lahore.dat", ios::binary );
		file.write((char*)this, sizeof(*this));
		file.close();
	}
	void ReadStore() {
		ifstream file("Lahore.dat", ios::binary);
		file.read((char*)this, sizeof(*this));
		file.close();
	}
};

class Customer :public User {
	char cnic[100];
	long long int PhoneNo;
	char gender[100];           //Customer class
	int accountNo;
	char Address[100];
	char City[100];
	Store store;
public:
	bool Logout() {
		Customer a;  //Logout Function 
		*this = a;
		return true;
	}
	void ViewCustomer()
	{
		cout << "---------------------------------------" << endl;
		cout << "Enter your CNIC: " << cnic << endl;
		cout << "Enter your Phone-Number: " << PhoneNo << endl;
		cout << "Enter your Gender: " << gender << endl;           //View Customer Function
		cout << "Enter your Account-Number: " << accountNo << endl;
		cout << "Enter your Address: " << Address << endl;
		cout << "Enter your City: " << City << endl;
		cout << "----------------------------------------." << endl;
	}
	Customer() {
		cnic[0] = '\0';
		PhoneNo = 0;
		gender[0] = '\0';
		accountNo = 0;
		Address[0] = '\0';
		City[0] = '\0';
	}
	bool CNICCheck(string z) {

		if (z.length() != 13) {
			return false;
		}
		for (int i = 0; i < 13; i++) {
			if (!(z[i] >= 48 && z[i] <= 57)) {
				return false;
			}
		}
		ifstream file("Customer.dat", ios::binary);
		if (!file) {
			return true;
		}
		else {
			Customer dummy;
			while (file.read((char*)&dummy, sizeof(dummy))) {
				if (dummy.cnic == z) {
					return false;
				}
			}
			return true;
		}
	}
	bool UsernameCheck(string z) {
		ifstream file("Customer.dat", ios::binary);
		if (!file)
			return true;
		else {
			Customer dummy;
			while (file.read((char*)&dummy, sizeof(dummy))) {
				if (dummy.getUsername() == z) {
					return false;
				}
			}
			return true;
		}

	}
	bool AccountNoCheck(int n) {
		ifstream file("Customer.dat", ios::binary);
		if (!file)
			return true;
		else {
			Customer dummy;
			while (file.read((char*)&dummy, sizeof(dummy)))
			{
				if (dummy.accountNo == n)
				{
					return false;
				}
			}
			return true;
		}
	}
	bool PasswordCheck(string z)
	{
		if (z.length() < 9)
		{
			return false;
		}
		bool check = false;
		bool check1 = false;
		for (int i = 0; i < z.length(); i++) {
			if (z[i] >= 48 && z[i] <= 57)
				check = true;;
			if (z[i] >= 65 && z[i] <= 90) {
				check1 = true;
			}
		}
		if (!check1 || !check)
			return false;
		return true;
	}
	void Register() {
		string z;
		long long int y;
		bool check = false;
		cout << "Please enter a valid CNIC: ";
		cin >> z;
		while (!CNICCheck(z) && z != "N") {
			cout << "Press N to stop Register or Please enter a valid CNIC: ";
			cin >> z;
		}
		strcpy_s(cnic, 100, z.c_str());
		cout << "Enter your Phone-Number: ";
		cin >> y;
		PhoneNo = y;
		cout << "Enter your Gender: ";
		cin >> z;
		strcpy_s(gender, 100, z.c_str());
		cout << "Please enter your street-Number: ";
		cin >> z;
		strcpy_s(Address, 100, z.c_str());
		cout << "Please enter your City: ";
		cin >> z;
		strcpy_s(City, 100, z.c_str());
		cout << "Please enter your Username: ";
		cin >> z;
		while (!UsernameCheck((z)) && z != "N") {
			cout << "Press N to stop Register or Please enter a valid Username: ";
			cin >> z;
		}
		setUsername(z);
		cout << "Please enter your Password: ";
		cin >> z;
		while (!PasswordCheck(z)) {
			cout << "Please enter a valid password: ";
			cin >> z;

		}
		int n;
		cout << "Please enter your AccountNo: ";
		cin >> n;
		while (!AccountNoCheck(n)) {
			cout << "Please enter your AccountNo: ";
			cin >> n;
		}
		accountNo = n;
		setPassword(z);
		ofstream file("Customer.dat", ios::binary | ios::app);
		file.write((char*)this, sizeof(*this));
		file.close();
	}
	bool Login() {
		ifstream file("Customer.dat", ios::binary);
		if (!file)
			return false;
		else {
			Customer dummy;
			string y;
			cout << "Please enter your Username: ";
			cin >> y;
			setUsername(y);
			cout << "Please enter your Password: ";
			cin >> y;
			setPassword(y);
			while (file.read((char*)&dummy, sizeof(dummy))) {
				if (strcmp(dummy.getUsername(), getUsername()) == 0 && strcmp(getPassword(), dummy.getPassword()) == 0) {
					*this = dummy;
					return true;
				}
			}
			return false;
		}
	}
	void Menu() {
		int n;
		bool flag = false;

		cout << "-----------Press 1 to Login-----------" << endl;;
		cout << "----------Press 2 to Register---------" << endl;

		cin >> n;
		switch (n)
		{
		case 1:
			if (Login()) {
				flag = true;
				cout << "**Congratulations! Your Data entry was Successfull**" << endl;
			}
			else
				cout << "**ooh Sorry! Your Data entry was not Successfull**" << endl;
			break;
		case 2:
			Register();
			break;

		}
		if (flag) {
			cout << "**Press 1 to View all Details**" << endl;
			cout << "**Press 2 to shop**" << endl;
			cin >> n;
			switch (n) {
			case 1:
				ViewCustomer();
				break;
			case 2:
				store.Shop();
				break;
				//case 3:

			}
		}
	}
};
class Manager : public User
{
	char city[100];
	Store store;
public:
	Manager()
	{
		city[0] = '\0';                     //Manager Class with all attributes
	}
	bool logout()
	{
		Manager a;
		*this = a;
		return true;
	}
	bool UsernameCheck(string z)
	{
		ifstream file("Manager.dat", ios::binary);
		if (!file)
			return true;
		else {
			Manager dummy;
			while (file.read((char*)&dummy, sizeof(dummy)))
			{
				if (dummy.getUsername() == z)
				{
					return false;
				}
			}
			return true;
		}

	}
	bool Login()
	{
		ifstream file("Manager.dat", ios::binary);
		if (!file)
			return false;
		else
		{
			Manager dummy;             //Manager Login Function
			string y;
			cout << "Please enter your Username: ";
			cin >> y;
			setUsername(y);
			cout << "Please enter ypur Password: ";
			cin >> y;
			setPassword(y);
			while (file.read((char*)&dummy, sizeof(dummy)))
			{
				if (strcmp(dummy.getUsername(), getUsername()) == 0 && strcmp(getPassword(), dummy.getPassword()) == 0)
				{
					Store c;
					ifstream file1("Store.dat", ios::binary);
					file1.read((char*)&c, sizeof(c));
					store = c;
					*this = dummy;
					return true;
				}
			}
			return false;
		}
	}
	bool PasswordCheck(string z)
	{
		if (z.length() < 9)
		{
			return false;
		}
		bool check = false;
		bool check1 = false;
		for (int i = 0; i < z.length(); i++)
		{
			if (z[i] >= 48 && z[i] <= 57)
				check = true;;
			if (z[i] >= 65 && z[i] <= 90) {
				check1 = true;
			}
		}
		if (!check1 || !check)
			return false;
		return true;
	}
	char* getCity() {
		return city;
	}
	void setCity(string z) {
		strcpy_s(city, 100, z.c_str());
	}
	void Menu() {
		int n;
		bool flag = false;
		cout << "**Press 1 to login**";
		cin >> n;
		switch (n) {
		case 1:
			if (Login()) {
				flag = true;
				cout << "**Congratulations! your Data entry was Successfull**";
			}
			else
				cout << "**ooh Sorry! your Data entry was Unsuccessfull**";
			break;

		}
		if (flag) {
			ifstream file;
			Store b;
			cout << "1. To set Inventory of the store: ";

			cout << endl;
			cout << "2. To show Revenue:  " << endl;
			cout << "3. To search and delete item : " << endl;;
			cin >> n;
			switch (n)
			{
			case 1:

				store.setInventory();
				break;
			case 2:
				
				file.open("Store.dat", ios::binary);
				file.read((char*)&b, sizeof(b));
				store = b;
				file.close();
				store.ShowRevenue();
				break;
			case 3:
				
				file.open("Store.dat", ios::binary);
				file.read((char*)&b, sizeof(b));
				store = b;
				file.close();
				store.DeleteAndReplace();
				break;
			}
		}
	}

};

class Admin : public User
{

	Store store;
public:
	bool login()
	{
		fstream file1;
		string z;
		cout << "Enter username ";
		cin >> z;
		cout << "Enter password: ";
		cin >> z;
		file1.open("Admin.dat", ios::binary | ios::in | ios::out);
		while (file1.read((char*)this, sizeof(*this))) {
			cout << "Login Successful: " << endl;
			return true;
		}
	}
	void DeleteCustomer()
	{                                // Admin class who can also delete customer
		Customer dummy;
		Customer current;
		bool flag = false;
		string name;
		cout << "Enter your Username: ";
		cin >> name;


		fstream file("Customer.dat", ios::out | ios::binary | ios::in);
		while (file.read((char*)&dummy, sizeof(dummy))) {
			if (strcmp(name.c_str(), dummy.getUsername()) == 0) {
				current = dummy;
				flag = true;
				break;
			}
		}
		file.close();
		if (!flag) {
			cout << "**Username doesnot does not exist**" << endl;
		}
		else {
			int n;
			current.ViewCustomer();
			cout << "**Press 1 to delete this user**" << endl;
			cout << "**Press 2 to if you dont want to delete**" << endl;
			cin >> n;
			switch (n) {
			case 1:
				ofstream file1("Customer1.dat", ios::binary | ios::app);
				file.open("Customer.dat", ios::out | ios::binary | ios::in);
				while (file.read((char*)&dummy, sizeof(dummy))) {
					if (!(strcmp(dummy.getUsername(), current.getUsername()) == 0)) {
						file1.write((char*)&dummy, sizeof(dummy));
					}
				}
				file.close();
				file1.close();
				remove("Customer.dat");
				int x = rename("Customer1.dat", "Customer.dat");
				break;

			}
		}

	}
	void RegisterManager() {
		Manager dummy;
		string z;
		cout << "Please enter your Username: ";
		cin >> z;
		while (!dummy.UsernameCheck(z)) {
			cout << "***This Username is already Taken***";
			cin >> z;
		}
		dummy.setUsername(z);
		cout << "***Please enter your Password***";
		cin >> z;
		while (!dummy.PasswordCheck(z)) {
			cout << "**Invalid Password! Please Enter again** ";          //Register Manager Function only access to admin
			cin >> z;
		}
		dummy.setPassword(z);
		cout << "Please etner your city: ";
		cin >> z;
		dummy.setCity(z);
		ofstream file("Manager.dat", ios::binary | ios::app);

		file.write((char*)&dummy, sizeof(dummy));
		file.close();
	}
	void Menu() {
		int n;
		bool flag = false;
		cout << "Please login as Admin: ";
		login();
		cout << "**Press 1 to Register Manager**" << endl;
		cout << "**Press 2 to Delete Customer**" << endl;
		cout << "**Press 3 to set Product of store**" << endl;
		cout << "**Press 4 to delete feedback**" << endl;
		cin >> n;
		switch (n) {
		case 1:
			RegisterManager();
			break;
		case 2:
			DeleteCustomer();
			break;
		case 3:
			store.setProducts();
			break;
		case 4:
			Store c;
			ifstream file1("Store.dat", ios::binary);
			file1.read((char*)&c, sizeof(c));
			store = c;
			store.DeleteFeedBack();
			break;
		}
	}

};
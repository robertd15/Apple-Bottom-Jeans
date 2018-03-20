//Apple Bottom Jeans: A Database of Apple Computers over the years
//Manish Goel , CIS 22C Winter 18
//Group 1: Robert Dyer, Frankie Ranallo, John Le, Tran Nguyen, and Charles Canasa
//Final Project
//

//Main written by: Tran Nguyen

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "BST.h"
#include "macHash.h"
#include "hashi.h"
//#include "HashMap.h"
#include "fileIO.h"
#include "macBook.h"


using namespace std;

string choiceError = " Error: Invalid choice\n";
const int MAX_ENTRY_SIZE = 30;


//Main Menu function prototypes
void enterToContinue(string);
void showMenu();
void shoppingMenu();
macBook menuAdd();
macBook menuRemove();
void searchByNumber();
macBook tempObjectCreate();

//Login function prototypes
void showOpeningScreen(hashi hashy);
void showLoginScreen(hashi hashy);
void showCreateAccountScreen(hashi hashy);
void showForgotPasswordScreen(hashi hashy);
void showAdminScreen(hashi hashy);


int main()
{


	hashi hashy;

	showOpeningScreen(hashy);

	macBook catalog[MAX_ENTRY_SIZE];
	fileIO file;
	file.readFile(catalog);

	//Create BST and Hash Table
	BST<macBook> macTree;
	macHash macTable;

	//Initialize BST contents
	for (int i = 0; i < MAX_ENTRY_SIZE; i++)
	{
		macTree.addByOrder(catalog[i]);
	}



	int choice = -1;


	do {

		system("CLS");
		showMenu();
		cin >> choice;
		cin.clear();
		cin.ignore(1000, '\n');

		macBook tempValue;

		switch (choice)
		{
		case 1:
			tempValue = menuAdd();
			macTree.add(tempValue);
			macTable.addMac(tempValue);
			break;
		case 2:
			tempValue = menuRemove();
			macTree.deleteData(tempValue);
			macTable.removeMac(tempValue);
			break;

		case 3:
			searchByNumber();

			break;

		case 4:
			cout << "4\n";
			enterToContinue("return to the main menu");
			break;
		case 5:
			cout << "5\n";
			enterToContinue("return to the main menu");
			break;
		case 6:
			cout << "6\n";
			enterToContinue("return to the main menu");
			break;
		case 7:
			cout << "7\n";
			enterToContinue("return to the main menu");
			break;
		case 8:
			shoppingMenu();
			break;

		case 9:
			exit(0);
			break;

		default:

			cout << choiceError;
			enterToContinue("return to the main menu");


		}
	} while (choice != 9);

	system("CLS");
	enterToContinue("to exit the program");
	return 0;
}

//Main Menu function implementations
void showMenu()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t   ****** Welcome To Apple Bottom Jean ****** \n";
	cout << "\n\n\t\t   Please Select From The Following Menu ";
	cout << "\n\n\t\t   [1]. Add Record  " << endl;
	cout << "\n\t\t   [2]. Delete Record  " << endl;
	cout << "\n\t\t   [3]. Search By Order Number " << endl;
	cout << "\n\t\t   [4]. Print Data " << endl;
	cout << "\n\t\t   [5]. Print Data (sorted by order number) " << endl;
	cout << "\n\t\t   [6]. Print Indented Tree " << endl;
	cout << "\n\t\t   [7]. Print Efficiency of Data " << endl;
	cout << "\n\t\t   [8]. Shopping Cart" << endl;
	cout << "\n\t\t   [9]. Exit " << endl;
	cout << "\n Enter Your Choice: ";
}

void shoppingMenu() {
	int subChoice = -1;

	do {
		system("CLS");
		cout << "\n\t\t   ****** Welcome To Shopping Cart ****** \n";
		cout << "\n\n\t\t   Please Select From The Following Menu ";
		cout << "\n\n\t\t   [1]. Place Order  " << endl;
		cout << "\n\t\t   [2]. Delete Order  " << endl;
		cout << "\n\t\t   [3]. Check Out  " << endl;
		cout << "\n\t\t   [4]. Return To The Main Menu " << endl;
		cout << "\n Enter Your Choice: ";
		cin >> subChoice;
		cin.clear();
		cin.ignore(1000, '\n');


		switch (subChoice) {
		case 1:
			cout << "Place your oder";
			enterToContinue("return to the shopping cart");
			break;
		case 2:
			cout << "Delete your order";
			enterToContinue("return to the shopping cart");
			break;
		case 3:
			cout << "Check out the order";
			enterToContinue("return to the shopping cart");
			break;
		case 4:
			break;
		default:
			cout << choiceError;
			enterToContinue("return to the shopping menu");

		}


	} while (subChoice != 4);

	enterToContinue("return to main menu");
}

void enterToContinue(string string)
{
	cout << "\nPress enter to " << string;
	cin.get();
	system("CLS");
}




macBook menuAdd()
{
	system("CLS");
	cout << "Add function:" << endl << endl;

	macBook addMac;
	addMac = tempObjectCreate();

	return addMac;

	enterToContinue("return to main menu");
}

macBook menuRemove()
{
	system("CLS");
	cout << "Remove Function:" << endl << endl;

	macBook removeMac;
	removeMac = tempObjectCreate();

	return removeMac;
	
	enterToContinue("return to main menu");

}

void searchByNumber()
{
	system("CLS");
	cout << "search function";
	enterToContinue("return to main menu");

}

//Creates a temporary mac object to pass to an add function
macBook tempObjectCreate()
{
	//Variables for temporary object creation
	string tempOrderNum, tempName, tempRelease;
	double tempPrice;
	int tempQuantity;

	cout << "Please enter data for the particular model you are looking to modify in the database" << endl << endl;

	cout << "Order Number?:" << endl << endl;
	getline(cin, tempOrderNum);
	cout << endl;

	cout << "Name?:" << endl << endl;
	getline(cin, tempName);
	cout << endl;

	cout << "Release Date?:" << endl << endl;
	getline(cin, tempRelease);
	cout << endl;

	cout << "Price?:" << endl << endl;
	cin >> tempPrice;
	cin.ignore();
	cout << endl;

	cout << "Quantity?:" << endl << endl;
	cin >> tempQuantity;
	cin.ignore();
	cout << endl;

	macBook tempMac(tempOrderNum, tempName, tempRelease, tempPrice, tempQuantity);

	return tempMac;
}

//Login function implementations
/*
Displays opening screen
Select user choice of menu options
*/
void showOpeningScreen(hashi hashy) {
	char choice = ' ';
	bool lock = true;

	cout << "\t\t   ****** Welcome To Apple Bottom Jeans ****** \n";
	cout << "\n\n\t\t   Please Select From The Following Menu ";
	cout << "\n\n\t\t\t(1) Login\n";
	cout << "\n\n\t\t\t(2) Create Account\n";
	cout << "\n\n\t\t\t(3) Forgot Password?\n";
	cout << "\n\n\t\t\t(4) Exit\n\n";
	cout << "\n\n\t\t\tChoice: ";
	cin >> choice;

	switch (choice) {
	case '1': system("cls");
		showLoginScreen(hashy);
		break;
	case '2': system("cls");
		showCreateAccountScreen(hashy);
		break;
	case '3': system("cls");
		showForgotPasswordScreen(hashy);
		break;
	case '4': cout << "\nGoodbye!\n" << endl;
		system("exit");
		break;
	case '5': system("cls");
		showAdminScreen(hashy);
		break;
	default:  system("cls");
		showOpeningScreen(hashy);
	}
}

/*
Shows the login screen
Requests user to input their username-password
If successful, enter the database
If unsuccessful, return to opening screen
*/
void showLoginScreen(hashi hashy) {
	string username, password;

	cout << "\t\t   ****** Login ****** \n";
	cout << "\n\n\t\tUsername: ";
	cin >> username;
	cout << "\n\n\t\tPassword: ";
	cin >> password;
	cout << "\n\t\t";
	if (hashy.confirmUser(username, password) == true) {
		cout << "\n\t\tPassed" << endl;
	}

	system("pause");
	system("cls");
}

void showCreateAccountScreen(hashi hashy) {
	string username, password;

	cout << "\t\t   ****** Create Account ****** \n";
	cout << "\n\n\t\t\tUsername: ";
	cin >> username;
	cout << "\n\n\t\t\tPassword: ";
	cin >> password;

	if (hashy.hasDuplicate(username)) {
		cout << "\n\n\t\t\t" << username << " already exists" << endl;
	}
	else {
		hashy.addUser(username, password);
		hashy.addToTextFile(username, password);
		cout << "\n\n\t\t\t" << username << " was successfully created" << endl;
	}
	system("pause");
	system("cls");
	showOpeningScreen(hashy);
}

/*
Displays the "Forgot Password" menu
Type the username to search the password for.
Type "exit" to return back to the Opening Screen
*/
void showForgotPasswordScreen(hashi hashy) {
	string username;

	cout << "\t\tForgot Your Password?\n";
	cout << "\t\tNOTE: \"exit\" to return to Opening Menu\n\n";

	while (username != "exit") {
		cout << "\n\t\tSearch: ";
		cin >> username;

		if (username != "exit") {
			cout << "\t\t";
			hashy.findPassword(username);
		}
		cout << endl;
	}
	system("pause");
	system("cls");
	showOpeningScreen(hashy);
}

/*
1 - Print Table
2 - Remove User
3 - Back to Main Menu
*/
void showAdminScreen(hashi hashy) {
	bool lock = true;
	int choice = 0;
	string username, password;
	cout << "\t\t   ****** DEBUG ****** \n";
	cout << "1. Print Table\n";
	cout << "2. Remove User\n";
	cout << "3. Number of Users in Index\n";
	cout << "4. Return to Main Menu\n";

	while (lock == true) {
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1) {
			lock = false;
			hashy.printTable();
			system("pause");
			system("cls");
			showAdminScreen(hashy);
		}
		else if (choice == 2) {
			lock = false;
			cout << "Remove Username: ";
			cin >> username;
			cout << "Confirm Password: ";
			cin >> password;
			hashy.removeUser(username);
			hashy.removeFromTextFile(username, password);
			system("pause");
			system("cls");
			showAdminScreen(hashy);
		}
		else if (choice == 3) {
			int index;
			lock = false;
			cout << "\nWhich Index would you like to look through (0-3)? ";
			cin >> index;
			if (index >= 0 && index <= 3) {
				hashy.printUsersInIndex(index);
				system("pause");
				system("cls");
				showAdminScreen(hashy);
			}
		}
		else if (choice == 4) {
			lock = false;
			system("cls");
			showOpeningScreen(hashy);
		}
	}
}
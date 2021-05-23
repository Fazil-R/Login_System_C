#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
	//credentials
	string username;
	string password;
	//comparison strings
	string un;
	string pw;

	cout << "Enter username: ";
	cin >> username;

	cout << "Enter password: ";
	cin >> password;

	//reads the username and compares it to existing username and password
	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw);

	//if the username and passwords are the same then return true, else false
	if (un == username && pw == password)
		return true;

	else
		return false;
}

int main()
{
	int choice; 

	//pick option
	cout << "1: Register\n2: Login\nYour choice: "; 
	cin >> choice;

	if (choice == 1)
	{
		string username, password;

		cout << "select a username: "; 
		cin >> username;

		cout << "select a password: ";
		cin >> password;

		ofstream file;
		file.open(username + ".txt");
		file << username << endl << password;

		file.close();

		main();
	}
	else if (choice == 2) {
		bool status = IsLoggedIn();

		//if no account exists
		if (!status) {
			cout << "False login!" << endl;
			main();
		}

		else {
			cout << "Succesfully logged in!" << endl;
			system("PAUSE");
			return 1;
		}
	}
}
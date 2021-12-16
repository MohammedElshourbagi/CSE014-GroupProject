// CSE014 Group project that's worth 25% of our grade
// Basic Libraies used, ADD more if used here
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Library DataBase Functions
	// Prototype functions are declared here
void DBsearch(); // AbdoAymen
void DBdisplay(); // AbuBakr
void DBadd(); // Bodz the following is yours 
void DBdelete(); 
void DBupdate(); 

int main() {
	// Vectors containing all the info on the books 
	vector<string> BOOKID, TITLE, AUTHOR, GENRE, PUBLISHER, ISBN, YEAR, PAGES;
	// All data stored in text file is assinged to the vectors used in the program
	// This allows us to manipulate the data more easily
	fstream iofs("BookData.txt"); 
	int atLine = 1;
	for (string LineRead; getline(iofs, LineRead);) {
		if ((atLine % 9) == 1) { BOOKID.push_back(LineRead); }
		if ((atLine % 9) == 2) { TITLE.push_back(LineRead); }
		if ((atLine % 9) == 3) { AUTHOR.push_back(LineRead); }
		if ((atLine % 9) == 4) { ISBN.push_back(LineRead); }
		if ((atLine % 9) == 5) { GENRE.push_back(LineRead); }
		if ((atLine % 9) == 6) { PUBLISHER.push_back(LineRead); }
		if ((atLine % 9) == 7) { YEAR.push_back(LineRead); }
		if ((atLine % 9) == 8) { PAGES.push_back(LineRead); }
	}
	cout << " This is program manages and maintain a database of books in a library.\n";
	// Displays all Starting choices 
	cout << " Select by entering the corresponding numbers:\n";
	cout << "\n\t 1.) Search \n";
	cout << "\n\t 2.) Display \n";
	cout << "\n\t 3.) Add \n";
	cout << "\n\t 4.) Delete \n";
	cout << "\n\t 5.) Update \n";

	int choice = 0;
	cout << "\n Choice: ";
	cin >> choice;
	while ((choice <= 0) || (choice > 5)) {
		cout << " ***INVALID INPUT***\n";
		cout << " Try Again: number must be between 1 to 5 \n";
		cout << " Choice: ";
		cin >> choice;
	}

	switch (choice) {
	case 1:
		DBsearch();
		break;
	case 2:
		DBdisplay();
		break;
	case 3:
		DBadd();
		break;
	case 4:
		DBdelete();
		break;
	case 5:
		DBupdate();
		break;
	}
}

void DBsearch() {

}
void DBdisplay() {

}
void DBadd() {

}
void DBdelete() {

}
void DBupdate() {

}

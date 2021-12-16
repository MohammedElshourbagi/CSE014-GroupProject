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

// Vectors containing all the info on the books 
vector<int> BOOKID; 	// BOOKID is used Internally only
vector<string> TITLE, AUTHOR, GENRE, PUBLISHER, ISBN /*13 Standard*/;
vector<int> YEAR /*of publishing*/, PAGES;

	/* Typical Structure of Data
	* BOOKID
	* AUTHOR
	* ISBN
	* GENRE
	* PUBLISHER
	* YEAR 
	* PAGES
	*/

int main() {
	// Before the rest of the code executes all the information is initialized from a textfile 

	fstream iofs("BookData.txt"); // Reads from this file 
	int atLine = 1;
	for (string LineRead; getline(iofs, LineRead);) {
		if ((atLine % 9) == 1) { BOOKID.push_back(stoi(LineRead)); }
		if ((atLine % 9) == 2) { TITLE.push_back(LineRead); }
		if ((atLine % 9) == 3) { AUTHOR.push_back(LineRead); }
		if ((atLine % 9) == 4) { ISBN.push_back(LineRead); }
		if ((atLine % 9) == 5) { GENRE.push_back(LineRead); }
		if ((atLine % 9) == 6) { PUBLISHER.push_back(LineRead); }
		if ((atLine % 9) == 7) { YEAR.push_back(stoi(LineRead)); }
		if ((atLine % 9) == 8) { PAGES.push_back(stoi(LineRead)); }

		cout << LineRead << endl; // DEBUG
		atLine++; // DEBUG
	}

	// Displays all Starting choices 
	cout << "Select by entering the corresponding numbers\n";
	cout << "\n\t 1.) Search \n";
	cout << "\n\t 2.) Display \n";
	cout << "\n\t 3.) Add \n";
	cout << "\n\t 4.) Delete \n";
	cout << "\n\t 5.) Update \n";

	int choice = 0;
	cout << "\n Choice: ";
	cin >> choice;

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

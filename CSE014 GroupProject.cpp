// CSE014 Group project that's worth 25% of our grade
// Everyone is assigned a Function to complete 
// and everyone is responsible for their code's analysis (flow chart and algorithim)

// Basic Libraies used, ADD more if used here
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Library Database (hence the DB) Functions
	// Prototype functions are declared here
void DBsearch(); // AbdoAymen
void DBdisplay(); // AbuBakr
void DBadd(); // Bodz the following is yours 
void DBdelete();	// The following are really similiar 
void DBupdate();	// But I'll be mostly helping you with them 

// Vectors containing all the info on the books 
vector<int> BOOKID; 
	// BOOKID is used Internally only
	// Is used alongside with the index number which is how we're gonna find the following
vector<string> TITLE, AUTHOR, GENRE, PUBLISHER; // These are what I find neccessary,
vector<int> ISBN /*13 Standard*/, YEAR /*of publishing*/, PAGES;

int main() {
	// Before the rest of the code executes all the information is initialized from a textfile 
	fstream iofs("BookData.txt"); // Reads from this file 
	string bookID, title, author, isbn, genre, publisher, year, pages;
	// string GatheringData[8] = { bookID, title, author, isbn, genre, publisher, year, pages };
	for (string LineRead; getline(iofs, LineRead);) {
		/* Processes of reading the line converted to local variableand push.backing to vectors
		Each Book has 8 lines dedicated to them 
		with a empty line seperating them */
		// ((LineRead & 9)==0; then skip line and )
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

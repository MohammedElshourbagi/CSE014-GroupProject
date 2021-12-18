// CSE014 Group project that's worth 25% of our grade
// Basic Libraies used, ADD more if used here
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Prototype functions are declared here
void TableHeader();
void TableEnd();
void DBsearch(); // AbdoAymen
void DBdisplay(); // AbuBakr
void DBadd(); // Bodz the following is yours 
void DBdelete(); 
void DBupdate();

int main() {
	// Vectors containing all the info on the books 
	vector<string> BOOKID, TITLE, AUTHOR, GENRE, PUBLISHER, ISBN, YEAR, PAGES, PRICE;
	// All data stored in text file is assinged to the vectors used in the program
	// This allows us to manipulate the data more easily
	fstream ifs("BookData.txt"); 
	int AmountOfBooks = 1;
	if (ifs.is_open()) {
		for (string atLineRead; getline(ifs, atLineRead);) {
			stringstream unprocessedLine(atLineRead);
			string segment;
			int position = 1;
			while (getline(unprocessedLine, segment, '|')) {
				if (position == 1) { BOOKID.push_back(segment); }
				if (position == 2) { TITLE.push_back(segment); }
				if (position == 3) { AUTHOR.push_back(segment); }
				if (position == 4) { GENRE.push_back(segment); }
				if (position == 5) { PUBLISHER.push_back(segment); }
				if (position == 6) { ISBN.push_back(segment); }
				if (position == 7) { YEAR.push_back(segment); }
				if (position == 8) { PAGES.push_back(segment); }
				if (position == 9) { PRICE.push_back(segment); }
				if (position >= 10) { cout << "\n ERROR: Improper Data Format.\n"; }
				position++;
			}
			AmountOfBooks++;
		}
	} else { cout << "\n ERROR: Something went wrong with openining the file\n"; }
	bool NeedSave = 0; // Did the content of file change?, if it did then save

	cout << "\n This is program manages and maintain a database of books in a library.\n";
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
		// This is a query 
			// Display a search fields 
			// Ask for the search term
		DBsearch(); // This function should be givin a vectorName, searchTerm 
		TableHeader();
		// output all books that have the search term in the right field
		TableEnd();
		break;
	case 2:
		TableHeader();
		DBdisplay(); // This function diplays all the information stored in the vectors
		TableEnd();
		break;
	case 3:
		DBadd();
		NeedSave = 1;
		break;
	case 4:
		DBdelete();
		NeedSave = 1;
		break;
	case 5:
		DBupdate();
		NeedSave = 1;
		break;
	}
	
	// Saving changes made to the file
	if (NeedSave == 1) {
		ofstream os("BookData.txt", ios::out | ios::trunc);
		if (os.is_open()) {
			string part1, part2, part3, aggregated;
			for (int i = 0; i <= (AmountOfBooks - 1); i++) {
				part1 = BOOKID.at(i) + "|" + TITLE.at(i) + "|" + AUTHOR.at(i) + "|";
				part2 = GENRE.at(i) + "|" + PUBLISHER.at(i) + "|" + ISBN.at(i) + "|";
				part3 = YEAR.at(i) + "|" + PAGES.at(i) + "|" + PRICE.at(i);
				aggregated = part1.append(part2.append(part3));
				os << aggregated << endl;
			}
		} else { cout << "\n ERROR: Something went wrong with opening the file.\n"; }
	}
}


void TableHeader() {
	cout << "\n=====================================================================================";
	cout << "\n         Title         |     Author     |  Genre  | Year | Pages | Publisher ";
	cout << "\n-----------------------+----------------+---------+------+-------+-------------------\n";
}
void TableEnd() {
	cout << "\n=====================================================================================\n";
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

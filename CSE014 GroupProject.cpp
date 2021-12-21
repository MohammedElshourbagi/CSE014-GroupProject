// CSE014 Group project that's worth 25% of our grade
#include <iostream>	
#include <iomanip>
#include <fstream>		
#include <sstream>	    
#include <string>		
#include <algorithm>
#include <vector>	
using namespace std;

// Prototype functions are declared here
void TableHeader();
void TableEnd();

int main() {
	cout << " This is program manages and maintain a database of books in a library.";

	int AmountOfBooks = 0;
	vector<string> BOOKID, TITLE, AUTHOR, GENRE, PUBLISHER, YEAR, PAGES, ORGPRICE, RETAILPRICE, ISBN; 	// Vectors containing all the info on the books 
	// All data stored in text file is assinged to the vectors used in the program
	// This allows us to manipulate the data more easily
	fstream ifs("BookData.txt"); 
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
				if (position == 6) { YEAR.push_back(segment); }
				if (position == 7) { PAGES.push_back(segment); }
				if (position == 8) { ORGPRICE.push_back(segment); }
				if (position == 9) { RETAILPRICE.push_back(segment); }
				if (position == 10) { ISBN.push_back(segment); }
				if ((position >= 11) || (position == 0)) { cout << "\n ERROR: Improper Data Format.\n"; }
				position++;
			}
			AmountOfBooks++;
		}
	} else { cout << "\n ERROR: Something went wrong with openining the file\n"; }
	bool NeedSave = 0; // Did the content of file change?, if it did then save

	int PassodeEntered, Passcode = 123;
	bool isAdmin = 0;
	char RunAsAdmin;
	cout << "\n Run Program as Administrator? (Y/N): ";
	cin >> RunAsAdmin;
	if (RunAsAdmin == 'Y') {
		cout << " Enter Admins Code = ";
		cin >> PassodeEntered;
		if (PassodeEntered == Passcode) { isAdmin = 1;
		} else {
			int Attempts = 3;
			while ((PassodeEntered != Passcode) && (Attempts > 0)){
				cout << " Incorrect Password: You have " << Attempts << " arrempts left = ";
				cin >> PassodeEntered;
				Attempts--; }
			if (Attempts == 0) { cout << "\n Program will run with standard functions only\n"; }
		}
	} else { cout << "\n Program will run with standard functions only\n"; }
	
	// Displays all Starting choices 
	cout << "\n Select by entering the corresponding numbers:\n";
	cout << "\n\t 1.) Search \n";
	cout << "\n\t 2.) Display \n";
	if (isAdmin == 1) { 
		cout << "\n\t 3.) Add \n"; 
		cout << "\n\t 4.) Delete \n"; 
		cout << "\n\t 5.) Update \n"; 
		cout << "\n\t 6.) Organize Sale \n"; }

	int choice = 0;
	cout << "\n Choice: ";
	cin >> choice;
	if (isAdmin == 1) {
		while ((choice <= 0) || (choice > 6)) {
			cout << " ***INVALID INPUT***\n";
			cout << " Try Again: number must be between 1 to 6 \n";
			cout << " Choice: ";
			cin >> choice;
		}
	} else {
		while ((choice <= 0) || (choice > 2)) {
			cout << " ***INVALID INPUT***\n";
			cout << " Try Again: number must be between 1 to 2 \n";
			cout << " Choice: ";
			cin >> choice;
		}
	}
	
	switch (choice) {
	case 1: // QUERY
		int querychoice;
		cout << "\n select by entring the corresponding number :\n";
		cout << "\n\t 1: Search by Title \n";
		cout << "\n\t 2: Search by Author \n";
		cout << "\n\t 3: Search by Genre \n";
		cout << "\n\t 4: Search by Publisher \n";
		cout << "\n\t 5: Search by Price \n";
		cin >> querychoice;
		while ((querychoice <= 0) || (querychoice > 7)) {
			cout << "INVALID INPUT\n";
			cout << "Try Again : number must be between 1 to 7 \n";
			cout << "choice; ";
			cin >> querychoice;
		}
		switch (querychoice) {
		case 1: // Checks the TITLE vector if it contains the search term 
			break;
		case 2: // Checks the AUTHOR vector if it contains the search term  
			break;
		case 3: // Checks the GENRE vector if it contains the search term
			break;
		case 4: // Checks the Publisher vector if it contains the search term
			break;
		case 5: // Display a small MENU with a price range
		}

		TableHeader();
		// output all books that have the search term in the right field
		TableEnd();
		break;

	case 2: // DISPLAY
		TableHeader();
		for (int i = 0; i <= (AmountOfBooks - 1); i++) {
			cout << setw(45) << left << TITLE.at(i);
			cout << setw(18) << right << AUTHOR.at(i);
			cout << setw(10) << right << GENRE.at(i);
			cout << setw(6) << right << YEAR.at(i);
			cout << setw(8) << right << PAGES.at(i);
			cout << setw(20) << right << PUBLISHER.at(i);
			cout << setw(8) << right << RETAILPRICE.at(i);
			cout << endl; }
		TableEnd();
		break;

	// Manipulating Data stored in Database
	case 3: // ADD
		// use this to add an element
			//vectorname.insert(vectorname.begin() + (n-1), NewValueAdded)
		NeedSave = 1;
		break;
	case 4: // DELETE
		// use this to delete an element and shift the rest down by one
			// using vectorname.erase (vectorname.begin()+(n-1))
		NeedSave = 1;
		break;
	case 5: // UPDATE
		// use this to update an element 
			// vectorname.at((n-1)) = NewValue
		NeedSave = 1;
		break;

	case 6: // ORGANIZE SALE
		// Something like 20& off for all fantasy books 
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
				part2 = GENRE.at(i) + "|" + PUBLISHER.at(i) + "|" + YEAR.at(i) + "|";
				part3 = PAGES.at(i) + "|" + ORGPRICE.at(i) + "|" + RETAILPRICE.at(i) + "|" + ISBN.at(i);
				aggregated = part1.append(part2.append(part3));
				os << aggregated << endl;
			}
		} else { cout << "\n ERROR: Something went wrong with opening the file.\n"; }
	}
}

void TableHeader() {
	cout << "\n===================================================================================================================";
	cout << "\n                   Title                    |      Author      |  Genre  | Year | #Pages |    Publisher    | Price ";
	cout << "\n--------------------------------------------+------------------+---------+------+--------+-----------------+-------\n";
}
void TableEnd() {
	cout << "\n===================================================================================================================\n";
}
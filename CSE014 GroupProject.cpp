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

char AskAnotherOperation();
void UpdateSwitch(int AddChoice);
bool UniqueCheck(string NewISBN);
vector<int> searchWithinFunction(vector<string> vectorname);

// Global Variables // Done to make effective use of functions 
int AmountOfBooks = 0;
char AnotherOperation = 'Y', ConfirmationCheck;

// Vectors containing all the info on the books 
vector<string> BOOKID, TITLE, AUTHOR, GENRE, PUBLISHER, YEAR, PAGES, ORGPRICE, RETAILPRICE, ISBN;
string NewBOOKID, NewTITLE, NewAUTHOR, NewGENRE, NewPUBLISHER, NewYEAR, NewPAGES, NewPRICE, NewISBN;
vector<int> IndexOfSearchedTerm; // Used in Query 

int main() {
	cout << " This is program manages and maintain a database of books in a library.";
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
	}
	else { cout << "\n ERROR: Something went wrong with openining the file\n"; }
	bool NeedSave = 0; // Did the content of file change?, if it did then save

	int PassodeEntered, Passcode = 123;
	bool isAdmin = 0;
	char RunAsAdmin;
	cout << "\n Run Program as Administrator? (Y/N): ";
	cin >> RunAsAdmin;
	if (RunAsAdmin == 'Y') {
		cout << " Enter Admins Code = ";
		cin >> PassodeEntered;
		if (PassodeEntered == Passcode) {
			isAdmin = 1;
		}
		else {
			int Attempts = 3;
			while ((PassodeEntered != Passcode) && (Attempts > 0)) {
				cout << " Incorrect Password: You have " << Attempts << " arrempts left = ";
				cin >> PassodeEntered;
				Attempts--;
			}
			if (Attempts == 0) { cout << "\n Program will run with standard functions only\n"; }
		}
	}
	else { cout << "\n Program will run with standard functions only\n"; }

	// Initialize Variables 
	bool AddChangedData = 1;
	int AtIndex, IDXDel, IDXUpd;
	string SearchForBOOKID;
	vector<string>::iterator iterID;

	while (AnotherOperation == 'Y') {
		// Displays all Starting choices 
		cout << "\n Select by entering the corresponding numbers:\n";
		cout << "\n\t 1.) Search \n";
		cout << "\n\t 2.) Display \n";
		if (isAdmin == 1) {
			cout << "\n\t 3.) Add \n";
			cout << "\n\t 4.) Delete \n";
			cout << "\n\t 5.) Update \n";
			cout << "\n\t 6.) Organize Sale \n";
		}

		int choice = 0, ChoiceUpperBound[2] = { 2,6 }, UpperBound;
		if (isAdmin == 1) { UpperBound = 1; }
		else { UpperBound = 0; }
		cout << "\n Choice: ";
		cin >> choice;
		while ((choice <= 0) || (choice > ChoiceUpperBound[UpperBound])) {
			cout << " ***INVALID INPUT***\n";
			cout << " Try Again: number must be between 1 to " << ChoiceUpperBound[UpperBound];
			cout << " \n Choice: ";
			cin >> choice;
		}

		switch (choice) {
		case 1: // QUERY
			int querychoice;
			cout << "\n Select by entring the corresponding number :\n";
			cout << "\n\t 1: Search by Title \n";
			cout << "\n\t 2: Search by Author \n";
			cout << "\n\t 3: Search by Genre \n";
			cout << "\n\t 4: Search by Publisher \n";
			cout << "\n\t 5: Search by Price \n";
			cout << " Choice: ";
			cin >> querychoice;
			while ((querychoice <= 0) || (querychoice > 7)) {
				cout << " ***INVALID INPUT***\n";
				cout << " Try Again : number must be between 1 to 7 \n";
				cout << " \n Choice; ";
				cin >> querychoice;
			}
			switch (querychoice) {
			case 1: // Checks the TITLE vector if it contains the search term 
				IndexOfSearchedTerm = searchWithinFunction(TITLE);
				break;
			case 2: // Checks the AUTHOR vector if it contains the search term 
				IndexOfSearchedTerm = searchWithinFunction(AUTHOR);
				break;
			case 3: // Checks the GENRE vector if it contains the search term
				IndexOfSearchedTerm = searchWithinFunction(GENRE);
				break;
			case 4: // Checks the Publisher vector if it contains the search term
				IndexOfSearchedTerm = searchWithinFunction(PUBLISHER);
				break;
			case 5: // Display a small MENU with a price range
				int UpperBound, LowerBound;
				cout << "\n\t 1: Price range of 0 to 15\n";
				cout << "\n\t 2: Price range of 16 to 35\n";
				cout << "\n\t 3: Price range of 36 to 50\n";
				cout << "\n\t 4: Price range of 51 to 75\n";
				cout << "\n\t 5: Price range of 76 to 100\n";
				cout << "\n\t 6: Price range of bigger than 100 \n";
				int numberchoice;
				cout << "Choice: ";
				cin >> numberchoice;
				while ((numberchoice <= 0) || (numberchoice >= 6)) {
					cout << "***INVALID INPUT***\n";
					cout << "Try Again : number must be between 1 to 6 \n";
					cin >> numberchoice;
				}
				switch (numberchoice) {
				case 1:
					LowerBound = 0, UpperBound = 15; break;
				case 2:
					LowerBound = 16, UpperBound = 35; break;
				case 3:
					LowerBound = 36, UpperBound = 50; break;
				case 4:
					LowerBound = 51, UpperBound = 75; break;
				case 5:
					LowerBound = 76, UpperBound = 100; break;
				case 6: 
					LowerBound = 101, UpperBound = 100000; break;
				}
				int i = 0;
				for (iterID = RETAILPRICE.begin(); iterID != RETAILPRICE.end(); ++iterID) {
					if ((stof(RETAILPRICE.at(i)) >= LowerBound) && (stof(RETAILPRICE.at(i)) <= UpperBound)) {
						IndexOfSearchedTerm.push_back(i);
					} i++; }
				break;
			}
			TableHeader();
			for (int i = 0, j = 0; i <= (AmountOfBooks - 1); i++) {
				if (IndexOfSearchedTerm.at(j) == i) {
				cout << setw(45) << left << TITLE.at(i);
				cout << setw(18) << right << AUTHOR.at(i);
				cout << setw(10) << right << GENRE.at(i);
				cout << setw(6) << right << YEAR.at(i);
				cout << setw(8) << right << PAGES.at(i);
				cout << setw(20) << right << PUBLISHER.at(i);
				cout << setw(8) << right << RETAILPRICE.at(i);
				cout << endl;
				j++; } }
			TableEnd();
			AskAnotherOperation();
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
			AskAnotherOperation();
			break;

			// Manipulating Data stored in Database
		case 3: // ADD
			NewBOOKID = to_string(stoi(BOOKID.back()) + 1);
			cout << "\t State the Title: ";
			cin >> NewTITLE;
			cout << "\t State the Author: ";
			cin >> NewAUTHOR;
			cout << "\t State the Genre: ";
			cin >> NewGENRE;
			cout << "\t State the Publisher: ";
			cin >> NewPUBLISHER;
			cout << "\t State the Year: ";
			cin >> NewYEAR;
			cout << "\t State the Pages: ";
			cin >> NewPAGES;
			cout << "\t State the Price: ";
			cin >> NewPRICE;
			cout << "\t State the ISBN number: ";
			cin >> NewISBN;
			while (UniqueCheck(NewISBN) == 0) {
				cout << "\n ISBN number is already taken \n";
				cout << "\t Enter a New Number: ";
				cin >> NewISBN;
			}

			TableHeader();
			cout << setw(45) << left << NewTITLE;
			cout << setw(18) << right << NewAUTHOR;
			cout << setw(10) << right << NewGENRE;
			cout << setw(6) << right << NewYEAR;
			cout << setw(8) << right << NewPAGES;
			cout << setw(20) << right << NewPUBLISHER;
			cout << setw(8) << right << NewPRICE;
			TableEnd();

			cout << "\n Confirmation, Is all the Information correct? (Y/N) = ";
			cin >> ConfirmationCheck;
			while (AddChangedData == 1) {
				if (ConfirmationCheck == 'Y') {
					BOOKID.push_back(NewBOOKID);
					TITLE.push_back(NewTITLE);
					AUTHOR.push_back(NewAUTHOR);
					GENRE.push_back(NewGENRE);
					PUBLISHER.push_back(NewPUBLISHER);
					YEAR.push_back(NewYEAR);
					PAGES.push_back(NewPAGES);
					ORGPRICE.push_back(NewPRICE);
					RETAILPRICE.push_back(NewPRICE);
					ISBN.push_back(NewISBN);
					AmountOfBooks++;
					AddChangedData = 0;
				}
				else if (ConfirmationCheck == 'N') {
					int AddChoice;
					cout << "\n\t 1: Change the Title? \n";
					cout << "\n\t 2: Change the Author? \n";
					cout << "\n\t 3: Change the Genre? \n";
					cout << "\n\t 4: Change the Publisher? \n";
					cout << "\n\t 5: Change the Year? \n";
					cout << "\n\t 6: Change the Pages? \n";
					cout << "\n\t 7: Change the Price? \n";
					cout << "\n\t 8: No More Changes? \n";
					cout << "\n Choice: ";
					cin >> AddChoice;
					while ((AddChoice <= 0) || (AddChoice > 8)) {
						cout << " INVALID INPUT\n";
						cout << " Try Again : number must be between 1 to 8 \n";
						cout << " \n Choice; ";
						cin >> AddChoice;
					}
					UpdateSwitch(AddChoice);
				}
				else {
					cout << "\n\t*** INVALID INPUT ***\n";
					cout << " Try Again (Y/N): ";
					cin >> ConfirmationCheck;
				}
			}

			NeedSave = 1;
			AskAnotherOperation();
			break;

		case 4: // DELETE
			AtIndex = 0, IDXDel = 0;
			cout << " \n Enter the BOOKID = ";
			cin >> SearchForBOOKID;
			for (iterID = BOOKID.begin(); iterID != BOOKID.end(); ++iterID) {
				if (BOOKID.at(AtIndex) == SearchForBOOKID) { IDXDel = AtIndex; }
				AtIndex++;
			}

			TableHeader();
			cout << setw(45) << left << TITLE.at(IDXDel);
			cout << setw(18) << right << AUTHOR.at(IDXDel);
			cout << setw(10) << right << GENRE.at(IDXDel);
			cout << setw(6) << right << YEAR.at(IDXDel);
			cout << setw(8) << right << PAGES.at(IDXDel);
			cout << setw(20) << right << PUBLISHER.at(IDXDel);
			cout << setw(8) << right << RETAILPRICE.at(IDXDel);
			TableEnd();

			cout << "\n Confirmation, Do you want procced with deletion? (Y/N) = ";
			cin >> ConfirmationCheck;
			if (ConfirmationCheck == 'Y') {
				BOOKID.erase(BOOKID.begin() + IDXDel);
				TITLE.erase(TITLE.begin() + IDXDel);
				AUTHOR.erase(AUTHOR.begin() + IDXDel);
				GENRE.erase(GENRE.begin() + IDXDel);
				PUBLISHER.erase(PUBLISHER.begin() + IDXDel);
				YEAR.erase(YEAR.begin() + IDXDel);
				PAGES.erase(PAGES.begin() + IDXDel);
				ORGPRICE.erase(ORGPRICE.begin() + IDXDel);
				RETAILPRICE.erase(RETAILPRICE.begin() + IDXDel);
				ISBN.erase(ISBN.begin() + IDXDel);
				AmountOfBooks--;
			}
			else if (ConfirmationCheck == 'N') { cout << "\n\t*** No changes were made ***\n"; }
			else {
				cout << "\n\t INVALID INPUT \n";
				cout << " Try Again (Y/N): ";
				cin >> ConfirmationCheck;
			}
			NeedSave = 1;
			AskAnotherOperation();
			break;

		case 5: // UPDATE
			cout << " \n Enter the BOOKID = ";
			cin >> SearchForBOOKID;
			AtIndex = 0, IDXUpd = 0;
			for (iterID = BOOKID.begin(); iterID != BOOKID.end(); ++iterID) {
				if (BOOKID.at(AtIndex) == SearchForBOOKID) { IDXUpd = AtIndex; }
				AtIndex++;
			}
			TableHeader();
			cout << setw(45) << left << TITLE.at(IDXUpd);
			cout << setw(18) << right << AUTHOR.at(IDXUpd);
			cout << setw(10) << right << GENRE.at(IDXUpd);
			cout << setw(6) << right << YEAR.at(IDXUpd);
			cout << setw(8) << right << PAGES.at(IDXUpd);
			cout << setw(20) << right << PUBLISHER.at(IDXUpd);
			cout << setw(8) << right << RETAILPRICE.at(IDXUpd);
			TableEnd();

			int UpdChoice;
			cout << "\n\t 1: Change the Title? \n";
			cout << "\n\t 2: Change the Author? \n";
			cout << "\n\t 3: Change the Genre? \n";
			cout << "\n\t 4: Change the Publisher? \n";
			cout << "\n\t 5: Change the Year? \n";
			cout << "\n\t 6: Change the Pages? \n";
			cout << "\n\t 7: Change the Price? \n";
			cout << "\n\t 8: No More Changes? \n";
			cout << "\n Choice: ";
			cin >> UpdChoice;
			while ((UpdChoice <= 0) || (UpdChoice > 8)) {
				cout << " INVALID INPUT\n";
				cout << " Try Again : number must be between 1 to 8 \n";
				cout << " \n Choice; ";
				cin >> UpdChoice;
			}
			UpdateSwitch(UpdChoice);

			NeedSave = 1;
			AskAnotherOperation();
			break;

		case 6: // ORGANIZE SALE
			// Something like 20& off for all fantasy books 
			NeedSave = 1;
			AskAnotherOperation();
			break;
		}
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
		}
		else { cout << "\n ERROR: Something went wrong with opening the file.\n"; }
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
char AskAnotherOperation() {
	cout << "\n Perform another operation? (Y/N) = ";
	cin >> AnotherOperation;
	return AnotherOperation;
}

void UpdateSwitch(int AddChoice) {
	switch (AddChoice) {
	case 1: // CHANGE TITLE
		cout << "Change the Title to = ";
		cin >> NewTITLE;
		break;
	case 2: // CHANGE AUTHOR
		cout << "Change the Author to = ";
		cin >> NewAUTHOR;
		break;
	case 3: // CHANGE GENRE
		cout << "Change the Genre to = ";
		cin >> NewGENRE;
		break;
	case 4: // CHANGE PUBLISHER
		cout << "Change the Publisher to = ";
		cin >> NewPUBLISHER;
		break;
	case 5: // CHANGE YEAR
		cout << "Change the Year to = ";
		cin >> NewYEAR;
		break;
	case 6: // CHANGE PAGES
		cout << "Change the Pages to = ";
		cin >> NewPAGES;
		break;
	case 7: // CHANGE PRICES 
		cout << "Change the Price to = ";
		cin >> NewPRICE;
		break;
	case 8: // NO MORE CHANGES
		ConfirmationCheck = 'Y';
		break;
	}
}

bool UniqueCheck(string NewISBN) {
	bool IsUnique = 1;
	vector<string>::iterator iterISBNunique;

	int i = 0;
	for (iterISBNunique = BOOKID.begin(); iterISBNunique != BOOKID.end(); ++iterISBNunique) {
		if (BOOKID.at(i) == NewISBN) {
			IsUnique = 0;
			i++;
		}
	}
	return IsUnique;
}

vector<int> searchWithinFunction(vector<string> vectorname) {
	vector<int> IndexOfSearchedTerm;
	vector<string>::iterator iter;

	string SearchTerm;
	cout << " Type the term you want to search for: ";
	cin >> SearchTerm;

	int i = 0;
	for (iter = vectorname.begin(); iter != vectorname.end(); ++iter) {
		if (vectorname.at(i) == SearchTerm) { IndexOfSearchedTerm.push_back(i); }
		i++;
	}
	return IndexOfSearchedTerm;
}


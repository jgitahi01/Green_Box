#include "Loans.h"

int Loans::FindLoanByID(string id) {
	int location = -1;
	for (int i = 0; i < loans.size(); ++i) {
		if (loans.at(i).GetLoanID() == id) {
			location = i;
		}
	}
	return location;
}

int Loans::FindLoanByName(string name) {
	int location = -1;
	for (int i = 0; i < loans.size(); ++i) {
		if (loans.at(i).GetLoanCustomerID() == name) {
			location = i;
		}
		if (loans.at(i).GetLoanCustomerName() == name) {
			location = i;
		}
	}
	return location;
}

int Loans::FindLoanByMovie(string name) {
	int location = -1;
	for (int i = 0; i < loans.size(); ++i) {
		if (loans.at(i).GetLoanMovieID() == name) {
			location = i;
		}
		if (loans.at(i).GetLoanMovieName() == name) {
			location = i;
		}
	}
	return location;
}

void Loans::AddLoan(Customer l_customer, Movie l_movie) {
	Loan tempLoan;
	bool loopcheck = true;
	char stat = 'O';
	tempLoan.SetMovie(l_movie);
	tempLoan.SetCustomer(l_customer);
	tempLoan.SetStatus(stat);
	tempLoan.SetDueSeconds();
	tempLoan.SetDueTime();
	tempLoan.SetDueDate();

	srand(time(NULL));
	while (loopcheck) {
		int tempID = 10000000 + rand() % 90000000;
		string convtempID = to_string(tempID);
		if (FindLoanByID(convtempID) == -1) {
			tempLoan.SetLoanID(convtempID);
			break;
		}
	}
	tempLoan.SetCustomerCharge(l_movie.GetRentalCost());
	loans.push_back(tempLoan);
}

string Loans::DeleteLoan() {
	string t_remove;
	string to_return = "\0";
	cout << "TYPE THE LOAN ID TO REMOVE: ";
	getline(cin, t_remove);
	if (FindLoanByID(t_remove) == -1) {
		cout << "THE LOAN DOES NOT EXIST." << endl;
	}
	else {
		int location;
		location = FindLoanByID(t_remove); 
		cout << "LOAN " << loans.at(location).GetLoanID() << " HAS BEEN REMOVED." << endl;
		to_return = loans.at(location).GetLoanCustomerID();
		loans.erase(loans.begin() + location);
	}
	return to_return;
}

// This function checks each loans due time
void Loans::CheckLoans() {
	time_t check;
	check = time(NULL); // gets the current time in seconds
	int timecheck = check;
	int charge;
	for (int i = 0; i < loans.size(); ++i) {
		if (loans.at(i).GetDueSeconds() <= timecheck) {
			loans.at(i).SetStatus('o');
			charge = timecheck - loans.at(i).GetDueSeconds();
			charge /= 86400;
			//charge /= 60; test with 60 seconds, 1 min
			if (charge > 0) {
				float tocharge = charge;
				loans.at(i).SetChargeOnLoan(tocharge);
				//loans.at(i).SetDueSeconds(); dont uncomment
			}
			else {
				continue;
			}
		}
	}
}

void Loans::PrintLoans() {
	for (int i = 0; i < loans.size(); ++i) {
		loans.at(i).PrintLoan();
		cout << endl;
	}
}

void Loans::PrintActiveLoans() {
	for (int i = 0; i < loans.size(); ++i) {
		if (loans.at(i).GetStatus() == "Out") {
			loans.at(i).PrintLoan();
			cout << endl;
		}
	}
	cout << endl;
}

void Loans::PrintCompleteLoans() {
	for (int i = 0; i < loans.size(); ++i) {
		if (loans.at(i).GetStatus() == "In") {
			loans.at(i).PrintLoan();
			cout << endl;
		}
	}
	cout << endl;
}

void Loans::PrintLostOvLoans() {
	for (int i = 0; i < loans.size(); ++i) {
		if (loans.at(i).GetStatus() == "Overdue" || loans.at(i).GetStatus() == "Lost") {
			loans.at(i).PrintLoan();
			cout << endl;
		}
	}
	cout << endl;
}

void Loans::PrintLoansForMovie(string movie) {
	for (int i = 0; i < loans.size(); ++i) {
		if (loans.at(i).GetLoanMovieID() == movie || loans.at(i).GetLoanMovieName() == movie) {
			loans.at(i).PrintLoan();
			cout << endl;
		}
	}
	cout << endl;
}

void Loans::PrintLoansForCustomer(string customer) {
	for (int i = 0; i < loans.size(); ++i) {
		if (loans.at(i).GetLoanCustomerID() == customer || loans.at(i).GetLoanCustomerName() == customer) {
			loans.at(i).PrintLoan();
			cout << endl;
		}
	}
	cout << endl;
}

int Loans::CheckOverdueLoansForCustomer(string customer) {
	int overdue = 0;
	for (int i = 0; i < loans.size(); ++i) {
		if (loans.at(i).GetLoanCustomerID() == customer || loans.at(i).GetLoanCustomerName() == customer) {
			if (loans.at(i).GetStatus() == "Overdue") {
				overdue++;
			}
		}
	}
	cout << endl;

	return overdue;
}

void Loans::EditLoan() {
	string t_remove;
	cout << "TYPE THE LOAN ID TO EDIT: ";
	getline(cin, t_remove);
	if (FindLoanByID(t_remove) == -1) {
		cout << "THE LOAN DOES NOT EXIST." << endl;
	}
	else {
		int location = FindLoanByID(t_remove);
		string choice;
		cout << "WHAT DO YOU WISH TO CHANGE: " << endl;
		cout << "1. CHANGE STATUS (ADMIN)" << endl;
		cin >> choice;
		if (choice == "1") {
			string mid;
			cout << "ENTER NEW STATUS";
			cout << "1. OVERDUE" << endl;
			cout << "2. OUT" << endl;
			cout << "3. IN" << endl;
			cout << "4. LOST" << endl;
			cin >> mid;
			if (mid == "1") {
				loans.at(location).SetStatus('o');
			}
			else if (mid == "2") {
				loans.at(location).SetStatus('O');
			}
			else if (mid == "3") {
				loans.at(location).SetStatus('i');
			}
			else if (mid == "4") {
				loans.at(location).SetStatus('l');
			}
			else {
				cout << "INVALID SELECTION, TRY AGAIN" << endl;
			}
		}
	}
}

void Loans::PrintALoan() {
	string t_remove;
	cout << "TYPE THE LOAN ID TO DISPLAY: ";
	getline(cin, t_remove);
	if (FindLoanByID(t_remove) == -1) {
		cout << "THE LOAN DOES NOT EXIST." << endl;
	}
	else {
		int location = FindLoanByID(t_remove);
		loans.at(location).PrintLoan();
	}
}

string Loans::ReportLostMovie() {
	string ID;
	string to_return= "\0";
	cout << "YOU WILL BE CHARGED A REPLACEMENT COST FOR THE MOVIE." << endl;
	cout << "ENTER THE LOAN ID FOR THE LOST MOVIE: ";
	cin >> ID;
	if (FindLoanByID(ID) == -1) {
		cout << "THE LOAN DOES NOT EXIST." << endl;
	}
	else {
		int location = FindLoanByID(ID);
		loans.at(location).SetStatus('l');
		cout << "YOU HAVE BEEN CHARGED $" << loans.at(location).GetMovie().GetReplacementCost() << " FOR MOVIE REPLACEMENT" << endl;
		loans.at(location).SetChargeOnLoan(loans.at(location).GetMovie().GetReplacementCost());
		to_return = loans.at(location).GetLoanCustomerID();
	}
	return to_return;
}

string Loans::ReturnMovie() {
	string t_remove;
	string to_return = "\0";
	cout << "TYPE THE LOAN ID TO RETURN: ";
	getline(cin, t_remove);
	if (FindLoanByID(t_remove) == -1) {
		cout << "THE LOAN DOES NOT EXIST." << endl;
	}
	else {
		int location;
		location = FindLoanByID(t_remove); 
		cout << "MOVIE " << loans.at(location).GetLoanMovieName() << " HAS BEEN RETURNED." << endl;
		to_return = loans.at(location).GetLoanCustomerID();
		loans.at(location).SetStatus('i');
	}
	return to_return;
}

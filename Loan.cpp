#include "Loan.h"

void Loan::SetStatus(char status) {
	if (status == 'o') {
		Status = "Overdue";
	}
	if (status == 'O') {
		Status = "Out";
	}
	if (status == 'i') {
		Status = "In";
	}
	if (status == 'l') {
		Status = "Lost";
	}
}

void Loan::SetDueDate() {
	time_t duetime;
	duetime = time(NULL);
	tm *tm_local = localtime(&duetime);
	int month = tm_local->tm_mon + 1;
	int day = tm_local->tm_mday + 1;
	int year = 1900 + tm_local->tm_year;
	dueDate = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

void Loan::SetDueTime() {
	time_t duetime;
	duetime = time(NULL);
	tm *tm_local = localtime(&duetime);
	int min = tm_local->tm_min;
	int hour = tm_local->tm_hour;
	dueTime = to_string(hour) + ":" + to_string(min);
}

void Loan::SetDueSeconds() {
	time_t duetime;
	duetime = time(NULL);
	t_seconds = duetime + 86400;
	//t_seconds = duetime + 60;
}

void Loan::PrintLoan() {
	cout << "LOAN ID: " << loanid << endl;
	cout << "CUSTOMER ID: " << loan_customer.GetCustomerID() << endl;
	cout << "CUSTOMER NAME: " << loan_customer.GetCustomerName() << endl;
	cout << "MOVIE ID: " << loan_movie.GetMovieID() << endl;
	cout << "MOVIE TITLE: " << loan_movie.GetTitle() << endl;
	cout << "DUE DATE: " << dueDate << endl;
	cout << "DUE TIME: " << dueTime << endl;
	cout << "STATUS: " << Status << endl;
	cout << "CREDIT CARD CHARGE (TOTAL): $" << chargeOnLoan + m_charge << endl;
	if (Status == "Overdue") {
		cout << "OVERDUE CHARGE: $" << chargeOnLoan << endl;
	}
	else if (Status == "Lost") {
		cout << "CHARGE: $" << chargeOnLoan << endl;
	}
	else {
		cout << "NO OVERDUE CHARGE ON LOAN" << endl;
	}
	
}

void Loan::SetChargeOnLoan(float charge) {
	chargeOnLoan = charge;
}
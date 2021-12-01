#include <iostream>
#include "Customers.h"
#include "Movies.h"
#include <ctime>
using namespace std;

class Loan {
	private:
		string loanid;
		Movie loan_movie;
		Customer loan_customer;
		string dueDate;
		string dueTime;
		int t_seconds;
		string Status;
		float chargeOnLoan = 0;
		float m_charge = 0;
	public:
		void SetLoanID(string id) {loanid = id;}
		string GetLoanID() {return loanid;}
		void SetMovie(Movie movie) {loan_movie = movie;}
		string GetLoanMovieID() {return loan_movie.GetMovieID();}
		string GetLoanMovieName() {return loan_movie.GetTitle();}
		void SetCustomer(Customer customer) {loan_customer = customer;}
		string GetLoanCustomerID() {return loan_customer.GetCustomerID();}
		string GetLoanCustomerName() {return loan_customer.GetCustomerName();}
		void SetDueDate();
		string GetDueDate() {return dueDate;}
		void SetDueTime();
		string GetDueTime() {return dueTime;}
		void SetDueSeconds();
		int GetDueSeconds() {return t_seconds;}
		void SetStatus(char status);
		string GetStatus() {return Status;}
		void PrintLoan();

		Movie GetMovie() {return loan_movie;}

		void SetChargeOnLoan(float charge);
		float GetChargeOnLoan() {return chargeOnLoan;}

		void SetCustomerCharge(float charge) {m_charge += charge;}
		float GetCustomerCharge() {return m_charge;}

		
};
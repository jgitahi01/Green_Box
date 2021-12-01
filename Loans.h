#include "Loan.h"
#include <vector>

class Loans {
	private:
		vector<Loan> loans;
	public:
		void AddLoan(Customer l_customer, Movie l_movie);
		void EditLoan();
		string DeleteLoan();// deletes a loan
		string ReturnMovie(); // returns a movie
		int FindLoanByID(string id); // returns the location of the loan in the vector or -1
		int FindLoanByName(string name);// 
		int FindLoanByMovie(string movie);//
		void PrintLoans();// prints all loans
		void PrintALoan();
		void PrintLoansForMovie(string movie); //-
		void PrintLoansForCustomer(string customer); //-
		void PrintActiveLoans();//
		void PrintCompleteLoans();//
		void PrintLostOvLoans();//
		void CheckLoans(); // 
		int CheckOverdueLoansForCustomer(string customer);

		string ReportLostMovie();
};
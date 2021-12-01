#include <iostream>
#include <string>
using namespace std;

class Customer {
	private:
		string customerID;
		string creditCardNo;
		string customerName;
		int expirationDay, expirationMonth, expirationYear;// date
		string validationKey; // validation key
		int numberofMovies; // number of movies loaned
	public:
		//All these functions have their implementations in the same line
		void SetCustomerID(string ID) {customerID = ID;}
		string GetCustomerID() {return customerID;}
		void SetCustomerName(string Name) {customerName = Name;}
		string GetCustomerName() {return customerName;}
		void SetCreditCardNo(string creditCardNumber) {creditCardNo = creditCardNumber;}
		void SetCreditCardValidationKey(string Key) {validationKey = Key;}
		void SetExpDate(int expDay, int expMonth, int expYear);
		string GetExpDate();
		void SetNumberofMovies(int nmovies) {numberofMovies = nmovies;}
		void AddMovie(int s) {
			numberofMovies = numberofMovies + s;
		}
		int GetNumberofMovies() {return numberofMovies;}
		void printCustomer();
};

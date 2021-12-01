#include "Customer.h"

// accesors and mutators for customer
void Customer::SetExpDate(int expDay, int expMonth, int expYear) {
	expirationDay = expDay;
	expirationMonth = expMonth;
	expirationYear = expYear;
}

string Customer::GetExpDate() {
	string expDate = to_string(expirationMonth) + "/" + to_string(expirationDay) + "/" + to_string(expirationYear);
	return expDate;
}

void Customer::printCustomer() {
	cout << "Name: " << customerName << endl;
	cout << "ID: " << customerID << endl;
	cout << "Number of Active Movies: " << numberofMovies << endl;
}
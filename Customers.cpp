#include "Customers.h"

void Customers::AddMovieToCustomer(string ID, int m) { //Adds a movie to the customer
	int found = -1; // check
	for (int i = 0; i < customers.size(); ++i) {
		if (customers.at(i).GetCustomerID() == ID) {
			found = i;
			break;
		}
	}
	if (found != -1) { // if the customer is found add m to their number of movies
		customers.at(found).AddMovie(m);
	}
	
}

Customer Customers::FindCustomerByIDC(string ID) {
	int found = 0;
	for (int i = 0; i < customers.size(); ++i) {
		if (customers.at(i).GetCustomerID() == ID) {
			found = i;
			break;
		}
	}
	return customers.at(found); // returns the customer in the vector, will always be run if the customer is actually there. 
}

Customer Customers::FindCustomerByNameC(string ID) {
	int found = 0;
	for (int i = 0; i < customers.size(); ++i) {
		if (customers.at(i).GetCustomerID() == ID) {
			found = i;
		}
	}
	return customers.at(found);
}

int Customers::FindCustomerByID(string ID) {
	int found = -1;
	for (int i = 0; i < customers.size(); ++i) {
		if (customers.at(i).GetCustomerID() == ID) {
			found = i;
		}
	}

	return found;
}

int Customers::FindCustomerByName(string name) {
	int found = -1;
	for (int i = 0; i < customers.size(); ++i) {
		if (customers.at(i).GetCustomerName() == name) {
			found = i;
		}
	}
	
	return found;
}

void Customers::PrintCustomers() {
	for (int i = 0; i < customers.size(); ++i) {
		cout << "CUSTOMER " << i+1 << endl;
		customers.at(i).printCustomer();
		cout << endl;
	}
}

void Customers::AddCustomer() {
	Customer tempCustomer;
	int t_customerID;
	string t_creditCardNo;
	string t_customerName;
	int t_expirationDay, t_expirationMonth, t_expirationYear;
	string t_validationKey;
	int t_nmovies = 0;
	bool loopcheck = true;
	//This loop gets user input from user
	while (loopcheck) {
		cout << "ENTER CUSTOMER NAME: ";
		getline(cin, t_customerName);
		if (t_customerName.size() > 40) {
			cout << "YOU HAVE REACH THE CHARACTER LIMIT OF 40." << endl;
		}
		else {
			break;
		}
	}
	while (loopcheck) {
		cout << "ENTER CREDIT CARD NUMBER (12 DIGITS): ";
		cin >> t_creditCardNo;
		if (t_creditCardNo.size() != 12) {
			cout << "PLEASE ENTER 12 DIGITS." << endl;
		}
		else {
			for (int i = 0; i < 12; ++i) {
				if (!isdigit(t_creditCardNo.at(i))) {
					cout << "ENTER NUMERICAL VALUES ONLY." << endl;
					break;
				}
			}
			break;
		}
	}
	cout << "ENTER THE EXPIRATION DATE AS (MM DD YYYY): ";
	cin >> t_expirationMonth >> t_expirationDay >> t_expirationYear;
	while (loopcheck) {
		cout << "ENTER THE 3 DIGIT VALIDATION KEY: ";
		cin >> t_validationKey;
		if (t_validationKey.size() != 3) {
			cout << "PLEASE ENTER 3 DIGITS." << endl;
		}
		else {
			for (int i = 0; i < 3; ++i) {
				if (!isdigit(t_validationKey.at(i))) {
					cout << "ENTER NUMERICAL VALUES ONLY." << endl;
					break;
				}
			}
			break;
		}
	}
	cout << endl;
	srand(time(NULL));
	while (loopcheck) {
		int tempID = 100000 + rand() % 900000;
		string convtempID = to_string(tempID);
		if (FindCustomerByID(convtempID) == -1) {
			tempCustomer.SetCustomerID(convtempID);
			break;
		}
	}
	// Setting all the user inputted data into customer
	tempCustomer.SetCustomerName(t_customerName);
	tempCustomer.SetCreditCardNo(t_creditCardNo);
	tempCustomer.SetNumberofMovies(t_nmovies);
	tempCustomer.SetCreditCardValidationKey(t_validationKey);
	tempCustomer.SetExpDate(t_expirationDay, t_expirationMonth, t_expirationYear);
	
	customers.push_back(tempCustomer); //Adding that customer to the vector
}

void Customers::DeleteCustomer() {
	string t_remove;
	cout << "TYPE THE ID OR NAME OF THE CUSTOMER YOU WANT TO REMOVE: ";
	getline(cin, t_remove);
	if (FindCustomerByName(t_remove) == -1 && FindCustomerByID(t_remove) == -1) {
		cout << "THE CUSTOMER DOES NOT EXIST." << endl;
	}
	else {
		int location;
		if (FindCustomerByName(t_remove) != -1) {
			location = FindCustomerByName(t_remove); 
		}
		else if (FindCustomerByID(t_remove) != -1) {
			location = FindCustomerByID(t_remove);
		}
		cout << customers.at(location).GetCustomerName() << " HAS BEEN REMOVED." << endl;
		customers.erase(customers.begin() + location);
	}
	cout << endl;

}

void Customers::EditCustomer() {
	string t_edit;
	cout << "ENTER THE ID OR NAME OF THE CUSTOMER YOU WANT TO EDIT: ";
	getline(cin, t_edit);
	bool loopcheck = true;
	if (FindCustomerByName(t_edit) == -1 && FindCustomerByID(t_edit) == -1) {
		cout << "THE CUSTOMER DOES NOT EXIST." << endl;
	}
	else {
		int location;
		if (FindCustomerByName(t_edit) != -1) {
			location = FindCustomerByName(t_edit); 
		}
		else if (FindCustomerByID(t_edit) != -1) {
			location = FindCustomerByID(t_edit);
		}
		while (loopcheck) {
			char choice;
			cout << "WHAT ATTRUBUTE DO YOU WISH TO CHANGE." << endl;
			cout << "1. NAME" << endl;
			cout << "2. CREDIT CARD INFO" << endl;
			cout << "3. GO BACK" << endl;
			cin >> choice;
			if (choice == '1') {
				cin.ignore();
				string tempName;
				while (loopcheck) {
					cout << "ENTER NEW NAME FOR " << customers.at(location).GetCustomerName() << ": ";
					getline(cin, tempName);
					if (tempName.size() > 40) {
						cout << "YOU HAVE REACH THE CHARACTER LIMIT OF 40." << endl;
					}
					else {
						break;
					}
				}
				customers.at(location).SetCustomerName(tempName);
			}
			else if (choice == '2') {
				string t_creditCardNo;
				int t_expirationDay, t_expirationMonth, t_expirationYear;
				string t_validationKey;
				while (loopcheck) {
					cout << "ENTER CREDIT NEW CARD NUMBER (12 DIGITS): ";
					cin >> t_creditCardNo;
					if (t_creditCardNo.size() != 12) {
						cout << "PLEASE ENTER 12 DIGITS." << endl;
					}
					else {
						for (int i = 0; i < 12; ++i) {
							if (!isdigit(t_creditCardNo.at(i))) {
								cout << "ENTER NUMERICAL VALUES ONLY." << endl;
								break;
							}
						}
						break;
					}
				}
				cout << "ENTER THE EXPIRATION DATE AS (MM DD YYYY): ";
				cin >> t_expirationMonth >> t_expirationDay >> t_expirationYear;
				while (loopcheck) {
					cout << "ENTER THE 3 DIGIT VALIDATION KEY: ";
					cin >> t_validationKey;
					if (t_validationKey.size() != 3) {
						cout << "PLEASE ENTER 3 DIGITS." << endl;
					}
					else {
						for (int i = 0; i < 3; ++i) {
							if (!isdigit(t_validationKey.at(i))) {
								cout << "ENTER NUMERICAL VALUES ONLY." << endl;
								break;
							}
						}
						break;
					}
				}
				customers.at(location).SetExpDate(t_expirationDay, t_expirationMonth, t_expirationYear);
				customers.at(location).SetCreditCardNo(t_creditCardNo);
				customers.at(location).SetCreditCardValidationKey(t_validationKey);
				break;
			}
			else if (choice == '3') {
				break;
			}
			else {
				cout << "INVALID SELECTION." << endl;
			}
		}
		
	}
	cout << endl;
}

void Customers::PrintACustomer() {
	string t_display;
	cout << "ENTER THE ID OR NAME OF THE CUSTOMER YOU WANT TO DISPLAY: ";
	getline(cin, t_display);
	if (FindCustomerByName(t_display) == -1 && FindCustomerByID(t_display) == -1) {
		cout << "THE CUSTOMER DOES NOT EXIST." << endl;
	}
	else {
		int location;
		if (FindCustomerByName(t_display) != -1) {
			location = FindCustomerByName(t_display); 
		}
		else if (FindCustomerByID(t_display) != -1) {
			location = FindCustomerByID(t_display);
		}
		
		customers.at(location).printCustomer();
		cout << endl;
	}
}

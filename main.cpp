/*	Author: Justin Mariki (justinmariki@my.unt.edu)
 	Date: 11/16/2021
 	Instructor: Asif Baba
 	Description: This is a Walmart RedBox rip-off, it stores loans, Customers
	and movies and stores their values.
*/

#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <iomanip>
#include "Loans.h" // We include Loans.h, its the bridge to all our header files

using namespace std;

int main() {
	// Creating collection entities for our variables
	Customers GreenBoxCustomers;
	Loans GreenBoxLoans;
	Movies GreenBoxMovies; 

	// INPUT FILE READ WILL GO HERE
	
    cout << "WELCOME TO GREEN BOX. THE NUMBER 1 MOVIE RENTAL SERVICE." << endl;
	bool loop1 = true;
	// Loop for main menu
	while (loop1) {
		char choice1;
		cout << "SELECT AN OPTION." << endl;
		cout << "1. CUSTOMERS" << endl;
		cout << "2. MOVIES" << endl;
		cout << "3. LOANS" << endl;
		cout << "4. QUIT" << endl;
		cin >> choice1;
		cout << endl;

		if (choice1 == '1') {
			bool loop2 = true;
			char choice2;
			cout << "YOU HAVE SELECTED CUSTOMERS" << endl;
			while (loop2) {
				cout << "CUSTOMER MENU. SELECT AN OPTION." << endl;
				cout << "1. ADD CUSTOMER" << endl;
				cout << "2. REMOVE CUSTOMER" << endl;
				cout << "3. EDIT CUSTOMER" << endl;
				cout << "4. DISPLAY ALL CUSTOMERS" << endl;
				cout << "5. DISPLAY A CUSTOMER" << endl;
				cout << "6. GO BACK" << endl;
				cin >> choice2;
				cout << endl;
				cin.ignore(); // avoiding cin to getline error

				if (choice2 == '1') {
					GreenBoxCustomers.AddCustomer(); // runs the function in customers.cpp
				}
				else if (choice2 == '2') {
					GreenBoxCustomers.DeleteCustomer(); // runs the function in customers.cpp
				}
				else if (choice2 == '3') {
					GreenBoxCustomers.EditCustomer(); // runs the function in customers.cpp
				} 
				else if (choice2 == '4') {
					GreenBoxCustomers.PrintCustomers(); // runs the function in customers.cpp
				}
				else if (choice2 == '5') {
					GreenBoxCustomers.PrintACustomer(); // runs the function in customers.cpp
				}
				else if (choice2 == '6') {
					break; // exits customer loop
				}
				else {
					cout << "INVALID CHOICE\n" << endl; 
				}
			}
		}
		else if (choice1 == '2') {
			bool loop3 = true;
			char choice3;
			cout << "YOU HAVE SELECTED MOVIES" << endl;
			while (loop3) {
				cout << "MOVIE MENU. SELECT AN OPTION." << endl;
				cout << "1. ADD MOVIE" << endl;
				cout << "2. REMOVE MOVIE" << endl;
				cout << "3. EDIT MOVIE" << endl;
				cout << "4. DISPLAY ALL MOVIES" << endl;
				cout << "5. DISPLAY A MOVIE" << endl;
				cout << "6. GO BACK" << endl;
				cin >> choice3;
				cout << endl;
				cin.ignore();
				// running fuctions in movies.cpp
				if (choice3 == '1') {
					GreenBoxMovies.AddMovie();
				}
				else if (choice3 == '2') {
					GreenBoxMovies.DeleteMovie();
				}
				else if (choice3 == '3') {
					GreenBoxMovies.EditMovie();
				} 
				else if (choice3 == '4') {
					GreenBoxMovies.PrintMovies();
				}
				else if (choice3 == '5') {
					GreenBoxMovies.PrintAMovie();
				}
				else if (choice3 == '6') {
					break;
				}
				else {
					cout << "INVALID CHOICE\n" << endl; 
				}
			}
		}
		else if (choice1 == '3') {
			bool loop4 = true;
			string choice4;
			cout << "YOU HAVE SELECTED LOANS" << endl;
			while (loop4) {
				GreenBoxLoans.CheckLoans(); // This checks all loans for overdue loans, timee
				cout << "LOAN MENU. SELECT AN OPTION." << endl;
				cout << "1.  ADD LOAN" << endl;
				cout << "2.  REMOVE LOAN" << endl;
				cout << "3.  EDIT LOAN" << endl;
				cout << "4.  DISPLAY ALL LOANs" << endl;
				cout << "5.  DISPLAY A LOAN" << endl;
				cout << "6.  DISPLAY LOANS FOR A CUSTOMER" << endl;
				cout << "7.  DISPLAY LOANS FOR A MOVIE" << endl;
				cout << "8.  DISPLAY ALL ACTIVE LOANS" << endl;
				cout << "9.  DISPLAY ALL OVERDUE OR LOST LOANS" << endl;
				cout << "10. DISPLAY ALL COMPLETE LOANS" << endl;
				cout << "11. REPORT A LOST MOVIE" << endl;
				cout << "12. RETURN A MOVIE" << endl;
				cout << "13. GO BACK" << endl;
				cin >> choice4;
				cout << endl;
				cin.ignore();

				if (choice4 == "1") {
					string c_toadd;
					string m_toadd;
					cout << "ENTER CUSTOMER ID: ";
					getline(cin, c_toadd); 
					//checks to see if id is in the system
					if (GreenBoxCustomers.FindCustomerByID(c_toadd) == -1) {
						cout << "CUSTOMER DOES NOT EXIST SIGN UP FIRST" << endl; 
					}
					else {
						bool loopchecker = true;
						// checks if the customer has more than 2 movies loaned
						if (GreenBoxCustomers.FindCustomerByIDC(c_toadd).GetNumberofMovies() == 2) {
							cout << "YOU HAVE TOO MANY MOVIES RETURN ONE TO RENT AGAIN." << endl;
							loopchecker = false;
						}
						// checks to see if the customer has any overdue movies
						else if (GreenBoxLoans.CheckOverdueLoansForCustomer(c_toadd) > 0) {
							cout << "YOU HAVE OVERDUE LOANS RETURN THEM OR REPORT THEM AS LOST" << endl;
							loopchecker = false;
						}
						else {
							while (loopchecker) {
								cout << "ENTER MOVIE ID TO LOAN: ";
								getline(cin, m_toadd);
								if (GreenBoxMovies.FindMovieByID(m_toadd) == -1) {
									cout << "MOVIE DOES NOT EXIST" << endl;
								}
								else {
									GreenBoxCustomers.AddMovieToCustomer(c_toadd, 1); // add the movie to the movies loaned variable in customers
									GreenBoxLoans.AddLoan(GreenBoxCustomers.FindCustomerByIDC(c_toadd), GreenBoxMovies.FindMovieByIDC(m_toadd));// adds the loan
									break;
								}
							
							}
						}
						cout << endl;
						
						
					}
				}
				else if (choice4 == "2") {
					GreenBoxCustomers.AddMovieToCustomer(GreenBoxLoans.DeleteLoan(), -1); // deletes loan and removes it from the customer
				}
				else if (choice4 == "3") {
					GreenBoxLoans.EditLoan();
				} 
				else if (choice4 == "4") {
					GreenBoxLoans.PrintLoans();
				}
				else if (choice4 == "5") {
					GreenBoxLoans.PrintALoan();
				}
				else if (choice4 == "6") {
					string c_toprint;
					cout << "ENTER CUSTOMER NAME OR ID TO DISPLAY: ";
					getline(cin, c_toprint);
					if (GreenBoxCustomers.FindCustomerByID(c_toprint) == -1 && GreenBoxCustomers.FindCustomerByName(c_toprint) == -1) {
						cout << "CUSTOMER DOES NOT EXIST" << endl; 
					}
					else {
						GreenBoxLoans.PrintLoansForCustomer(c_toprint);
					}
				}	
				else if (choice4 == "7") {
					string m_toprint;
					cout << "ENTER MOVIE TITLE OR ID TO DISPLAY: ";
					getline(cin, m_toprint);
					if (GreenBoxMovies.FindMovieByID(m_toprint) == -1 && GreenBoxMovies.FindMovieByTitle(m_toprint) == -1) {
						cout << "CUSTOMER DOES NOT EXIST" << endl; 
					}
					else {
						GreenBoxLoans.PrintLoansForMovie(m_toprint);
					}
				}
				else if (choice4 == "8") {
					GreenBoxLoans.PrintActiveLoans();
				}
				else if (choice4 == "9") {
					GreenBoxLoans.PrintLostOvLoans();
				}
				else if (choice4 == "10") {
					GreenBoxLoans.PrintCompleteLoans();
				}
				else if (choice4 == "11") {
					GreenBoxCustomers.AddMovieToCustomer(GreenBoxLoans.ReportLostMovie(), -1);
				}
				else if (choice4 == "12") {
					GreenBoxCustomers.AddMovieToCustomer(GreenBoxLoans.ReturnMovie(), -1);
				}
				else if (choice4 == "13") {
					break;
				}
				else {
					cout << "INVALID CHOICE\n" << endl; 
				}
			}
		}
		else if (choice1 == '4') {
			cout << "THANK YOU FOR USING GREEN BOX" << endl;
			break;
		}
		else {
			cout << "INVALID CHOICE.\n" << endl; 
		}


	}
	// OUTPUT TO FILE SHOULD GO HERE
	return 0;
} 
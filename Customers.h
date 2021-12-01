#include "Customer.h"
#include <vector>
#include <time.h>

class Customers {
	private:
		vector<Customer> customers; // vector of customers
	public:
		void AddCustomer(); // adds a customer to vector
		void EditCustomer(); // removes a customer from vector
		void DeleteCustomer();
		int FindCustomerByName(string name);
		Customer FindCustomerByNameC(string name);
		int FindCustomerByID(string ID);
		Customer FindCustomerByIDC(string ID);
		void AddMovieToCustomer(string ID, int m);
		void PrintCustomers();
		void PrintACustomer();
};

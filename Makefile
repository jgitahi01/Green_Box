GreenBox: main.o Customer.o Customers.o Movie.o Movies.o Loan.o Loans.o
	g++ main.o Customer.o Customers.o Movie.o Movies.o Loan.o Loans.o -o GreenBox

Customer.o: Customer.h Customer.cpp
	g++ -c Customer.cpp

Customers.o: Customer.h Customers.h Customer.cpp Customers.cpp
	g++ -c Customers.cpp

Movie.o: Movie.h Movie.cpp
	g++ -c Movie.cpp

Movies.o: Movie.h Movies.h Movie.cpp Movies.cpp
	g++ -c Movies.cpp

Loan.o: Customers.h Movies.h Loan.h Loan.cpp
	g++ -c Loan.cpp

Loans.o: Loan.h Loans.h Loan.cpp Loans.cpp
	g++ -c Loans.cpp

main.o: Loans.h Movies.h Customers.h
	g++ -c main.cpp

clean:
	rm *.o GreenBox
	
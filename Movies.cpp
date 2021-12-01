#include "Movies.h"

Movie Movies::FindMovieByIDC(string ID) {
	Movie found;
	for (int i = 0; i < movies.size(); ++i) {
		if (movies.at(i).GetMovieID() == ID) {
			found = movies.at(i);
		}
	}

	return found;
}

int Movies::FindMovieByID(string ID) {
	int found = -1;
	for (int i = 0; i < movies.size(); ++i) {
		if (movies.at(i).GetMovieID() == ID) {
			found = i;
		}
	}

	return found;
}

int Movies::FindMovieByTitle(string name) {
	int found = -1;
	for (int i = 0; i < movies.size(); ++i) {
		if (movies.at(i).GetTitle() == name) {
			found = i;
		}
	}
	
	return found;
}

void Movies::PrintMovies() {
	for (int i = 0; i < movies.size(); ++i) {
		cout << "MOVIE " << i+1 << endl;
		movies.at(i).printMovieInfo();
		cout << endl;
	}
}

void Movies::AddMovie() {
	Movie tempMovie;
	string t_movieID;
	string t_title;
	int t_releaseMonth, t_releaseYear;
	string t_rating;
	int t_durationHr;
	int t_durationMin;
	float t_rentalCost;
	float t_replacementCost;
	bool loopcheck = true;
	while (loopcheck) {
		cout << "ENTER MOVIE TITLE: ";
		getline(cin, t_title);
		if (t_title.size() > 40) {
			cout << "YOU HAVE REACH THE CHARACTER LIMIT OF 40." << endl;
		}
		else {
			break;
		}
	}
	cout << "ENTER DURATION AS (HH MM): ";
	cin >> t_durationHr >> t_durationMin;
	cout << "ENTER RELEASE DATE AS (MM YYYY): ";
	cin >> t_releaseMonth >> t_releaseYear;
	cin.ignore();
	while (loopcheck) {
		cout << "ENTER RATING: ";
		getline(cin, t_rating);
		if (t_rating.size() > 20) {
			cout << "YOU HAVE REACH THE CHARACTER LIMIT OF 20." << endl;
		}
		else {
			break;
		}
	}
	cout << "ENTER RENTAL COST: $";
	cin >> t_rentalCost;
	cout << "ENTER REPLACEMENT COST: $";
	cin >> t_replacementCost;
	srand(time(NULL));
	while (loopcheck) {
		int tempID = 100000 + rand() % 900000;
		string convtempID = to_string(tempID);
		if (FindMovieByID(convtempID) == -1) {
			tempMovie.SetMovieID(convtempID);
			break;
		}
	}
	tempMovie.SetTitle(t_title);
	tempMovie.SetDuration(t_durationHr, t_durationMin);
	tempMovie.SetReleaseDate(t_releaseMonth, t_releaseYear);
	tempMovie.SetRentalCost(t_rentalCost);
	tempMovie.SetReplacementCost(t_replacementCost);
	tempMovie.SetRating(t_rating);

	movies.push_back(tempMovie);
	cout << endl;
}

void Movies::DeleteMovie() {
	string t_remove;
	cout << "TYPE THE ID OR NAME OF THE MOVIE YOU WANT TO REMOVE: ";
	getline(cin, t_remove);
	if (FindMovieByTitle(t_remove) == -1 && FindMovieByID(t_remove) == -1) {
		cout << "THE MOVIE DOES NOT EXIST." << endl;
	}
	else {
		int location;
		if (FindMovieByTitle(t_remove) != -1) {
			location = FindMovieByTitle(t_remove); 
		}
		else if (FindMovieByID(t_remove) != -1) {
			location = FindMovieByID(t_remove);
		}
		cout << movies.at(location).GetTitle() << " HAS BEEN REMOVED." << endl;
		movies.erase(movies.begin() + location);
	}
}

void Movies::PrintAMovie() {
	string t_display;
	cout << "ENTER THE ID OR TITLE OF THE MOVIE YOU WANT TO DISPLAY: ";
	getline(cin, t_display);
	if (FindMovieByTitle(t_display) == -1 && FindMovieByID(t_display) == -1) {
		cout << "THE MOVIE DOES NOT EXIST." << endl;
	}
	else {
		int location;
		if (FindMovieByTitle(t_display) != -1) {
			location = FindMovieByTitle(t_display); 
		}
		else if (FindMovieByID(t_display) != -1) {
			location = FindMovieByID(t_display);
		}
		
		movies.at(location).printMovieInfo();
		cout << endl;
	}
}

void Movies::EditMovie() {
	string t_edit;
	cout << "ENTER THE ID OR TITLE OF THE MOVIE YOU WANT TO DISPLAY: ";
	getline(cin, t_edit);
	bool loopcheck = true;
	if (FindMovieByTitle(t_edit) == -1 && FindMovieByID(t_edit) == -1) {
		cout << "THE MOVIE DOES NOT EXIST." << endl;
	}
	else {
		int location;
		if (FindMovieByTitle(t_edit) != -1) {
			location = FindMovieByTitle(t_edit); 
		}
		else if (FindMovieByID(t_edit) != -1) {
			location = FindMovieByID(t_edit);
		}
		while (loopcheck) {
			char choice;
			cout << "WHAT DO YOU WISH TO CHANGE" << endl;
			cout << "1. TITLE" << endl;
			cout << "2. RELEASE DATE" << endl;
			cout << "3. DURATION" << endl;
			cout << "4. RATING" << endl;
			cout << "5. RENTAL COST" << endl;
			cout << "6. REPLACEMENT COST" << endl;
			cout << "7. GO BACK" << endl;
			cin >> choice;
			if (choice == '1') {
				cin.ignore();
				string tempTitle;
				while (loopcheck) {
					cout << "ENTER NEW TITLE FOR " << movies.at(location).GetTitle() << ": ";
					getline(cin, tempTitle);
					if (tempTitle.size() > 40) {
						cout << "YOU HAVE REACH THE CHARACTER LIMIT OF 40." << endl;
					}
					else {
						break;
					}
				}
				movies.at(location).SetTitle(tempTitle);

			}
			else if (choice == '2') {
				int tempmonth, tempyear;
				cout << "ENTER NEW RELEASE DATE AS (MM YYYY): ";
				cin >> tempmonth >> tempyear;
				movies.at(location).SetReleaseDate(tempmonth, tempyear);
				
			}
			else if (choice == '3') {
				int temphr, tempmin;
				cout << "ENTER NEW DURATION AS (HH MM): ";
				cin >> temphr >> tempmin;
				movies.at(location).SetDuration(temphr, tempmin);

			}
			else if (choice == '4') {
				cin.ignore();
				string temprating;
				while (loopcheck) {
					cout << "ENTER NEW RATING: ";
					getline(cin, temprating);
					if (temprating.size() > 20) {
						cout << "YOU HAVE REACH THE CHARACTER LIMIT OF 20." << endl;
					}
					else {
						break;
					}
				}
				movies.at(location).SetRating(temprating);
			}
			else if (choice == '5') {
				float temprentalcost;
				cout << "ENTER NEW RENTAL COST: $";
				cin >> temprentalcost;
				movies.at(location).SetRentalCost(temprentalcost);
			}
			else if (choice == '6') {
				float tempreplacementcost;
				cout << "ENTER REPLACEMENT COST: $";
				cin >> tempreplacementcost;
				movies.at(location).SetReplacementCost(tempreplacementcost);
			}
			else if (choice == '7') {
				break;
			}
			else {
				cout << "INVALID SELECTION.";
			}
			cout << endl;
		}
	}
}

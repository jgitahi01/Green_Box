#include "Movie.h"

void Movie::SetReleaseDate(int month, int year) {
	releaseMonth = month;
	releaseYear = year;
}

void Movie::SetDuration(int hour, int min) {
	durationHr = hour;
	durationMin = min;
}

string Movie::GetReleaseDate() {
	string releaseDate;
	releaseDate = to_string(releaseMonth) + "/" + to_string(releaseYear);
	return releaseDate;
}

string Movie::GetDuration() {
	string duration;
	duration = to_string(durationHr) + ":" + to_string(durationMin);
	return duration;
}

void Movie::printMovieInfo() {
	cout << "TITLE: " << title << endl;
	cout << "MOVIE ID: " << movieID << endl;
	cout << "RELEASE DATE: " << GetReleaseDate() << endl;
	cout << "DURATION: " << GetDuration() << endl;
	cout << "RATING: " << rating << endl;
	cout << "RENTAL COST: $" << rentalCost << endl;
	cout << "REPLACEMENT COST: $" << replacementCost << endl;
}
#include <iostream>
using namespace std;

class Movie {
	private:
		string movieID;
		string title;
		int releaseMonth, releaseYear;
		string rating;
		int durationHr;
		int durationMin;
		float rentalCost;
		float replacementCost;
	public:
		void SetMovieID(string ID) {movieID = ID;}
		string GetMovieID() {return movieID;}
		void SetTitle(string mtitle) {title = mtitle;}
		string GetTitle() {return title;}
		void SetReleaseDate(int month, int year);
		string GetReleaseDate();
		void SetDuration(int hour, int min);
		string GetDuration();
		void SetRentalCost(float cost) {rentalCost = cost;}
		float GetRentalCost() {return rentalCost;}
		void SetReplacementCost(float cost) {replacementCost = cost;}
		float GetReplacementCost() {return replacementCost;}
		void SetRating(string rate) {rating = rate;}
		string GetRating() {return rating;}
		void printMovieInfo();
};

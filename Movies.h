#include "Movie.h"
#include <vector>
#include <time.h>

class Movies {
	private:
		vector<Movie> movies;
	public:
		void AddMovie();
		void EditMovie();
		void DeleteMovie();
		int FindMovieByTitle(string name);
		int FindMovieByID(string ID);
		Movie FindMovieByIDC(string ID);
		void PrintMovies();
		void PrintAMovie();
};
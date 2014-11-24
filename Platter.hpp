#include "Track.hpp"

struct Platter{
	// Platter number
	int platter_no;

	// Number of tracks in the platter
	int size;
	
	// List of Tracks in the Platter
	Track * tracks;

	// Statistics object
	Statistics * stats;


public:
	Platter();
	Platter(int, Statistics *);

	bool write_data(char *, int, int);

	bool read_data(char *, int, int);
};

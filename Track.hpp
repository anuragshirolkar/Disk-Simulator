#include "Sector.hpp"

struct Track{
	// Track number
	int track_no;

	// Number of Sectors in the track
	int size;

	// List of Sectors in the Track
	Sector * sectors;

	// Statistics object
	Statistics * stats;


public:
	Track();
	Track(int, Statistics *);

	bool write_data(char *, int);
	bool read_data(char *, int);

};

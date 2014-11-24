#include "Track.hpp"
#include <iostream>
using namespace std;

Track::Track(){
	track_no = 0;
	size = NO_SECTORS_MIN;
	sectors = new Sector[size];
}

Track::Track(int n, Statistics * s) {
	track_no = n;
	size = NO_SECTORS_MIN+track_no;
	sectors = new Sector[size];
	stats = s;
	for(int i = 0; i < size; i++) {
		sectors[i] = *(new Sector(i, stats));
	}
}

bool Track::write_data(char *d, int s) {
	return sectors[s].write_data(d);
}

bool Track::read_data(char *d, int s) {
	return sectors[s].read_data(d);
}

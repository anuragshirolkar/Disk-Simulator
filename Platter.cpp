#include "Platter.hpp"
#include <iostream>
using namespace std;

Platter::Platter(){
	size = NO_TRACKS;
	tracks = new Track[size];
}


Platter::Platter(int n, Statistics * s){
	platter_no = n;
	size = NO_TRACKS;
	stats = s;
	tracks = new Track[size];
	for (int i = 0; i < size; i++) {
		tracks[i] = *(new Track(i, stats));
	}
}


bool Platter::write_data(char * d, int t, int s) {
	return tracks[t].write_data(d, s);
}

bool Platter::read_data(char * d, int t, int s) {
	return tracks[t].read_data(d, s);
}


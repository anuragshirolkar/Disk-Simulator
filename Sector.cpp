#include "Sector.hpp"
using namespace std;


void Sector::writefile(){
	
}


Sector::Sector() {
	size = DATA_SIZE;
	data = new char[size];
}

Sector::Sector(int n, Statistics * s) {
	sector_no = n;
	size = DATA_SIZE;
	data = new char[size];
	stats = s;
}

void Sector::_assign(char * d) {
	for (int i = 0; i < size; i++) {
		data[i] = d[i];
	}
}

void Sector::_copy(char * d) {
	for (int i = 0; i < size; i++) {
		d[i] = data[i];
	}
}

bool Sector::write_data(char *d) {
	_assign(d);
	stats->add_write_latency(1);
	cout << "Data written" << endl;
	return true;
}

bool Sector::read_data(char *d) {
	_copy(d);
	for (int i = 0; i < 512; i++) cout << data[i];
	cout << endl;
	return true;
}

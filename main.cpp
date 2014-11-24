#include "DiskController.hpp"
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int timer=0;
	DiskController disk(&timer);

	char c[512];
	strcpy(c,"Hello I am an Indian");
	int next_op = 0;
	cin >> next_op;
	for(timer = 0; timer < 1000000; timer++) {
		if(next_op == timer){
			int addr, rw;
			cin >> addr >> rw;
			//cout << addr << " " << rw << endl;
			//if(rw == 0) cerr << rw << endl;
			if(rw == 0) disk.read_data(addr,c,timer);
			if(rw == 1) {
				cin.getline(c, 512);
				cin.getline(c, 512);
				disk.write_data(addr,c,timer);
			}
			cin >> next_op;
			if(next_op == -1) {
				cerr << timer << endl << "======================" << endl;
				disk.print_stats(); 
				cin >> next_op;
			}
		}
		//cout << timer << endl;
		//cerr << timer << endl;
		disk.update();
		//cout << timer << endl;
	}
	return 0;


}

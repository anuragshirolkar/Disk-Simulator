#include "DiskController.hpp"
#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	DiskController disk;
	char c[512];
	disk.read_data(98354,c,1);
	return 0;


}

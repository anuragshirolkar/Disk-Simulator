#include "sizes.hpp"
#include <vector>

const int CACHE_SIZE=999;
class Cache
{
	bool valid[CACHE_SIZE];					// To store if a bit is valid
	std::vector<long long int> addr;		//To store all the addresses
	char data[CACHE_SIZE][DATA_SIZE];		// TO store data in cache

public:
	Cache();
	bool read(long long int address,char data_incoming[DATA_SIZE]);
	void update(long long int address,char data_incoming[DATA_SIZE]);
	void clear();
};
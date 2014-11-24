#include "HardDisk.hpp"
#include "Cache.hpp"

struct DiskController{
	/// Implementation of RAID 1
	HardDisk h[TOTAL_DISK];
	HardDisk h_copy[TOTAL_DISK];

	Cache cache;
	
public:
	DiskController();

	void read_data(long long int addr,char data[DATA_SIZE],int time);
	void write_data(long long int addr,char data[DATA_SIZE],int time);
};

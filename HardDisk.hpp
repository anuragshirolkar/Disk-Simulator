#include "Platter.hpp"
#include <set>
using namespace std;

struct buffer_entry{
	int time;
	int read_or_write;
	int platter_no;
	int track_no;
	int sector_no;
	char * data;

	buffer_entry();
	buffer_entry(int tm, int rw, int p, int t, int s, char * d);
};



struct Buffer{
	set<buffer_entry> content;
	set<buffer_entry>::iterator current;

	Buffer();

	void add_entry(int, int, int, int, int, char *);
	int give_next(int);
};

struct HardDisk
{

	// SPINDLE
	int rotation;
	// HEAD FOR DISK
	int trackno;

	// Direction of motion of the Arm
	int arm_dir;

	// Position of arm - wrt track number
	int arm_pos;

	// rotation speed of platters int rotations per second
	double rot_speed;

	int * timer;

	// Direction of movement of Arm
	int arm_direction;

	// time for the next operation
	int next_op_time;

	// Buffer for the hard DISK
	Buffer buffer;

	// Statistics object
	Statistics *stats;

	Platter *platters;
public:
	HardDisk();

	HardDisk(int*);

	bool write_data(char*, int, int, int);

	bool read_data(char *, int, int, int);

	bool add_operation(int, int, char *, int, int, int);

	bool operate();
	
	
};


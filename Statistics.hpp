
struct Statistics {
	double seek_time;
	double write_latency;

	double cum_rot_latency;
	int cum_seek;
	int cum_write_latency;
	double cum_tot_time;

	double cur_rot_latency;
	int cur_seek;
	int cur_write_latency;
	double cur_tot_time;

public:
	Statistics();

	void reinitialize_cur_stat();
	
	void add_rot_latency(double);
	void add_seek(int);
	void add_write_latency(int);

	void print_stats();

};

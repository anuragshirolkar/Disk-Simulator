#include "HardDisk.hpp"
#include <set>

using namespace std;

HardDisk::HardDisk(){

}

HardDisk::HardDisk(int * t){
	rotation=0;
	trackno=0;
	platters = new Platter[3];
	stats = new Statistics();
	for(int i = 0; i < 3; i++) {
		platters[i] = *(new Platter(i, stats));
	}
	arm_dir = 0;
	arm_pos = 0;
	rot_speed = 150;
	timer = t;
	buffer.current = buffer.content.end();
	arm_direction = 1;
	next_op_time = 0;
}

bool HardDisk::write_data(char * d, int p, int t, int s) {
	cout << *timer << " ";
	return platters[p].write_data(d, t, s);
}

bool HardDisk::read_data(char * d, int p, int t, int s) {
	cout << *timer << " ";
	return platters[p].read_data(d, t, s);
}

bool HardDisk::add_operation(int tm, int op, char * d, int p, int t, int s) {
	buffer.add_entry(tm, op, p, t, s, d);
}

bool HardDisk::operate() {
		//cout << "next " << next_op_time << " " << *timer << endl;
	if(buffer.content.size() == 0){
		next_op_time++;
		return false;
	}
	if((*timer) >= next_op_time) {
		next_op_time++;
		int prev_track = buffer.current->track_no;
		int output = buffer.give_next(arm_direction);
		if(output == 0) return false;
		arm_direction = output;
		int prev_stat_time = stats->cur_tot_time;
		cout << buffer.current->time << endl;
		if(buffer.current->track_no != prev_track) stats->add_seek(1);
		if(buffer.current->read_or_write == 0) read_data(buffer.current->data, buffer.current->platter_no, buffer.current->track_no, buffer.current->sector_no);
		else if(buffer.current->read_or_write == 1) write_data(buffer.current->data, buffer.current->platter_no, buffer.current->track_no, buffer.current->sector_no);
		next_op_time += (stats->cur_tot_time-prev_stat_time-1);
		if(stats->cur_tot_time == prev_stat_time) return operate();
		return true;
	}
}


buffer_entry::buffer_entry(){};
buffer_entry::buffer_entry(int tm, int rw, int p, int t, int s, char * d) { 
	time = tm;
	read_or_write = rw;
	platter_no = p;
	track_no = t;
	data = d;
}

bool operator<(buffer_entry a, buffer_entry b) {
	if(a.track_no == b.track_no) return a.time < b.time;
	return a.track_no < b.track_no;
}

Buffer::Buffer(){
	current = content.end();
}

void Buffer::add_entry(int tm, int rw, int p, int t, int s, char * d) {
	buffer_entry be = *(new buffer_entry(tm, rw, p, t, s, d));
	content.insert(be);
}

int Buffer::give_next(int direction) {
	if(content.size() == 0) {
		return 0;
	}
	if(current  == content.end()) {
		current = content.begin();
		return 1;
	}
	if(content.size() == 1){
		set<buffer_entry>::iterator temp = current;
		current++;
		content.erase(temp);
		return 0;
	}
	if(direction == 1) {
		if(distance(current, content.end()) == 1){
			set<buffer_entry>::iterator temp = current;
			temp++;
			if(temp == content.end() || current->track_no != temp->track_no) {
				temp = current;
				current--;
				content.erase(temp);
				temp = current;
				temp--;
				if(current->track_no == content.begin()->track_no) {
					current = content.begin();
					return -1;
				}
				else{
					while(temp->track_no == current->track_no){
						temp--;
					}
					return -1;
				}
			}
			else {
				set<buffer_entry>::iterator temp = current;
				current++;
				content.erase(temp);
				return -1;
			}
		}
		else {
			set<buffer_entry>::iterator temp = current;
			current++;
			content.erase(temp);
			return 1;
		}
	}
	if(direction == -1) {
		if(current == content.begin()) {
			set<buffer_entry>::iterator temp = current;
			current++;
			content.erase(temp);
			return -1;
		}
		set<buffer_entry>::iterator temp = current;
		temp++;
		if(temp == content.end() || current->track_no != temp->track_no) {
			temp = current;
			current--;
			content.erase(temp);
			temp = current;
			temp--;
			if(current->track_no == content.begin()->track_no) {
				current = content.begin();
				return -1;
			}
			else{
				while(temp->track_no == current->track_no){
					temp--;
				}
				return -1;
			}
		}
		else {
			set<buffer_entry>::iterator temp = current;
			current++;
			content.erase(temp);
			return -1;
		}
	}
	/*
	 *if(current  == content.end()) {
	 *    cout << "here" << endl;
	 *    current = content.begin();
	 *    return *current;
	 *}
	 *if(direction == 1) {
	 *    if(distance(current, content.end()) == 1)  direction = -1;
	 *}
	 *else if(direction == -1) {
	 *    if(current == content.begin()) direction = 1;
	 *}
	 *if(direction == 1) {
	 *    set<buffer_entry>::iterator temp = current;
	 *    current++;
	 *    content.erase(temp);
	 *    return *current;
	 *}
	 *else if(direction == -1) {
	 *    set<buffer_entry>::iterator temp = current;
	 *    current--;
	 *    content.erase(temp);
	 *    return *current;
	 *}
	 */
}

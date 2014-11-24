#include "DiskController.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

DiskController::DiskController(){
	
}

void DiskController::read_data(long long int addr,char data[DATA_SIZE],int tim){
	
	srand(time(NULL));

	int disk_no=addr/DISK_SIZE;
	cout<<DISK_SIZE<<" - "<<addr<<" "<<(addr/DISK_SIZE)<<endl;
	if(disk_no<0 || disk_no >= TOTAL_DISK){
		cout<<addr<<" Error:Read Operation Failed"<<endl;
		return;
	}
	if(cache.read(addr,data)){
		cout<<addr<<" "<<data<<endl;
		return;
	}

	cout<<addr<<" ";

	int address_in_disk=addr%DISK_SIZE;
	int platter_no=address_in_disk/PLATTER_SIZE;
	int address_in_platter=address_in_disk/PLATTER_SIZE;
	int track_no;
	for (int i = 0; i < NO_TRACKS; ++i)
	{
		if(address_in_platter>= (NO_SECTORS_MIN+i)){
			address_in_platter-=i;
			address_in_platter-=NO_SECTORS_MIN;
		}
		else{
			track_no=i;
			break;
		}
	}
	int sector_no=address_in_platter;

	cout<<addr<<" => "<<disk_no<<" : "<<platter_no<<" : "<<track_no<<" : "<<sector_no<<endl;
	if(rand() % 2 ==0){
		//h[disk_no].add_operation(tim,0,data,platter_no,track_no,sector_no);
	}
	else{
		// Read from mirrored Disk
	}
	cout<<endl;



}

void DiskController::write_data(long long int addr,char data[DATA_SIZE],int tim){
	srand (time(NULL));

	int disk_no=addr/DISK_SIZE;
	if(disk_no<0 || disk_no >= TOTAL_DISK){
		cout<<addr<<" Error:Read Operation Failed"<<endl;
		return;
	}

	// Write in disk

	// Write in mirrored disk
}
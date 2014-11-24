CPPFLAGS=-I/usr/local/include

BIN2=simulator
SRCS2=main.cpp DiskController.cpp Cache.cpp HardDisk.cpp Platter.cpp Sector.cpp Track.cpp Statistics.cpp 
#SRCS2=main.cpp HardDisk.cpp Platter.cpp Sector.cpp Track.cpp Statistics.cpp 
INCLUDES=DiskController.hpp Cache.hpp HardDisk.hpp Platter.hpp Sector.hpp Track.hpp Statistics.hpp sizes.hpp 

all: $(BIN2)


$(BIN2): $(SRCS2) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS2) -o $(BIN2)

clean:
	rm -f *~ *.o  $(BIN2) *.tar.gz 

# PROGRAM:    Assign 5 
# PROGRAMMER: Samuel Piecz
# LOGON ID:   Z1732715
# DATE DUE:   10/25/19
#

CCFLAGS = -ggdb -Wall -std=c++11

Assign5: Assign5.o Process.o
	g++ $(CCFLAGS) -o Assign5 Assign5.o 

Assign5.o: Assign5.cxx 
	g++ $(CCFLAGS) -c Assign5.cxx

clean:
	-rm *.o Assign5

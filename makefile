# PROGRAM:    Assign 5 
# PROGRAMMER: Samuel Piecz
# LOGON ID:   Z1732715
# DATE DUE:   10/25/19
#

CCFLAGS = -ggdb -Wall -std=c++11

Assign5: Assign5.o Widget.o
	g++ $(CCFLAGS) -pthread -o Assign5 Assign5.o 

Assign5.o: Assign5.cxx  Widget.h Constants.h
	g++ $(CCFLAGS) -pthread -c Assign5.cxx

Widget.o: Widget.cxx Widget.h
	g++ $(CCFLAGS) -c Widget.cxx

clean:
	-rm *.o Assign5

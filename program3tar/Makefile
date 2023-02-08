CC = g++ -std=c++11
exe_file = run
$(exe_file): adventurer.o event.o game.o room.o driver.o coordinates.o super_bats.o gold.o wumbus.o empty_room.o bottomless_pit.o
	$(CC) adventurer.o event.o game.o room.o driver.o coordinates.o super_bats.o gold.o wumbus.o empty_room.o bottomless_pit.o -o $(exe_file)
adventurer.o: adventurer.cpp
	$(CC) -c adventurer.cpp
event.o: event.cpp
	$(CC) -c event.cpp
game.o: game.cpp
	$(CC) -c game.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
coordinates.o: coordinates.cpp
	$(CC) -c coordinates.cpp
super_bats.o: super_bats.cpp
	$(CC) -c super_bats.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
wumbus.o: wumbus.cpp
	$(CC) -c wumbus.cpp
empty_room.o: empty_room.cpp
	$(CC) -c empty_room.cpp
bottomless_pit.o: bottomless_pit.cpp
	$(CC) -c bottomless_pit.cpp
clean:
	rm -f *.out *.o $(exe_file)
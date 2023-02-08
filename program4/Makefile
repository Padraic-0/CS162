CC = g++ -std=c++11
exe_file = run
$(exe_file): driver.o linkedlist.o
	$(CC) driver.o linkedlist.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
linkedlist.o: linkedlist.cpp
	$(CC) -c linkedlist.cpp
clean:
	rm -f *.out *.o $(exe_file)
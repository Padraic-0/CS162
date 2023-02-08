CC = g++
exe_file = run
$(exe_file): shape.o rectangle.o driver.o square.o circle.o
	$(CC) shape.o rectangle.o driver.o square.o circle.o -o $(exe_file)
shape.o: shape.cpp
	$(CC) -c shape.cpp
rectangle.o: rectangle.cpp
	$(CC) -c rectangle.cpp
circle.o: circle.cpp
	$(CC) -c circle.cpp
square.o: square.cpp
	$(CC) -c square.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
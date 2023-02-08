CC = g++
exe_file = pokedex
$(exe_file): pokedex.o pokemon.o driver.o 
	$(CC) pokedex.o pokemon.o driver.o -o $(exe_file)
pokedex.o: pokedex.cpp
	$(CC) -c pokedex.cpp
pokemon.o: pokemon.cpp
	$(CC) -c pokemon.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
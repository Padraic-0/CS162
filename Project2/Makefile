CC = g++
exe_file = run
$(exe_file): bulbasaur.o charizard.o charmander.o squirtle.o driver.o trainer.o pokemon.o arena.o
	$(CC) bulbasaur.o charizard.o charmander.o squirtle.o driver.o trainer.o pokemon.o arena.o -o $(exe_file)
bulbasaur.o: bulbasaur.cpp
	$(CC) -c bulbasaur.cpp
charmander.o: charmander.cpp
	$(CC) -c charmander.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
squirtle.o: squirtle.cpp
	$(CC) -c squirtle.cpp
trainer.o: trainer.cpp
	$(CC) -c trainer.cpp
pokemon.o: pokemon.cpp
	$(CC) -c pokemon.cpp
arena.o: arena.cpp
	$(CC) -c arena.cpp
charizard.o: charizard.cpp
	$(CC) -c charizard.cpp
clean:
	rm -f *.out *.o $(exe_file)
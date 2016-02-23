run: driver
	./driver

driver: driver.o database.o
	g++ -o driver driver.o -std=c++11

driver.o: driver.cpp database.h
	g++ -c -o driver.o driver.cpp -std=c++11

database.o: database.cpp database.h
	g++ -c -o database.o database.cpp -std=c++11

clean:
	@rm -f *.o driver

	# all: driver.o driver

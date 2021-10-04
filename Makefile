CC = g++
EXEC = quicksort

exe:
	$(CC) -std=c++11 -W main.cpp -o $(EXEC)
	./$(EXEC)

clean:
	rm -f *.o
	rm -f $(EXEC)
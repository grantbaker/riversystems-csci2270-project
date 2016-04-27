CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -pedantic -g
DEPS = RiverGraph.h
OBJ = main.o RiverGraph.o 
PROG = RiverSystem

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

RiverSystem: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	$(RM)  $(OBJ) $(PROG)
.PHONY: cl
cl:
	$(RM) $(OBJ)

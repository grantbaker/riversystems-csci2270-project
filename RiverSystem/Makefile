CC = g++
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g

PROG = RiverSystem
SRC = main.cpp RiverGraph.cpp
HDR = RiverGraph.h
OBJ = $(SRC:.c=.o)

$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
tags: $(SRC) $(HDR)
	ctags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)

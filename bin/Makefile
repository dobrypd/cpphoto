##/****************************************/
##/*  cpPhoto                             */
##/*  author: Piotr Dobrowolski           */
##/*  fall 2011                           */
##/*                                      */
##/*  Makefile                            */
##/*                                      */
##/****************************************/
include paths

DEBUGOROPT = -O2 -DNDEBUG
ifeq ($(debuglevel), 1)
	DEBUGOROPT = -g
endif

BOOSTOPT=-lboost_filesystem-mt -lboost_thread-mt

CC=g++
CFLAGS=-Wall -c $(DEBUGOROPT)
LFLAGS=-Wall $(BOOSTOPT) $(DEBUGOROPT)

PROJECT=$(BIN)cpphoto
OBJECTS:=$(patsubst $(SRC)%.cpp,%.o,$(wildcard $(SRC)*.cpp))

all: $(PROJECT)

$(PROJECT): $(OBJECTS)
	$(CC) $(LFLAGS) $^ -o $@
$(OBJECTS): %.o : $(SRC)%.cpp
	$(CC) $(CFLAGS) $< -o $@

rebuild: clean all

run : rebuild
	./cpphoto

clean:
	rm -f *~ *.o *.swp $(PROJECT)
	rm -f $(SRC)*~ $(BIN)*.o $(SRC)*.swp $(PROJECT)

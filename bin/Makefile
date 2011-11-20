##/****************************************/
##/*  cpPhoto                             */
##/*  author: Piotr Dobrowolski           */
##/*  fall 2011                           */
##/*                                      */
##/*  Makefile                            */
##/*                                      */
##/****************************************/
include paths

CC=g++
CFLAGS=-Wall -c $(DEBUGOROPT)
LFLAGS=-Wall -lboost_filesystem-mt $(DEBUGOROPT)

PROJECT=$(BIN)cpphoto
OBJECTS:=$(patsubst $(SRC)%.cpp,%.o,$(wildcard $(SRC)*.cpp))

DEBUGOROPT = -O2 -DNDEBUG
ifeq ($(debuglevel), 1)
	DEBUGOROPT = -g
endif


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

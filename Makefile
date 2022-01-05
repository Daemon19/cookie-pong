INCLUDE=include
SRC=src
OBJ=obj
BUILD=build

CPP=g++
CXXFLAGS=-Wall -g -std=c++2a
LDLIBS=-lmingw32 -lSDL2main -lSDL2
INCFLAGS=-m64 -I $(INCLUDE)

INCLUDES=$(wildcard $(INCLUDE)/*.h)
SRCS=$(patsubst $(INCLUDE)/%.h, $(SRC)/%.cc, $(INCLUDES))
OBJS=$(patsubst $(SRC)/%.cc, $(OBJ)/%.o, $(SRCS))

MAIN=main
MAINSRC=$(SRC)/$(MAIN).cc
MAINOBJ=$(OBJ)/$(MAIN).o

BIN=$(BUILD)/cookie-pong.exe

all: $(BIN)

run: all
run:
	./$(BIN)

release: CXXFLAGS=-Wall -std=c++2a -O2 -DNDEBUG
release:
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $(SRCS) $(MAINSRC) -o $(DIST)/$(BIN) $^ $(LDLIBS)

$(BIN): $(OBJS) $(MAINOBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

$(OBJ)/%.o: $(SRC)/%.cc $(INCLUDE)/%.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c -o $@ $<

$(MAINOBJ): $(MAINSRC)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c -o $@ $<

clean:
	rm -v $(OBJ)/* $(BIN)
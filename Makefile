INCLUDE=include
SRC=src
OBJ=obj
BUILD=build

CXX=g++
CXXFLAGS=-Wall -g -std=c++2a
LDLIBS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
LDFLAGS=-mwindows
INCFLAGS=-I $(INCLUDE)

SRCS=$(wildcard $(SRC)/*.cc)
OBJS=$(patsubst $(SRC)/%.cc, $(OBJ)/%.o, $(SRCS))
DEPENDS=$(patsubst $(SRC)/%.cc, %.d, $(SRCS))

-include $(DEPENDS)

BIN=$(BUILD)/cookie-pong.exe

all: $(BIN)

run: all
run:
	./$(BIN)

release: CXXFLAGS=-Wall -std=c++2a -O2 -DNDEBUG
release:
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $(LDFLAGS) -o $(BIN) $(SRCS) $^ $(LDLIBS)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJ)/%.o: $(SRC)/%.cc Makefile
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -MMD -MP -c -o $@ $<

clean:
	$(RM) $(OBJ)/* $(BIN)
CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -luser32 -lgdi32 -lopengl32 -lgdiplus

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	$(BIN)/$(EXECUTABLE).exe

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES) $(CXX_FLAGS)

clean:
	-rm $(BIN)/*

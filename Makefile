.RECIPEPREFIX := >
VPATH := .
CXX := /usr/bin/clang++
CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic -O3 -fPIC -D__EA64__
INCLUDE := ./idasdk9/include

BIN := bin
OUT := class_informer_gcc.so

SRC := $(wildcard *.cc)
OBJ := $(patsubst %.cc,$(BIN)/%.o,$(SRC))

all: $(BIN)/$(OUT)

$(BIN)/$(OUT): $(OBJ)
>       $(CXX) $(CXXFLAGS) -shared $^ -o $@

$(BIN)/%.o : %.cc | $(BIN)
>       $(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -c -o $@

$(BIN):
>       mkdir -p $(BIN)

clean:
>       rm -r $(BIN)/*

BIN_DIR = exe
CXX = g++
CPPFLAGS = -g -Wall -Ilib

all: $(BIN_DIR)/.dirstamp $(BIN_DIR)/pokemon

$(BIN_DIR)/pokemon: src/main.cpp $(BIN_DIR)/attackMove.o $(BIN_DIR)/battle.o $(BIN_DIR)/pokemon.o
	$(CXX) $(CPPFLAGS) $^ -o $@

$(BIN_DIR)/attackMove.o: src/attackMove.cpp lib/attackMove.h 
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/battle.o: src/battle.cpp lib/battle.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/pokemon.o: src/pokemon.cpp lib/pokemon.h 
	$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp


BIN_DIR = exe


all: $(BIN_DIR)/.dirstamp $(BIN_DIR)/main

$(BIN_DIR)/.dirstamp: 
	mkdir -p $(BIN_DIR) 
	touch $(BIN_DIR)/.dirstamp

$(BIN_DIR)/main.o: main.cpp
	g++ -Wall -g -c $^ -o $@


$(BIN_DIR)/fold.o: fold.cpp
	g++ -Wall -g -c $^ -o $@

$(BIN_DIR)/main: $(BIN_DIR)/main.o $(BIN_DIR)/fold.o
	g++ -Wall -g -mconsole $^ -o main

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)
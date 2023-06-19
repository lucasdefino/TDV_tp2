CC = g++
CFLAGS = -std=c++17
SRC = busqueda_local_2.cpp busqueda_local_1.cpp heuristica_2.cpp heuristica_1.cpp read_instance.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = gap_simulator

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
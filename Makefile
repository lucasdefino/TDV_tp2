CC = g++
CFLAGS = -std=c++17
SRC = solver.cpp read_instance.cpp solucion.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = tp_2

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
# Variables o Macros
EXE=sub
OBJS=main.o
CC=g++
FLAGS=-Wall -g

# Reglas explícitas
# Para linkear todos los objetos y generar un ejecutable
all:$(OBJS)
	$(CC) $(FLAGS)  $(OBJS) -o $(EXE)
	#./$(EXE) < entrada.txt

ddd:$(OBJS)
	$(CC) $(FLAGS)  $(OBJS) -o $(EXE)
	rm $(OBJS)
	ddd $(EXE)
# Generara todos los objetos apartir de las reglas implicitas
%.o:%.cpp
	$(CC) $(FLAGS) -c  $<
# Para eliminar .o y el ejecutable
clean:
	rm -rf $(EXE) $(OBJS)
# Reglas implícitas
main.o: main.cpp pila.hpp nodo.hpp




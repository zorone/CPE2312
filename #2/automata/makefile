CC=gcc
CFLAGS=-I.
DEPS = internal/automata.h
OBJ = workspace.o internal/setup.o internal/strGen.o internal/test.o internal/dataFlag.o internal/setProjectName.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

automata: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
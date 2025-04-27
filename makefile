OBJ := $(patsubst %.c, %.o, $(wildcard *.c))

project.exe: $(OBJ)
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

clean:
	rm -f *.exe *.o

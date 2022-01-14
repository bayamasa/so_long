all:	
	gcc -L lib/mlx -lmlx -framework OpenGL -framework AppKit main.c -o main
	./main

clean: 
	rm -rf *.out

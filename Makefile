FLAGS := -Wall -Werror -Wconversion -Wno-unused-variable -Wno-missing-braces -O2 -lSDL2

build: main.out

main.out: src/main.c Makefile
	clang -std=c99 $(FLAGS) src/main.c -o main.out

run: main.out
	./main.out

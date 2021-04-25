FLAGS := -Wall -Werror -Wconversion -Wno-unused-variable -Wno-missing-braces

build: dist dist/render.dylib dist/main.out
.PHONY: build

dist:
	mkdir -p dist

dist/main.out: src/main.c Makefile
	clang -std=c99 $(FLAGS) -lSDL2 $< -o $@

dist/render.dylib: src/render.c Makefile
	clang -std=c99 $(FLAGS) -dynamiclib $< -o $@

run: dist/main.out
	./dist/main.out
.PHONY: run

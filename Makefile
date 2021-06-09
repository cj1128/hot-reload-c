CFLAGS := -Wall -Werror -Wconversion -Wno-unused-variable -Wno-missing-braces

build: dist dist/main.out dist/render.dylib
.PHONY: build

dist:
	mkdir dist

dist/main.out: src/main.c Makefile
	gcc -std=c99 $(CFLAGS) -ldl -lSDL2 $< -o $@

dist/render.dylib: src/render.c Makefile
	gcc -std=c99 $(CFLAGS) -shared $< -o $@

run: build
	./dist/main.out
.PHONY: run

clean:
	rm -rf dist
.PHONY: clean

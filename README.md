# Hot Reload C

A simple SDL2 program to demonstrate how to hot reload C.

https://user-images.githubusercontent.com/4210829/121360538-179e5900-c967-11eb-9e98-fd57acc239a5.mp4

## Build

This program can be built on MacOS and Linux.

First you need to install `SDL2`:

- MacOS: `brew install sdl2`
- Linux: Check your package manager, e.g. on Manjaro, `pacman -S sdl2`

Then clone the code and build

```bash
$ git clone ... && cd ...
$ make run
# while the program is running, modify render.c and rebuild
$ make build
# and then the program will be hot reloaded 🚀
```

## Idea

The main idea behind this is `Shared Library` a.k.a `Dynamic Loaded Library`.

We compile the render logic into a separate shared library and load it in main program dynamically via these apis:

- `dlopen`
- `dlclose`
- `dlsym`

So while the main program is running, we can rebuild our render library to hot load the main program.

Google `dynamic linking` for more details.

COMPILER = clang++
CFLAGS = -std=c++17 -fdiagnostics-color=always -Wall -g -Iinclude -Llib -o main
LIBS = -lglfw.3 -framework OpenGL
SOURCES = src/glad.c src/*.cpp

all:
	$(COMPILER) $(CFLAGS) $(SOURCES) $(LIBS) -Wl,-rpath,@executable_path/lib
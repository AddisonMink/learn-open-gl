COMPILER = clang++
CFLAGS = -std=c++17 -fdiagnostics-color=always -Wall -g -Iinclude -Llib
LIBS = -lglfw.3 -framework OpenGL
SOURCES = src/glad.c

hello-triangle:
	$(COMPILER) $(CFLAGS) -o hello-triangle $(SOURCES) src/hello-triangle.cpp $(LIBS) -Wl,-rpath,@executable_path/lib
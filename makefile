.PHONY: green-flashing-triangle
.PHONY: hello-triangle

COMPILER = clang++
CFLAGS = -std=c++17 -fdiagnostics-color=always -Wall -g -Iinclude -Llib
LIBS = -lglfw.3 -framework OpenGL
SOURCES = src/glad.c

green-flashing-triangle:
	$(COMPILER) $(CFLAGS) -o green-flashing-triangle $(SOURCES) src/green-flashing-triangle.cpp $(LIBS) -Wl,-rpath,@executable_path/lib

hello-triangle:
	$(COMPILER) $(CFLAGS) -o hello-triangle $(SOURCES) src/hello-triangle.cpp $(LIBS) -Wl,-rpath,@executable_path/lib
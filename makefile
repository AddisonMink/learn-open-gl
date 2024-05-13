.PHONY: main main-rect

COMPILER = clang++
CFLAGS = -std=c++17 -fdiagnostics-color=always -Wall -g -Iinclude -Llib
LIBS = -lglfw.3 -framework OpenGL
SOURCES = src/glad.c

main:
	$(COMPILER) $(CFLAGS) -o program $(SOURCES) src/main.cpp $(LIBS) -Wl,-rpath,@executable_path/lib

main-rect:
	$(COMPILER) $(CFLAGS) -o program $(SOURCES) src/main-rect.cpp $(LIBS) -Wl,-rpath,@executable_path/lib
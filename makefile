.PHONY: main simple-rect chromatic-rect texture-rect transform-rect rotating-cube flying-camera phong-cube

COMPILER = clang++
CFLAGS = -std=c++17 -fdiagnostics-color=always -Wall -g -Iinclude -Llib
LIBS = -lglfw.3 -framework OpenGL
SOURCES = src/glad.c

main:
	$(COMPILER) $(CFLAGS) -o program $(SOURCES) src/main.cpp $(LIBS) -Wl,-rpath,@executable_path/lib

simple-rect:
	$(COMPILER) $(CFLAGS) -o program $(SOURCES) src/simple-rect.cpp $(LIBS) -Wl,-rpath,@executable_path/lib

chromatic-rect:
	$(COMPILER) $(CFLAGS) -o program $(SOURCES) src/chromatic-rect.cpp $(LIBS) -Wl,-rpath,@executable_path/lib

texture-rect:
	$(COMPILER) $(CFLAGS) -o program $(SOURCES) src/texture-rect.cpp $(LIBS) -Wl,-rpath,@executable_path/lib

transform-rect:
	$(COMPILER) $(CFLAGS) -o program $(SOURCES) src/transform-rect.cpp $(LIBS) -Wl,-rpath,@executable_path/lib

rotating-cube:
	$(COMPILER) $(CFLAGS) -o program $(SOURCES) src/rotating-cube.cpp $(LIBS) -Wl,-rpath,@executable_path/lib

flying-camera:
	$(COMPILER) $(CFLAGS) -o program $(SOURCES) src/flying-camera.cpp $(LIBS) -Wl,-rpath,@executable_path/lib

phong-cube:
	$(COMPILER) $(CFLAGS) -o program $(SOURCES) src/phong-cube.cpp $(LIBS) -Wl,-rpath,@executable_path/lib
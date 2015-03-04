libs = -lGLEW -lglfw -lGL -lX11 -lpthread -lSOIL
flags = -Wall -g
std = -std=c++14
cc = clang++


all: camera_zoom.cpp
	$(cc) $(std) $(libs)  -I./soil camera_zoom.cpp -o main.exe

run: all
	./main.exe

clean:
	rm *.o

libs = -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi
flags = -Wall -g
std = -std=c++14
cc = clang++


all: a.out

a.out: main.cpp
	$(cc) $(std) $(flags) $(libs) main.cpp -o a.out
run:
	primusrun ./a.out
clean:
	rm ./a.out

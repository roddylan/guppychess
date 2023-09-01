all:
	gcc -Ofast main.cpp -o ../bin/ce -std="c++11"
	x86_64-win64-mingw32-gcc -Ofast main.cpp -o ../bin/ce.exe

debug:
	gcc main.cpp -o ../bin/ce
	x86_64-win64-mingw32-gcc main.cpp -o ../bin/ce.exe
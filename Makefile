all:
	g++ -I src/include -I src/lib -o main main.cpp -lmingw32 -lSDL2
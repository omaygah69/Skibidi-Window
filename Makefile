test: main
	./main
main: main.cpp
	g++ main.cpp -o main -lSDL2 -ldl
clean:
	rm -rf main

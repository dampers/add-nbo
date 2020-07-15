all: add-nbo

add-nbo:
	g++ -o add-nbo main.cpp


clean:
	rm add-nbo

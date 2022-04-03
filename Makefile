all: run

run: build
	./build

build: $(wildcard *.c *.h)
	gcc-11 -std=c99 -O3 -fopenmp *.c -o build

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf build

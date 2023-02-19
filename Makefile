CC=gcc

all: imager

imager: utils.o functions.o image.o main.o
	$(CC) *.o -o ~/.local/bin/imager

utils.o:
	$(CC) -c utils/*.c

functions.o:
	$(CC) -c functions/*.c

image.o:
	$(CC) -c image/*.c

main.o:
	$(CC) -c main.c

clean:
	rm -rf *.o

uninstall:
	rm -rf ~/.local/bin/imager
CC=g++
LIBS=-lm 

hola: ImageProcessing.o main1.o
	$(CC) -std=c++11 ImageProcessing.o main1.o -o hola $(LIBS)
	
ImageProcessing.o: ImageProcessing.cpp ImageProcessing.h
	$(CC) -std=c++11 ImageProcessing.cpp -c

main1.o: main1.cpp
	$(CC) -std=c++11 main1.cpp -c
clean:
	@rm -f *.o
install:
	@mv hola ~/bin

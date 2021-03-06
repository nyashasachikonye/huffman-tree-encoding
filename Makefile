# Author: Kuziwa Sachikonye
# Project Title: Huffman Tree Encoding
# Date 30/03/15 30 March 2015
# File Description: Makefile

####################### MAKEFILE #######################

CPP=g++
CPPFLAGS= -std=c++11
CUSTOM_LIBRARY = /home/schkuz002/Dropbox/Schoolwork/Computer\ Science\ CSC3023F/Computer\ Science\ CSC3022H/Assignments/Assignment\ 3/Working\ Directory/HuffmanTreeEncoding
LIBS = -lm -l$(CUSTOM_LIBRARY) #Referencing System Library:

%.o: %.cpp
	$(CPP) -c -o $@ $< $(CPPFLAGS)

huffencode: HuffmanEncode.o HuffmanNode.o HuffmanTree.o
	$(CPP) -o huffencode HuffmanEncode.o HuffmanNode.o HuffmanTree.o $(CCFLAGS)

clean:
	rm -f *.o
	rm -f huffencode

run:	huffencode
	./huffencode "Assignment Resources/inputfile" "Assignment Resources/outputfile"

mktut: tut.o
	$(CPP) -o tut tut.cpp -$(CPPFLAGS)

rntut: ./tut
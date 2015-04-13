/*
 * File:   HuffmanEncode.cpp
 * Description: This is the main driver file for the Huffman Encoding Program.
 * Author: Kuziwa Sachikonye
 * Student Number: SCHKUZ002
 * Created on 30 March 2015, 9:36 AM
 */

/* Statement Description: Include statements*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "FrequencyTally.cpp"
#include "CodeTableBuilder.cpp"
#include "Development/Development.cpp"
#include "HuffmanTreeBuilder.cpp"
#include "Encoder.cpp"
#include "FileOperations.cpp"

int main(int argc, char** argv)
    {

    //Command Line Parsing
    string flnm = argv[1]; /*Statement Description: Retrieving the input filename from the command-line*/
    string oflnm = argv[2]; /*Statement Description: Retrieving the output filename from the command-line*/
    //Command Line Parsing

    //creating buffer for compression
    string cBuffer = readFile(argv[1]); /* Statement Description: Reading in the file into a string buffer*/

    unordered_map<char, int> myset = freqTable(flnm); /* Statement Description: Creating a frequency table from
                                                       * the different letters in the text-file.*/
    unordered_map<char, int>::iterator it; /* Statement Description: Creating an iterator
                                            * for traversing the unordered_map<char, int> */
    //Developmental Trace
    /* Statement Description: Print out the generated frequency table*/
    //    printMap(myset);

    priority_queue<HuffmanNode, vector<HuffmanNode>, compare> HuffmanTreeQueue;
    /* Statement Description: Create a Huffman Tree Priority Queue using the Comparator*/

    //
    for (it = myset.begin(); it != myset.end(); ++it)
        {
        shared_ptr<HuffmanNode> k(new HuffmanNode(it -> first, it -> second)); /* Statement Description: Create a Huffman Node from the first
                                                                                * element in the frequency table*/
        //Developmental Trace
        /* Statement Description: Print out the HUffman Node and its associated frequency*/
        //cout << "Huffman Node: " << it -> first << " : " << it -> second << endl;

        HuffmanTreeQueue.push(*k); /* Statement Description: Insert this created Huffman Node into the Huffman Tree Priority Queue */
        }

    shared_ptr<HuffmanTree> HuffTree = buildHuffTree(HuffmanTreeQueue);

    //Developmental Trace
    /* Statement Description: Print out the Huffman Tree to check that it has been formed correctly*/
    //printHuffmanTree(HuffTree->root);

    /* Statement Description: Create a Code Table and populate it*/
    unordered_map<char, string> codeTable;
    codeTableGen(HuffTree->root, codeTable, "");

    //Developmental Trace
    /* Statement Description: Print out the Code Table to ensure that it has been formed correctly*/
    //printMap(codeTable);

    /* Statement Description: Create an output buffer and a header file and write to the file*/
    string output = compress(cBuffer, codeTable);
    writeFile(output, oflnm);
    writeHeader(codeTable, oflnm);

    return 0; /* Statement Description: End the program*/
    }




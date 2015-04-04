/*
 * File:   HuffmanEncode.cpp
 * Author: Sach
 *
 * Created on 30 March 2015, 9:36 AM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

//Huffman Node Priority Queue Comparator

class compare

    {
public:

    bool operator()(const HuffmanNode& a, const HuffmanNode& b) //returns true is a has a lower frequency than b
        {
        return a.freq > b.freq;

        }
    };

void printMap(unordered_map<char, int> myset)
    {

    for (auto kv : myset)
        {
        cout << kv.first << ": " << kv.second << endl;
        }
    }

unordered_map<char, int> freqTable(string filename)
    {
    string line;
    unordered_map<char, int> myset;
    ifstream myfile(filename);
    while (getline(myfile, line))
        {
        for (int f = 0; f < line.length(); f++)
            {
            if (myset.count(line[f]) == 1)
                {
                myset[line[f]]++;
                } else
                {
                myset.insert(make_pair(line[f], 1));
                }
            }
        }
    myfile.close();
    return myset;
    }

int main(int argc, char** argv)
    {

    //Command Line Parsing
    string flnm = argv[1];
    //Command Line Parsing

    //create a frequency table from characters
    unordered_map<char, int> myset = freqTable(flnm);
    unordered_map<char, int>::iterator it;
    //print frequency table
    //printMap(myset);

    //adding frequency table/map to priority queue

    //Create Huffman Node Priority Queue
    //priority_queue<HuffmanNode, vector<HuffmanNode>, decltype(&compare) > HuffmanTreeQueue(&compare);
    priority_queue<HuffmanNode, vector<HuffmanNode>, compare> HuffmanTreeQueue;

    for (it = myset.begin(); it != myset.end(); ++it)
        {
        HuffmanNode k = HuffmanNode(it -> first, it -> second);
        //cout << "Frequency: " << it -> first << " " << it -> second << endl;
        HuffmanTreeQueue.push(k);
        cout << "Frequency: " << HuffmanTreeQueue.top().freq << endl;
        }


    return 0;
    }



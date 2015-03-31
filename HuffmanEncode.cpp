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

bool compare(HuffmanNode hN1, HuffmanNode hN2) //returns true is hN1 has a lower frequency than hN2
    {
    if ((hN1.freq) < (hN2.freq))
        {
        return true;
        } else
        {
        return false;
        }
    return true;
    }

//typedef bool (*comp)(int, int);
//
//bool compare(int a, int b)
//    {
//    return (a < b);
//    }

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


    unordered_map<char, int> myset = freqTable(flnm);
    //priority_queue<HuffmanNode, vector < HuffmanNode>, comp> HuffmanTreeQueue;
    std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, decltype(&compare) > HuffmanTreeQueue(&compare);

    for (auto kv : myset)
        {
        HuffmanNode *k = new HuffmanNode(kv.first, kv.second);
        //cout << "Frequency: " << k->freq << endl;
        HuffmanTreeQueue.push(*k);
        *k = HuffmanTreeQueue.top();
        cout << "Frequency: " << k->freq << endl;
        }

    return 0;
    }


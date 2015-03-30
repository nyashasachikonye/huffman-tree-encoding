/*
 * File:   HuffmanEncode.cpp
 * Author: Sach
 *
 * Created on 30 March 2015, 9:36 AM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <Vector>
#include <unordered_map>

using namespace std;

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
    printMap(freqTable(flnm));

    return 0;
    }


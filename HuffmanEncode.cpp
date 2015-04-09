/*
 * File:   HuffmanEncode.cpp
 * Author: Kuziwa Sachikonye
 * Student Number: SCHKUZ002
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

void printMap(unordered_map<char, string> myset)
    {

    for (auto kv : myset)
        {
        cout << kv.first << ": " << kv.second << endl;
        }
    }

void printMap(unordered_map<char, int> myset)
    {

    for (auto kv : myset)
        {
        cout << kv.first << ": " << kv.second << endl;
        }
    }

unordered_map<char, int> freqTable(string filename)
    {
    char line;
    unordered_map<char, int> myset;
    ifstream myfile(filename);
    while (myfile >> noskipws >> line)
        {
        if (myset.count(line) == 1)
            {
            myset[line]++;
            } else
            {
            myset.insert(make_pair(line, 1));
            }
        }
    myfile.close();
    return myset;
    }

void codeTableGen(shared_ptr<HuffmanNode> root, unordered_map<char, string> &map, string code)
    {
    if (root->left != nullptr)
        {
        codeTableGen(root->left, map, code + "0");
        }
    if ((root->left == nullptr)&&(root->right == nullptr)) //checking leaf
        {
        map.insert(make_pair(root->value, code));
        }

    if (root->right != nullptr)
        {
        codeTableGen(root->right, map, code + "1");
        }
    }

string readFile(string filename)
    {
    char line;
    string a;
    ifstream myfile(filename);
    while (myfile >> noskipws >> line)
        {
        a += line;
        }
    myfile.close();
    return a;
    }

void printHuffmanTree(shared_ptr<HuffmanNode> root)
    {

    if (root->left != nullptr)
        {
        printHuffmanTree(root->left);
        }
    if ((root->left == nullptr)&&(root->right == nullptr))
        {
        cout << root->value << " : " << root->freq << endl;
        }
    if (root->right != nullptr)
        {
        printHuffmanTree(root->right);
        }
    }

string compress(string cBuffer, unordered_map<char, string> codeTable)
    {
    string out;

    for (int k = 0; k < cBuffer.length(); k++)
        {
        //        out += "." + codeTable.at((cBuffer[k]));
        out += codeTable.at((cBuffer[k]));
        }
    return out;
    }

void writeFile(string buffer, string filename)
    {
    ofstream out(filename);
    out << buffer;
    out.close();
    }

void writeHeader(unordered_map<char, string> cMap, string flm)
    {
    flm = flm + ".hdr";
    ofstream out(flm);
    //write field count
    out << "Field Count: " << cMap.size() << "\n\n";
    for (auto kv : cMap)
        {
        //        if (kv.first == '_')
        //            {
        //            kv.first = ' ';
        //            }
        //        if (kv.first == '/')
        //            {
        //            kv.first = '\n';
        //            }
        out << kv.first << ": " << kv.second << endl;
        }
    out.close();

    }

int main(int argc, char** argv)
    {

    //Command Line Parsing
    string flnm = argv[1];
    string oflnm = argv[2];
    //Command Line Parsing

    //creating buffer for compression
    string cBuffer = readFile(argv[1]);

    //create a frequency table from characters
    unordered_map<char, int> myset = freqTable(flnm);
    unordered_map<char, int>::iterator it;
    //print frequency table
    //    printMap(myset);

    //Create Huffman Node Priority Queue
    priority_queue<HuffmanNode, vector<HuffmanNode>, compare> HuffmanTreeQueue;

    for (it = myset.begin(); it != myset.end(); ++it)
        {
        shared_ptr<HuffmanNode> k(new HuffmanNode(it -> first, it -> second));
        //cout << "Huffman Node: " << it -> first << " : " << it -> second << endl;
        HuffmanTreeQueue.push(*k);
        }

    //building tree
    while (HuffmanTreeQueue.size() > 1)
        {
        //        cout << "Queue Size: " << HuffmanTreeQueue.size() << endl;
        shared_ptr<HuffmanNode> left = make_shared<HuffmanNode>(HuffmanTreeQueue.top());
        HuffmanTreeQueue.pop();
        //        cout << "Queue Size: " << HuffmanTreeQueue.size() << endl;
        //cout << "LHS: " << left->value << ": " << left->freq << endl;
        shared_ptr<HuffmanNode> right = make_shared<HuffmanNode>(HuffmanTreeQueue.top());
        HuffmanTreeQueue.pop();
        //cout << "Queue Size: " << HuffmanTreeQueue.size() << endl;
        //cout << "RHS: " << right->value << " : " << right->freq << endl;
        //cout << endl;
        shared_ptr<HuffmanNode> parent(new HuffmanNode((left->freq + right->freq)));
        parent->left = left;
        parent->right = right;
        //        HuffmanNode parent = new HuffmanNode(' ', (left.freq + right.freq));
        //cout << "Parent: " << parent->value << " " << parent->freq << endl;
        //cout << "Children: Left Freq: " << parent->left->freq << " Right Freq: " << parent->right->freq << endl;
        HuffmanTreeQueue.push(*parent);
        //cout << "Queue Size: " << HuffmanTreeQueue.size() << endl;
        //cout << endl;
        }

    HuffmanTree *hTree = new HuffmanTree(HuffmanTreeQueue.top());
    //move tree to hTree from the queue
    //then delete the queue.

    //HuffmanNode r = HuffmanTreeQueue.top();
    shared_ptr<HuffmanNode> t = make_shared<HuffmanNode>(HuffmanTreeQueue.top());
    //printHuffmanTree(t);
    unordered_map<char, string> codeTable;
    codeTableGen(t, codeTable, "");
    //    cout << "++++++++++++++++++" << endl;
    //printMap(codeTable);
    string output = compress(cBuffer, codeTable);
    writeFile(output, oflnm);
    writeHeader(codeTable, oflnm);

    return 0;
    }




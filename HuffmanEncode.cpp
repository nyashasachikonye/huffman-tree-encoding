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
#include <memory>

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

void printHuffmanTree(HuffmanNode *HuffmanTree)
    {
    cout << HuffmanTree->value << " : " << HuffmanTree->freq << endl;
    if (HuffmanTree->left != nullptr)
        {
        printHuffmanTree(HuffmanTree->left);
        cout << "     ";
        printHuffmanTree(HuffmanTree->right);
        cout << endl;
        } else
        {
        //cout << "     " << endl;
        }

    }

void codeTableGen(HuffmanNode *HuffmanTree)
    {
    string code;
    cout << HuffmanTree->value << " : " << HuffmanTree->freq << endl;
    if (HuffmanTree->left != nullptr)
        {

        printHuffmanTree(HuffmanTree->left);
        printHuffmanTree(HuffmanTree->right);
        cout << endl;
        } else
        {
        }

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

    //Create Huffman Node Priority Queue
    priority_queue<HuffmanNode, vector<HuffmanNode>, compare> HuffmanTreeQueue;

    for (it = myset.begin(); it != myset.end(); ++it)
        {
        shared_ptr<HuffmanNode> k(new HuffmanNode(it -> first, it -> second));
        HuffmanTreeQueue.push(*k);
        }

    //building tree

    while (HuffmanTreeQueue.size() > 1)
        {
        //cout << "Queue Size: " << HuffmanTreeQueue.size() << endl;
        HuffmanNode left = HuffmanTreeQueue.top();
        HuffmanTreeQueue.pop();
        //cout << "Queue Size: " << HuffmanTreeQueue.size() << endl;
        //cout << "Left: " << left.value << " " << left.freq << endl;
        HuffmanNode right = HuffmanTreeQueue.top();
        HuffmanTreeQueue.pop();
        //cout << "Queue Size: " << HuffmanTreeQueue.size() << endl;
        //cout << "Right: " << right.value << " " << right.freq << endl;
        //cout << endl;
        HuffmanNode *parent = new HuffmanNode(' ', (left.freq + right.freq));
        parent->left = &left;
        parent->right = &right;
        //HuffmanNode parent = new HuffmanNode(' ', (left.freq + right.freq));
        //cout << "Parent: " << parent->value << " " << parent->freq << endl;
        //cout << "Children: Left Freq: " << parent->left->freq << " Right Freq: " << parent->right->freq << endl;
        HuffmanTreeQueue.push(*parent);
        //cout << "Queue Size: " << HuffmanTreeQueue.size() << endl;
        //cout << endl;
        }

    //HuffmanTree *hTree = new HuffmanTree(HuffmanTreeQueue.top());
    //move tree to hTree from the queue
    //then delete the queue.

    HuffmanNode *root = new HuffmanNode(' ', 10);
    HuffmanNode *a = new HuffmanNode('a', 4);
    HuffmanNode *b = new HuffmanNode(' ', 6);
    HuffmanNode *c = new HuffmanNode('d', 3);
    HuffmanNode *d = new HuffmanNode(' ', 3);
    HuffmanNode *e = new HuffmanNode('c', 1);
    HuffmanNode *f = new HuffmanNode('b', 2);
    root->left = a;
    root->right = b;
    b->left = c;
    b->right = d;
    d->left = e;
    d->right = f;

    //    cout << endl;
    //cout << "++++++++++++++++++" << endl;
    HuffmanNode r = HuffmanTreeQueue.top();
    HuffmanNode * t = &r;
    //    cout << r.freq << endl;
    //    cout << r.left->freq << endl;
    //    cout << " " << r.right->freq << endl;
    //    cout << r.right->left->freq << endl;
    //    cout << " " << r.right->right->freq << endl;

    printHuffmanTree(t);

    return 0;
    }




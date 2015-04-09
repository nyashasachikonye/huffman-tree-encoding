/*
 * File:   HuffmanNode.h
 * Author: Sach
 *
 * Created on 30 March 2015, 5:09 PM
 */

#ifndef HUFFMANNODE_H
#define	HUFFMANNODE_H

#include <memory>

using namespace std;

class HuffmanNode {
private:


public:

    char value;
    shared_ptr<HuffmanNode> left;
    //HuffmanNode *left;
    shared_ptr<HuffmanNode> right;
    //HuffmanNode *right;
    int freq;

    HuffmanNode();

    HuffmanNode(char v, int frq); //TODO: Complete Huffman Node Default Constructor
    //TODO: Complete Huffman Node Move Constructor

    HuffmanNode(int frq);

    HuffmanNode(const HuffmanNode& orig); //TODO: Complete Huffman Node Copy Constructor
    ~HuffmanNode(); //TODO: Complete Huffman Node Destructor
    //TODO: Create Huffman Node Assignment Operator
    //TODO: Create Huffman Node Move Assignment operator

    int getFreq(); //obtain the frequency of the letter
    char getValue(); //obtain the value of the node
};

#endif	/* HUFFMANNODE_H */


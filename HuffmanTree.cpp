/*
 * File:   HuffmanTree.cpp
 * Description: This is the .cpp file for the Huffman Tree Class containing
 * method implementations and the 6 memeber functions.
 * Author: Kuziwa Sachikonye
 * Student Number: SCHKUZ002
 * Created on 30 March 2015, 5:39 PM
 */

/* Statement Description: Include Statements*/
#include "HuffmanTree.h"
#include "HuffmanNode.h"

/* Statement Description: Huffman Tree Constructor*/
HuffmanTree::HuffmanTree(HuffmanNode rt)
    {
    root = make_shared<HuffmanNode>(rt);
    }

/* Statement Description: Huffman Tree Default Constructor*/
HuffmanTree::HuffmanTree() { }

/* Statement Description: Huffman Tree Copy Assignment*/
HuffmanTree::HuffmanTree(const HuffmanTree& orig)
    {
    root = orig.root; /* Statement Description: Copy over the contents of the root*/
    }

/* Statement Description: Huffman Tree Destructor*/
HuffmanTree::~HuffmanTree()
    {
    root = nullptr; /* Statement Description: Set the root to null thereby deleting null pointers*/
    }
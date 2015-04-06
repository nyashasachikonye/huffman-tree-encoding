/*
 * File:   HuffmanTree.cpp
 * Author: Sach
 *
 * Created on 30 March 2015, 5:39 PM
 */

#include "HuffmanTree.h"
#include "HuffmanNode.h"

using namespace std;

HuffmanTree::HuffmanTree(HuffmanNode rt)
    {
    root = rt;
    }

HuffmanTree::HuffmanTree() {
    //fill in
    }

HuffmanTree::HuffmanTree(const HuffmanTree& orig) { }

HuffmanTree::~HuffmanTree() { }
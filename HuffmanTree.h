/*
 * File:   HuffmanTree.h
 * Author: Sach
 *
 * Created on 30 March 2015, 5:39 PM
 */

#ifndef HUFFMANTREE_H
#define	HUFFMANTREE_H
#include "HuffmanNode.h"

//using namespace std;

class HuffmanTree {
private:
public:
    HuffmanNode root;

    HuffmanTree(); //TODO: Complete Huffman Tree Default Constructor
    HuffmanTree(HuffmanNode rt);
    HuffmanTree(const HuffmanTree& orig);
    ~HuffmanTree();


private:

};

#endif	/* HUFFMANTREE_H */


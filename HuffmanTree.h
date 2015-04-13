/*
 * File:   HuffmanTree.h
 * Description: This is the header file for the Huffman Tree Class
 * Author: Kuziwa Sachikonye
 * Student Number: SCHKUZ002
 * Created on 30 March 2015, 5:39 PM
 */


#ifndef HUFFMANTREE_H
#define	HUFFMANTREE_H
#include "HuffmanNode.h"


class HuffmanNode; /* Statement Description: Including a pointer to the Huffman Node Class*/

class HuffmanTree {
public:

    shared_ptr<HuffmanNode> root;

    HuffmanTree();
    HuffmanTree(HuffmanNode rt);
    HuffmanTree(const HuffmanTree& orig);
    ~HuffmanTree();

};

class compare {
    /* Class Definition:
     * This class hold simply holds the comparator for the Huffman Node Priority Queue.
     */
public:

    bool operator()(const HuffmanNode& a, const HuffmanNode& b) //returns true is a has a lower frequency than b
    {
        /* Function Definition:
         * This function serves to compare two Huffman Nodes. The function precludes
         * the priority structure for the priority queue. This function returns true
         * if the first Huffman Node has a lower frequency than the second Huffman Node.
         */
        return a.freq > b.freq;
    }
};

#endif	/* HUFFMANTREE_H */


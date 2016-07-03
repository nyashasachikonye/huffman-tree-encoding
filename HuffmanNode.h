/*
 * File:   HuffmanNode.h
 * Author: Sach
 *
 * Created on 30 March 2015, 5:09 PM
 */

#ifndef HUFFMANNODE_H
#define	HUFFMANNODE_H

#include <memory>

class HuffmanNode {
private:


public:

    char value;
    std::shared_ptr<HuffmanNode> left;

    std::shared_ptr<HuffmanNode> right;

    int freq;

    HuffmanNode(void) = default;

    HuffmanNode(char v, int frq);

    HuffmanNode(int frq);

    HuffmanNode(const HuffmanNode& orig);

    HuffmanNode(HuffmanNode && rhs) = default;

    HuffmanNode & operator=(const HuffmanNode & rhs) = default;
    HuffmanNode & operator=(HuffmanNode && rhs) = default;

    ~HuffmanNode();

};

#endif	/* HUFFMANNODE_H */


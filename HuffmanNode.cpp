/*
 * File:   HuffmanNode.cpp
 * Author: Sach
 *
 * Created on 30 March 2015, 5:09 PM
 */

#include <cstddef>
#include "HuffmanNode.h"

using namespace std;

HuffmanNode::HuffmanNode(char v, int frq)
    {
    value = v;
    freq = frq;
    left = nullptr;
    right = nullptr;
    }

HuffmanNode::HuffmanNode(const HuffmanNode& orig) { }

HuffmanNode::~HuffmanNode() { }




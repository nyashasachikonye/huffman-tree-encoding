#include "HuffmanTree.h"

std::shared_ptr<HuffmanTree> buildHuffTree(std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, compare> &HuffmanTreeQueue)
    {

    /*Description: Constructing a Huffman Tree by selecting the first two nodes from the top of the Huffman Tree Queue and aggregate
     * them into one. They will will form the children and the sum of their frequencies will be the frequency of the parent. */
    while (HuffmanTreeQueue.size() > 1)
        {
        /* Statement Description: Obtain the first element from the Huffman Tree Queue and set it as a left child*/
        std::shared_ptr<HuffmanNode> left = std::make_shared<HuffmanNode>(HuffmanTreeQueue.top());
        HuffmanTreeQueue.pop(); /* Statement Description: Remove the element from the Huffman Tree Queue*/

        //Developmental Trace
        /* Statement Description: Print out the left child of the Huffman Parent Node to be formed
         * and its associated frequency*/
        //cout << "LHS: " << left->value << ": " << left->freq << endl;

        /* Statement Description: Obtain the next element from the Huffman Tree Queue and set it to the right child*/
        std::shared_ptr<HuffmanNode> right = std::make_shared<HuffmanNode>(HuffmanTreeQueue.top());
        HuffmanTreeQueue.pop(); /* Statement Description: Remove the element from the Huffman Tree Queue*/

        //Developmental Trace
        /* Statement Description: Print out the right child of the Huffman Parent Node to be formed
         * and its associated frequency*/
        //cout << "RHS: " << right->value << " : " << right->freq << endl;
        //cout << endl;

        /* Statement Description: Combine the left and the right child by creating a parent Huffman Node and
         * setting its frequency to the sum of the frequencies of the child Huffman Nodes.*/
        std::shared_ptr<HuffmanNode> parent(new HuffmanNode((left->freq + right->freq)));
        parent->left = left;
        parent->right = right;

        //Developmental Trace
        /* Statement Description: Print out the parent Huffman Node's frequency and the respective frequencies of the children */
        //cout << "Parent: " << parent->value << " " << parent->freq << endl;
        //cout << "Children: Left Freq: " << parent->left->freq << " Right Freq: " << parent->right->freq << endl;

        HuffmanTreeQueue.push(*parent); /* Statement Description: Insert this aggregated tree structure into the Huffman Tree Priority Queue*/
        }

    std::shared_ptr<HuffmanTree> HuffTree = std::make_shared<HuffmanTree>(HuffmanTreeQueue.top()); /* Statement Description: Create a Huffman Tree Object
                                                                   * from  the Huffman Node left in the Huffman Tree Priority Queue*/

    HuffmanTreeQueue.pop(); /* Statement Description: Empty the Huffman Tree Priority Queue (effectively deleting it)*/

    return HuffTree;

    }
#include "../HuffmanTree.h"

void printMap(std::unordered_map<char, std::string> myset)
    {
    /* Function Definition:
     * This is a developmental function used to print out an unordered map. This
     * is used to trace that the correct contents have been written to the Code
     * Table.
     */

    for (auto kv : myset)
        {
        std::cout << kv.first << ": " << kv.second << std::endl;
        }
    }

void printMap(std::unordered_map<char, int> myset)
    {
    /* Function Definition:
     * This is a developmental function used to print out an unordered map. This
     * is used to trace that the correct contents have been written to the frequency map.
     */

    for (auto kv : myset)
        {
        std::cout << kv.first << ": " << kv.second << std::endl;
        }
    }

void printHuffmanTree(std::shared_ptr<HuffmanNode> root)
    {
    /* Function Definition:
     * This function is a developmental function used to trace the contents of
     * the Huffman Tree. It provides an in order traversal of the Huffman Tree
     * and outputs each one the the leaves (letters) and their frequency of occurence
     * in the text-file.
     */

    if (root->left != nullptr)
        {
        printHuffmanTree(root->left);
        }
    if ((root->left == nullptr)&&(root->right == nullptr))
        {
        std::cout << root->value << " : " << root->freq << std::endl;
        }
    if (root->right != nullptr)
        {
        printHuffmanTree(root->right);
        }
    }
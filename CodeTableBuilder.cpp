#include <unordered_map>
//#include "HuffmanNode.h"
#include "HuffmanTree.h"

void codeTableGen(std::shared_ptr<HuffmanNode> root, std::unordered_map<char, std::string> &map, std::string code)
    {
    /* Function Definition:
     * This recursive function traverses the HuffmanTree and creates a code table based on
     * the entries found in the Huffman Tree. The code that each letter receives is
     * based on the location of that letter in the Huffman Tree. Whilst traversing the tree
     * if we traverse left we append a "0" to the code for that respective letter
     * and if we traverse right then we append a "1" to the code. The final code is
     * the Huffman Code for that letter.
     */
    if (root->left != nullptr) /* Statement Description: As long as there is a left child, we
                                * first traverse down all the children here generating a "0".*/
        {
        codeTableGen(root->left, map, code + "0"); /* Statement Description: Add a "0" to the Huffman Code for the letter.*/
        }
    if ((root->left == nullptr)&&(root->right == nullptr)) /* Statement Description: If we reach a Huffman Node without any children
                                                            this represents a letter and thus we finally insert this element and the final code
                                                            into the code table.*/
        {
        map.insert(std::make_pair(root->value, code)); /* Statement Description: Inserting the letter and its respective code into the Code Table*/
        }

    if (root->right != nullptr) /* Statement Description: As long as there is a right child, we
                                * first traverse down all the children here generating a "1".*/
        {
        codeTableGen(root->right, map, code + "1"); /* Statement Description: Add a "1" to the Huffman Code for the letter.*/
        }
    }
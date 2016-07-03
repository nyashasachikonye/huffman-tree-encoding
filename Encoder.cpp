#include "HuffmanTree.h"

std::string compress(std::string cBuffer, std::unordered_map<char, std::string> codeTable)
    {
    /* Function Definition:
     * This function creates an output buffer by converting all the chars in the
     * text-file and write out their Huffman Equivalent.
     */
    std::string out;

    for (int k = 0; k < cBuffer.length(); k++)
        {
        out += codeTable.at((cBuffer[k]));
        }
    return out;
    }

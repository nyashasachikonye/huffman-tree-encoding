#include "HuffmanTree.h"

string compress(string cBuffer, unordered_map<char, string> codeTable)
    {
    /* Function Definition:
     * This function creates an output buffer by converting all the chars in the
     * text-file and write out their Huffman Equivalent.
     */
    string out;

    for (int k = 0; k < cBuffer.length(); k++)
        {
        out += codeTable.at((cBuffer[k]));
        }
    return out;
    }

#include <unordered_map>
//#include "HuffmanNode.h"
#include "HuffmanTree.h"

unordered_map<char, int> freqTable(string filename)
    {
    /* Function Definition:
     * This function creates the frequency table by reading in a text file and
     * creating an unordered_map<char, int> that will hold the different chars found
     * in the file and the frequency of each char.
     */

    char line;
    unordered_map<char, int> myset;
    ifstream myfile(filename);
    while (myfile >> noskipws >> line) /* Statement Description: "noskipws" is used so that white-spaces (including newlines)
                                        * are also read into the program.*/
        {
        if (myset.count(line) == 1) /* Statement Description: If the letter already exists in the container then increment the frequency by one*/
            {
            myset[line]++;
            } else
            {
            myset.insert(make_pair(line, 1)); /* Statement Description: If the letter does not exist, create an instance of that letter in the container
                                               * with a frequency of 1*/
            }
        }
    myfile.close();
    return myset;
    }
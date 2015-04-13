#include "HuffmanTree.h"

string readFile(string filename)
    {
    /* Function Definition:
     * This function reads in the file and creates a string buffer with the contents of the file.
     */
    char line;
    string a;
    ifstream myfile(filename);
    while (myfile >> noskipws >> line) /* Statement Description: "noskipws" is used so that white-spaces (including newlines)
                                        * are also read into the program.*/
        {
        a += line; /* Statement Description: Append each letter to the buffer*/
        }
    myfile.close();
    return a;
    }

void writeFile(string buffer, string filename)
    {
    /* Function Definition:
     * This function writes the string buffer to the output-file specified.
     */
    ofstream out(filename);
    out << buffer;
    out.close();
    }

void writeHeader(unordered_map<char, string> cMap, string flm)
    {
    /* Function Definition:
     * This function creates the header file for the conversion, it states the
     * number of different fields that were found the file and then proceeds to
     * write them out to a header file "output-file.hdr"
     */
    flm = flm + ".hdr"; /* Statement Description: Appending the header prefix to the output-file*/
    ofstream out(flm);
    out << "Field Count: " << cMap.size() << "\n\n";
    for (auto kv : cMap)
        {
        out << kv.first << ": " << kv.second << endl;
        }
    out.close();

    }

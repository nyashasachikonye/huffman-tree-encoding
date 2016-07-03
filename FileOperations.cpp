#include "HuffmanTree.h"

std::string readFile(std::string filename)
    {
    /* Function Definition:
     * This function reads in the file and creates a string buffer with the contents of the file.
     */
    char line;
    std::string a;
    std::ifstream myfile(filename);
    while (myfile >> std::noskipws >> line) /* Statement Description: "noskipws" is used so that white-spaces (including newlines)
                                        * are also read into the program.*/
        {
        a += line; /* Statement Description: Append each letter to the buffer*/
        }
    myfile.close();
    return a;
    }

void writeFile(std::string buffer, std::string filename)
    {
    /* Function Definition:
     * This function writes the string buffer to the output-file specified.
     */
    std::ofstream out(filename);
    out << buffer;
    out.close();
    }

void writeHeader(std::unordered_map<char, std::string> cMap, std::string flm)
    {
    /* Function Definition:
     * This function creates the header file for the conversion, it states the
     * number of different fields that were found the file and then proceeds to
     * write them out to a header file "output-file.hdr"
     */
    flm = flm + ".hdr"; /* Statement Description: Appending the header prefix to the output-file*/
    std::ofstream out(flm);
    out << "Field Count: " << cMap.size() << "\n\n";
    for (auto kv : cMap)
        {
        out << kv.first << ": " << kv.second << std::endl;
        }
    out.close();

    }

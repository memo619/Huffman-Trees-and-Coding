#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include "BinSearchTree.hpp"
#include "PriorityQueue.hpp"
#include "Scanner.hpp"
#include "utils.hpp"
#include "HuffmanTree.hpp"

using namespace std;

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        cerr << "Usage: " << argv[0] << " <input_file.txt>\n";
        return 1;
    }
    
    namespace fs = std::filesystem;
    
    const std::string dirName = "input_output";
    const std::string baseFile = std::string(argv[1]);
    const std::string inputFileName = dirName + "/" + baseFile;
    const std::string inputFileBaseName = baseNameWithoutTxt(baseFile);
    
    const string wordTokensFileName = dirName + "/" + inputFileBaseName + ".tokens";
    const string freqFileName = dirName + "/" + inputFileBaseName + ".freq";
    const string hdrFileName = dirName + "/" + inputFileBaseName + ".hdr"; 
    const string codeFileName = dirName + "/" + inputFileBaseName + ".code";
    
    if (error_type status; (status = regularFileExistsAndIsAvailable(inputFileName)) != NO_ERROR)
        exitOnError(status, inputFileName);
    
    if (error_type status; (status = directoryExists(dirName)) != NO_ERROR)
        exitOnError(status, dirName);
    
    if (error_type status; (status = canOpenForWriting(wordTokensFileName)) != NO_ERROR)
        exitOnError(status, wordTokensFileName);
    
    if (error_type status; (status = canOpenForWriting(freqFileName)) != NO_ERROR)
        exitOnError(status, freqFileName);
    
    vector<string> words;
    Scanner fileToWords(inputFileName);
    
    if (error_type status; (status = fileToWords.tokenize(words)) != NO_ERROR)
        exitOnError(status, inputFileName);
    
    if (error_type status; (status = writeVectorToFile(wordTokensFileName, words)) != NO_ERROR)
        exitOnError(status, wordTokensFileName);
    
    BinSearchTree bst;
    bst.bulkInsert(words);
    
    vector<pair<string, size_t>> frequencies;
    bst.inorderCollect(frequencies);
    
    unsigned treeHeight = bst.height();
    size_t uniqueWords = bst.size();
    size_t totalTokens = words.size();
    
    size_t minFreq = 0;
    size_t maxFreq = 0;
    
    if (!frequencies.empty()) 
    {
        minFreq = frequencies[0].second;
        maxFreq = frequencies[0].second;
        
        for (const auto& [word, count] : frequencies) 
        {
            minFreq = min(minFreq, count);
            maxFreq = max(maxFreq, count);
        }
    }
    
    cout << "BST height: " << treeHeight << '\n';
    cout << "BST unique words: " << uniqueWords << '\n';
    cout << "Total tokens: " << totalTokens << '\n';
    cout << "Min frequency: " << minFreq << '\n';
    cout << "Max frequency: " << maxFreq << '\n';
    
    PriorityQueue pq(frequencies);
    pq.writeFreqFile(freqFileName);
    HuffmanTree huffman;
    huffman.buildFromFrequencies(frequencies);
    huffman.writeHeader(hdrFileName);
    huffman.encode(words, codeFileName);
    
    return 0;
}
//
// Created by Ali Kooshesh on 9/27/25.
//

#include "Scanner.hpp"

#include<utility>
#include <fstream>
#include "utils.hpp"

Scanner::Scanner(std::filesystem::path inputPath) 

    : inputPath_(std::move(inputPath))
     {
        if (inputPath_.has_extension() && inputPath_.extension() == ".tokens")
        {
            inputPath_.replace_extension(".txt");
        }
        
     }

error_type Scanner::tokenize(std::vector<std::string>& words)
 {
    std::ifstream inFile(inputPath_);
    
    if (!inFile.is_open()) 
    {
        return UNABLE_TO_OPEN_FILE;
    }
    
    words.clear();
    
    std::string word;
    while (!(word = readWord(inFile)).empty()) 
    {
        words.push_back(word);
    }
    
    if (inFile.bad()) 
    {
        return UNABLE_TO_OPEN_FILE;
    }
    
    return NO_ERROR;
}

std::string Scanner::readWord(std::istream& input)
 {
    std::string word;
    char character;

    while (input.get(character)) 
    {   
        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
        {
            word.push_back(tolower(character));
            break;
        }
    }
    
    if (word.empty()) 
    {
        return "";
    }
    
    while (input.get(character)) 
    {        
        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
        {
            word.push_back(tolower(character));
        }
        else if (character == '\'') 
        {
            char nextChar;
            if (input.get(nextChar)) 
            {                
                if ((nextChar >= 'a' && nextChar <= 'z') || (nextChar >= 'A' && nextChar <= 'Z')) 
                {
                    word.push_back('\'');
                    word.push_back(tolower(nextChar));
                }

                else
                {
                    input.putback(nextChar);
                    break;
                }
                

            }
            else
            {
                 break;
            }

        }

        else
        {
            input.putback(character);
            break;
        }

    }
    
    return word;
}
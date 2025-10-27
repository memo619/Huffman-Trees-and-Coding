#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <string>

struct TreeNode 
{
    std::string word;
    size_t count;
    size_t freq;
    std::string key_word;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(const std::string& w, size_t c = 1)
        : word(w), count(c), freq(c), key_word(w), left(nullptr), right(nullptr) 
        {

        }
    
    TreeNode(size_t f, std::string& kw, TreeNode* l, TreeNode* r)
        : word(""), count(0), freq(f), key_word(kw), left(l), right(r) 
        {

        }
    
    bool isLeaf() 
    {
        return left == nullptr && right == nullptr;
    }
};

#endif
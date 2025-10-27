#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "TreeNode.hpp"

class HuffmanTree 
{
public:
    HuffmanTree();
    ~HuffmanTree();
    
    void buildFromFrequencies(const std::vector<std::pair<std::string, size_t>>& frequencies);
    void writeHeader(const std::string& filename) const;
    void encode(const std::vector<std::string>& tokens, const std::string& filename) const;
    
private:
    TreeNode* root_;
    std::unordered_map<std::string, std::string> codebook_;
    
    void buildCodebook(TreeNode* node, const std::string& code);
    void writeHeaderHelper(TreeNode* node, const std::string& code, std::ofstream& out) const;
    void destroy(TreeNode* node);
};

#endif
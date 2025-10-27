#include "HuffmanTree.hpp"
#include "PriorityQueue.hpp"
#include <fstream>
#include <algorithm>

using namespace std;

HuffmanTree::HuffmanTree() : root_(nullptr) 
{
}

HuffmanTree::~HuffmanTree() 
{
    destroy(root_);
}

void HuffmanTree::destroy(TreeNode* node) 
{
    if (node == nullptr) 
    {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

void HuffmanTree::buildFromFrequencies(const vector<pair<string, size_t>>& frequencies) 
{
    if (frequencies.empty()) 
    {
        root_ = nullptr;
        return;
    }
    
    if (frequencies.size() == 1) 
    {
        root_ = new TreeNode(frequencies[0].first, frequencies[0].second);
        codebook_[frequencies[0].first] = "0";
        return;
    }
    
    vector<TreeNode*> nodes;
    for (const auto& [word, count] : frequencies) 
    {
        TreeNode* leaf = new TreeNode(word, count);
        leaf->freq = count;
        leaf->key_word = word;
        nodes.push_back(leaf);
    }
    
    PriorityQueue pq(nodes);
    
    while (pq.size() > 1) 
    {
        TreeNode* left = pq.extractMin();
        TreeNode* right = pq.extractMin();
        
        size_t combinedFreq = left->freq + right->freq;
        string combinedKey = (left->key_word < right->key_word) ? left->key_word : right->key_word;
        
        TreeNode* parent = new TreeNode(combinedFreq, combinedKey, left, right);
        pq.insert(parent);
    }
    
    root_ = pq.extractMin();
    
    buildCodebook(root_, "");
}

void HuffmanTree::buildCodebook(TreeNode* node, const string& code) 
{
    if (node == nullptr) 
    {
        return;
    }
    
    if (node->isLeaf()) 
    {
        if (code.empty()) 
        {
            codebook_[node->word] = "0";
        }
        else 
        {
            codebook_[node->word] = code;
        }
        return;
    }
    
    buildCodebook(node->left, code + "0");
    buildCodebook(node->right, code + "1");
}

void HuffmanTree::writeHeader(const string& filename) const 
{
    ofstream out(filename);
    if (!out.is_open()) 
    {
        return;
    }
    
    writeHeaderHelper(root_, "", out);
}

void HuffmanTree::writeHeaderHelper(TreeNode* node, const string& code, ofstream& out) const 
{
    if (node == nullptr) 
    {
        return;
    }
    
    if (node->isLeaf()) 
    {
        if (code.empty()) 
        {
            out << node->word << " 0\n";
        }
        else 
        {
            out << node->word << " " << code << "\n";
        }
        return;
    }
    
    writeHeaderHelper(node->left, code + "0", out);
    writeHeaderHelper(node->right, code + "1", out);
}

void HuffmanTree::encode(const vector<string>& tokens, const string& filename) const 
{
    ofstream out(filename);
    if (!out.is_open()) 
    {
        return;
    }
    
    string bitstream;
    for (const auto& token : tokens) 
    {
        auto it = codebook_.find(token);
        if (it != codebook_.end()) 
        {
            bitstream += it->second;
        }
    }
    
    int col = 0;
    for (char bit : bitstream) 
    {
        out << bit;
        col++;
        if (col == 80) 
        {
            out << '\n';
            col = 0;
        }
    }
    
    if (col > 0) 
    {
        out << '\n';
    }
}
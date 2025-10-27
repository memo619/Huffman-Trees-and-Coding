#include "BinSearchTree.hpp"
#include <algorithm>

using namespace std;

BinSearchTree::~BinSearchTree() 
{
    destroy(root_);
}

void BinSearchTree::destroy(TreeNode* node) noexcept 
{
    if (node == nullptr) 
    {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

void BinSearchTree::insert(const string& word) 
{
    root_ = insertHelper(root_, word);
}

TreeNode* BinSearchTree::insertHelper(TreeNode* node, const string& word) 
{
    if (node == nullptr) 
    {
        return new TreeNode(word, 1);
    }
    
    if (word == node->word) 
    {
        node->count++;
        return node;
    }
    
    if (word < node->word) 
    {
        node->left = insertHelper(node->left, word);
    }
    else 
    {
        node->right = insertHelper(node->right, word);
    }
    return node;
}

void BinSearchTree::bulkInsert(const vector<string>& words) 
{
    for (const auto& word : words) 
    {
        insert(word);
    }
}

bool BinSearchTree::contains(string_view word) const noexcept 
{
    return findNode(root_, word) != nullptr;
}

optional<size_t> BinSearchTree::countOf(string_view word) const noexcept 
{
    const TreeNode* node = findNode(root_, word);
    if (node == nullptr) 
    {
        return nullopt;
    }
    return node->count;
}

const TreeNode* BinSearchTree::findNode(const TreeNode* node, string_view word) noexcept 
{
    if (node == nullptr) 
    {
        return nullptr;
    }
    
    if (word == node->word) 
    {
        return node;
    }
    
    if (word < node->word) 
    {
        return findNode(node->left, word);
    }
    else 
    {
        return findNode(node->right, word);
    }
}

void BinSearchTree::inorderCollect(vector<pair<string, size_t>>& out) const 
{
    inorderHelper(root_, out);
}

void BinSearchTree::inorderHelper(const TreeNode* node, vector<pair<string, size_t>>& out) 
{
    if (node == nullptr) 
    {
        return;
    }
    inorderHelper(node->left, out);
    out.push_back({node->word, node->count});
    inorderHelper(node->right, out);
}

size_t BinSearchTree::size() const noexcept 
{
    return sizeHelper(root_);
}

size_t BinSearchTree::sizeHelper(const TreeNode* node) noexcept 
{
    if (node == nullptr) 
    {
        return 0;
    }
    return 1 + sizeHelper(node->left) + sizeHelper(node->right);
}

unsigned BinSearchTree::height() const noexcept 
{
    return heightHelper(root_);
}

unsigned BinSearchTree::heightHelper(const TreeNode* node) noexcept 
{
    if (node == nullptr) 
    {
        return 0;
    }
    unsigned leftHeight = heightHelper(node->left);
    unsigned rightHeight = heightHelper(node->right);
    return 1 + max(leftHeight, rightHeight);
}
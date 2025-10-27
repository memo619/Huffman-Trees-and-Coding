#ifndef BINSEARCHTREE_HPP
#define BINSEARCHTREE_HPP

#include <string>
#include <vector>
#include <optional>
#include "TreeNode.hpp"

class BinSearchTree 
{
public:
    BinSearchTree() = default;
    ~BinSearchTree();
    
    BinSearchTree(const BinSearchTree&) = delete;
    BinSearchTree& operator=(const BinSearchTree&) = delete;
    
    void insert(const std::string& word);
    void bulkInsert(const std::vector<std::string>& words);
    bool contains(std::string_view word) const noexcept;
    std::optional<size_t> countOf(std::string_view word) const noexcept;
    void inorderCollect(std::vector<std::pair<std::string, size_t>>& out) const;
    size_t size() const noexcept;
    unsigned height() const noexcept;
    
private:
    TreeNode* root_ = nullptr;
    
    static void destroy(TreeNode* node) noexcept;
    static TreeNode* insertHelper(TreeNode* node, const std::string& word);
    static const TreeNode* findNode(const TreeNode* node, std::string_view word) noexcept;
    static void inorderHelper(const TreeNode* node, std::vector<std::pair<std::string, size_t>>& out);
    static size_t sizeHelper(const TreeNode* node) noexcept;
    static unsigned heightHelper(const TreeNode* node) noexcept;
};

#endif
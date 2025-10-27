#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <vector>
#include <string>
#include <iostream>
#include "TreeNode.hpp"

class PriorityQueue {
public:


    PriorityQueue(const std::vector<std::pair<std::string, size_t>>& frequencies);
    PriorityQueue(std::vector<TreeNode*> nodes);
    ~PriorityQueue();


    size_t size() const noexcept 
    {
        return items_.size(); 
    }

    bool empty() const noexcept 
    {
        return items_.empty(); 
    }
    TreeNode* findMin() const noexcept;
    TreeNode* extractMin() noexcept;
    void deleteMin() noexcept;
    void insert(TreeNode* node);
    void writeFreqFile(const std::string& filename) const;
    void print(std::ostream& os = std::cout) const;
    
    
private:
    std::vector<TreeNode*> items_;
    bool ownsNodes_;
    bool higherPriority(const TreeNode* a, const TreeNode* b) noexcept;
    size_t findInsertPosition(const TreeNode* node) const;
};

#endif
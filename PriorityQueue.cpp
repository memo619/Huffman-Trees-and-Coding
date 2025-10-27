#include "PriorityQueue.hpp"
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

bool compareNodes(const TreeNode* a, const TreeNode* b) 
{
    if (a->freq != b->freq) 
    {
        return a->freq > b->freq;
    }
    return a->key_word < b->key_word;
}

PriorityQueue::PriorityQueue(const vector<pair<string, size_t>>& frequencies)
    : ownsNodes_(true)
{ 
    for (const auto& [word, count] : frequencies) 
    {
        items_.push_back(new TreeNode(word, count));
    }
    sort(items_.begin(), items_.end(), compareNodes);
}

PriorityQueue::PriorityQueue(vector<TreeNode*> nodes)
    : ownsNodes_(false) 
{
    items_ = nodes;
    sort(items_.begin(), items_.end(), compareNodes);
}

PriorityQueue::~PriorityQueue() 
{
    if (ownsNodes_) 
    {
        for (TreeNode* node : items_) 
        {
            delete node;
        }
    }
}

bool PriorityQueue::higherPriority(const TreeNode* a, const TreeNode* b) noexcept
{
    if (a->freq != b->freq) 
    {
        return a->freq > b->freq;
    }
    return a->key_word < b->key_word;
}

TreeNode* PriorityQueue::findMin() const noexcept
{
    if (items_.empty())
    {
        return nullptr;
    }
    return items_.back();
}

TreeNode* PriorityQueue::extractMin() noexcept
{
    if (items_.empty()) 
    {
        return nullptr;
    }
    TreeNode* min = items_.back();
    items_.pop_back();
    return min;
}

void PriorityQueue::deleteMin() noexcept
{
    if (!items_.empty()) 
    {
        items_.pop_back();
    }
}

void PriorityQueue::insert(TreeNode* node) 
{
    size_t pos = 0;
    for (size_t i = 0; i < items_.size(); i++)
    {
        if (compareNodes(node, items_[i]))
        {
            break;
        }
        pos++;
    }
    items_.insert(items_.begin() + pos, node);
}

size_t PriorityQueue::findInsertPosition(const TreeNode* node) const
{
    for (size_t i = 0; i < items_.size(); i++)
    {
        if (compareNodes(node, items_[i]))
        {
            return i;
        }
    }
    return items_.size();
}

void PriorityQueue::writeFreqFile(const string& filename) const
{
    ofstream out(filename);
    if (!out.is_open()) 
    {
        return;
    }
    for (const TreeNode* node : items_) 
    {
        out << setw(10) << node->count << ' ' << node->word << '\n';
    }
}

void PriorityQueue::print(ostream& os) const 
{
    os << "PriorityQueue (" << items_.size() << " items):\n";
    for (size_t i = 0; i < items_.size(); ++i) 
    {
        const TreeNode* node = items_[i];
        os << "  [" << i << "] freq=" << node->freq 
           << ", key_word=\"" << node->key_word << "\"";
        if (!node->word.empty()) 
        {
            os << ", word=\"" << node->word << "\"";
        }
        os << '\n';
    }
    os << "  MIN is at back: ";
    if (!items_.empty()) 
    {
        os << "freq=" << items_.back()->freq 
           << ", key_word=\"" << items_.back()->key_word << "\"";
    }
    os << '\n';
}
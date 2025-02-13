/*
Problem of the Day: Pair Sum in BST
Problem Description: https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1
*/

class Solution {
  public:
    bool findTarget(Node *root, int target) {
        unordered_set<int> set;
        return find(root, set, target);
    }

  private:
    bool find(Node* node, unordered_set<int>& set, int target) {
        if (!node) return false;
        if (set.count(target - node->data)) return true;
        set.insert(node->data);
        return find(node->left, set, target) || find(node->right, set, target);
    }
};

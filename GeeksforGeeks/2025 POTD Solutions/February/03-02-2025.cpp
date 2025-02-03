/*
Problem of the Day: Height of Binary Tree
Problem Description: https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
*/

int height(struct Node* node) {
    if (node == NULL) {
        return -1;
    }
    
    int left_height = height(node->left);
    int right_height = height(node->right);
    
    return (left_height > right_height ? left_height : right_height) + 1;
}

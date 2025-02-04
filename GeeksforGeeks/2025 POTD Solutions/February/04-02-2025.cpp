/*
Problem of the Day: Diameter of a Binary Tree
Problem Description: https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
*/

int height(struct Node* node, int* diameter) {
    if (node == NULL) {
        return 0;
    }
    
    int leftHeight = height(node->left, diameter);
    int rightHeight = height(node->right, diameter);
    
    *diameter = fmax(*diameter, leftHeight + rightHeight);
    
    return 1 + fmax(leftHeight, rightHeight);
}

int diameter(struct Node* root) {
    int diameter = 0;
    height(root, &diameter);
    return diameter;
}

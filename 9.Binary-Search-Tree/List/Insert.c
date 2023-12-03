struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to insert a value into the binary tree
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        // Create a new node if the current position is empty
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    // Recursively insert into the left or right subtree
    if (value <= root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

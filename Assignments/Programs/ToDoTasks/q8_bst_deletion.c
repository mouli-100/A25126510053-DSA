#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int value)
{
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void inorder(struct Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Find the smallest node in a subtree (inorder successor)
struct Node* findMin(struct Node* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from the BST
struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL) {
        printf("Value %d not found. Nothing deleted.\n", key);
        return NULL;
    }
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: node with zero children (leaf)
        if (root->left == NULL && root->right == NULL) {
            printf("Case 1: %d is a leaf node (zero children).\n", key);
            free(root);
            return NULL;
        }
        // Case 2: node with one child
        else if (root->left == NULL) {
            printf("Case 2: %d has one child (right).\n", key);
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            printf("Case 2: %d has one child (left).\n", key);
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: node with two children
        else {
            printf("Case 3: %d has two children.\n", key);
            struct Node* succ = findMin(root->right);
            printf("Replaced with inorder successor %d.\n", succ->data);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

int main()
{
    struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of nodes : ");
    scanf("%d", &n);
    printf("Enter %d values :\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder before deletion : ");
    inorder(root);

    printf("\n\nEnter value to delete : ");
    scanf("%d", &key);
    root = deleteNode(root, key);

    printf("\nInorder after deletion  : ");
    inorder(root);
    printf("\n");

    /* Suggested test input: 50 30 70 20 40 60 80 (n = 7)
       Delete 20 -> zero children
       Delete 30 (after 20 removed) -> one child
       Delete 50 -> two children                              */
    return 0;
}

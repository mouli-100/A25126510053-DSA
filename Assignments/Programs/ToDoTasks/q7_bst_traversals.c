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
    else
        printf("ID %d already exists. Duplicate ignored.\n", value);
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
void preorder(struct Node* root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int search(struct Node* root, int key)
{
    while (root != NULL) {
        if (key == root->data)
            return 1;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}
int main()
{
    struct Node* root = NULL;
    int n, value, key;
    printf("Enter number of values : ");
    scanf("%d", &n);
    printf("Enter %d unique integer IDs :\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("\nInorder   traversal : ");
    inorder(root);
    printf("\nPreorder  traversal : ");
    preorder(root);
    printf("\nPostorder traversal : ");
    postorder(root);
    printf("\n\nEnter value to search : ");
    scanf("%d", &key);
    if (search(root, key))
        printf("Value %d exists in the BST.\n", key);
    else
        printf("Value %d does not exist in the BST.\n", key);
    printf("\nWhy inorder gives sorted output:\n");
    printf("Inorder visits Left subtree -> Node -> Right subtree.\n");
    printf("In a BST every value in the left subtree is smaller than the node\n");
    printf("and every value in the right subtree is larger, so visiting the\n");
    printf("left first, then the node, then the right always produces the\n");
    printf("values in ascending order.\n");
    return 0;
}

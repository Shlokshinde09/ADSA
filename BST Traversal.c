#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Binary Search Tree (BST) node

struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
}*root = NULL;

// Function to create a new node
struct Node* createNode(int data)
{
      // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new value into the BST

struct Node* insert(struct Node *root, int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }
    if(data < root->data)
    {
        root->left = insert(root->left, data);
    } else 
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Preorder Traversal: Visit Root → Left Subtree → Right Subtree
void preorder(struct Node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal: Visit Left Subtree → Root → Right Subtree
void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder Traversal: Visit Left Subtree → Right Subtree → Root
void postorder(struct Node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int i, n;
       // Input: Number of elements to insert in BST
    printf("Enter the number of elements to be inserted in BST: ");
    scanf("%d", &n);
    int a[n]; // Array to store elements

     // Input: Elements to insert
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        root = insert(root, a[i]);
    }

     // Display traversals
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

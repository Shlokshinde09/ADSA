
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}*root = NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void preorder(struct Node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}
int main(){
    int i, n;
    printf("Enter the number of elements to be inserted in BST: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
        root = insert(root, a[i]);
    }

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Enter an element to search: ");
    int searchElement;
    scanf("%d", &searchElement);

    if(search(root,searchElement)){
        printf("Given node exist");

    }
    else{
        printf("Given node does not exist");
    }


    return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};
struct node * new_node(int value){
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}
struct node * insert(struct node * root, int value){
    if(root == NULL){
        return new_node(value);
    }
    else if(value < root->data){
        root->left = insert(root->left , value);
    }
    else{
        root->right = insert(root->right , value);
        return root;
    }
}
void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node * root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
struct node * search(struct node * root, int key){
    if(root == NULL || root->data == key){
        return root;
    }
    else if(key < root->data){
        return search(root->left,key);
    }
    else {
        return search(root->right,key);
    }
}

int main(){
    struct node * root = NULL;
    int n,data;
    printf("Enter the No. of Elements You Want in BST: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter the Element %d: ",i+1);
        scanf("%d",&data);
        root = insert(root , data);
    }
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");

    int key;
    printf("Enter the Number You Want to Search: ");
    scanf("%d",&key);
    struct node * result = NULL;
    result = search(root,key);
    if(result != NULL){
        printf("The %d element is Found in BST",key);
    }
    else{
        printf("The %d element is Not FOund in BST",key);
    }
    return 0;
}
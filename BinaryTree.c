//Binary Tree Creatation and Traversal
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *create(int x){
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    if(x==-1){
        return NULL;
    }
    nn->data = x;
    nn->left = NULL;
    nn->right = NULL;
    printf("Enter the left child of %d: ",x);
    scanf("%d",&x);
    nn->left = create(x);
    printf("Enter the right child of %d: ",x);
    scanf("%d",&x);
    nn->right = create(x);
    return nn;
}
void inorder(struct node *temp){
    if(temp == NULL){
        return;
    }
    inorder(temp->left);
    printf("%d ",temp->data);
    inorder(temp->right);
}
void preorder(struct node *temp){
    if(temp == NULL){
        return;
    }
    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(struct node *temp){
    if(temp == NULL){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);
}
void main(){
    int x;
    printf("Enter the root node: ");
    scanf("%d",&x);
    root = create(x);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
}

#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
}*root=NULL;
struct node *find_min(struct node *r){
    struct node *t=r;
    while(t->left!=NULL)
        t=t->left;
    return r;
}
struct node *insert(int data,struct node *root){
    if(root==NULL){
        struct node *root = (struct node *)malloc(sizeof(struct node));
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    else if(data<=root->data)
        root->left=insert(data,root->left);
    else
        root->right=insert(data,root->right);
    return root;
}
struct node *delete(int data,struct node *r){
    if(r==NULL)
        return r;
    else{
        if(data<r->data)
            r->left=delete(data,r->left);
        else if(data>r->data)
            r->right=delete(data,r->right);
        else{
            if(r->left==NULL&r->right==NULL){
                struct node *t=r;
                r=NULL;
                free(t);
                return r;
            }
            else if(r->left==NULL){
                struct node *t=r;
                r=r->right;
                free(t);
                return r;
            }
            else if(r->right==NULL){
                struct node *t=r;
                r=r->left;
                free(t);
                return r;
            }
            else{
                struct node *temp=find_min(r->right);
                r->data=temp->data;
                r->right=delete(temp->data,r->right);
                return r;
            }
        }
    }
}
void inorder(struct node *r){
    if(r==NULL)
        return;
    inorder(r->left);
    printf("%d ",r->data);
    inorder(r->right);
    printf("\n");
}
void main(){
    int opt,data;
    do{
        printf("1.Insert\n2.Delete\n3.Inorder traversal\nEnter your choice: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                root=insert(data,root);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d",&data);
                root=delete(data,root);
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
        }
    }while(opt!=4);
}

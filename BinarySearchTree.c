#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
   
};

struct Node* createNode(int value){
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}



struct Node* insert(struct Node* root,int value){

if(root==NULL){
    return createNode(value);

}

if(value<root->data){
    root->left=insert(root->left,value);
}else if(value>root->data){
  root->right=insert(root->right,value);
}

return root;
}

struct Node* findMin(struct Node* root){
    if(root==NULL){
        return NULL;
    }
    struct Node* current = root;
    while(current->left!=NULL){
        current = current->left;
    }
    return current;
}

struct Node* findMax(struct Node* root){
    if(root==NULL){
        return NULL;
    }
    struct Node* current = root;
    while(current->right!=NULL){
        current = current->right;
    }
    return current;
}
struct Node* deleteNode(struct Node* root,int value){
    if(root == NULL) return NULL;
    if(value < root->data){
        root->left=deleteNode(root->left,value);
    }else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }else{
        if(root->left==NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }else{
            struct Node* temp = findMin(root->right);
            root->data=temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
return root;
}
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    struct Node* root=NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Initial tree (in-order): ");
    inorder(root);
    printf("\n");

    printf("\nDeleting 20 (leaf node)...\n");
    root = deleteNode(root, 20);
    printf("Updated tree: ");
    inorder(root);
    printf("\n");

    printf("\nDeleting 30 (node with one child)...\n");
    root = deleteNode(root, 30);
    printf("Updated tree: ");
    inorder(root);
    printf("\n");

    printf("\nDeleting 50 (root node with two children)...\n");
    root = deleteNode(root, 50);
    printf("Updated tree: ");
    inorder(root);
    printf("\n");
}


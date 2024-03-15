#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* makeEmpty(struct TreeNode* root)
{
    if(root != NULL)
    {
        makeEmpty(root->left);
        makeEmpty(root->right);
        free(root);
    }
    return NULL;
}

struct TreeNode* insert(struct TreeNode* root, int x)
{   
    printf("%d", x);
    if(root == NULL)
    {
        root = malloc(sizeof(struct TreeNode));
        root->data = x;
        root->left = root->right = NULL;
    }
    else if(x < root->data)
        root->left = insert(root->left, x);
    else if(x > root->data)
        root->right = insert(root->right, x);
    return root;
}

int main(int argc, char const *argv[])
{
    struct TreeNode* root = insert(NULL, 10);
    struct TreeNode* node1 = insert(root, 20);
    {
        /* data */
    };
    
    return 0;
}

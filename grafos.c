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

struct TreeNode* findMin(struct TreeNode* root)
{
    if(root == NULL)
    	return NULL;
    else if(root->left == NULL)
    	return root;
    else
    	return findMin(root->left);
}

struct TreeNode* findMax(struct TreeNode* root)
{
    if(root == NULL)
    	return NULL;
    else if(root->right == NULL)
    	return root;
    else
    	return findMax(root->right);
}

struct TreeNode* find(struct TreeNode* root, int x)
{
    if(root == NULL)
        return NULL;
    else if(x < root->data)
        return find(root->left, x);
    else if(x > root->data)
        return find(root->right, x);
    else
        return root;
}

struct TreeNode* delete(struct TreeNode* root, int x)
{
    struct TreeNode* temp;
    if(root == NULL)
        return NULL;
    else if(x < root->data)
        root->left = delete(root->left, x);
    else if(x > root->data)
        root->right = delete(root->right, x);
    else if(root->left && root->right)
    {
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, root->data);
    }
    else
    {
        temp = root;
        if(root->left == NULL)
            root = root->right;
        else if(root->right == NULL)
            root = root->left;
        free(temp);
    }
    return root;
}

void inorder(struct TreeNode* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main(int argc, char const *argv[])
{
    struct TreeNode* root = insert(NULL, 10);
    insert(root, 20);
    
    printf("%d", root->right); // Funciona?

    insert(root, 30);
    insert(root->right, 30);
    return 0;
}

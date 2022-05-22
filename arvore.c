#include <stdio.h>
#include "arvore.h"

Job* makeEmpty(Job* root)
{
    if (root != NULL)
    {
        makeEmpty(root->left);
        makeEmpty(root->right);
        free(root);
    }
    return NULL;
}

Job* insert(Job* root, int x)
{
    if (root == NULL)
    {
        root = malloc(sizeof(Job));
        root->id = x;
        root->left = root->right = NULL;
    }
    else if (x < root->id)
        root->left = insert(root->left, x);
    else if (x > root->id)
        root->right = insert(root->right, x);
    return root;
}

Job* findMin(Job* root)
{
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

Job* findMax( Job* root)
{
    if (root == NULL)
        return NULL;
    else if (root->right == NULL)
        return root;
    else
        return findMax(root->right);
}

Job* find(Job* root, int x)
{
    if (root == NULL)
        return NULL;
    else if (x < root->id)
        return find(root->left, x);
    else if (x > root->id)
        return find(root->right, x);
    else
        return root;
}

int findHeight(Job* root)
{
    int lefth, righth;
    if (root == NULL)
        return -1;
    lefth = findHeight(root->left);
    righth = findHeight(root->right);
    return (lefth > righth ? lefth : righth) + 1;
}

Job* delete(Job* root, int x)
{
    struct Job* temp;
    if (root == NULL)
        return NULL;
    else if (x < root->id)
        root->left = delete(root->left, x);
    else if (x > root->id)
        root->right = delete(root->right, x);
    else if (root->left && root->right)
    {
        temp = findMin(root->right);
        root->id = temp->id;
        root->right = delete(root->right, root->id);
    }
    else
    {
        temp = root;
        if (root->left == NULL)
            root = root->right;
        else if (root->right == NULL)
            root = root->left;
        free(temp);
    }
    return root;
}

void inorder(Job* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->id);
    inorder(root->right);
}

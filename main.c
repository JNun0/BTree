#include <stdio.h>
#include <locale.h>	// ASCII SET
#include "arvore.h"

int main() {

    setlocale(LC_ALL, "Portuguese");

    Job* root;
    Job* temp;
    root = NULL;

    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 7);
    printf("Height: %d\n", findHeight(root));

    root = insert(root, 13);
    root = insert(root, 18);
    root = insert(root, 30);
    printf("Height: %d\n", findHeight(root));

    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 16);
    printf("Height: %d\n", findHeight(root));

    root = insert(root, 22);
    root = insert(root, 35);
    inorder(root); printf("\n");

    temp = findMax(root);
    printf("Max Element: %d\n", temp->id);

    temp = findMin(root);
    printf("Min Element: %d\n", temp->id);

    root = delete(root, 8);
    root = delete(root, 16);
    inorder(root); printf("\n");

    root = delete(root, 18);
    inorder(root); printf("\n");

    root = delete(root, 10);
    inorder(root); printf("\n");

    root = delete(root, 35);
    inorder(root); printf("\n");

    root = makeEmpty(root);
    return 0;
}

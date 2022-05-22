

#ifndef BTREE
#define BTREE

#include<stdio.h>
#include<stdlib.h>

typedef struct Maquina {
    int id;
    struct Maquina* next;
}Maquina;

typedef struct Operacao {
    int id;
    struct Maquina maquina;
    int tempo;
    struct Operacao* next;
}Operacao;

typedef struct Job
{
    int id;
    struct Job* left;
    struct Job* right;
}Job;

Job* makeEmpty(Job* root);
Job* insert(Job* root, int x);
Job* findMin(Job* root);
Job* findMax(Job* root);
Job* find(Job* root, int x);
int findHeight(Job* root);
Job* delete(Job* root, int x);
void inorder(Job* root);

#endif
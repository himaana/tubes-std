#ifndef TUBESH_H_INCLUDED
#define TUBESH_H_INCLUDED
#include <iomanip>
#include <iostream>
using namespace std;
#define info(P) P->info
#define next(P) P->next
#define head(P) (P).head
#define tail(P) (P).tail

typedef struct Queue *adr;

struct infotype{
    int burstTime;
    int arroundTime;
    int waitingTime;
    string name;
};

struct Queue{
    infotype info;
    adr next;
};

struct List{
    adr head;
    adr tail;
};

void createQueue(List &Q);
void createElement(infotype x, adr &P);
void enqueue(List &Q, adr P);
void dequeue(List &Q, adr &P);
void show(List Q);
void printJob(adr P);
void firstTimeFirstServe(List &Q1, List &Q2, List &Q3, int quantum, int prioritas, int n);
bool isEmpty(List Q);
int menu();

#endif // TUBESH_H_INCLUDED

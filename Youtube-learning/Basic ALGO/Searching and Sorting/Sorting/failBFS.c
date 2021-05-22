#include <stdio.h>
#include <stdlib.h>
#define size 10
#define true 1
#define false 0
typedef struct
{
    int arr[size];
    int front;
    int rear;
} queue;
int isEmpty(queue *q);
int isFull(queue *q);
void enqueue(queue *q, int val);
int dequeue(queue *q);
void display(queue *q);
int isEmpty(queue *q)
{
    if (q->front == -1 && q->rear == -1)
        return true;
    else
        return false;
}
int isFull(queue *q)
{
    if (q->rear == (size - 1))
        return true;
    else
        return false;
}
void enqueue(queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is now full. ");
        return;
    }
    else if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->arr[q->rear] = val;
    printf("int in enqueue %d \n", q->arr[q->rear]);
}
int dequeue(queue *q)
{
    int x;
    if (isEmpty(q))
    {
        printf("Queue is now Empty. ");
        return -1;
    }
    else if (q->front == q->rear)
    {
        x = q->arr[q->front];
        q->arr[q->front] = 0;
        q->front = q->rear = -1;
        return x;
    }
    else
    {
        x = q->arr[q->front];
        q->arr[q->front++] = 0;
        return x;
    }
}
void display(queue *q)
{
    for (int i = q->front; i <= q->rear; i++)
        printf("%d", q->arr[i]);
}
#include < stdio.h >
#include < stdlib.h >
#include "myIntQueue.h"
int constructGraph(int adjacencyMatrix[100][100], int vertices, int ver1, int ver2)
{
    adjacencyMatrix[ver1][ver2] = 1;
    adjacencyMatrix[ver2][ver1] = 1;
}
int printGraph(int adjacencyMatrix[100][100], int vertices)
{
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf(" %d ", adjacencyMatrix[i][j]);
        }
        printf(" \n");
    }
}
void myBFSnew(queue *q, int adjacencyMatrix[100][100], int vertices, int start, int visited[])
{
    visited[start] = 1;
    printf(" Visited %d \n", start);
    while (!isEmpty(q))
        dequeue(q);
    enqueue(q, start);
    while (!isEmpty(q))
    {
        for (int k = 0; k < vertices; k++)
        {
            printf("\n K value is %d \n", k);
            if (adjacencyMatrix[q->front][k] == 1 && !visited[k])
            {
                visited[k]++;
                printf(" Visited %d \n", k);
                enqueue(q, k);
            }
        }
        dequeue(q);
    }
}
int main()
{
    int adjacencyMatrix[100][100];
    int vertices;
    int edges;
    int ver1, ver2;
    printf("Please Enter the number of vertices and edges \n");
    scanf(" %d%d", &vertices, &edges);
    printf("constructGraph\n");
    for (int i = 0; i < edges; ++i)
    {
        scanf(" %d%d", &ver1, &ver2);
        constructGraph(adjacencyMatrix, vertices, ver1, ver2);
    }
    printGraph(adjacencyMatrix, vertices);
    int *visited = (int *)calloc(vertices, sizeof(int));
    printf(" printing visited array\n");
    for (int i = 0; i < vertices; ++i)
        printf(" %d ", visited[i]);
    printf("\n");
    int start;
    printf(" Just enter the start vertex \n");
    scanf(" %d", &start);
    queue Q;
    myBFSnew(&Q, adjacencyMatrix, vertices, start, visited);
    for (int j = 0; j < vertices; j++)
    {
        if (!visited[j])
            myBFSnew(&Q, adjacencyMatrix, vertices, j, visited);
    }
}
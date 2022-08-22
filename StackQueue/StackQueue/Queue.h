#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDaTaType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDaTaType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDaTaType x);
void QueuePop(Queue* pq);
QDaTaType QueueFront(Queue* pq);
QDaTaType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);



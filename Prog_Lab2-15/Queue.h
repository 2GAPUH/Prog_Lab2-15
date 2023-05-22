#pragma once

struct element
{
	int data;
	element* next;
};

struct queue
{
	element* head, * tail;
};

void InitQueue(queue* q, int tmp);
void PrintQueue(queue* const q);
void PushQueue(queue* q, int tmp);
int PopQueue(queue* q);
int PeekQueue(queue* const q);
bool IsEmptyQueue(queue* const q);
void ClearQueue(queue* q);

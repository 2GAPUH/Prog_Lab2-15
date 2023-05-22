#include "Queue.h" 
#include <stdio.h>
#include <stdlib.h>

void InitQueue(queue* q, int tmp)
{
	q->head = q->tail = (element*)malloc(sizeof(element));
	q->tail->next = NULL;
	q->head->data = tmp;
}

void PrintQueue(queue* const q)
{
	if (IsEmptyQueue(q))
		return;
	for (element* i = q->head; i != NULL; i = i->next)
		printf_s("%d -> ", i->data);
	printf_s("\b\b\b   \n");
}

void PushQueue(queue* q, int tmp)
{
	if (IsEmptyQueue(q))
	{
		InitQueue(q, tmp);
		return;
	}

	element* e = (element*)malloc(sizeof(element));
	e->data = tmp;
	e->next = NULL;
	q->tail->next = e;
	q->tail = e;
}

int PopQueue(queue* q)
{
	if (IsEmptyQueue(q))
		return INT_MAX;

	if (q->head == q->tail)
	{
		int tmp = q->head->data;
		free(q->head);
		q->tail = q->head = NULL;
		return tmp;
	}

	element* e = q->head;
	int tmp = e->data;
	q->head = q->head->next;
	free(e);
	return tmp;
}

int PeekQueue(queue* const q)
{
	if (IsEmptyQueue(q))
		return INT_MAX;;
	return q->head->data;
}

bool IsEmptyQueue(queue* const q)
{
	return q->head == NULL;
}

void ClearQueue(queue* q)
{
	while (!(IsEmptyQueue(q)))
	{
		element* e = q->head;
		q->head = q->head->next;
		free(e);
	}
	q->tail = NULL;
}



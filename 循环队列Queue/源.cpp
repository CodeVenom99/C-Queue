#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctime>

#define  LEN 5
typedef struct queue
{
	int* pBase;
	int front;
	int rear;
}Queue;
void init_queue(Queue* q,int len);
bool push_queue(Queue* q, int num);
void pop_queue(Queue* q);
void show_queue(Queue q);
bool full_queue(Queue q);
bool empty_queue(Queue q);
int len_queue(Queue q); 
void test01()
{
	//printf("%d", LEN);
	Queue q;
	init_queue(&q,LEN);
	for (int i = 0; i < LEN; i++)
	{
		push_queue(&q, i);
	}
		
	show_queue(q);
	full_queue(q);
	printf("链表长度：%d\r\n", len_queue(q));
	printf("-------------\r\n");
	pop_queue(&q);
	pop_queue(&q);
	show_queue(q);
	printf("链表长度：%d\r\n", len_queue(q));
	printf("-------------\r\n");
	push_queue(&q, 100);
	push_queue(&q, 200);
	show_queue(q);
	printf("链表长度：%d\r\n", len_queue(q));
	printf("-------------\r\n");
	for (int i = 0; i < 4; i++)
		pop_queue(&q);
	empty_queue(q);
	printf("链表长度：%d\r\n",len_queue(q) );
}
int main()
{
	test01();
	return 0;
}
void init_queue(Queue* q,int len)
{
	q->pBase = (int*)malloc(sizeof(int) * len);
	q->front = q->rear = 0;
}
bool push_queue(Queue* q, int num)
{
	if (full_queue(*q))
	{
		printf("队列已满，不能继续插入\r\n");
		return 0;
	}

	*(q->pBase + q->rear) = num;
	q->rear = (q->rear + 1) % LEN;
	return 1;
}
void pop_queue(Queue* q)
{
	q->front = (q->front + 1) % LEN;
}
void show_queue(Queue q)
{
	if (q.front <= q.rear)
	{
		for (int i = q.front; i < q.rear; i++)
			printf("%d\r\n", *(q.pBase + i));
	}
	else
	{
		for (int i = q.front; i < LEN; i++)
		{
			printf("%d\r\n", *(q.pBase + i));
		}
		for (int i = 0; i < q.rear; i++)
		{
			printf("%d\r\n", *(q.pBase + i));
		}
			
	}

}
bool full_queue(Queue q)
{
	if ((q.rear + 1) % LEN == q.front)
	{
		printf("链表满\r\n");
		return 1;
	}
	else
	{
		printf("链表不满\r\n");
		return 0;
	}
		
}
bool empty_queue(Queue q)
{
	if (q.rear == q.front)
	{
		printf("链表空\r\n");
		return 1;
	}
	else
	{
		printf("链表不为空\r\n");
		return 0;
	}

}
int len_queue(Queue q)
{
	if (q.rear >= q.front)
	{
		return q.rear - q.front;
	}
	else
		return q.rear +(LEN- q.front);
}











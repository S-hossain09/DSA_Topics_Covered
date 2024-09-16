#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int front;
    int back;
    int *arr;

} queue;

int full_queue(queue *ptr_queue)
{
    if ((ptr_queue->back + 1) % ptr_queue->size == ptr_queue->front)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int empty_queue(queue* ptr_queue)
{
    if(ptr_queue->front == ptr_queue->back)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void enqueue(queue *ptr_queue, int value)
{
    if (full_queue(ptr_queue))
    {
        printf("Queue Overflow\n");
    }

    else
    {
        ptr_queue->back = (ptr_queue->back + 1) % ptr_queue->size;
        ptr_queue->arr[ptr_queue->back] = value;
    }
}

void dequeue(queue* ptr_queue)
{
    if(empty_queue(ptr_queue))
    {
        printf("Queue is Empty");
    }

    else
    {
        ptr_queue->front = (ptr_queue->front + 1) % ptr_queue->size;

        
    }
}

int main()
{
    queue q1;

    q1.size = 3;
    q1.front = 0;
    q1.back = 0;

    q1.arr = (int *)malloc(q1.size * (sizeof(int)));

    enqueue(&q1, 54);
    enqueue(&q1, 23);
    enqueue(&q1, 1);

    // dequeue(&q1);
    // dequeue(&q1);
    // dequeue(&q1);

    // enqueue(&q1, 54);

    if(empty_queue(&q1))
    {
        printf("The queue is empty\n");
    }
    if(full_queue(&q1))
    {
        printf("The queue is full\n");
    }

    return 0;
}
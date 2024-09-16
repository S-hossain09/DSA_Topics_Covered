#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    /*
        it will have the first index stored to indicate the
        first element in the queue.
    */
    int back;
    /*
        The index of this will move with elements when pushed.
    */

    int *arr;
    /*
         As we don't know the size of the array. so we
         store an address to this array. later on we will
         dynamically allocate space for this array.
    */
};

int full_queue(struct queue *ptr_queue)
{
    if (ptr_queue->back == (ptr_queue->size - 1))
    // size - 1 coz suppose size = 5 then
    // 0 to 4.
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int empty_queue(struct queue *ptr_queue)
{
    if (ptr_queue->front == ptr_queue->back)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void enqueue(struct queue *ptr_queue, int value)
{
    if (full_queue(ptr_queue))
    {
        printf("Cannot Enqueue in queue. Size is full\n");
    }

    else
    {
        ptr_queue->back++;
        ptr_queue->arr[ptr_queue->back] = value;
    }
}

int dequeue(struct queue *ptr_queue)
{
    int a = -1;
    if(empty_queue(ptr_queue))
    {
        printf("Nothing to dequeue");
    }

    else
    {
        ptr_queue->front++;
        a = ptr_queue->arr[ptr_queue->front];
    }

    return a;
}

int main()
{
    struct queue q;

    q.size = 5;
    /*  as this is not a pointer to struct .
        so it is doint q.size or else it would
        have done like this q->size
    */

    q.front = -1;
    q.back = -1;
    /*
        means it is pointing to none.
    */

    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueing some elements
    
    printf("Enqueuing Elements \n");
    enqueue(&q, 54);
    enqueue(&q, 23);
    enqueue(&q, 10);
    enqueue(&q, 11);
    enqueue(&q, 13);

    printf("Dequeing Elements \n");
    printf("Element : %d\n",dequeue(&q));
    printf("Element : %d\n",dequeue(&q));
    printf("Element : %d\n",dequeue(&q));
    printf("Element : %d\n",dequeue(&q));
    printf("Element : %d\n",dequeue(&q));

    if(empty_queue(&q))
    {
        printf("The Queue is Empty\n");
    }

    if(full_queue(&q))
    {
        printf("The queue is Full\n");
    }
    
    return 0;
}
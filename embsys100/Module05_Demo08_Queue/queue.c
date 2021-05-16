#include "queue.h"
#define QUEUE_SIZE 3

// Backing store
char QueueStore[QUEUE_SIZE];

// Pointers to queue elements for adding and retrieving
char* putPtr;
char* getPtr;

// FIFO Queue is Empty if putPtr==getPtr;
// FIFO Queue is Full if putPtr+1 > Address of last element in the queue;

// Initialize internals of the queue
void queue_init(void)
{
    putPtr = 0;
    getPtr = 0;
    for(int i=0; i<QUEUE_SIZE; i++)
    {
        QueueStore[i] = '\0';
    }
}

// Add data to queue
// If queue is full return error
// Otherwise return success
int queue_put(char data)
{
    if (getPtr == &QueueStore[0] && putPtr == &QueueStore[QUEUE_SIZE-1])
    {
        // queue is full
        return -1;
    }
    
    if (getPtr == putPtr+1)
    {
        //queue is full
        return -1;
    }
    
    if (getPtr == 0)
    {
        getPtr = &QueueStore[0];
    }    
    
    if (putPtr == 0 || putPtr == &QueueStore[QUEUE_SIZE-1])
    {
        putPtr = &QueueStore[0];
    }
    else
    {
        putPtr++;
    }
    
    *putPtr = data;
    return 0;
}

// Get data from queue
// If queue is empty return error
// Otherwise return success
int queue_get(char* data)
{   
    if (getPtr == 0)
    {
        // queue is empty
        return -1;
    }

    *data = *getPtr;
    
    if (getPtr == putPtr)
    {
        
        getPtr = 0;
        putPtr = 0;
    }
    else if (getPtr == &QueueStore[QUEUE_SIZE-1])
    {
        // wrap
        getPtr = &QueueStore[0];
    }
    else
    {
        getPtr++;
    }
    
    return 0;
}

#include <stdio.h>
#define MAX_SIZE 5
// peek - look a the front element
// without removing it
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}
int isEmpty() {
    return (front == -1);
}
void enqueue(int value)
{
    if (isFull())
        {
        printf("Queue Overflow\n");
        return;
        }
    if (isEmpty())
        {
        front = 0;
        }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear)
        {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}
int main() {
    enqueue(10);  enqueue(20);   enqueue(30);
    enqueue(40);   enqueue(50);
    enqueue(60);  // Overflow situation
    displayQueue();
    dequeue();    dequeue();
    displayQueue();
    enqueue(60);    enqueue(70);  // Potential overflow
    displayQueue();
   printf("Peek front: %d\n", peek());
    return 0;
}

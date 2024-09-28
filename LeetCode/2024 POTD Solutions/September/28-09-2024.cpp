/*
Problem of the Day: 641. Design Circular Deque
Problem Description: https://medium.com/@pradeepsooryavanshee1210/641-design-circular-deque-leetcode-solution-65f89bbf2257
*/

class MyCircularDeque
{
private:
    std::vector<int> data;
    int front;
    int rear;
    int capacity;
    int count;

public:
    MyCircularDeque(int k)
    {
        capacity = k;
        data.resize(k);
        front = -1;
        rear = -1;
        count = 0;
    }

    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            front = (front - 1 + capacity) % capacity;
        }
        data[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        data[rear] = value;
        count++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
        {
            return false;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        count--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear - 1 + capacity) % capacity;
        }
        count--;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return data[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return data[rear];
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == capacity;
    }
};
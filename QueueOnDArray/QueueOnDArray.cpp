#include <iostream>
using namespace std;

class Queue
{
private:
    int* arr;
    int size;
    int front; //указатель на первый элемент очереди
    int rear; //указатель на последний элемент очереди

public:
    Queue(int size)
    {
        this->arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    ~Queue()
    {
        delete[] arr;
    }

    int getFront()
    {
        return front;
    }

    int getRear()
    {
        return rear;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
            return false;
    }

    bool isFull()
    {
        if (front == 0 && rear == size - 1)
        {
            return true;
        }
        else
            return false;
    }

    void push(int value) //позволяет добавить элемент в конец очереди
    {
        if (isFull())
        {
            cout << "Очередь уже преполнена" << endl;
        }
        else
        {
            if (isEmpty())
            {
                front = 0;
            }
            if (rear != size - 1) //если указатель на последний элемент очереди не упирается в правую границу массива
            {
                rear++;
                arr[rear] = value; 
                cout << "Добавлен элемент " << value << endl;
            }
            else
                cout << "Error! Добавление элемента приведет к выходу за границу массива. " << endl;
        }
    }

    void pop() //позволяет удалить элемент из начала очереди
    {
        int value;

        if (isEmpty())
        {
            cout << "Очередь и так пуста" << endl;
        }
        else
        {
            value = arr[front];
            cout << "Удален элемент " << value << endl;
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else
                front++;
        }
    }

    void print()
    {
        if (!isEmpty())
        {
            cout << "Очередь:" << endl;
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << endl;
            }
        }
        else
            cout << "Очередь пуста" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Queue q(9);
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << "front = " << q.getFront() << endl;
    cout << "rear = " << q.getRear() << endl;
    q.print();
    q.pop();
    q.pop();
    q.pop();
    cout << "front = " << q.getFront() << endl;
    cout << "rear = " << q.getRear() << endl;
    q.print();
    q.push(61);
    cout << "front = " << q.getFront() << endl;
    cout << "rear = " << q.getRear() << endl;
    q.print();
    q.pop();
    q.pop();
    cout << "front = " << q.getFront() << endl;
    cout << "rear = " << q.getRear() << endl;
    q.print();
}


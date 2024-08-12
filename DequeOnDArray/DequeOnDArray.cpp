#include <iostream>
using namespace std;

class Deque 
{
private:
    int* arr;
    int size;   //максимальный размер двухсторонней очереди
    int front; //указатель на первый элемент двухсторонней очереди
    int rear; //указатель на последний элемент двухсторонней очереди

public:
    Deque(int size)
    {
        this->arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    ~Deque()
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
    void push_front(int value) //добавить элемент в начало двухсторонней очереди
    {
        if (isFull()) 
        {
            cout << "Дек уже преполнен" << endl;
        }
        else 
        {
            if (front == 0)
            {
                cout << "Error! Добавление элемента в начало приведет к выходу за левую границу массива. " << endl;
            }
            else if(!isEmpty())
            {
                arr[--front] = value;
                cout << "В начало дека добавлен элемент " << value << endl;
            }
            if (isEmpty())
            {
                rear = 0;
                arr[++front] = value;
                cout << "В начало дека добавлен элемент " << value << endl;
            }
        }
    }
    void push_back(int value) //добавить элемент в конец двухсторонней очереди
    {
        if (isFull())
        {
            cout << "Дек уже преполнен" << endl;
        }
        else
        {
            if (isEmpty())
            {
                front = 0;
            }
            if (rear != size - 1)
            {
                arr[++rear] = value;
                cout << "В конец дека добавлен элемент " << value << endl;
            }
            else
                cout << "Error! Добавление элемента в конец приведет к выходу за правую границу массива. " << endl;
        }
    }
    void pop_front() //удалить элемент из начала двухсторонней очереди
    {
        int value;

        if (isEmpty())
        {
            cout << "Дек и так пуст" << endl;
        }
        else
        {
            value = arr[front];
            cout << "Из начала дека удален элемент " << value << endl;
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else
                front++;
        }
    }
    void pop_back() //удалить элемент из конца двухсторонней очереди
    {
        int value;

        if (isEmpty())
        {
            cout << "Дек и так пуст" << endl;
        }
        else
        {
            value = arr[rear];
            cout << "Из конца дека удален элемент " << value << endl;
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else
                rear--;
        }
    }
    void print()
    {
        if (!isEmpty())
        {
            cout << "Дек:" << endl;
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << endl;
            }
        }
        else
            cout << "Дек пуст" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Deque dq(10);
    
    dq.push_front(1);
    dq.push_back(4);
    cout << "front = " << dq.getFront() << endl;
    cout << "rear = " << dq.getRear() << endl;
    dq.push_back(11);
    dq.push_back(47);
    dq.push_back(17);
    dq.push_back(28);
    dq.push_back(407);
    dq.push_back(59);
    cout << "front = " << dq.getFront() << endl;
    cout << "rear = " << dq.getRear() << endl;
    dq.print();
    dq.pop_front();
    dq.pop_front();
    dq.pop_front();
    dq.pop_back();
    cout << "front = " << dq.getFront() << endl;
    cout << "rear = " << dq.getRear() << endl;
    dq.print();
    dq.push_front(88);
    dq.push_front(88);
    cout << "front = " << dq.getFront() << endl;
    cout << "rear = " << dq.getRear() << endl;
    dq.print();
}


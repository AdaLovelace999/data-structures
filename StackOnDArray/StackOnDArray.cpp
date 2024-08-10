#include <iostream>
using namespace std;

class Stack
{
private:
    int* arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        this->arr = new int[size];
        this->size = size;
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
    };

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
            return false;
    };

    void push(int value)
    {
        if (isFull())
        {
            cout << "Стек уже преполнен" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << "Добавлен элемент " << value << endl;
        }
    };

    void pop()
    {
        if (isEmpty())
        {
            cout << "Стек и так пуст" << endl;
        }
        else
        {
            cout << "Удален элемент " << arr[top] << endl;
            top--;

        }
    }

    void print()
    {
        if (!isEmpty())
        {
            cout << "Стек:" << endl;
            for (int i = 0; i < top + 1; i++)
            {
                cout << arr[i] << endl;
            }
        }
        else
            cout << "Стек пуст" << endl;
    }
};
int main()
{
    setlocale(LC_ALL, "ru");
    Stack s(5);
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    s.pop();
    s.pop();
    s.pop();
    s.print();
    s.push(31);
    s.push(112);
    s.push(34);
    s.push(554);
    s.push(25);
    s.print();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.print();
}


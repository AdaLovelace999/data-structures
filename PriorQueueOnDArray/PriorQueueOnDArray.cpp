#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    struct Item //структура Item содержит значение элемента очереди и его приоритет
    {
        int data;    // data
        int priority; //приоритет элемента в очереди
    };
    Item* arr; //массив элементов очереди типа Item
    int size;
    int front; //указатель на первый элемент очереди
    int rear; //указатель на последний элемент очереди

public:
    PriorityQueue(int size)
    {
        this->arr = new Item[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    ~PriorityQueue()
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
        if (rear == -1)
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

    void sortByPriority() //сортирует массив элементов очереди по убыванию их приоритета (точнее в порядке невозрастания)
    {
        for (int i = 1; i < size; ++i) //обычная пузырьковая сортировка 
        {
            for (int j = 0; j < size - i; j++)
            {
                if (arr[j].priority < arr[j + 1].priority)
                {
                    // Обмен местами
                    Item temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void push(int value, int priority) //позволяет добавить элемент в конец очереди
    {
        if (isFull())
        {
            cout << "Очередь уже преполнена, КУДА еще добавлять!" << endl;
        }
        else
        {
            if (isEmpty())
            {
                front = 0;
            }
            rear++;

            Item itm; //создаем новый элемент очереди
            itm.data = value; //присваиваем значение
            itm.priority = priority; //присваиваем приоритет

            arr[rear] = itm; //добавляем созданный элемент в конец нашей очереди
            sortByPriority(); //отсортируем элементы очереди по убыванию их приоритета (точнее в порядке невозрастания)
            cout << "Добавлен элемент " << value << "\tс приоритетом = " << priority << endl;
        }
    }
    void pop() //удаляет элементы из начала очереди (они уже расставлены в очереди в в порядке НЕвозрастания приоритета, т. е. в начале элементы с наибольшим приоритетом)
    {
        Item itm;

        if (isEmpty())
        {
            cout << "Очередь и так пуста, НЕЧЕГО удалять!!! =)" << endl;
        }
        else
        {
            itm = arr[front];
            cout << "Удален элемент " << itm.data << "\tс приоритетом " << itm.priority << endl;
            for (int i = front; i <= rear; i++)
            {
                arr[i] = arr[i + 1]; //сдвигаем элементы влево чтобы смоделировать удаление элемента из головы очереди
            }
            arr[rear].priority = -1; //инициализируем приоритет пустой ячейки отрицательным числом, чтоб при сортировке ячеек по приоритету она не окакзалась случайно в голове очереди 
            rear--; //сдвигаем указатель на последний элемент очереди на 1 позицию влево
        }
    }
    void print()
    {
        if (!isEmpty())
        {
            cout << "Очередь:" << endl;
            Item itm;
            for (int i = front; i <= rear; i++)
            {
                itm = arr[i];
                cout << itm.data << "\t" << itm.priority << endl;
            }
        }
        else
            cout << "Очередь пуста." << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    PriorityQueue pq(4);
    pq.push(2, 1);
    pq.push(0, 4);
    pq.push(77, 2);
    pq.push(15, 3);
    pq.push(9, 1);
    pq.push(225, 3);
    cout << "front = " << pq.getFront() << endl;
    cout << "rear = " << pq.getRear() << endl;
    pq.print();
    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();
    cout << "front = " << pq.getFront() << endl;
    cout << "rear = " << pq.getRear() << endl;
    pq.print();
    pq.push(60, 4); 
    pq.push(12, 2);
    cout << "front = " << pq.getFront() << endl;
    cout << "rear = " << pq.getRear() << endl;
    pq.print();

}


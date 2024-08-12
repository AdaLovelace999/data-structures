#include <iostream>
using namespace std;

class CircularQueue 
{
private:
	int* arr;
	int size; //хранит максимальную емкость кольцевого буфера
	int front, rear;
	int count; //хранит реальное количество элементов в очереди

public:
	CircularQueue(int size) 
	{
		this->arr = new int[size];
		this->size = size;
		front = -1;
		rear = -1;
		count = 0;
	}

	~CircularQueue() 
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
		if (count == 0)
		{
			return true;
		}
		else
			return false;
	}
	bool isFull()
	{
		if (count == size)
		{
			return true;
		}
		else
			return false;
	}

	void push(int value) //Функция добавления элемента в очередь с проверкой необходимости перехода в начало массива
	{
		if (isFull())
		{
			cout << "Емкость кольцевого буфера заполнена." << endl;
		}
		else
		{
			if (isEmpty())
			{
				front = 0;
			}
			rear = (rear + 1) % size; //Циклически инкрементируем значение REAR на 1. Когда указатель окажется в конце очереди, он должен переместится в ее начало.
			arr[rear] = value;
			count++; //увеличиваем счетчик элементов в очереди на 1
			cout << "Добавлен элемент " << value << endl;
		}
	}

	void pop() 
	{
		int value;

		if (isEmpty())
		{
			cout << "Очередь пуста." << endl;
		}
		else 
		{
			value = arr[front];
			cout << "Удален элемент " << value << endl;
			if (front == rear)
			{
				front = -1;
				rear = -1;
			}
			else 
			{
				front = (front + 1) % size; //Циклически инкрементируем значение FRONT на 1
			}
			count--; //уменьшаем счетчик элементов в очереди на 1
		}
	}

	void print() 
	{
		int i;
		if (!isEmpty())
		{
			cout << "Очередь:" << endl;
			for (i = front; i != rear; i = (i + 1) % size)
			{
				cout << arr[i] << endl;
			}
			cout << arr[i] << endl; //последний элемент 
		}
		else
			cout << "Очередь пуста" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	CircularQueue cq(5);
	cq.push(0);
	cq.push(1);
	cq.push(2);
	cq.push(3);
	cq.push(4);
	cq.push(5);
	cout << "front = " << cq.getFront() << endl;
	cout << "rear = " << cq.getRear() << endl;
	cq.print();
	cq.pop();
	cq.pop();
	cq.pop();
	cout << "front = " << cq.getFront() << endl;
	cout << "rear = " << cq.getRear() << endl;
	cq.print();
	cq.push(22);
	cq.push(51);
	cq.push(677);
	cout << "front = " << cq.getFront() << endl;
	cout << "rear = " << cq.getRear() << endl;
	cq.print();
	cq.pop();
	cq.pop();
	cout << "front = " << cq.getFront() << endl;
	cout << "rear = " << cq.getRear() << endl;
	cq.print();
}

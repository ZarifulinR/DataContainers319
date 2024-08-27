#include<iostream>
using namespace std;
constexpr auto tab = "\t";;
#define delimiter "\n-------------------------"
class List
{
	class Element
	{
		int Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr)
			:Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{

			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
	}*Head, * Tail;
	size_t size;
public:
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~List()
	{
		while (Tail)pop_back();
		

		
		cout << "LDestructor:\t" << this << endl;
	}
	void push_front(int data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = new Element(data);
			
		}
		else
		{
			Element* New = new Element(data);
			New->pNext = Head;
			Head->pPrev = New;
			Head = New;
			size++;
		}
		
	}
	void push_back(int data)
	{
		Element* New = new Element(data);
		{
			New->pPrev = Tail;
			if (Tail != NULL)
				Tail->pNext = New;
			if (Head == NULL)
				Head == NULL;
			Tail = New;
			
		}
		size++;
	}
	void pop_front()
	{
		if (Head == NULL)return;
		Element* New = Head->pNext;
		if (New != NULL)
			New->pPrev = NULL;
		else
			Tail = NULL;

		delete Head;
		Head = New;
		size--;
	}
	
	void pop_back()
	{
		if (Tail == NULL)return;
		Element* New = Tail->pPrev;
		if (New != NULL)
			New->pNext = NULL;
		else
			Head = NULL;
		delete Tail;
		Tail = New;
		size--;
	}
	void print()const
	{
		cout << delimiter << endl;
		cout << "Head:\t" << Head << endl;

		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout<< Temp->pPrev << tab<< Temp << tab<< Temp->Data << tab<< Temp->pNext << endl;

		cout << "Tail:\t" << Tail << endl;
		cout << "Колличество элементов в списке: " << size << endl;
		cout << delimiter << endl;
	}
	void revers_print()const
	{
		cout << delimiter << endl;
		cout << "Tail:\t" << Tail << endl;

		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;

		cout << "Head:\t" << Head << endl;
		cout << "Колличество элементов в списке: " << size << endl;
		cout << delimiter << endl;
	}

	Element* getAt(int index)
	{
		Element* New = Head;
		int n=0 ;

			while (n != index)
			{
				if (New == NULL)
					return New;
				n++;
			}
			return New;
	}
	Element* operator [](int index)
	{
		return getAt(index);
	}
	void insert(int index, int data)
	{
		Element* right = getAt(index);
		if (right == NULL)
			return push_back(data);
		Element* left = right->pPrev;
		if (left == NULL)
			return push_front(data);
		Element* New = new Element(data);
		New->pPrev = left;
		New->pNext = right;
		left->pNext = New;
		right->pPrev = New;
		
	}
	void erase(int index)
	{
		Element* New = getAt(index);
		if (New == NULL)
			return;
		if (New->pPrev == NULL)
		{
			pop_front();
			return;
		}
		if (New->pNext ==NULL)
		{
			pop_back();
			return;
		}
		Element* left = New->pPrev;
		Element* right = New->pNext;
		left->pNext = right;
		right->pPrev = left;
		delete New;
		size--;
	}
};

	

							


		
	int main()
	{
		setlocale(LC_ALL, "");
		int n;
		cout << "Insert element "; cin >> n;
		List list;
		for (int i = 0; i < n; i++)
		{
			//list.push_front(rand() % 100);
			list.push_back(rand() % 100);
		}
		list.print();
		list.revers_print();
	}
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
constexpr char tab = '\t';;
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
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) : Temp(Temp)
		{
			cout << " ItConstructor:\t" << this << endl;
		}
		~Iterator()
		{
			cout << "tDestructor:\t" << this << endl;
		}
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator& operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		Iterator& operator--() {
			Temp = Temp->pPrev;
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		// Comparsion operators:
		bool operator==(const Iterator& othe)const
		{
			return this->Temp == othe.Temp;
		}
		bool operator!=(const Iterator& othe)const
		{
			return this->Temp != othe.Temp;
		}
			//  Dereference operators:
		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}
	};
	class ReversIterator
	{
		Element* Temp;
	public:
		ReversIterator(Element* Temp = nullptr) : Temp(Temp)
		{
			cout << "RItConstructor:\t" << this << endl;
		}
		~ReversIterator()
		{
			cout << "RiDectructor :\t" << endl;
		}
		// Incremento/Dicremento:
		ReversIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ReversIterator operator++(int)
		{
			ReversIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		ReversIterator& operator--()
		{
			Temp = Temp->pNext;
			return *this;
		}
		ReversIterator operator--(int)
		{
			ReversIterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		    ////Comprison operaor
		bool operator==(const ReversIterator& othe)const
		{
			return this->Temp == othe.Temp;
		}
		bool operator!=(const ReversIterator& othe)const
		{
			return this->Temp != othe.Temp;
		}
		/////////// Dereference operator
		const int& operator*() const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}
		ReversIterator operator +(const Element& Temp)
		{
			Element New = Temp;
			New = New.Data;

		}
		ReversIterator operator +(const Element& Temp)const
		{
			Element New = Temp;
			New = Temp.Data + Temp.Data;
		}
		
	
	};
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ReversIterator rbegid()
	{
		return Tail;
	}
	ReversIterator rend()
	{
		return nullptr;
	}
	

	//Constractors
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	List(const std::initializer_list<int>& il) :List()
	{
		for (int const* it = il.begin(); it != il.end(); ++it)
			push_back(*it);
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
			Head = Tail = new Element(data);

		}
		else
		{
			Element* New = new Element(data);
			New->pNext = Head;
			Head->pPrev = New;
			Head = New;
		}
		size++;

	}
	void push_back(int data)
	{
		Element* New = new Element(data);
		
			New->pPrev = Tail;
			if (Head == nullptr && Tail==nullptr)
				Head=Tail = New;
			else
			{
				New->pPrev = Tail;
				Tail = Tail->pNext = New;
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
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;

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
		int n = 0;

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
		if (New->pNext == NULL)
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

//#define BASE_CHECK

int main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
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
#endif // BASE_CHECK

	List list = { 3,5,8,13,21 };
	/*list.print();
	list.revers_print();*/
	for (int i : list)
		cout << i << tab;
	cout << endl;
	List list1 = { 1,1,1,1,1 };
	for (List::ReversIterator it = list.rbegid(); it != list.rend(); it++)
	{
		cout << *it << tab;
	}
	list + list1;

}
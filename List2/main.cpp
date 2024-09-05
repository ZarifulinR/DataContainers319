﻿#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
constexpr char tab = '\t';
#define delimiter "\n-------------------------"
template<typename T>
class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr)
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
	
	class ConstBaseItertor
	{
	protected:
			Element* Temp;
	public:
		ConstBaseItertor(Element*Temp =nullptr):Temp(Temp){}
		~ConstBaseItertor(){}
		bool operator==(const ConstBaseItertor& othe)const
		{
			return this->Temp == othe.Temp;
		}
		bool operator!=(const ConstBaseItertor& othe)const
		{
			return this->Temp != othe.Temp;
		}
		/////////// Dereference operator
		const T& operator*() const
		{
			return Temp->Data;
		}

	};

public:
	class ConstIterator: public ConstBaseItertor
	{
	public:
		ConstIterator(Element* Temp = nullptr) : ConstBaseItertor(Temp)
		{
			cout << " ItConstructor:\t" << this << endl;
		}
		~ConstIterator()
		{
			cout << "tDestructor:\t" << this << endl;
		}
		ConstIterator& operator++()
		{
			ConstBaseItertor::Temp = ConstBaseItertor:: Temp->pNext;
			return *this;
		}
		ConstIterator& operator++(int)
		{
			ConstIterator old = *this;
			ConstBaseItertor::Temp = ConstBaseItertor:: Temp->pNext;
			return old;
		}
		ConstIterator& operator--() {
			ConstBaseItertor::Temp = ConstBaseItertor:: Temp->pPrev;
			return *this;
		}
		ConstIterator operator--(int)
		{
			ConstIterator old = *this;
			ConstBaseItertor::Temp = ConstBaseItertor:: Temp->pPrev;
			return old;
		}
		
	};
	class ConstReversIterator:public ConstBaseItertor
	{
		
	public:
		ConstReversIterator(Element* Temp = nullptr) : ConstBaseItertor(Temp)
		{
			cout << "RItConstructor:\t" << this << endl;
		}
		~ConstReversIterator()
		{
			cout << "RiDectructor :\t" << endl;
		}
		// Incremento/Dicremento:
		ConstReversIterator& operator++()
		{
			ConstBaseItertor::Temp = ConstBaseItertor:: Temp->pPrev;
			return *this;
		}
		ConstReversIterator operator++(int)
		{
			ConstReversIterator old = *this;
			ConstBaseItertor ::Temp = ConstBaseItertor:: Temp->pPrev;
			return old;
		}
		ConstReversIterator& operator--()
		{
			ConstBaseItertor::Temp = ConstBaseItertor:: Temp->pNext;
			return *this;
		}
		ConstReversIterator operator--(int)
		{
			ConstReversIterator old = *this;
			ConstBaseItertor::Temp = ConstBaseItertor:: Temp->pNext;
			return old;
		}
		    
	};
	class Iterator : public ConstIterator
	{
	public:
		Iterator(Element*Temp = nullptr):ConstIterator(Temp){}
		~Iterator() {}
		T& operator*()
		{
			return ConstBaseItertor::Temp->Data;
		}
		
	};
	class ReversIterator :public ConstReversIterator
	{
	public:
		ReversIterator(Element* Temp = nullptr):ConstReversIterator(Temp) {}
		~ReversIterator(){}
		T& operator*()
		{
			return ConstBaseItertor::Temp->Data;
		}
	};
	
	ConstIterator begin()const
	{
		return Head;
	}
	ConstIterator end()const
	{
		return nullptr;
	}
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}

	ConstReversIterator rbegid()
	{
		return Tail;
	}
	ConstReversIterator rend()
	{
		return nullptr;
	}
	ReversIterator rbegid() const
	{
		return Tail;
	}
	ReversIterator rend()const
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
	List( const  std::initializer_list<T>& il) :List()
	{
		for (T const* it = il.begin(); it != il.end(); ++it)
			push_back(*it);
	}
	List(const List<T>& other) :List()
	{
		*this = other;
		cout << "CopyConstructor: " <<this<< endl;
	}
	~List()
	{
		while (Tail)pop_back();
		cout << "LDestructor:  \t" << this << endl;
	}

	//						Operators:
	template <typename T>List<T>& operator =(const List<T>& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
		cout << "CopyAssingment:  " <<this<< endl;
	}
	template <typename T>void push_front(T data)
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
	template <typename T>void push_back(T data)
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
	template <typename T>void pop_front()
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

	template <typename T>void pop_back()
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
	template <typename T>void print()const
	{
		cout << delimiter << endl;
		cout << "Head:\t" << Head << endl;

		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;

		cout << "Tail:\t" << Tail << endl;
		cout << "Колличество элементов в списке: " << size << endl;
		cout << delimiter << endl;
	}
	template <typename T>void revers_print()const
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
	template <typename T>void insert(T data, int index)
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
	template <typename T>void erase(int index)
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

 template<typename T> List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> buffer = left; // CopyConstructor
	for (List::ConstBaseItertor it = right.begin(); it != right.end(); ++it)
	{
		buffer.push_back(*it);
		//*it *= 10;
	}
	return buffer;
}
 template<typename T>void Grow(List<T>& list)
 {
	 for (List::ConstBaseItertor it = list.begin(); it != list.end(); ++it)
	 {
		 *it *= 10;
	 }
 }

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

#ifdef ITERATORS_CHECK
	List list = { 3,5,8,13,21 };
	list.print();
	list.revers_print();
	for (int i : list)
		cout << i << tab;
	cout << endl;
	List list1 = { 1,1,1,1,1 };
	for (List::ReversIterator it = list.rbegid(); it != list.rend(); it++)
	{
		cout << *it << tab;
	}
#endif // ITERATORS_CHECK



	List<int> list1 = { 3,5,8,13,21 };
	List<int> list2 = {34,55,89};
	/*list2.print();
	list2.revers_print();*/
	List<int> list3 = list1 + list2;
	//list3.print();
	//list3.revers_print();
	for (int i : list1)cout << i << tab; cout << endl;
	for (int i : list2)cout << i << tab; cout << endl;
	Grow(list3);
	for (int i : list3)cout << i << tab; cout << endl;
	List<double> d_list = { 11.1,22.1,56.45 };
}
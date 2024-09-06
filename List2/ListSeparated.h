#pragma once
template <typename T>
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
	class ConstBaseIterator
	{
	protected:
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp = nullptr) :Temp(Temp) {}
		~ConstBaseIterator() {}

		//					Comparison operators:
		bool operator==(const ConstBaseIterator& othe)const;
		bool operator!=(const ConstBaseIterator& othe)const;

		/////////// Dereference operator
		const T& operator*() const;
	};
public:
	class ConstIterator :public ConstBaseIterator
	{
	public:
		ConstIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp)
		{
			cout << "ItConstructor:\t" << this << endl;
		}
		~ConstIterator()
		{
			cout << "ItDestructor:\t" << this << endl;
		}


		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
	};
	class ConstReverseIterator :public ConstBaseIterator
	{
	public:
		ConstReverseIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp) {}
		~ConstReverseIterator()
		{
			cout << "RItDestructor:\t" << this << endl;
		}

		//					Incremento/Decremento:
		ConstReverseIterator& operator++();
		ConstReverseIterator operator++(int);
		ConstReverseIterator& operator--();
		ConstReverseIterator operator--(int);
	};

	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp = nullptr) :ConstIterator(Temp) {}
		~Iterator() {}

		T& operator*()
		{
			return ConstBaseIterator::Temp->Data;
		}
	};
	class ReverseIterator :public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp = nullptr) :ConstReverseIterator(Temp) {}
		~ReverseIterator() {}

		T& operator*();
	};


	ConstIterator begin()const;
	ConstIterator end()const;
	Iterator begin();
	Iterator end();


	ConstReverseIterator rbegin()const;
	ConstReverseIterator rend()const;
	ReverseIterator rbegin();
	ReverseIterator rend();

	//				Constructors:
	List();
	List(const std::initializer_list<T>& il);
	List(const List<T>& other);
	~List();

	//				Operators:
	List<T>& operator=(const List<T>& other);

	//				Adding elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(T Data, int index);

	//				Removing elements:
	void pop_front();
	void pop_back();

	//				Methods:
	void print()const;
	void reverse_print()const;
};

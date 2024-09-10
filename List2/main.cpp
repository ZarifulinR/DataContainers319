#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#include"ListSeparated.cpp"
#include <deque>
#define tab "\t"
#define delimiter "\n-------------------------------------------------\n"
///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////// Iterators ///////////////////////////////////

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	int n;
	cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();
	//for (int i = 0; i < 100; i++)list.pop_back();
	//list.reverse_print();

	int index;
	int value;
	cout << "Ââåäèòå èíäåêñ äîáàâëÿåìîãî ýëåìåíòà:"; cin >> index;
	cout << "Ââåäèòå çíà÷åíèå äîáàâëÿåìîãî ýëåìåíòà:"; cin >> value;
	list.insert(value, index);
	list.print();
	list.reverse_print();
#endif // BASE_CHECK

#ifdef ITERATORS_CHECK
	List list = { 3, 5, 8, 13, 21 };
	//list.print();
	//list.reverse_print();
	for (int i : list)cout << i << tab; cout << endl;
	for (List::ReverseIterator it = list.rbegin(); it != list.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // ITERATORS_CHECK

#ifdef LIS2


	List<int> list1 = { 3, 5, 8, 13, 21 };
	List<int> list2 = { 34, 55, 89 };
	List<int> list3 = list1 + list2;
	/*list3.print();
	list3.reverse_print();*/
	for (int i : list1)cout << i << tab; cout << endl;
	for (int i : list2)cout << i << tab; cout << endl;
	for (int i : list3)cout << i << tab; cout << endl;
	Grow(list3);
	for (int i : list3)cout << i << tab; cout << endl;
	List<double> d_list = { 22.2,332.55,4.5,66.5 };
	for (double i : d_list)cout << i << tab; cout << endl;
	List<std::string>s_list = { "Hello","World","" };
	for (std::string i : s_list)cout << i << tab; cout << endl;
#endif  LIS2
	int size = 10;
	deque<int>qeuue;
	

	for(int i=0; i<size;i++)
	{
		qeuue.push_front(rand() % 100);
				
	}
	
	for (int i : qeuue)cout << i << tab; cout << endl;
	cout << qeuue.size();  cout <<endl;
	qeuue.push_back(14);
	for (int i : qeuue)cout << i << tab; cout << endl;
	qeuue.pop_front();
	for (int i : qeuue)cout << i << tab; cout << endl;
	qeuue.push_front(222);
	for (int i : qeuue)cout << i << tab; cout << endl;
	qeuue.pop_back();
	for (int i : qeuue)cout << i << tab; cout << endl;
	qeuue.clear();
	for (int i : qeuue)cout << i << tab; cout << endl;

};

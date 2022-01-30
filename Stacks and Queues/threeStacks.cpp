#ifndef STACKS_H
#define STACKS_H

#include <iostream>
#include <map>

enum class StackIndex
{
	first,
	second,
	third
}; 

template <class T>
class ThreeStacks
{
public:
	ThreeStacks();
	~ThreeStacks();
public:
	void push(const T&, StackIndex);
	void pop(StackIndex);
	T top(StackIndex);
	bool isEmpty(StackIndex);
	void getArr() const;
private:
	const int m_arrSize;
	T* m_arr;
	const int m_firstStackMaxIndex;
	const int m_secondStackMaxIndex;
	const int m_thirdStackMaxIndex;
private:
	bool stackOverflow(StackIndex);
private:
	std::map<StackIndex, std::pair<const int, int*>> m_stack;

	int m_currentIndex1;
	int m_currentIndex2;
	int m_currentIndex3;
};

template <typename T>
void ThreeStacks<T>::getArr() const
{
	for(int i = 0; i < m_arrSize; ++i)
	{
		std::cout << m_arr[i] << " ";
	}
}

template <typename T>
void ThreeStacks<T>::pop(StackIndex index)
{
	--(*m_stack[index].second);
	m_arr[(*m_stack[index].second)] = 0;
}

template <typename T>
bool ThreeStacks<T>::isEmpty(StackIndex index)
{
	return !((*(m_stack[index].second)) % 10);
}

template <typename T>
T ThreeStacks<T>::top(StackIndex index)
{
	if (isEmpty(index))
	{
		std::cout << "Stack is empty !!! " << std::endl;
	}

	return m_arr[(*(m_stack[index].second)) - 1];
}

template <typename T>
ThreeStacks<T>::ThreeStacks() : m_arrSize (30),
			   m_firstStackMaxIndex (m_arrSize / 3 - 1),
			   m_secondStackMaxIndex (m_firstStackMaxIndex + 10),
			   m_thirdStackMaxIndex (m_secondStackMaxIndex + 10)
{
	m_currentIndex1 = 0;
	m_currentIndex2 = 10;
	m_currentIndex3 = 20;

	m_arr = new T[m_arrSize];
	m_stack.emplace(StackIndex::first, std::pair<const int, int*> ( m_firstStackMaxIndex, &m_currentIndex1 ));
	m_stack.emplace(StackIndex::second, std::pair<const int, int*> ( m_secondStackMaxIndex, &m_currentIndex2 ));
	m_stack.emplace(StackIndex::third, std::pair<const int, int*> ( m_thirdStackMaxIndex, &m_currentIndex3 ));
}

template <typename T>
bool ThreeStacks<T>::stackOverflow(StackIndex index)
{
	return *(m_stack[index].second) > m_stack[index].first ? throw std::overflow_error("Stack Overflow !!! ") : false;
}

template <typename T>
void ThreeStacks<T>::push(const T& data, StackIndex index)
{
	if (!(stackOverflow(index)))
	{
		m_arr[*(m_stack[index].second)] = data;
		++(*(m_stack[index].second));
	}
}

template <typename T>
ThreeStacks<T>::~ThreeStacks()
{
	delete[] m_arr;
}

int main()
{
	ThreeStacks<int> s;
	StackIndex index = StackIndex::first;

	s.push(4, index);
	s.push(5, index);
	s.push(7, index);
	s.push(11, index);

	s.getArr();
	std::cout << std::endl << s.top(index) << std::endl;

	s.push(1, index);
	s.push(0, index);
	s.push(-8, index);
	s.push(8, index);
	s.push(3, index);
	s.push(2, index);
//	s.push(6, index);  //first stack overflow

	std::cout << s.top(index) << std::endl;

	index = StackIndex::second;
	s.top(index);      //second stack is empty

	index = StackIndex::third;

	s.push(4, index);
	std::cout << s.top(index) << std::endl;
	s.pop(index);
	s.top(index); //third stack is empty

	s.getArr(); // all 3 stacks

	std::cout << std::endl;

	return 0;
}

#endif

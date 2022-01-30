#ifndef STACK_CPP
#define STACK_CPP

#include <iostream>

template <class T>
class Stack
{
public:
	Stack();
	~Stack();
public:
	void push(const T&);
	void pop();
	T top() const;
	bool isEmpty() const;
	T min() const;
private:
	bool stackOverflow() const;
private:
	const int m_stackMaxSize;
	T* m_stack;
	int m_sp;
	T m_min;
};

template <typename T>
bool Stack<T>::stackOverflow() const
{
	return (m_sp > m_stackMaxSize) ? throw std::overflow_error("Stack Overflow !!! ") : false;
}

template <typename T>
T Stack<T>::min() const
{
	return m_min;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return !m_sp;
}

template <typename T>
T Stack<T>::top() const
{
	if (isEmpty())
	{
		std::cout << "Stack is empty !!! " << std::endl;
	}

	return m_stack[m_sp - 1];
}

template <typename T>
void Stack<T>::pop()
{
	if (!(isEmpty()))
	{
		--m_stack[m_sp];
		m_stack[m_sp] = 0;
	}
}

template <typename T>
void Stack<T>::push(const T& data)
{
	if (!(stackOverflow()))
	{
		if(m_sp == 0 || (data < m_min))
		{
			m_min = data;
		}

		m_stack[m_sp] = data;
		++m_sp;
	}
}

template <typename T>
Stack<T>::Stack() : m_stackMaxSize(100),
		    m_sp(0)
{
	m_stack = new T[m_stackMaxSize];
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] m_stack;
}

int main()
{
	Stack<int> st;

	st.push(4);
	st.push(7);
	st.push(1);
	st.push(11);

	std::cout << "top : " << st.top() << std::endl;
	std::cout << "min : " << st.min() << std::endl;

	return 0;
}

#endif

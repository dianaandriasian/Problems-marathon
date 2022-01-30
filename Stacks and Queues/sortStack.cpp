#ifndef SORT_CPP
#define SORT_CPP

#include <iostream>
#include <stack>

template <typename T>
void fillStack(std::stack<T>&);

template <typename T>
std::stack<T> sortStack(std::stack<T>&);

template <typename T>
void printStack(std::stack<T>);

int main()
{
	std::stack<int> st;

	fillStack(st);
	std::stack<int> sortedStack = sortStack(st);
	printStack(sortedStack);

	return 0;
}

template <typename T>
void printStack(std::stack<T> sortedStack)
{
	while(!sortedStack.empty())
	{

		std::cout << sortedStack.top() << " ";
		sortedStack.pop();
	}

	std::cout << std::endl;
}

template <typename T>
std::stack<T> sortStack(std::stack<T>& st)
{
	std::stack<T> helperStack;

	while(!st.empty())
	{
		T tmp = st.top();
		st.pop();

		while(!helperStack.empty() && tmp > helperStack.top())
		{

			st.push(helperStack.top());
			helperStack.pop();
		}

		helperStack.push(tmp);
	}

	return helperStack;
}

template <typename T>
void fillStack(std::stack<T>& st)
{
	int n = 7;
	T data = 0;

	while(n)
	{
		std::cout << "Enter data for pushing : ";
		std::cin >> data;
		st.push(data);

		--n;
	}	
}

#endif

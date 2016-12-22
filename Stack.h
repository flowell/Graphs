/*
* Array-based Stack
*
*/

#ifndef STACK_H
#define STACK_H

template <typename E>
class Stack {
public:
	Stack(int maxsize = 0);
	void push(E e);
	bool isEmpty() const { return size == 0; }
	E pop();
	E last() const { return stack[size-1]; }
private:
	E* stack;
	int size;
	int maxSize;

	void resize(int newSize);
};

template <typename E>
Stack<E>::Stack(int maxsize) {
	maxSize = maxsize;
	size = 0;
	first = last = 0;
	if (maxSize <= 0)
		stack = NULL;
	else
		stack = new E[maxSize];
}

template <typename E>
void Stack<E>::push(E e) {
	if (maxSize == 0) {
		stack = new E[1];
		stack[0] = e;
		maxSize = 1;
		size = 1;
		return;
	}
	if (size == maxSize)
		resize(2*maxSize);
	stack[size++] = e;
	return;
}

template <typename E>
void Stack<E>::resize(int newSize) {
	E* temp = stack;
	stack = new E[newSize];
	for (int i = 0; i < size; ++i)
		stack[i] = temp[i];
	maxSize = newSize;
	delete [] temp;
}

template <typename E>
E Stack<E>::pop() {
	if (size == 0)
		std::cout << "The Stack was empty.\n";
	if (size <= maxSize/4)
		resize(maxSize/2);
	return stack[--size];
}

#endif

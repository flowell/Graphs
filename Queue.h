/*
*环形可变长Queue
*
*
*/

#ifndef QUEUE_H
#define QUEUE_H

template <typename E>
class Queue {
public:
	Queue();
	void enqueue(E e);
	E dequeue();
	E first() const { return queue[first]; }
	bool isEmpty() const { return size == 0; }

private:
	int size;
	int maxSize;

	int first;
	int last;

	E* queue;
	void resize(int newSize);
};

template <typename E>
Queue<E>::Queue() {
	queue = NULL;
	size = maxSize = 0;
	first = last = 0;
}

template <typename E>
void Queue<E>::enqueue(E e) {
	if (maxSize == 0) {
		queue = new E[1];
		queue[0] = e;
		first = last = 0;
		size = maxSize = 1;
		return;
	}
	if (size == maxSize)
		resize(2*maxSize);
	last = (last+1) % maxSize;
	queue[last] = e;
	++size;
}

template <typename E>
E Queue<E>::dequeue() {
	if (size == 0)
		std::cout << "The Queue was empty.\n";
	if (size <= maxSize/4)
		resize(maxSize/2);
	E temp = queue[first];
	first = (first+1) % maxSize;
	--size;
	return temp;
}

template <typename E>
void Queue<E>::resize(int newSize) {
	E* temp = queue;
	queue = new E[newSize];
	if (first < last)
		for (int j = first, i = 0; i < size; ++i, ++j)
			queue[i] = temp[j];
	else {
		int i = 0;
		for (int j = first; j < maxSize; ++j, ++i)
			queue[i] = temp[j];
		for (int j = 0; j <= last; ++j, ++i)
			queue[i] = temp[j];
	}
	//重置first和last的index
	if (maxSize >= newSize) {
		first = 0;
		last = size;
	}
	maxSize = newSize;
	delete [] temp;
}
#endif

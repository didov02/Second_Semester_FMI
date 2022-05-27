#pragma once
#include <iostream>

const int DEFAULT_CAPACITY = 4;

template <typename T>
struct K
{
	T element;
	size_t priority;
};

template <typename T>
class kPriorityQueue
{
private:
	K* elements;
	size_t maxPriority;
	size_t size;
	size_t capacity;
public:
	kPriorityQueue();
	kPriorityQueue(const K*, size_t, size_t, size_t);
	kPriorityQueue(const kPriorityQueue&);
	kPriorityQueue& operator=(const kPriorityQueue&);
	~kPriorityQueue();

	void enqueue(T,size_t);
	const T dequeue() const;

	size_t getBiggestPriority() const;
	size_t getSize() const;

	void setMaxPriority(size_t);

private:
	void copy(const kPriorityQueue&);
	void free();

	size_t calculateCapacity(const size_t) const;
	void resize(const size_t);
};



template <typename T>
void kPriorityQueue<T>::copy(const kPriorityQueue& other)
{
	this->size = other.size;
	this->maxPriority = other.maxPriority;

	for (int i = 0; i < size; i++)
	{
		elements[i].element = other[i].element;
		elements[i].priority = other[i].;
	}
}

template <typename T>
void kPriorityQueue<T>::free()
{
	delete[] elements;
}

template <typename T>
size_t kPriorityQueue<T>::calculateCapacity(const size_t number) const {
	size_t result = DEFAULT_CAPACITY;
	while (number > result)
		result *= 2;

	return result;
}

template <typename T>
void kPriorityQueue<T>::resize(const size_t expectedCapacityToFit) {
	capacity = calculateCapacity(expectedCapacityToFit);
	K* temp = new K[capacity];

	for (size_t i = 0; i < size; i++)
		temp[i] = elements[i];

	delete[] elements;
	elements = temp;
}

template <typename T>
kPriorityQueue<T>::kPriorityQueue()
{
	elements = nullptr;
	maxPriority = 0;
	size = 0;
	capacity = DEFAULT_CAPACITY;
}

template <typename T>
kPriorityQueue<T>::kPriorityQueue(const K<T>* elements, size_t maxPriority, size_t size, size_t capacity)
{
	for (int i = 0; i < size; i++)
	{
		this->elements[i].element = elements[i].elements;
		this->elements[i].size = elements[i].size;
	}

	this->maxPriority = maxPriority;

	this->size = size;

	this->capacity = capacity;
}

template <typename T>
kPriorityQueue<T>::kPriorityQueue(const kPriorityQueue& other)
{
	copy(other);
}

template <typename T>
kPriorityQueue<T>& kPriorityQueue<T>::operator=(const kPriorityQueue& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

template <typename T>
kPriorityQueue<T>::~kPriorityQueue()
{
	free();
}

template <typename T>
size_t kPriorityQueue<T>::getBiggestPriority() const
{
	size_t biggestPriority = 0;
	
	for (int i = 0; i < size; i++)
	{
		if (elements[i].priority > biggestPriority)
		{
			biggestPriority = elements[i].priority;
		}
	}

	return biggestPriority;
}

template <typename T>
size_t kPriorityQueue<T>::getSize() const
{
	return size;
}

template <typename T>
void kPriorityQueue<T>::setMaxPriority(size_t currentPriority)
{
	this->maxPriority = currentPriority - 1;
}

template <typename T>
void kPriorityQueue<T>::enqueue(T element, size_t priority)
{
	if (priority > maxPriority-1)
	{
		throw "Error! No such priority";
	}

	if (size + 1 > capacity)
		resize(size + 1);

	elements[size].element = element;
	elements[size++].priority = priority;
}

template <typename T>
const T kPriorityQueue<T>::dequeue() const
{
	size_t biggestPriority = getBiggestPriority();
	T biggestElement = NULL;

	for (int i = 0; i < size; i++)
	{
		if (elements[i].priority == biggestPriority)
		{
			if (elements[i].element > biggestElement)
			{
				biggestElement = elements[i].element;
			}
		}
	}

	std::cout << biggestElement << std::endl;

	for (int i = 0; i < size; i++)
	{
		if (elements[i].priority == biggestPriority)
		{
			if (elements[i].element == biggestElement)
			{
				delete[] elements[i];
				size--;
			}
		}
	}
}
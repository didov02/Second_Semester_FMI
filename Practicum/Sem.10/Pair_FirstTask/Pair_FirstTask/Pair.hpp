#pragma once

template <typename T>
class Pair
{
private:
	T firstElement;
	T secondElement;
public:
	Pair() = default;
	Pair(const T&, const T&);

	bool operator==(const Pair&);
	bool operator!=(const Pair&);

	T getFirstElement() const;
	T getSecondElement() const;

	void setFirstElement(const T&);
	void setSecondElement(const T&);

	T getMaxElement() const;
};

template<typename T>
Pair<T>::Pair(const T& firstElement, const T& secondElement)
{
	this->firstElement = firstElement;
	this->secondElement = secondElement;
}

template<typename T>
bool Pair<T>::operator==(const Pair& other)
{
	if (firstElement == other.firstElement && secondElement == other.secondElement)
		return true;

	return false;
}

template<typename T>
bool Pair<T>::operator!=(const Pair& other)
{
	if (firstElement == other.firstElement && secondElement == other.secondElement)
		return false;

	return true;
}

template<typename T>
T Pair<T>::getFirstElement() const
{
	return firstElement;
}

template<typename T>
T Pair<T>::getSecondElement() const
{
	return secondElement;
}

template<typename T>
void Pair<T>::setFirstElement(const T& element)
{
	firstElement = element;
}

template<typename T>
void Pair<T>::setSecondElement(const T& element)
{
	secondElement = element;
}

template<typename T>
T Pair<T>::getMaxElement() const
{
	if (firstElement > secondElement)
		return firstElement;

	return secondElement;
}
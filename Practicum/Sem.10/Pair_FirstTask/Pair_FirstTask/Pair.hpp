#pragma once

template <typename T>
class Pair
{
private:
	T firstElement;
	T secondElement;
public:

	bool operator==(const Pair& other)
	{
		if (this->firstElement == other.firstElement
			&& this->secondElement == other.secondElement)
		{
			return true;
		}

		return false;
	}

	bool operator!=(const Pair& other)
	{
		if (this->firstElement != other.firstElement
			&& this->secondElement != other.secondElement)
		{
			return true;
		}

		return false;
	}


	T getFirstElement() const
	{
		return firstElement;
	}

	T getSecondElement() const
	{
		return secondElement;
	}

	void setFirstElement(const T& element)
	{
		this->firstElement = element;
	}

	void setSecondElement(const T& element)
	{
		this->secondElement = element;
	}

	const T& getMaxElement() const
	{
		if (this->firstElement > this->secondElement)
		{
			return this->firstElement;
		}

		return this->secondElement;
	}

};

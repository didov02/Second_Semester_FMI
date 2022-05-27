#include "kPriorityQueue.hpp"
#include <iostream>

int main()
{
	kPriorityQueue<char> q;
	q.setMaxPriority(4);

	q.enqueue('A', 0);
	q.enqueue('B', 3);
	q.enqueue('C', 2);
	q.enqueue('D', 2);
	q.enqueue('E', 1);


	q.dequeue(); // B
	q.dequeue(); // C
	q.dequeue(); // D
	q.dequeue(); // E
	q.dequeue(); // A
}
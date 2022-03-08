#include <iostream>
#include <fstream>

using namespace std;

const int MAX_PAIRS = 25;

struct Pair
{
	int x, y;
};

struct Relation
{
	Pair pairs[MAX_PAIRS];
	size_t size;
};

void createPair(Pair pair)
{
	cin >> pair.x >> pair.y;
}

void readPairFromFile(Pair pair, size_t size)
{
	ifstream in;
	in.open("relation.txt");

	if (in.is_open())
	{
		int x, y;
		int counter = 0;

		while (in >> x >> y)
		{
			if (counter == size)
			{
				cout << x << " " << y;
			}
			counter++;
		}
	}

	in.close();
}

void writePairToFile(Pair pair)
{
	ofstream out;
	out.open("relation.txt");

	if (out.is_open())
	{
		out << pair.x << " " << pair.x << endl;
	}
}

void addPairToRelation(Pair pair, Relation relation)
{
	relation.pairs[relation.size++] = pair;
}

void writeRelationToFile()
{
	Relation relation;

	for (int i = 0; i < relation.size; i++)
	{
		writePairToFile(relation.pairs[i]);
	}
}

void readRelationFromFile()
{
	Relation relation;

	for (int i = 0; i < relation.size; i++)
	{
		readPairFromFile(relation.pairs[i], i);
	}
}

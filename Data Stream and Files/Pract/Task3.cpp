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

void createPair(Pair& pair)
{
	cin >> pair.x >> pair.y;
}

void readPairFromFile(Relation& relation, int firstNum, int secondNum, size_t size)
{
	relation.pairs[size].x = firstNum;
	relation.pairs[size].y = secondNum;
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

void writeRelationToFile(Relation relation)
{

	for (int i = 0; i < relation.size; i++)
	{
		writePairToFile(relation.pairs[i]);
	}
}

Relation readRelationFromFile()
{
	Relation newRelation;

	ifstream in;
	in.open("relation.txt");

	if (!in.is_open())
	{
		cout << "Error!" << endl;
		return newRelation;
	}

	int x, y;
	newRelation.size = 0;

	while (in >> x >> y)
	{
		readPairFromFile(newRelation,x,y,newRelation.size);
		newRelation.size++;
	}

	return newRelation;
}

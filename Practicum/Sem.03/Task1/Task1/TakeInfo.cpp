#include "TakeInfo.h"

size_t getFileSize(std::ifstream& f)
{
	size_t currentPos = f.tellg();
	f.seekg(0, std::ios::end);
	size_t size = f.tellg();

	f.seekg(currentPos);
	return size;
}

void takeInfoFromFile(std::ifstream& inFile, OffersCollector& offers)
{
	size_t sizeOfFile = getFileSize(inFile);
	size_t offersCount = sizeOfFile / sizeof(Offers);

	for (int i = 0; i < offersCount; i++)
	{
		Offers temp;

		size_t nameLen;
		inFile.read((char*)&nameLen, sizeof(nameLen));
		char* tempName = new char[nameLen];
		inFile.read(tempName, sizeof(nameLen));

		size_t programersCount;
		inFile.read((char*)&programersCount, sizeof(programersCount));

		size_t daysOff;
		inFile.read((char*)&daysOff, sizeof(daysOff));

		double payment;
		inFile.read((char*)&payment, sizeof(payment));

		temp.setName(tempName);
		temp.setProgramersCount(programersCount);
		temp.setDaysOff(daysOff);
		temp.setPayment(payment);

		offers.addOffer(temp);
	}
}
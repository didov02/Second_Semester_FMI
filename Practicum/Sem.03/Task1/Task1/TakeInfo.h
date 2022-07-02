#pragma once
#include "OffersCollector.h"

size_t getFileSize(std::ifstream& f);

void takeInfoFromFile(std::ifstream& inFile, OffersCollector offers);

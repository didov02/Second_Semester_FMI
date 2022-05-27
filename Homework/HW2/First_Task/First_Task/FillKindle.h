#pragma once

#include <cstring>
#include "Kindle.h"
#pragma warning (disable : 4996)

const int MAX_SYMBOL = 50;

void GetReadBooksFileName(char*& fileName, char* username);

void GetWritenBooksFileName(char*& fileName, char* username);

void Fill(char* fileName, User& currentUser, char* mode, Kindle& kindle);

void FillKindleUsers(Kindle& kindle);

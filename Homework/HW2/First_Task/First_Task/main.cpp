#include <fstream>
#include "Kindle.h"
#include "FillKindle.h"

const int MAX_MENU = 7;
const int MAX_SYMBOLS = 50;
const int READ = 5;

void GetBookName(char*& input)
{
	size_t sizeNeeded = strlen(input) - READ + 1;
	char* temp = new char[sizeNeeded];
	for (int i = 0; i < sizeNeeded; i++)
	{
		temp[i] = input[i + READ + 1];
	}
	temp[sizeNeeded] = '\0';

	delete[] input;
	input = new char[sizeNeeded];
	strcpy(input, temp);

	delete[] temp;
}

void Menu()
{
	std::cout << "1.sign up" << std::endl;
	std::cout << "2.log in" << std::endl;
	std::cout << "3.leave the program" << std::endl;
}

void Options()
{
	std::cout << "1.view" << std::endl;
	std::cout << "2.read" << std::endl;
	std::cout << "3.write" << std::endl;
	std::cout << "4.rate" << std::endl;
	std::cout << "5.leave a comment" << std::endl;
	std::cout << "6.change a rate" << std::endl;
	std::cout << "7.get page" << std::endl;
	std::cout << "8.read comments" << std::endl;
	std::cout << "9.log out" << std::endl;
}

int main()
{
	Kindle kindle;
	FillKindleUsers(kindle);

	std::cout << "Menu:" << std::endl;

	while (true)
	{
		Menu();
		char* chooseFromMenu = new char[MAX_MENU];
		std::cin.getline(chooseFromMenu, MAX_MENU);

		if (strcmp(chooseFromMenu, "sign up"))
		{
			std::cout << "Enter username: ";
			char* currentUsername = new char[MAX_SYMBOLS];
			std::cin.getline(currentUsername, MAX_SYMBOLS);

			std::cout << "Enter password: ";
			char* currentPassword = new char[MAX_SYMBOLS];
			std::cin.getline(currentPassword, MAX_SYMBOLS);

			kindle.setUsersCount(kindle.getUsersCount() + 1);
			kindle.addUser(currentUsername, currentPassword, kindle.getUsersCount());
			std::cout << "User added!" << std::endl;
		}
		else if (strcmp(chooseFromMenu, "log in"))
		{
			std::cout << "Enter username: ";
			char* currentUsername = new char[MAX_SYMBOLS];
			std::cin.getline(currentUsername, MAX_SYMBOLS);

			std::cout << "Enter password: ";
			char* currentPassword = new char[MAX_SYMBOLS];
			std::cin.getline(currentPassword, MAX_SYMBOLS);

			if (kindle.getInSystem(currentUsername, currentPassword))
			{
				User currentUser;
				currentUser = kindle.getUser(currentUsername, currentPassword);
				Options();

				while (true)
				{
					char* option = new char[MAX_SYMBOLS];
					std::cin.getline(option, MAX_SYMBOLS);

					if (strcmp(option, "view"))
					{
						std::ifstream books("books.txt");

						size_t allBooksCount;
						books >> allBooksCount;

						for (int i = 0; i < allBooksCount; i++)
						{
							char* bookName = new char[MAX_SYMBOLS];
							books.getline(bookName, MAX_SYMBOLS);
							std::cout << bookName << std::endl;

							delete[] bookName;
						}
					}
					else if (strcmp(option, "read"))
					{
						char* bookToRead = new char[MAX_SYMBOLS];
						std::cin.getline(bookToRead, MAX_SYMBOLS);

						GetBookName(bookToRead);

						if (currentUser.isBookRead(bookToRead))
						{
							std::cout << "This book is already read by " << currentUsername << std::endl;
						}
						else
						{
							Book newBook;
							newBook = kindle.getBook(bookToRead);
							currentUser.readBook(newBook);
						}
						
						delete[] bookToRead;
					}
					else if (strcmp(option, "write"))
					{
						std::cout << "Your new book name is:" << std::endl;
						char* newBookName = new char[MAX_SYMBOLS];
						std::cin.getline(newBookName, MAX_SYMBOLS);

						std::cout << "Your new book pages count is:" << std::endl;
						size_t pagesCount;
						std::cin >> pagesCount;

						Page* pages = new Page[pagesCount];

						for (int i = 0; i < pagesCount; i++)
						{
							pages[i].setPage(i + 1);

							char* content = new char[MAX_SYMBOLS];
							std::cout << "Content: " << std::endl;
							std::cin.getline(content, MAX_SYMBOLS);

							pages[i].setContent(content);

							delete[] content;
						}

						currentUser.writeBook(newBookName, currentUsername, pagesCount, pages);

						kindle.addBook(newBookName, currentUsername, pagesCount, pages);

						delete[] newBookName;
					}
					else if (strcmp(option, "rate"))
					{
						std::cout << "Book you want to rate:" << std::endl;
						char* bookToRate = new char[MAX_SYMBOLS];
						std::cin.getline(bookToRate, MAX_SYMBOLS);

						std::cout << "Rate:" << std::endl;
						size_t rate;
						std::cin >> rate;

						Book temp;
						temp = kindle.getBook(bookToRate);
						currentUser.rateBook(temp, rate);

						delete[] bookToRate;
					}
					else if (strcmp(option, "leave a comment"))
					{
						std::cout << "Book you want to leave comment after:" << std::endl;
						char* bookToComment = new char[MAX_SYMBOLS];
						std::cin.getline(bookToComment, MAX_SYMBOLS);

						std::cout << "Comment:" << std::endl;
						char* comment = new char[MAX_SYMBOLS];
						std::cin.getline(comment, MAX_SYMBOLS);

						Book temp;
						temp = kindle.getBook(bookToComment);

						Comment tempComment;
						tempComment.setAuthor(currentUser.getName());
						tempComment.setContent(comment);
						currentUser.leaveComment(temp, tempComment);

						delete[] bookToComment;
						delete[] comment;
					}
					else if (strcmp(option, "change a rate"))
					{
						std::cout << "On witch book you want to change the rate:" << std::endl;
						char* bookToChangeRate = new char[MAX_SYMBOLS];
						std::cin.getline(bookToChangeRate, MAX_SYMBOLS);

						std::cout << "New rate:" << std::endl;
						size_t rate;
						std::cin >> rate;

						Book temp;
						temp = kindle.getBook(bookToChangeRate);

						temp.changeRating(currentUser.getName(), rate);
					}
					else if (strcmp(option, "get page"))
					{
						std::cout << "Book you want to get page from:" << std::endl;
						char* bookToGetPageFrom = new char[MAX_SYMBOLS];
						std::cin.getline(bookToGetPageFrom, MAX_SYMBOLS);

						std::cout << "Which page:" << std::endl;
						size_t page;
						std::cin >> page;

						Book temp;
						temp = kindle.getBook(bookToGetPageFrom);

						currentUser.getPage(temp, page);

						delete[] bookToGetPageFrom;
					}
					else if (strcmp(option, "read comments"))
					{
						std::cout << "Which book comments do you want to read:" << std::endl;
						char* bookToReadCommentsFrom = new char[MAX_SYMBOLS];
						std::cin.getline(bookToReadCommentsFrom, MAX_SYMBOLS);

						Book temp;
						temp = kindle.getBook(bookToReadCommentsFrom);

						temp.printComments();

						delete[] bookToReadCommentsFrom;
					}
					else if (strcmp(option, "log out"))
					{
						break;
					}

					delete[] option;

				}
			}
			
			delete[] currentUsername;
			delete[] currentPassword;
		}
		else if (strcmp(chooseFromMenu, "leave the program"))
		{
			delete[] chooseFromMenu;
			std::cout << "Have a nice day!" << std::endl;
			break;
		}

		delete[] chooseFromMenu;
	}
}
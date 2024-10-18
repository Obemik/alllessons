#include <iostream>
using namespace std;

#include "solo_linked_list.h"

int main()
{
	SoloLinkedList<double> list;
	do
	{
		system("cls");
		cout << "#>----------<MENU>----------<#" << endl;
		cout << "| 1. Push back               |" << endl;
		cout << "| 2. Push front              |" << endl;
		cout << "| 3. Insert                  |" << endl;
		cout << "| 4. Pop back                |" << endl;
		cout << "| 5. Pop front               |" << endl;
		cout << "| 6. Erase                   |" << endl;
		cout << "| 7. Remove                  |" << endl;
		cout << "| 8. Print                   |" << endl;
		cout << "| 9. Exit                    |" << endl;
		cout << "#>--------------------------<#" << endl;
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			double value;
			cout << "Enter value: ";
			cin >> value;
			list.push_back(value);
		}break;
		case 2:
		{
			double value;
			cout << "Enter value: ";
			cin >> value;
			list.push_front(value);
		}break;
		case 3:
		{
			double value;
			size_t index;
			cout << "Enter value: ";
			cin >> value;
			cout << "Enter index: ";
			cin >> index;
			list.insert(value, index);
		}break;
		case 4:
		{
			list.pop_back();
		}break;
		case 5:
		{
			list.pop_front();
		}break;
		case 6:
		{
			size_t index;
			cout << "Enter index: ";
			cin >> index;
			list.erase(index);
		}break;
		case 7:
		{
			double value;
			cout << "Enter value: ";
			cin >> value;
			list.remove(value);
		}break;
		case 8:
		{
			list.print();
		}break;
		case 9:
		{
			exit(0);
		}break;
		}
		system("pause");
	} while (true);

	return 0;
}
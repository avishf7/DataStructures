//Avishay Farkash 205918790
//Shai Axelrod 205544307

#include<iostream>
#include "HSubject.h"
using namespace std;

int main()
{
	char ch;//the user choice
	int n;//For the printN function
	HSubject hs(1000);//the hash table
	string subject, title;//For key end dat
	
	//Options menu:
	cout << "Hash Table\n";
	cout << "\nChoose one of the following" << endl;
	cout << "n: New hash table" << endl;
	cout << "a: Add a subject and a title" << endl;
	cout << "d: Del a subject " << endl;
	cout << "t: print all titles of the subject " << endl;
	cout << "s: print N first appearances of a subect " << endl;
	cout << "p: print all non-empty entries " << endl;
	cout << "e: Exit" << endl;
	do//All options for actions on the table - according to the user's choice(see in HSubject.h)
	{
		cin >> ch;
		switch (ch)
		{
		case 'n':hs.startNewTable(); break;
		case 'a':cout << "Enter a subject and a title\n";
			cin >> subject >> title;
			hs.addSubjectAndTitle(subject, title);
			break;
		case 'd':cout << "Enter a subject to remove\n";
			cin >> subject;
			hs.remove(subject); break;
		case 't':cout << "enter subject to print\n";
			cin >> subject;
			hs.printS(subject); break;
		case 's':cout << "enter a subject and N\n"; cin >> subject >> n;
			hs.printN(subject, n); break;
		case 'e':cout << "bye\n"; break;
		case 'p':hs.print(); break;
		default: cout << "ERROR\n";  break;
		}
	} while (ch != 'e');
	return 0;
}
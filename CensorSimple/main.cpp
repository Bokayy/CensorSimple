//the plan: compare 2 sets of strings, no vectors

#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

//funkcija za detekciju i cenzuriranje zlih riječi
string BadWordsFilter(string tocheck)
{
	istringstream iss(tocheck);
	string NewMessage;
	int howManyWords = 0; //counter which counts how many words (NOT letters (chars)) there are in a given string
	string Illegal[5] = { "badword1", "badword2", "badword3", "badword4", "badword5" };

	do{
		string temp;
		iss >> temp;
		howManyWords++;
	} while (iss);
	howManyWords--;


	istringstream iss2(tocheck);

	for (int i = 0; i <= howManyWords; i++)
	{
		string substring;
		iss2 >> substring;
		
		if (substring == Illegal[0]) { substring = "******"; }
		if (substring == Illegal[1]) { substring = "******"; }
		if (substring == Illegal[2]) { substring = "******"; }
		if (substring == Illegal[3]) { substring = "******"; }
		if (substring == Illegal[4]) { substring = "******"; }

		NewMessage.append(substring + " ");

	}
	return NewMessage;
}



int main()
{

	string poruka;
	cout << "unesi poruku" << endl;
	getline(cin, poruka); //getline VERY IMPORTANT, DON'T USE CIN BY ITSELF, but use it in getline

	//testiranje substringa
	//istringstream iss(poruka);
	//string connected;

	cout << BadWordsFilter(poruka);

	return 0;
}


//testing to see what iss spits out
//for (int i = 0; i < 5; i++) {
//	string subs;
//	iss >> subs;
//	cout << subs << endl;
//}
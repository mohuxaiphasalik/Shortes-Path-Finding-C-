
////////This is main file 

#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include"Graph.h"
#include"algo.h"
using namespace std;

string small_letter(string str) {

	int len = str.size();
	for (int i = 0; i < len; ++i)
	{
		if (str[i] != ' ')
		{
			if (isupper(str[i]))
				str[i] = tolower(str[i]);
		}
		else
		{
			i++;
			if (islower(str[i]))
				str[i] = toupper(str[i]);
		}
	}
	return str;
};
void main() {
	Graph gp;
	algo al;
	string origin, destination;
	while (true)
	{
		cout << "Enter Origin: ";
		getline(cin, origin);
		cout << "Enter destination: ";
		getline(cin, destination);
		origin = small_letter(origin);
		destination = small_letter(destination);
		al.origin = origin;
		al.destenation = destination;
		al.check_shortest_path();
	}
}

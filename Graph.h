#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<list>
using namespace std;
struct adjacent_city {
	string city_name;  //adjacent city name
	float distance;  //distance from origin

};

struct origin_nodes {
	string origin_name;  //orgin name
	list<adjacent_city> linked_cities;  //list of cities linked with that origin
};
class Graph {
public:
	list<origin_nodes> complete_graph;
	Graph() {
		ifstream out("new.txt");
		string word;
		float distance;
		bool new_line = true;
		origin_nodes a;
		adjacent_city b;
		while (out >> word) {
			if (int(word[0]) >= 97 && int(word[0]) <= 122) {
				if (new_line) {
					a.origin_name = word;
					new_line = false;
				}
				else {
					b.city_name = word;
				}
			}
			else if (word != ";") {
				distance = stof(word);
				b.distance = distance;
				a.linked_cities.push_back(b);
			}
			else if (word == ";") {
				new_line = true;
				complete_graph.push_back(a);
				a.linked_cities.clear();
			}
		}
		out.close();
	}
};

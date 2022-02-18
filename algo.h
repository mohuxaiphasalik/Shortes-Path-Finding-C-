#pragma once
#include<iostream>
#include<string>
#include<list>
#include"Graph.h"
#include<iterator>;"
using namespace std;
class algo {
private:
	Graph gp;
	list<adjacent_city> visited_cities;
	float td;
	string new_origin;
	float min_dis, alter_dis;
	origin_nodes check_origin(string origin_name) {
	again:
		bool org = false;
		list<origin_nodes>::iterator i = gp.complete_graph.begin();
		while (i != gp.complete_graph.end()) {
			if (origin_name == i->origin_name) {
				org = true;
				origin = origin_name;
				return *i;
			}
			i++;
		}
		if (!org) {
			cout << "origin Does Not exist" << endl;
			cout << "Enter Origin name Again: ";
			getline(cin, origin);
			return check_origin(origin);

		}

	}
	void check_dest(string dest) {
		bool d = false;
		list<origin_nodes>::iterator i = gp.complete_graph.begin();
		while (i != gp.complete_graph.end()) {
			if (dest == i->origin_name) {
				d = true;
				return;
			}
			i++;
		}
		if (!d) {
			cout << "Destenation Does Not exist" << endl;
			cout << "Enter Destination name Again: ";
			getline(cin, destenation);
			check_dest(destenation);
		}

	}
	float directly_link(origin_nodes origin, string destination) {
		visited_cities.clear();
		list<adjacent_city>::iterator i = origin.linked_cities.begin();
		while (i != origin.linked_cities.end()) {
			if (i->city_name == destenation) {
				return i->distance;
			}
			i++;
		}
		return 999999;
	}
	float cal_d(origin_nodes org, string destination) {
		float d = 9999999;
		list<origin_nodes>::iterator i = gp.complete_graph.begin();
		list<adjacent_city>::iterator j = org.linked_cities.begin();
		while (j != org.linked_cities.end()) {
			if (j->distance < d && j->city_name != origin) {
				if (check_visited(j->city_name)) {
					j++;
					continue;
				}
				else {
					d = j->distance;
					new_origin = j->city_name;
				}
			}
			j++;
		}
		td = td + d;
		if (td > min_dis) {
			return td = min_dis;
		}
		adjacent_city a;
		a.city_name = new_origin;
		a.distance = d;
		visited_cities.push_back(a);
		if (new_origin == destenation) {
			return td;
		}
		else {
			while (i != gp.complete_graph.end()) {
				if (i->origin_name == new_origin) {
					break;
				}
				i++;
			}
			cal_d(*i, destenation);
			return td;
		}
	}
	bool check_visited(string org) {
		list<adjacent_city>::iterator i = visited_cities.begin();
		while (i != visited_cities.end()) {
			if (i->city_name == org) {
				return true;
			}
			i++;
		}
		return false;

	}
	void output() {
		if (alter_dis >= min_dis) {
			cout << captalization(origin) << "---" << min_dis << "KM--->" << captalization(destenation) << endl;
		}
		else if (alter_dis <= min_dis) {
			cout << captalization(origin);
			while (!visited_cities.empty()) {
				cout << "--" << visited_cities.front().distance << "KM-->" << captalization(visited_cities.front().city_name);
				visited_cities.pop_front();
			}
		}
		cout << endl;
	}
	string captalization(string str) {
		int len = str.size();

		for (int i = 0; i < len; ++i)
		{
			if (i == 0)
			{
				if (islower(str[i]))
					str[i] = toupper(str[i]);
			}
			else
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
		}
		return str;
	}
public:
	string origin;
	string destenation;
	algo() {
		td = 0;
		new_origin = "";
		min_dis = 9999999;
		alter_dis = 9999999;
	}
	void check_shortest_path() {
		origin_nodes origin_node = check_origin(origin);
		check_dest(destenation);
		min_dis = 999999999;
		float total_dis = 0;
		min_dis = directly_link(origin_node, destenation);
		alter_dis = cal_d(origin_node, destenation);
		output();
	}
};

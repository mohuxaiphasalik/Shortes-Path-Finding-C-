#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include"Graph.h"
#include<iterator>;"
using namespace std;
class algo {
	Graph gp;
	list<string> visited_cities;
public:
	string origin;
	string destenation;
	algo() {
		Graph gp;
	}
	origin_nodes check_origin(string origin_name) {
		bool org = false;
		list<origin_nodes>::iterator i = gp.complete_graph.begin();
		while (i != gp.complete_graph.end()) {
			if (origin_name == i->origin_name) {
				org = true;
				origin = origin_name;
				return *i;
			}
		}
		if (!org) {
			cout << "origin Does Not exist" << endl;
			cout << "Enter Origin name Again: ";
			cin.ignore();
			getline(cin, origin);
			check_origin(origin);
		}

	}
	void check_dest(string dest) {
		bool d = false;
		list<origin_nodes>::iterator i = gp.complete_graph.begin();
		while (i != gp.complete_graph.end()) {
			if (dest == i->origin_name) {
				d = true;
			}
			i++;
		}
		if (!d) {
			cout << "origin Does Not exist" << endl;
			cout << "Enter Destination name Again: ";
			cin.ignore();
			getline(cin, destenation);
			check_dest(destenation);
		}

	}
	int check_possible_ways_to_dest(string destenation) {
		list<origin_nodes>::iterator i = gp.complete_graph.begin();
		while (i != gp.complete_graph.end()) {
			if (destenation == i->origin_name) {
				break;
			}
			i++;
		}
		return i->linked_cities.size(); //there will be that many possible entry ways to city
	}
	void check_shortest_path() {
		check_dest(destenation);
		int max_ways = check_possible_ways_to_dest(destenation);
		float min_dis = -1;
		float total_dis = 0;
		origin_nodes origin_node = check_origin(origin);
		min_dis = directly_link(origin_node, destenation);
		int alter_dis = cal_d(origin_node, destenation);
	}
	int directly_link(origin_nodes origin, string destination) {
		list<adjacent_city>::iterator i = origin.linked_cities.begin();
		while (i != origin.linked_cities.end()) {
			if (i->city_name == destenation) {
				return i->distance;
			}
			i++;
		}
		return -1;
	}
	int cal_d(origin_nodes origin, string destination) {
		float d = 9999999;
		float td = 0;
		string new_origin;
		list<origin_nodes>::iterator i = gp.complete_graph.begin();
		list<adjacent_city>::iterator j = origin.linked_cities.begin();
		while (j != origin.linked_cities.end()) {
			if (j->distance < d) {
				d = j->distance;
				new_origin = j->city_name;
			}
			j++;
		}
		td = td + d;
		visited_cities.push_back(new_origin);
		if (new_origin == destenation) {
			return td;;
		}
		else {
			while (i != gp.complete_graph.end()) {
				if (i->origin_name == new_origin) {
					break;
				}
				i++;
			}
			cal_d(*i, destenation);
		}
	}
};

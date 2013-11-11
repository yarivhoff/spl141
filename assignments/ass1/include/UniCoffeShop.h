#include<vector>
#include <map>
#include <string>
#include<iostream>

using namespace std;

#ifndef UNICOFFESHOP_H
#define	UNICOFFESHOP_H
map<string, pair<string,double> > getIngerdients(string fileName);

void printIngredients(map<string, pair<string,double> > ingredientsList);

map<string,set<string> > getSuppliersList(map<string, pair<string,double> > ingredients);

void generateSuppliersFile(map<string,set<string> > suppList);
#endif	


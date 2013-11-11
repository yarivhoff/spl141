#include<iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <set>
#include "../include/UniCoffeShop.h"

using namespace std;

int main(void) {
    //table with all the ingredients with lowest prices
    map<string, pair<string,double> > ingredients = getIngerdients("Suppliers.conf");
    
    
    map<string,set<string> > suppList = getSuppliersList(ingredients); 
    
    generateSuppliersFile(suppList);

    return 0;
}
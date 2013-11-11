#include<iostream>
#include<vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include "../include/UniCoffeShop.h"

using namespace std;




int main(void) {
    //table with all the ingredients with lowest prices
    map<string, pair<string,double> > ingredients = getIngerdients("Suppliers.conf");
    
    
    map<string,set<string> > suppList = getSuppliersList(ingredients); 
    
    ofstream myfile2;
    myfile2.open ("Suppliers.out");
    

    
    //Suppliers data structure
    


    
    for(map<string,set<string> >::iterator it3 = suppList.begin(); it3 != suppList.end();it3++){
        myfile2 << it3->first << ", ";
        for(set<string>::iterator it4= it3->second.begin() ;it4!= it3->second.end() ; it4++){
            myfile2 << it4->data();
            if (it4 ->data()!= it3->second.rbegin()->data()){
                myfile2 << ", ";
            }
        }
        myfile2 << "\n";
    }
    myfile2.close();

    return 0;
}
#include<iostream>
#include<vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

//function that returns the ingredients following Supplier and price
map<string, pair<string,double> > getIngerdients(string fileName){
    map<string, pair<string,double> > ingredients;
    vector<string> tempIngredient;
    string line;
    ifstream myfile (fileName.c_str());

    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            //work on each line
            tempIngredient.clear();
            int pos = 0;
            int next_space = 0;
            while (next_space >= 0) {
                next_space = line.find(",", pos);
                tempIngredient.push_back(line.substr(pos, next_space - pos));
                pos=line.find_first_not_of(",", next_space);
            }
            if (ingredients.find(tempIngredient[1]) != ingredients.end()) {
                //don't replace value because table value is smaller than current value
                if (ingredients[tempIngredient[1]].second < atof(tempIngredient[2].c_str())){
                    continue;
                }
            }
            ingredients[tempIngredient[1]] = pair<string,double> (tempIngredient[0],atof(tempIngredient[2].c_str()));
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    return ingredients;
}
//prints all of the ingredients, not arranged by price
void printIngredients(map<string, pair<string,double> > ingredientsList) {
    for(map<string, pair<string,double> >::iterator it = ingredientsList.begin();it!= ingredientsList.end();it++){
        cout << it->first << " : ";
        cout << it->second.first << ", " << it->second.second<< endl;
    }
}

int main(void) {
    //table with all the ingredients with lowest prices
    map<string, pair<string,double> > ingredients = getIngerdients("Suppliers.conf");
    string line;
    string productName;
    ifstream myfile ("Products.conf");
    ofstream myfile2;
    myfile2.open ("Suppliers.out");
    ofstream myfile3;
    myfile3.open ("Menu.out");

    //vector of pointers to pairs
    vector<string> tempIngredient;
    //Suppliers data structure
    map<string,set<string> > suppList;


    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            //work on each line
            int pos = 0;
            int next_space = 0;
            tempIngredient.clear();
            while (next_space >= 0) {
                next_space = line.find(",", pos);
                if (pos== 0){
                    //saved the product name because it's the start of the line
                    productName = line.substr(pos, next_space - pos);
                }else{
                    //we start at the next word and moving on to save all the ingredients and their price
                    //important: we need to save for each ingredient the supplier which it came from
                    //we get string of the ingredient and we need to search our table (ingredients) for that
                    //ingredient and get back the price and put it in the ingredientandPrice vector
                    //productName,ingredients.find(line.substr(pos, next_space - pos))
                    tempIngredient.push_back(line.substr(pos, next_space - pos));
                }

                pos=line.find_first_not_of(",", next_space);
            }
            double totalProductPrice = 0;
            for(vector<string>::iterator it = tempIngredient.begin();it!= tempIngredient.end();it++){
                totalProductPrice += ingredients.find(it->data())->second.second;
            }
            totalProductPrice = (totalProductPrice+1)*1.5;
            if (totalProductPrice <= 5){
                for(vector<string>::iterator it2 = tempIngredient.begin();it2!= tempIngredient.end();it2++){
                    suppList[ingredients.find(it2->data())->second.first].insert(it2->data());
                }
                myfile3 << productName << "," << totalProductPrice << "\n";
            }
        }
        myfile3.close();
        myfile.close();
    }
    else cout << "Unable to open file";
    for(map<string,set<string> >::iterator it3 = suppList.begin(); it3 != suppList.end();it3++){
        myfile2 << it3->first << ", ";
        cout << it3->first << ":";
        for(set<string>::iterator it4= it3->second.begin() ;it4!= it3->second.end() ; it4++){
            myfile2 << it4->data();

            cout << it4->data();

            if (it4 ->data()!= it3->second.rbegin()->data()){
                myfile2 << ", ";
                cout  << ", ";
            }
        }
        myfile2 << "\n";
        cout << endl;
    }
    myfile2.close();

    return 0;
}
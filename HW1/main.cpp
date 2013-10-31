
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(char sentence[]){
    vector<string> res;
    int pos = 0;
    int next_space = 0;
    string str(sentence);
    while (next_space >= 0) {
        next_space = str.find(" ", pos);
        res.push_back(str.substr(pos, next_space - pos));
        pos=str.find_first_not_of(" ", next_space);
    }
    return res;
}

void printWords(vector<string> words){
    for(vector<string>::iterator it = words.begin(); it != words.end(); it++){
        cout << *it << endl;
    }
}

long base2(int number){
    int pos = 1;
    long res = 0;
    while (number!=0) {
        int a = number % 2;
        res = res + (a * pos);
        pos = pos * 10;
        number = number / 2;
    }
    return res;
}

int main(int argc, char** argv) {
    cout << base2(42) << endl;
    printWords(split("THIS            IS AN    EXAMPLE OF A SENTENCE"));
    return 0;
}


#include<iostream> 
#include <vector> 
#include <array> 
#include <string>
using namespace std; 
  
vector<string> split(char sentence[]){ 
    vector<string> v(100); 
    int wordsNum = 0; 
    char space =' '; 
    string s = "";
    string newSebtence(sentence);
    for(int i=0; i<newSebtence.size(); i=i+1){//create string 
        if(sentence[i] != space){ 
            s = s + sentence[i]; 
        } 
        else if(s != "" && sentence[i] == space){//insert string to vector 
            v[wordsNum] = s; 
            wordsNum = wordsNum +1; 
            s = ""; 
        } 
    } 
    return v; 
} 
  
void printWords(vector<string> words){ 
    for(int i=0; i<100 && words[i] != ""; i=i+1){ 
        cout<<words[i]<<endl; 
    } 
} 
int main(){ 
    vector<string> v(100); 
    char arr [100] ; 
    cin>>arr; 
    v = split(arr); 
    printWords(v); 
    return 0; 
}
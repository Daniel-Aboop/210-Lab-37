// COMSC-210 | Lab 37 | Daniel Santisteban
// IDE used: VS Code

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream>

using namespace std;

int gen_hash_index(const string &code);

int main() {
    //file path : C:\\Users\\hope4\\Desktop\\COMSC 210 Work\\210-Lab-37\\lab-37-data.txt
    cout<<"Enter file path! ";
    string filepath;
    getline(cin,filepath);
    ifstream file(filepath);
    if(!file){
        cout<<"error opening file"<<endl;
        return 1;
    }
    else{
        cout<<"opened file!"<<endl;
    }
    string line;
    int size;
    while (getline(file, line)) {
        size++;
    }
    map<int,list<string>>hash_table;
    while(getline(file,line)){
        int key=gen_hash_index(line,size);
        hash_table[key].push_back(line);
    }

   
    return 0;
}

int gen_hash_index(const string &code, int size){
    int sum=0;
    for(char index: code){
        sum+=(int)index;
    }
    return sum%size;
}
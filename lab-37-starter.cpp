// COMSC-210 | Lab 38 | Daniel Santisteban
// IDE used: VS Code

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream>

using namespace std;

int gen_hash_index(const string &code, int size);
void print_hash_table(const map<int,list<string>> &hash_table);

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
    int size=0;
    while (getline(file, line)) {
        size++;
    }
    file.clear();
    file.seekg(0);
    map<int,list<string>>hash_table;
    while(getline(file,line)){
        int key=gen_hash_index(line,size);
        hash_table[key].push_back(line);
    }
    const int amount=100;
    int start;
      int choice;
    string input;
    do{
        cout<<"Hash Table Functions:"<<endl;
        cout<<"[1]Insert Key"<<endl;
        cout<<"[2]Search for Key"<<endl;
        cout<<"[3]Remove key from table"<<endl;
        cout<<"[4]Print out first 100 entries"<<endl;
        cout<<"[5]Modify key"<<endl;
        cout<<"[6]Exit Record functions"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
               
                break;
            case 2:
               
                break;
            case 3:
               
                break;
            case 4:
                print_hash_table(hash_table);
                break;
            case 5:
                
                break;
            case 6:
                cout<<"Exiting...";
                break;

        }
    }while(choice!=6);
    return 0;
}

int gen_hash_index(const string &code, int size){
    int sum=0;
    for(char index: code){
        sum+=(int)index;
    }
    return sum%size;
}
void print_hash_table(const map<int,list<string>> &hash_table){
    const int amount=100;
    int start;
    for(auto pair:hash_table){
        start=0;
        for(auto code:pair.second){
            cout<<pair.first<<"  "<<code<<endl;
            start++;
            if(start==amount){
                break;
            }
        }
        if(start==amount){
            break;
        }
    }
}
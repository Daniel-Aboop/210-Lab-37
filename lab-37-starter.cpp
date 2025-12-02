// COMSC-210 | Lab 37 | Daniel Santisteban
// IDE used: VS Code

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int sum_ascii(const string &code);

int main() {
    cout<<endl;
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    string test="18B51F64622B";
   cout<<sum_ascii(test)<<endl;
   // produces 669 i pulled a random code from the text and used it as an example

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
    int totalsum=0;
    while(getline(file,line)){
        totalsum+=sum_ascii(line);
    }
    cout<<totalsum;
    return 0;
}

int sum_ascii(const string &code){
    int sum=0;
    for(char index: code){
        sum+=(int)index;
    }
    return sum;
}


/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

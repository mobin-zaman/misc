#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    vector<string>v;
    string str;
    for(int i=0;;i++){
        getline(cin,str);
       if(str=="00") break;
       v.push_back(str); 
    }
    for(vector<string>::iterator it=v.begin();it!=v.end();it++) {cout<<*it<<endl;cout<<*it.size()<<endl;}
    
}
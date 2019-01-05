#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map <char,char> ref_map;

char decrypt(char ch){
    map<char,char> ::iterator it=ref_map.find(ch);
    return it->second;
}


void create_map(string str,string ref){

    int len=str.size();
    for(int i=0;i<len;i++){
        if(str[i]!=' ') ref_map.insert(pair<char,char>(str[i],ref[i]));
    } 
}
int main()
{
    string ref="the quick brown fox jumps over the lazy dog";
    int T;
    cin>>T;
    unsigned int ref_len=ref.size();

    bool flag=0;
    cin.ignore();
    string line;
    for(int t=0;t<T;t++){
        vector  <string> v;
        while(getline(cin,line)) {
            if(line.empty()) break;

            if(line.size()==ref_len){
                create_map(line,ref);
                flag=1;
            }

            v.push_back(line);
        }

        if(flag==0){
            cout<<"No solution"<<endl;
            continue;
        }

        for(vector<string>::iterator it=v.begin();it!=v.end();it++){
            
            for(string::iterator ii=(*it).begin();ii!=(*it).end();ii++){
                if(*ii!=' ')cout<<decrypt(*ii);
                else cout<<' ';
            }
            cout<<endl;
            
        }
        cin.ignore();
    }
}
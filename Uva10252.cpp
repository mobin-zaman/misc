#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    
    string a,b;
    while(getline(cin,a) && getline(cin,b)){
        
        string aa,bb;
        string result="";
        (a.size()<b.size())?(aa=a,bb=b) : (aa=b,bb=a);
        int a_len=aa.size();
        int b_len=bb.size();
        
        for(int i=0;i<a_len;i++){
            for(int j=0;j<b_len;j++){
                if(bb[j]=='-') continue;
                if(aa[i]==bb[j]){
                    bb[j]='-';
                    result+=aa[i];
                    break;
                }
            }
        }
        sort(result.begin(),result.end());
        cout<<result<<endl;
    }
}

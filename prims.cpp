#include <iostream>
#include <cstring>

using namespace std;

#define INF 9999999

#define v 5

int G[v][v] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}
};

int main(){
    int no_edge;
    int selected[v];
    memset(selected,false,sizeof(selected));
    no_edge=0;
    selected[0]=true;
    int x;
    int y;
    cout<<"edge"<<" : "<<"weight"<<endl;
    while(no_edge<v-1){
        int min=INF;
        x=0;
        y=0;
        for(int i=0;i<v;i++){
            if(selected[i]){
                for(int j=0;j<v;j++){
                    if(!selected[j] && G[i][j]) {
                        if(min>G[i][j]){
                            min=G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
            cout<<x<<" - "<<y<<" : "<<G[x][y]<<endl;
            selected[y]=true;
            no_edge++;
    }    
}
#include <iostream>
#include <algorithm>
using namespace std;

struct item{
    int value;
    int weight;
};

bool compare(item a, item b){
    double r1=(double) a.value/a.weight;
    double r2=(double) b.value/b.weight;
    return r1>r2;
}

double fractional_knapsack(int max_weight,item ara[],int n){
    sort(ara,ara+n,compare);
    
    int current_weight=0;
    double final_value=0;

    for(int i=0;i<n;i++){
        if(current_weight+ara[i].weight<=max_weight){
            current_weight+=ara[i].weight;
            final_value+=ara[i].value;
        }
        else {
            int remain=max_weight-current_weight;
            final_value+=ara[i].value*((double)remain/ara[i].weight);
            break;
        }
    }
    return final_value;
}

int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        int w;
        cin>>n>>w;
        item ara[n];
        for(int i=0;i<n;i++){
            cin>>ara[i].value>>ara[i].weight;
        }
        cout<<fractional_knapsack(w,ara,n)<<endl;
    }
}
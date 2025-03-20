#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    if(t>=1 && t<= pow(10,5)){
        long long x,y,maxi;
        long long a[t];
        for(int i = 0; i < t; i++){
            cin>>x>>y;
            maxi = (x>y) ? x : y;
            a[i] = maxi*maxi - (maxi - 1);
            if(maxi % 2 == 0){
                a[i] += (x-y);
            }else{
                a[i]-=(x-y);
            }
        }
        for(int i = 0; i < t; i++){
            cout<<a[i]<<endl;
        }
    }
}
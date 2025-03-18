#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n >= 1 && n <= pow(10,5)*2){
        int j=0;
        long long min,x,a[n];
        for(int i = 0; i < n; i++){
            cin>>x;
            if(x >= 1 && x <= pow(10,9)){
               a[j] = x;
               j++; 
            }
        }
        x = 0;
        min = 0;
        for(int i=1; i<j; i++){
            x = a[i-1] - a[i];
            if(x > 0){
                a[i] += x;
                min += x;
            }
        }
        cout<<min;
    }
    return 0;
}
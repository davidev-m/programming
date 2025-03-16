#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long n;
    cin>>n;
    if(n <= 2*pow(10,5) && n >= 2){
        long long sum;
        int m;
        sum = 0;
        for(int i = 0; i < n-1;i++){
            cin>>m;
            sum += m;
        }
        sum = (n*(n+1)/2) - sum;
        cout<<sum;
    }
}
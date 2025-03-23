#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n>=1 && n <= pow(10,9)){
        int sum;
        sum = 0;
        for(int i = 5; n/i >= 1; i*=5 ){
            sum+= n/i;
        }
        cout<<sum;
    }

    return 0;
}
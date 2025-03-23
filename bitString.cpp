#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n; 
    cin>>n;
    if(n>= 1 && n <= pow(10,6)){
        long long r,mod,res;
        int x = n / 40;
        mod = pow(10,9) + 7;
        res = (long long)pow(2,40) % mod;
        res = ((long long)pow(res,x) + (n%40)) % mod;
        cout<<res;
        cout<<endl<<"Resultado:"<<r;
    }
}
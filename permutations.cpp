#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n >= 1 && n<=pow(10,6)){
        int a,b;
        a = n/2;
        b = n-a;
        if(a == 1){
            cout<<"NO SOLUTION";
        }else{
            for(int i = 0; i < a; i++){
                cout<<(i+1)*2<<" ";
            }
            for(int i = 0; i < b; i++){
                cout<<i*2+1<<" ";
            }
        }
    }
    return 0;
}
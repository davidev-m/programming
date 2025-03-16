#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long n;
    cin>>n;
    if(n >= 1 && n <= pow(10,6)){
        cout<<n<<" ";
        while(n != 1){
            
            if(n % 2 == 0){
                n /= 2;
            }else{
                n = n*3 + 1;
            }
            cout<<n<<" ";
        }
        
    }
    return 0;
}
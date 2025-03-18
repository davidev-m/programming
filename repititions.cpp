#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    string n;
    cin>>n;
    int cant = n.size();
    if(cant >= 1 && cant <= pow(10,6)){
        int x = 1;
        int c = 1;
        for(int i = 1; i <= cant; i++){
            if(n[i] == n[i-1]){
                x++;
            }else{
                if(x > c){
                    c = x;
                }
                x = 1;
            }
        }
        cout<<c;

    }
    return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n>=1 && n<= pow(10,6)){
        int A,B;
        if(n*(n+1)/2 % 2 == 0){
            A = n/2;
            B = A;
            vector<int> a(B+1,0),b(B+1,0);
            if(n%2 != 0){
                A++;
                b[B-1] = n;
                n--;
            }
            for(int i = 0; i < n/2;i++){
                if(i % 2 == 0){
                    a[i] = i+1;
                    a[i+1] = n-i;
                }else{
                    b[i-1] = i+1;
                    b[i] = n-i;
                }
            }
            cout<<"YES"<<endl;
            cout<<A<<endl;
            for(int i = 0; i <A;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl<<B<<endl;
            for(int i = 0; i < B; i++){
                cout<<b[i]<<" ";
            }
            
        }else{
            cout<<"NO";
        }
    }
}
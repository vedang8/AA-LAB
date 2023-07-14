#include <iostream>
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int power(ull a, ull x, ull n){
    int res = 1;
    while(x > 0){
        if(x % 2 == 1){
           res = (res * a) % n;    
        }
        x = x / 2;
        a = (a * a) % n;
    }
    return res;
}

int gcd(ull a, ull b){
    if(a < b)
       return gcd(b, a);
    else if(a % b == 0)
       return b;
    else
       return gcd(b, a % b);  
}
bool Randomized_Primality_Test(ull n){
    if(n <=1 || n == 4)
       return false;
    else if(n <= 3)
      return true;
    else{
        int k = 100;
        while(k > 0){
            ull a = 2 + rand()%(n-3);
            if(gcd(n, a) != 1)
               return false;
            if(power(a,n-1,n) != 1)
               return false;
            k--;   
        }    
    }  
    return true;
}
int main() {
    // Write C++ code here
    cout << "Enter the number: ";
    long long int n;
    cin >> n;
    bool ans = Randomized_Primality_Test(n);
    if(ans)
       cout << "It is a prime number.";
    else
       cout << "It is a composite number.";
    return 0;
}
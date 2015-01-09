/***
 *
Modular inverses
Problem 451
Consider the number 15.
There are eight positive numbers less than 15 which are coprime to 15: 1, 2, 4, 7, 8, 11, 13, 14.
The modular inverses of these numbers modulo 15 are: 1, 8, 4, 13, 2, 11, 7, 14
because
1*1 mod 15=1
2*8=16 mod 15=1
4*4=16 mod 15=1
7*13=91 mod 15=1
11*11=121 mod 15=1
14*14=196 mod 15=1
Let I(n) be the largest positive number m smaller than n-1 such that the modular inverse of m modulo n equals m itself.
So I(15)=11.
Also I(100)=51 and I(7)=1.
Find ∑I(n) for 3≤n≤2·107
https://projecteuler.net/problem=451
 *
 *
***/
#include<iostream>
#include<string>
#include<unordered_map>
#include<list>
#include<map>
#include<set>
#include<chrono>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<deque>
#include<iterator>
#include<functional>
#include<algorithm>
#include<complex>
#include<cstring>
#include"fibonacci.hpp"
#include"next_prime_range.hpp"
#include"large_mod.hpp"
#include "factor.hpp"
using namespace std;

vector<bool> vb(2*1e7+1);
ll count2 = 2;
ll rs = 0;
void check(unordered_map<ll, ll>& m1,ll cur,ll n){
    
    ll x=(n-1)*(n+1)/cur;
 //   cout<<n<<" "<<cur<<" "<<x<<endl;
    if(x<2*n) return;
    if(x<vb.size() && !vb[x]){
        vb[x]=true;
        rs+=x-n;
        count2++;
    }
    for(auto& itr1:m1){
        if(itr1.second!=0){
            itr1.second--;
            check(m1,cur*itr1.first,n);
            itr1.second++;
        }
    }

}

void get_rs(){
    cout<<"451:"<<endl;
    auto time_begin = chrono::high_resolution_clock::now();
    
    
   
    factor f(1e4);
//    next_prime_range npr(1e4);
    for(ll i=3;i<=1e5;++i){
        auto m = f.get(i*i-1);
      //  check(m,1,i);
        cout<<i<<" "<<count2-2<<endl;
    }
    rs+=1e7-count2;
    cout<<rs<<endl;
    auto time_end = chrono::high_resolution_clock::now();
    cout<<"time_cost: "<<chrono::duration_cast<chrono::milliseconds>(time_end-time_begin).count()<<" ms"<<endl;
}
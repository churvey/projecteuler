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
Find 閳厲(n) for 3閳様閳拷2璺�107
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
#include"../factor.hpp"

using namespace std;

vector<bool> vb(2*1e7+1);
ll count2 = 2;
ll rs = 0;
void check(const unordered_map<ll, ll>& m1,ll n){
    
	ll t = (n-1)*(n+1);
    ll x = t/(2*n);
    vector<ll> f;
	f.push_back(1);
	for(auto itr:m1){
		ll p = 1;
		ll s = f.size();
		for(ll i=0;i<itr.second;++i){
			p*=itr.first;
			for(ll j=0;j<s;++j){
				ll ne = f[j]*p;
				if(ne <= x)
				f.push_back(ne);
			}
		}
	}
	for(auto itr:f){
		auto v = t/itr;
		if(v<vb.size() && !vb[v]){
			vb[v]=true;
			rs+=(v-n);
			count2++;
		}
	}

}

void get_rs_451(){
    cout<<"451:"<<endl;
    auto time_begin = chrono::high_resolution_clock::now();
    factor f(1e7+2);
    auto m = f.get(2);
    auto m3 = f.get(3);
    for(ll i=3;i<=1e7;i+=2){
    	auto m2 = f.get(i+1);
    	for(auto itr:m2){
    		m[itr.first]+=itr.second;
    	}
    	check(m,i);
    	m = move(m2);
    	auto m4 = f.get(i+2);
    	for(auto itr:m4){
			m3[itr.first]+=itr.second;
		}
		check(m3,i+1);
		m3 = move(m4);
    	cout<<i<<endl;
    }

    cout<<count2<<endl;
    rs+=2*1e7-count2;
    cout<<rs<<endl;
    auto time_end = chrono::high_resolution_clock::now();
    cout<<"time_cost: "<<chrono::duration_cast<chrono::milliseconds>(time_end-time_begin).count()<<" ms"<<endl;
}


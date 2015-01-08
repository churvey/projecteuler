/*
 * test2.cpp
 *
 *  Created on: 2014Äê11ÔÂ12ÈÕ
 *      Author: zh
 */




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

using namespace std;

typedef size_t ll;
typedef long long sll;
typedef long double ld;
typedef pair<ll,ll> rational;




int main()
{
	auto time_begin = chrono::high_resolution_clock::now();

//	function<void(ll)> fvl = [&](ll x){
//		ll n=(x-1)*(x+1);
//
//	};
//
//	ll rs = 0;
//	ll count = 2;
//	vector<bool> vb(2*1e7+1);
    
    next_prime_range npr(100);
    for(ll i=0;i<1e5;++i){
        cout<<npr.next()<<" "<<npr.get_range()<<endl;
    }
	cout<<rs<<endl;
	auto time_end = chrono::high_resolution_clock::now();
	cout<<"time_cost: "<<chrono::duration_cast<chrono::milliseconds>(time_end-time_begin).count()<<" ms"<<endl;
}




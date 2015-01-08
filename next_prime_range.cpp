/*
 * next_prime_range.cpp
 *
 *  Created on: 2014Äê11ÔÂ16ÈÕ
 *      Author: zh
 */




#include "next_prime_range.hpp"
#include <cmath>

next_prime_range::next_prime_range(ll n):base(n){
	ind = base;

	range = (ll)sqrt(base);
	if(range<1e7)range = 1e7;

	vector<bool> primes(range,true);
	base_primes.reserve(range);
	primes[0]=false;
	primes[1]=false;
	for(ll i=2;true;++i){
		if(!primes[i]) continue;
		ll p = primes.size()/i;
		if(p<i) break;
		while(p>=i) {primes[i*p]=false;--p;}
	}
	for(ll i=0;i<primes.size();++i){
		if(primes[i]) base_primes.push_back(i);
	}
	base_primes.shrink_to_fit();
}
next_prime_range::next_prime_range(){
	new (this) next_prime_range(0);
}

bool next_prime_range::is_prime(ll n){
	if(n<=base_primes.back()|| (n>=base && n<base+range)){
		return next(n)==n;
	}else{
		for(auto i:base_primes){
			if(n%i==0) return false;
			ll p=n/i;
			if(p<i) return true;
		}
		return true;
	}

}
ll next_prime_range::next(){
	if(ind<=base_primes.back()){
		 ll rs = *lower_bound(base_primes.begin(),base_primes.end(),ind);
		 ind = rs+1;
		 return rs;
	}
	if(ind>=range_primes.size()+base || ind<base){
		base = ind;
		range_primes.clear();
		range_primes.resize((ll)range,true);
	//	cout<<"base:"<<base<<endl;
		for(ui i:base_primes){
			ll p1 = ceil(base/(double)i);
			if(p1<i) p1=i;
			ui p2 = p1*i-base;
			if(p2>=range_primes.size()) break;
			while(p2<range_primes.size()){
				range_primes[p2]=false;
				p2+=i;
			}
		}
		return next();
	}
	else{
		while(ind < base+range_primes.size() && !range_primes[ind-base] )++ind;
		if(ind==base+range_primes.size()) return next();
		return ind++;
	}
}
ll next_prime_range::next(ll n){
	ind = n;
	return next();
}
vector<ll> next_prime_range::next_primes(ll n,ui size){
	vector<ll> tmp;
	tmp.reserve(size);
	if(n<=base_primes.back()){
		auto itr = lower_bound(base_primes.begin(),base_primes.end(),n);
		auto itr2 = itr;
		if(size<=distance(itr,base_primes.end()))
			advance(itr2,size);
		else itr2 = base_primes.end();
		copy(itr,itr2,back_inserter(tmp));
	}
//	if(tmp.size()==size) return tmp;
	ind = base_primes.back()+1;
	if(ind<n)ind=n;
	while(tmp.size()<size){
		tmp.push_back(next());
	}
	return tmp;
}
vector<ll> next_prime_range::next_primes(ui size){
	return next_primes(0,size);
}

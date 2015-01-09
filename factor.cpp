/*
 * factor.cpp
 *
 *  Created on: 2014Äê11ÔÂ18ÈÕ
 *      Author: zh
 */



#include"factor.hpp"

factor::factor(){
    sieve.resize(1e7);
    for(ll p=2;p<sieve.size();++p){
    	if(sieve[p]==0){
    		for(ll i=p;i<sieve.size();i+=p){
    			sieve[i]=p;
    		}
    	}
    }
}

factor::factor(ll n){
    sieve.resize(n);
	for(ll p=2;p<sieve.size();++p){
		if(sieve[p]==0){
			for(ll i=p;i<sieve.size();i+=p){
				sieve[i]=p;
			}
		}
	 }
}

unordered_map<ll,ll> factor::get(ll n)
{
	unordered_map<ll,ll>  rs(37);
	while(n!=1){
		ll p = sieve[n];
		rs[p]++;
		n/=p;
	}
	return rs;
}

ll factor::factor_count(ll n){
	auto f = get(n);
	ll rs = 1;
	for(auto itr:f){
		rs*=(itr.second+1);
	}
	return rs;
}

vector<ll>  factor::get_factors(ll n){
	auto f = get(n);
	vector<ll> rs;
	rs.push_back(1);
	for(auto itr:f){
		ll p = 1;
		ll s = rs.size();
		for(ll i=0;i<itr.second;++i){
			p*=itr.first;
			for(ll j=0;j<s;++j){
				rs.push_back(rs[j]*p);
			}
		}
	}
	sort(rs.begin(),rs.end());
	return rs;
}

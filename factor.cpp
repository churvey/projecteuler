/*
 * factor.cpp
 *
 *  Created on: 2014Äê11ÔÂ18ÈÕ
 *      Author: zh
 */



#include"factor.hpp"

next_prime_range factor::npr;
vector<pair<ll,ll>> factor::get(ll n)
{
	vector<pair<ll,ll>> rs;
	ll p=npr.next(0);
	while(n!=1){
		ll po = 0;
		while(n%p==0){

		}
		if(po!=0)rs.emplace_back(p,po);
		p=npr.next();
	}
	last = rs;
	return rs;
}

ll factor::euler(ll n){
	auto rs = get(n);
	ll lrs = 1;
	for(auto p:rs){
		lrs*=(pow(p.first,p.second+1)-1)/(p.first-1);
	}
	return lrs;
}

void factor::print(){
	for(auto p:last){
		cout<<"("<<p.first<<","<<p.second<<")";
	}
	cout<<endl;
}

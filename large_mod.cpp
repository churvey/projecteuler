/*
 * combinatorics.cpp
 *
 *  Created on: 2015Äê1ÔÂ5ÈÕ
 *      Author: zh
 */




#include"large_mod.hpp"
#include"util.hpp"
#include<cassert>

large_mod::large_mod(ll mod):mod(mod){
	rs = make_pair(1,1);
};
ll large_mod::get(){
	sll x,y;
	ll r = gcd_ext(rs.second,mod,x,y);
	assert(r==1);
	return (rs.first*x)%mod;
}

void large_mod::multi_com(ll n,ll k){
	ll &u = rs.first;
	ll &d = rs.second;
	for(ll i=0;i<k;++i){
		u*=(n-i);
		u%=mod;
	}
	for(ll i=0;i<k;++i){
		d*=(i+1);
		d%=mod;
	}
}

void large_mod::multi(ll n,ll k){
	ll &u = rs.first;
	ll &d = rs.second;
	u*=n;
	u%=mod;
	d*=k;
	d%=mod;
}
ll large_mod::pow_mod(ll n,ll k){
	ll r = 1;
	if(k!=0){
		r = pow_mod(n,k/2);
		r*=r;
		r%=mod;
		if(k%2) r*=n;
		r%=mod;
	}
	return r;
}

void large_mod::multi_pow(ll n,ll k){
	ll r = pow_mod(n,k);
	multi(r,1);
}

void large_mod::div_pow(ll n, ll k){
	ll r = pow_mod(n,k);
	multi(1,r);
}

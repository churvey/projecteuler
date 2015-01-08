/*
 * combinatorics.hpp
 *
 *  Created on: 2015Äê1ÔÂ5ÈÕ
 *      Author: zh
 */

#ifndef COMBINATORICS_HPP_
#define COMBINATORICS_HPP_
#include<iostream>
using namespace std;

typedef size_t ll;

class large_mod{
	private:
		ll mod;
		pair<ll,ll> rs;
		ll pow_mod(ll n,ll k);
	public:
		large_mod(ll mod);
		ll get();
		void multi(ll n, ll k);
		void multi_com(ll n,ll k);
		void multi_pow(ll n,ll k);
		void div_pow(ll n, ll k);
};



#endif /* COMBINATORICS_HPP_ */

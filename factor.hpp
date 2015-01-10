/*
 * factor.hpp
 *
 *  Created on: 2014Äê11ÔÂ18ÈÕ
 *      Author: zh
 */

#ifndef FACTOR_HPP_
#define FACTOR_HPP_
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<unordered_map>
#include<memory>
#include"next_prime_range.hpp"
using namespace std;

class factor{
	public:
        factor(ll n);
        factor();
        unordered_map<ll,ll> get(ll n);
        ll factor_count(ll n);
        vector<ll> get_factors(ll n);
	private:
        vector<ll> sieve;
};



#endif /* FACTOR_HPP_ */

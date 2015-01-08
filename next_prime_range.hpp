/*
 * next_prime_range.hpp
 *
 *  Created on: 2014Äê11ÔÂ16ÈÕ
 *      Author: zh
 */

#ifndef NEXT_PRIME_RANGE_HPP_
#define NEXT_PRIME_RANGE_HPP_
#include<vector>
#include<algorithm>
#include<iostream>
#include<iterator>

typedef unsigned int ui;
using namespace std;
typedef unsigned long long ll;

class next_prime_range{
public:
	next_prime_range(ll);
	next_prime_range();
	ll next();
	ll next(ll);
	vector<ll> next_primes(ll,ui);
	vector<ll> next_primes(ui);
	bool is_prime(ll);
private:
	ll base;
	ui range;
//	ll cur;
	ll ind;
	vector<ui> base_primes;
	vector<bool> range_primes;
};



#endif /* NEXT_PRIME_RANGE_HPP_ */

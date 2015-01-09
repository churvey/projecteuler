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
	bool is_prime(ll);
    ll get_range();
    void set_range(ll n);
private:
    void init();
	ll base;
	ll range;
    ll max_base;
	ll ind;
	vector<bool> base_primes;
	vector<bool> range_primes;
};



#endif /* NEXT_PRIME_RANGE_HPP_ */

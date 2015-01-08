/*
 * factor.hpp
 *
 *  Created on: 2014��11��18��
 *      Author: zh
 */

#ifndef FACTOR_HPP_
#define FACTOR_HPP_
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
#include"next_prime_range.hpp"
using namespace std;
typedef size_t ll;

class factor{
	public:
	vector<pair<ll,ll>> get(ll n);
	ll euler(ll n);
	void print();
	private:
	static	next_prime_range npr;
	vector<pair<ll,ll>> last;
};



#endif /* FACTOR_HPP_ */

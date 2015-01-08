/*
 * util.hpp
 *
 *  Created on: 2015Äê1ÔÂ5ÈÕ
 *      Author: zh
 */

#ifndef UTIL_HPP_
#define UTIL_HPP_
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

using namespace std;
typedef size_t ll;
typedef long long sll;
typedef long double ld;

template<typename C,typename F>
void choose(const C& v,ll i,F f);

ll gcd_ext (ll a, ll b, sll& x, sll& y);

ll gcd(ll n,ll m);
#endif /* UTIL_HPP_ */

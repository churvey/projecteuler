/*
 * Fibonacci.hpp
 *
 *  Created on: 2014Äê11ÔÂ16ÈÕ
 *      Author: zh
 */

#ifndef FIBONACCI_HPP_
#define FIBONACCI_HPP_
#include<vector>
#include<algorithm>
#include<array>
using namespace std;
typedef unsigned long long ll;
typedef array<ll,2> al2;

class fibonacci{
	public :
	ll get(ll n);
	ll get2(ll n);
	fibonacci(ll mod):mod(mod){

	}

	private:
	al2 get_a(ll n);
	al2 mulit(const al2&,const al2&);
	ll mod;

};


#endif /* FIBONACCI_HPP_ */

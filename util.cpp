/*
 * util.cpp
 *
 *  Created on: 2015Äê1ÔÂ5ÈÕ
 *      Author: zh
 */

#include"util.hpp"


//template<typename C,typename F>
//void choose(const C& v,ll i,F f){
//	vector<typename C::value_type> v_rs;
//	if(i==0){
//		f(v_rs);
//		return;
//	}
//	vector<typename C::const_iterator> itrs(i);
//	auto itr = v.begin();
//	for(ll j=0;j<i;++j){itrs[j]=itr++;}
//	for(auto a:itrs){
//		v_rs.push_back(*a);
//	}
//	f(v_rs);
//	v_rs.clear();
//	while(true){
//		auto p = itrs.rbegin();
//		while(next(*p)!=v.end()){
//			(*p)++;
//			for(auto a:itrs){
//				v_rs.push_back(*a);
//			}
//			f(v_rs);
//			v_rs.clear();
//		}
//		auto p2 = next(p);
//		for(;p2!= itrs.rend()&&*(prev(p2))==next(*p2);++p2);
//		if(p2==itrs.rend()) break;
//		++(*p2);
//		for(auto p3=p2;p3!=p;--p3){
//			*(prev(p3))=next(*p3);
//		}
//		for(auto a:itrs){
//			v_rs.push_back(*a);
//		}
//		f(v_rs);
//		v_rs.clear();
//	}
//}

ll gcd_ext (ll a, ll b, sll& x, sll& y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll t2 = gcd_ext(b,a%b,x,y);
	ll t = y;
	y = x-(a/b)*y;
	x = t;
	return t2;
}

ll gcd(ll n,ll m){
	while(m!=0){
		ll r=n%m;
		n=m;
		m=r;
	}
	return n;
}


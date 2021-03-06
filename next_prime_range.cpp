/*
 * next_prime_range.cpp
 *
 *  Created on: 2014��11��16��
 *      Author: zh
 */




#include "next_prime_range.hpp"
#include <cmath>

next_prime_range::next_prime_range(ll n):range(n){
	//ind = base = 0;
    init();
}
void next_prime_range::init(){
    base_primes.resize(range,true);
    base_primes[0]=false;
    base_primes[1]=false;
    for(ll i=2;true;++i){
        if(!base_primes[i]) continue;
        ll p = base_primes.size()/i;
        if(p<i) break;
        ll p2 = p*i;
        while(p2>i) {base_primes[p2]=false;p2-=i;}
    }
    max_base = range-1;
    while(!base_primes[max_base])--max_base;
}
next_prime_range::next_prime_range(){
    range = (ll)1e7;
    init();
}
ll next_prime_range::get_range(){
    return range;
}
bool next_prime_range::is_prime(ll n){
	// this will also change ind;
    return next(n)==n;

}
ll next_prime_range::next(){
    if(ind>max_base*max_base){
        ll tmp = ind;
        range = ceil(sqrt(ind));
        if(range < 1e7) range*=2;
        else range+=1e7;
        init();
        ind = tmp;
    }
	while(ind<base_primes.size() && !base_primes[ind]){
        ++ind;
	}
    if(ind<base_primes.size()) return ind++;
	if(ind>=range_primes.size()+base || ind<base){
		base = ind;
		range_primes.clear();
		range_primes.resize((ll)range,true);
	//	cout<<"base:"<<base<<endl;
        for(ll i=0;i<base_primes.size();++i){
            if(!base_primes[i])continue;
			ll p1 = ceil(base/(double)i);
			if(p1<i) p1=i;
			ll p2 = p1*i-base;
			if(p2>=range_primes.size()) break;
			while(p2<range_primes.size()){
				range_primes[p2]=false;
				p2+=i;
			}
		}
		return next();
	}
	else{
		while(ind < base+range_primes.size() && !range_primes[ind-base] )++ind;
		if(ind==base+range_primes.size()) return next();
		return ind++;
	}
}
ll next_prime_range::next(ll n){
	ind = n;
	return next();
}
void next_prime_range::set_range(ll n){
    range = n;
    init();
}


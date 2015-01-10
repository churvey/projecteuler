/*
 * factor.cpp
 *
 *  Created on: 2014Äê11ÔÂ18ÈÕ
 *      Author: zh
 */



#include"factor.hpp"

factor::factor(){
    npr=unique_ptr<next_prime_range>(new next_prime_range());
}

factor::factor(ll n){
    npr=unique_ptr<next_prime_range>(new next_prime_range(ceil(sqrt(n))));
}

unordered_map<ll,ll> factor::get(ll n)
{
	unordered_map<ll,ll>  rs(37);
	ll p=npr->next(0);
	while(p*p<=n){
		ll po = 0;
		while(n%p==0){
            n/=p;
            po++;
		}
        if(po!=0){
            rs[p]=po;
        //    cout<<p<<" "<<po<<endl;
        }
		p=npr->next();
	}
    if(n!=1)
        rs[n]=1;
	return rs;
}


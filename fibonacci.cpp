/*
 * fibonacci.cpp
 *
 *  Created on: 2014Äê11ÔÂ16ÈÕ
 *      Author: zh
 */


#include"fibonacci.hpp"

al2 fibonacci::get_a(ll n){
	al2 ini={1,0};
	if (n==1) return ini;
	al2 tmp = get_a(n/2);
	if(n&1){
		al2 tmp2;
		tmp2[0]=(tmp[0]+tmp[1]);
		tmp2[1]=tmp[0];
		return mulit(tmp,tmp2);
	}
	else return mulit(tmp,tmp);
}

al2 fibonacci::mulit(const al2& al,const al2& bl){
	array<unsigned __int128,2> a{al[0],al[1]};
	array<unsigned __int128,2> b{bl[0],bl[1]};
	return al2{(ll)(((a[0]+a[1])*(b[0]+b[1])-a[1]*b[1])%mod),(ll)((a[0]*b[0]+a[1]*b[1])%mod)};
}

ll fibonacci::get(ll n){
	return std::get<0>(get_a(n));
}



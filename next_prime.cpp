#include"next_prime.h"

bool prime::is_prime(ll n){
	for(auto p:small_primes){
		ll p2 = n/p;
		if(p2<p) return true;
		if(n%p==0) return false;
	}
	return true;// never reached
}
bool prime::is_prime_large(ll n){
	ll begin = 0;//small_primes[size];
	//if(n%begin==0) return false;
	while(true){
		for(auto itr = candi.begin();itr!=candi.end();++itr){
			ll p = begin+(*itr);
			if(p==1) continue;
			ll p2 = n/p;
			if(p2<p) return true;
			if(n%p==0) return false;
		}
		begin+=N;//candi.back();
	}
}
prime::prime(){new(this)prime(8);}
prime::prime(ll n){
	size = n;
	small_primes.push_back(2);
	N = 2;
	for(ll i=1;i<n;++i){
		ll ne = small_primes.back();
		if(ne&1)ne+=2;else ++ne;
		while(!is_prime(ne)) ne+=2;
		small_primes.push_back(ne);
		N*=ne;
	}
	while(true){
		ll ne = small_primes.back()+2;
		while(!is_prime(ne)) ne+=2;
		if(ne<N)
		small_primes.push_back(ne);
		else break;
	}

	ll tmp = 0;//small_primes[n];
	vector<bool> com(N,true);
	for(ll i=0;i<n;++i){
		ll mods=tmp%small_primes[i];
		ll t2 = small_primes[i]-mods;
		while(t2<N){
			com[t2-1]=false;
			t2+=small_primes[i];
		}
	}
	for(ll i=0;i<N-1;++i) if(com[i]) candi.push_back(i+1);
}

ll prime::next_prime(ll n){
	ll base = n/N;
	ll mod = n%N;
	if(base==0){ auto it = lower_bound(small_primes.begin(),small_primes.end(),n);
	if(it==small_primes.end()) return next_prime(N);
	else return *it;}
	auto itr = lower_bound(candi.begin(),candi.end(),mod);
	ll base2=n-mod;
	while(true){
		if(itr==candi.end()) {base2+=N;itr=candi.begin();}
		//ll base2 = base*N;
		while(itr!=candi.end()){
			ll n2 = base2+(*itr);
		//	cout<<base2<<" "<<*itr<<" "<<n2<<" "<<N<<" "<<candi.back()<<endl;
			if(is_prime_large(n2)) return n2;
			++itr;
		}
	}
}


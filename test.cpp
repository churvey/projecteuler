#include<chrono>
#include"factor.hpp"
using namespace std;

void test_factor(){
	auto time_begin = chrono::high_resolution_clock::now();
	ll n= 1e7;
	factor f(n);
	for(ll m = n-1;m>1;--m){
		f.get(m);
	}
	 auto time_end = chrono::high_resolution_clock::now();
	 cout<<"time_cost: "<<chrono::duration_cast<chrono::milliseconds>(time_end-time_begin).count()<<" ms"<<endl;
}

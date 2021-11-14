#include <bits/stdc++.h>
using namespace std;

const int maxX = 1e6+10;
int n,x;
int a[maxX];
int L[maxX],R[maxX];
int preL[maxX],preR[maxX];
int sufL[maxX],sufR[maxX];

void init() {
	for(int i=0;i<=x+1;i++) {
		L[i]=preL[i]=sufL[i]=x+1;
	}
	set<int> s;
	
	for(int i=1;i<=n;i ++) {
		int t = a[i];
		auto it = s.upper_bound(t);
		if(it == s.end()) {
			s.insert(t);
			continue;
		} else {
			L[t] = min(L[t], *it);
			R[t] = max(R[t], *s.rbegin());
		}
		s.insert(t);
	}
	
	set<int, greater<int> > s2;
	
	for(int i=n;i>=1;i --) {
		int t = a[i];
		auto it = s2.upper_bound(t);
		if(it == s2.end()) {
			s2.insert(t);
			continue;
		} else {
			L[t] = min(L[t], *s2.rbegin());
			R[t] = max(R[t], *it);
		}
		s2.insert(t);
	}
	
	for(int i=1;i<=x;i ++) {
		preL[i] = min(preL[i-1],L[i]);
		preR[i] = max(preR[i-1],R[i]);
	}
	
	for(int i=x;i>=1;i --) {
		sufL[i] = min(sufL[i+1],L[i]);
		sufR[i] = max(sufR[i+1],R[i]);
	}
} 

bool check(int i, int m) {
	if(m<=preR[i])return 0;
	if(m<=sufR[m])return 0;
	if(i>=sufL[m])return 0;
	return 1; 
} 

int main() {
	cin >>n >>x;
	for(int i=1;i<=n;i ++) {
		cin>>a[i];
	}
	init();
	
	long long ans = 0;
	for(int i=0;i<x;i ++) {
		if(i>=preL[i])break;
		int l = i+1,r = x+1;
		while(r-l>1) {
			int m = l + r >> 1;
			if(check(i,m))r=m;
			else l=m;
		}
		ans += x + 1 - l;
	}
	cout << ans;
	return 0;
}





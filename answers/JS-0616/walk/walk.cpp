#include<bits/stdc++.h>
using namespace std;
int n,k,w[119],c[101011],d[101001];
int space[11];
int sta[11];
int maxw=1;
inline void next(){
	sta[k]++;
	for(int i=k;i>=1;i--){
		if(sta[i]>w[i]){
			w[i]=1;
			w[i-1]++;
		}
		else break;
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	printf("-1");
}

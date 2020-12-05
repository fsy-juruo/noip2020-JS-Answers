#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t, l, vhc[30], vha[30], numc;
ll ans;
string s;
void zreset(){
	ans = 0; numc = 0;
	memset(vhc,0,sizeof(vhc));
}
bool check(int x, int pos){
	string ns = "", ns2 = "", ns3 = "";
	for(int i = 0; i < pos; i++) ns += s[i];
	for(int i = 0; i <= x ; i++) ns2 += s[i];
	for(int i = 1; i <= pos/(x+1); i++) ns3 += ns2; 
	if(ns == ns3) return true;
	return false;
}
void work(int pos){
	int num = 0;
	memset(vha,0,sizeof(vha));
	for(int i = 0; i <= pos - 2; i++){
		vha[s[i] - 'a']++;
		if(vha[s[i] - 'a'] % 2) num++;
		else num--;
		if(num > numc) continue;
		ans++;
		for(int j = 2; j * j <= pos; j++){
			if(pos % j) continue;
			if(i < pos/j-1 && check(pos/j-1, pos)) ans++;
			if(j * j == pos) continue;
			if(i < j - 1 && check(j-1,pos)) ans++;
		}
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t){
		t--;
		zreset();
		cin >> s;
		l = s.size();
		bool flag = true;
		for(int i = 1; i < l; i++){
			if(s[i] != s[i-1]) flag = false;
		}
		if(flag){
			for(int i = l - 1; i >= 2; i--){
				if((l-i)%2 == 0){
					if(i % 2){
						ans += (i-1)/2;
						for(int j = 1; j <= i - 2; j += 2){
							for(int k = 2; k * k <= i; k++){
								if(i % k) continue;
								if(j < i/k-1) ans++;
								if(k * k == i) continue;
								if(j < k - 1) ans++;
							}
						}
					}
					else{
						ans += (i-2)/2;
						for(int j = 1; j <= i - 3; j += 2){
							for(int k = 2; k * k <= i; k++){
								if(i % k) continue;
								if(j < i/k-1) ans++;
								if(k * k == i) continue;
								if(j < k - 1) ans++;
							}
						}
					}
				}
				else{
					ans += i-1;
					for(int k = 2; k * k <= i; k++){
						if(i % k) continue;
						ans += i/k-1;
						if(k * k == i) continue;
						ans += k - 1;
					}
				}
			}
			printf("%lld\n",ans);
		}
		else{
			for(int i = l - 1; i >= 2; i--){
				vhc[s[i] - 'a']++;
				if(vhc[s[i] - 'a'] % 2) numc++;
				else numc--;
				work(i);	
			}
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

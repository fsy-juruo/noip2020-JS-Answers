#include<bits/stdc++.h>
#include<string>
using namespace std;

const int Maxn = 1048576;

string st;
int cnt[100], jsz[Maxn + 7], jsf[Maxn + 7];
inline int read(){
	char c=getchar();
	int x = 0, y = 1;
	while(c<'0' | c>'9'){
		if (c == '-') y = -1;
		c = getchar();
	}
	while( c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c=getchar();
	}
	return x * y;
}

bool checkcf(int x, int stp){
	string rul = st.substr(1,stp);
	for(int i = 1 + stp; i <= x; i += stp){
		if (rul != st.substr(i, stp)) return false; 
	}
	return true;
}

int yxfa(int x, int q){
	int s = 0;
	for(int i = 1; i < x; ++i){
		if(jsz[i] <= q) s++;
	}
	return s;
}
int qys(int x, int q){
	int s;
	if (q == 0) s = x - 1;
	else s = x / 2;
 	for(int i = 2; i <= sqrt(x); ++i){
		if (x % i != 0) continue;
		if (q == 0) s += i / 2;
		if (q == 1) s += i - 1;
		if (x != i * i){
			int t = x/i;
			
			if (t == 0) s += i / 2;
			if (t == 1) s += i - 1;
		}
	}
	
	return s;
}

int qans(int x, int q){
	int s = 0;
	for(int i = 1; i < x; ++i){
		if(jsz[i] <= q) s ++;
	}
	for(int i = 2; i <= sqrt(x); ++i){
		if (x % i != 0 | !checkcf(x, i)) continue;
		s += yxfa(i, q);
		if (x != i * i){
			int t = x/i;
			s+=yxfa(t, q);
		}
	}
	
	return s;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T = read();
	while(T--){
		cin >> st;
		int l = st.length();
		st = "0" + st;
		
		memset(cnt, 0, sizeof(cnt));
		jsz[0] = 0;
		for(int i = 1; i <= l; ++i){
			int id = st[i] - 'a';
			jsz[i] = jsz[i - 1];
			cnt[id] ++;
			if(cnt[id] % 2 == 1) jsz[i] ++;
			else jsz[i] --;
		}
		
		
		memset(cnt, 0, sizeof(cnt));
		jsf[l + 1] = 0;
		for(int i = l; i >= 1; --i){
			int id = st[i] - 'a';
			jsf[i] = jsf[i + 1];
			cnt[id] ++;
			if(cnt[id] % 2 == 1) jsf[i] ++;
			else jsf[i] --;
		}
		
		bool flag = true;
		for(int i = 2; i <= l; ++i){
			if (st[i] != st[i - 1]){
				flag = false;
				break;
			} 
		}
		if(flag){
			int sum = 0, ans = 0;
			for(int i = l; i >= 3 ; --i){
				sum ++;
				ans += qys(i - 1, sum % 2);
			}
			
			printf("%d\n", ans);
			continue;
		}
		
		int ans = 0;
		for(int i = l; i >= 1; ++i){
			ans += qans(i - 1, jsf[i]);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}

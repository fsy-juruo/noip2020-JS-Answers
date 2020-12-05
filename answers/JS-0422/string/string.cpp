#include<bits/stdc++.h>
using namespace std;
int T;
char str[1500001];
int buk1[30], buk2[30];
int spc(){
	for(int i = 1;i <= strlen(str+1);i++){
		buk1[str[i]-'a']++;
	}
	int tot = 0;
	for(int i = 0;i < 26;i++){
		if(buk1[i]) tot++;
	}
	if(tot == 1 || tot == 2) return tot;
	return 0; 
}
void naive(){
	int n = strlen(str+1);
	int ans = 0;
	for(int len = 2;len < n;len++){
		for(int i = 2;i <= len;i++){
			if(len % i) continue;
			bool ok = 1;
			for(int j = i + 1;j <= len;j++){
				int pos = j % i;
				if(pos == 0) pos = i;
				if(str[pos] != str[j]){
					ok = 0;
					break;
				}
			}
			if(!ok) continue;
			memset(buk1, 0, sizeof(buk1));
			memset(buk2, 0, sizeof(buk2));
			int cnt1 = 0, cnt2 = 0;
			for(int j = len + 1;j <= n;j++){
				buk2[str[j]-'a']++;
			}
			for(int j = 0;j < 26;j++){
				if(buk2[j] % 2) cnt2++;
			}
			for(int j = 1;j < i;j++){
				buk1[str[j]-'a']++;
				if(buk1[str[j]-'a'] % 2) cnt1++;
				else cnt1--;
				if(cnt1 <= cnt2) ans++;
			}
		}
	}
	printf("%d\n", ans);
}
void part1(){
	int n = strlen(str+1);
	int ans = 0;
	for(int len = 2;len < n;len++){
		for(int i = 2;i <= len;i++){
			if(len % i) continue;
			bool ok = 1;
//			/*for(int j = i + 1;j <= len;j++){
//				int pos = j % i;
//				if(pos == 0) pos = i;
//				if(str[pos] != str[j]){
//					ok = 0;
//					break;
//				}
//			}*/
			if(!ok) continue;
			memset(buk1, 0, sizeof(buk1));
			memset(buk2, 0, sizeof(buk2));
			int cnt1 = 0, cnt2 = 0;
			for(int j = len + 1;j <= n;j++){
				buk2[str[j]-'a']++;
			}
			for(int j = 0;j < 26;j++){
				if(buk2[j] % 2) cnt2++;
			}
			for(int j = 1;j < i;j++){
				buk1[str[j]-'a']++;
				if(buk1[str[j]-'a'] % 2) cnt1++;
				else cnt1--;
				if(cnt1 <= cnt2) ans++;
			}
		}
	}
	printf("%d\n", ans);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%s", str+1);
		if(spc() == 0) naive();
		else if(spc() == 1) part1();
	}
	return 0;
}

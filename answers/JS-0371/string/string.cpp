#include <cstdio>
#include <cstring>
const int N = 2e6 + 7;

char s[N];
int cnt[30], f1[N], f2[N], nxt[N];

void GetNext(char m[]){
	for(int i=1, j=0; m[i]; ++i){
		while(j && m[i] != m[j]) j = nxt[j];
		if(m[i] == m[j]) ++j;
		nxt[i+1] = j;
	}
}

bool check(char s[]){
	for(int i=1; s[i]; ++i)
		if(s[i] != s[i-1]) return false;
	return true;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T, len;
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		for(int i=0; i<26; ++i) cnt[i] = 0;
		for(int i=0; s[i]; ++i) f1[i] = f2[i] = 0;
		for(int i=0; s[i]; ++i){
			++cnt[s[i]-'a'];
			if(cnt[s[i]-'a'] & 1) f1[i] = f1[i-1] + 1;
			else f1[i] = f1[i-1] - 1;
		}
		for(int i=0; i<26; ++i) cnt[i] = 0;
		for(int i=len-1; ~i; --i){
			++cnt[s[i]-'a'];
			if(cnt[s[i]-'a'] & 1)  f2[i] = f2[i+1] + 1;
			else f2[i] = f2[i+1] - 1;
		}
		len = strlen(s), GetNext(s);
		memset(f, 0, sizeof f);
		long long ans = len;
		
		printf("%lld\n", ans);
	}
	return 0;
}

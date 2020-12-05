
#include <bits/stdc++.h>
using namespace std;
string str, ab, cc; int ans;
int a[26], c[26];
int check(int b[]){
	int ans = 0;
	for(int i = 0; i < 26; i++)
	 ans += (b[i] % 2 == 1);
	return ans;
}
bool C(){
	return check(a) <= check(c);
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		ans = 0;
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		cin >> str;
		int len = str.size();
		for(int i = 1; i < len-1; i++){ // ab len-1
		    ab = cc = "";
		    int num = 0;
			for(int j = 0; j <= i; j++)
			 ab += str[j];
			bool f = true;
			for(int j = i+1; j < len-1 && f; j += (i+1)){
				for(int k = j; k < j+i+1; k++)
			     if(ab[k-j] != str[k]) { f = false; break; }
			    if(f) ++num;
			}
			for(int m = 1; m < ab.size(); m++){
				for(int g = 0; g < m; g++)
				 a[ab[g] - 'a']++;
				for(int n = 0; n <= num; n++){
					for(int p = ab.size() * (n+1); p < len; p++){
						if(p < len) c[str[p] - 'a']++;
			     	    
					}
				    if(C()) ans++;
			    	memset(c, 0, sizeof(c));
				}
				memset(a, 0, sizeof(a));
			}
		}
		bool f = 1;
		if(len % 2 == 0)
		 for(int i = 0; i < len/2; i++)
		  if(str[i] != str[i + len/2]) { f = 0; break; }
		printf("%d\n", ans - (len % 2 == 0 ? f : 0));
	}
	return 0;
}


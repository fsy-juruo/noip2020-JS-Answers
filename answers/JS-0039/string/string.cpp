#include <bits/stdc++.h>
using namespace std;
int read(){
	int n = 0, f = 1;
	char x =  getchar();
	while((x < '0' || x > '9') && x != '-') x = getchar();
	if(x == '-'){f = -1; x = getchar();}
	while(x >= '0' && x <= '9'){n = n * 10 + x - '0';x = getchar();}
	return n * f;
}
int read_c(){
	char x = getchar();
	if(x < 'a' || x > 'z') x = getchar();
	return x;
}
char a[1050000];
int n;
bool check(int len1,int beg){
	for(int i = 1;i <= len1;i ++){
		if(a[i] != a[beg + i - 1]) return 0;
	}
	return 1;
}
int ha[30], hc[30];
int ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T = read();
	while(T --){
		memset(a, 0, sizeof(a));
		scanf("%s", a + 1);
		n = strlen(a + 1);
		int cnt;
		int jic = 0, jia = 0;
		memset(ha, 0, sizeof(ha));
		jia = 0;
		ans = 0;
		for(int i = 1;i < n - 1;i ++){
			ha[a[i] - 'a'] ++;
			if(ha[a[i] - 'a'] & 1) jia ++;
			else jia --;
			for(int j = i + 1;j < n;j ++){
				jic = 0;
				memset(hc, 0 , sizeof(hc));
				for(int k = n;k > j;k --){
					hc[a[k] - 'a'] ++;
					if(hc[a[k] - 'a'] & 1) jic ++;
					else jic --;
				}
				if(jia <= jic) ans ++;
				int now = 1, len = 0;
				for(int k = j + 1;k < n;k ++){
					if(a[k] != a[k - j * now]) break;
					len ++;
					hc[a[k] - 'a'] --;
					if(hc[a[k] - 'a'] & 1) jic ++;
					else jic --;
					if(len == j){
						len = 0;
						now ++;
						if(jia <= jic) ans ++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

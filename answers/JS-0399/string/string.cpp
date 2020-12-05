#include<cstdio>
#include<cstdlib>
#include<ctime>
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T;
	srand((unsigned)time(0));
	char s[1000007];
	scanf("%d", &T);
	while(T--){
		scanf("%s", s+1);
		printf("%d\n", rand());
	}
	return 0;
}

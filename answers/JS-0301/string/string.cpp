#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int t;
char s[1048600];
int len;
int c;
long long ans;
int num;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	for(;t>0;t--){
		memset(s,'\n',sizeof(s));
		scanf("%s",&s);
		ans=0;
		for(int i=0;;i++){
			if(s[i]=='\n'){
				len=i;
				break;
			}
		}
		len-=1;
		if(len==1||len==2){
			printf("0\n");
			continue;
		}
		for(c=1;c<len-1;c++){
			if((len-c)%2==0){
				num=(len-c)/2;
			}else{
				num=(len-c+1)/2;
			}
			for(int i=1;i<=num;i++){
				if((len-c)%i!=0) continue;
				for(int a=1;a<(len-c)/i;a++){
					if(a%2!=0){
						if(c%2!=0){
							if(a>c) continue;
						}
					}
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}


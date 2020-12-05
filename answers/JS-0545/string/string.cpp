#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
char s[1050000];
int odd[26];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",&s);
		int n;
		//bool sp=1;
		int cnt=0,ans=0;
		while(s[n]){
			/*
			if(n!=0&&s[n]!=s[n-1]){
				sp=0;		
			}*/
			n++;
			
		}
		/*
		if(sp){
			for(int i=n-1;i>=2;i--){
				cnt++;
				if(cnt%2==1){
					ans+=i-1;
				}
				else{
					ans+=(i-1)/2;
				}
			}
			printf("%d\n",ans);
			continue;
		}
		*/
		memset(odd,0,sizeof(odd));
		for(int i=n-1;i>=2;i--){
			odd[s[i]-'a']++;
			if(odd[s[i]-'a']%2==0){
				cnt--;
			}
			else{
				cnt++;
			}
			for(int j=1;j<i;j++){
				if(i%(j+1)!=0){
					continue;
				}
				int m=i/(j+1);
				bool flag=1;
				if(j!=i-1){
					for(int k=0;k<=j;k++){
						char c=s[k];
						for(int t=1;t<m;t++){
							
							if(s[k+(j+1)*t]!=c){
								flag=0;
								break;
							}
						}
						if(!flag){
							break;
						}
					}
				}
				if(flag){
					int odda[26],cnta=0;
					memset(odda,0,sizeof(odda));
					for(int t=0;t<j;t++){
						odda[s[t]-'a']++;
						if(odda[s[t]-'a']%2==0){
							cnta--;
						}
						else{
							cnta++;
						}
						if(cnta<=cnt){
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo
*/

#include<bits/stdc++.h>
using namespace std;
char a[2000010],b[2000010];
int hasha[30],hashc[30],tot[1001000];
int p[2000010];
long long ans=0,sa=0,sc=0;
void reclear(int m,int n)
{
	memset(hasha,0,sizeof(hasha));
	memset(hashc,0,sizeof(hashc));
	sa=0,sc=0;
//	for(int i = 1 ; i <= n ; i++ )
//	{
//		hashc[a[i]-'a'+1]++;
//	}
}
int main()
{
	int t;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(p,0,sizeof(p));
		memset(hasha,0,sizeof(hasha));
		memset(hashc,0,sizeof(hashc));
		ans=0;
		scanf("%s",a+1);
		int n=strlen(a+1);
		for(int i = 1 ; i <= n ; i++ )
		{
			b[i]=' ';
		}		
		b[1]=a[1];
		for(int t = 2 ; t < n ; t++ )
		{
			int m=t;
			b[t]=a[t];
			int j=0,k;
			for(int i = 1 ; i <= m ; i++ )
			{
				while(j&&b[j]!=b[j+1]) j=p[j];
				if(b[j]==b[j+1]){
					j++;
				}
				p[i]=j;
			}
			j=0;
			reclear(m,n);
			k=1;
			for(int i = 1 ; i < n ; i++ )
			{
				while(j&&a[i]!=b[j+1]) j=p[j];
				if(a[i]==b[j+1]){
					j++;
				}
				if(j==m){
					if(i-j+1==k){
						k=i+1;
						sc=0;
						memset(hashc,0,sizeof(hashc));
						for(int p1 = k ; p1 <= n ; p1++ ){
							hashc[a[p1]-'a'+1]++;
						}
						for(int p1 = 1 ; p1 <= 27 ; p1++ )
						{
							if(hashc[p1]%2==1){
								sc++;
							}
						}
						memset(tot,0,sizeof(tot));
						memset(hasha,0,sizeof(hasha));
						sa=0;
						for(int p1 = 1 ; p1 < m ; p1++ )
						{
							hasha[a[p1]-'a'+1]++;
							if(hasha[a[p1]-'a'+1]%2==0){
								sa--;
							}
							else{
								sa++;
							}
							tot[p1]=sa;
						}
						for(int p1 = 1 ; p1 < m ; p1++ )
						{
							if(tot[p1]<=sc){
								ans++;
							}				
						}
					}
					else break;				
				}
			}	
		}
		printf("%lld\n",ans);		
	}
	return 0;
}

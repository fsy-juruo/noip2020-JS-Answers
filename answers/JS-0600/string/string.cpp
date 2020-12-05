#include<bits/stdc++.h>
using namespace std;
int f[1010][1010];
char st[1010],ss[1010];
int s[30];
int main(){
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
    
    int T;
    scanf("%d",&T);
    while (T){
    	T--;
		scanf("%s",st+1);
    	int len=strlen(st+1);
		long long ans=0;
    	memset(f,0,sizeof(f));
    	for (int i=1;i<=len;i++){
    		memset(s,0,sizeof(s));
    		f[i][i]=1;
    		s[st[i]-96]=1;
    		for (int j=i+1;j<=len;j++){
    			f[i][j]=f[i][j-1];
    			s[st[j]-96]++;
    			if (s[st[j]-96]%2==1) f[i][j]++;
    			else f[i][j]--;
			}
	    }
	    for (int i=1;i<=len-2;i++){
	    	for (int j=i+2;j<=len;j++)
	    	   if (f[1][i]<=f[j][len]) ans++;
		}
		ss[1]=st[1];
		for (int l=2;l<=len/2;l++){
			ss[l]=st[l];
			int lenn=l;
			while(1){
				if (lenn+l>=len) break;
				bool flag=0;
				for (int i=1;i<=l;i++)
				   if (st[lenn+1]==ss[i]) lenn++,flag=1;
				   else break;
				if (flag==0) break;
				if (lenn%l==0){
					for (int i=1;i<l;i++)
					   if (f[1][i]<=f[lenn+1][len]) ans++;
				}
				else break;
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}


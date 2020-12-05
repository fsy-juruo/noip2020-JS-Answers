#include<bits/stdc++.h>
using namespace std;
int w[15];
pair<int,int> ste[100005];
int pos[15],st[15],pre[100005],fir[200020];
const long long MOD=1e9+7;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k;
	int pro=1;
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++) {
		scanf("%d",&w[i]);
		pro*=w[i];
	}
	for(int i=0;i<n;i++){
		scanf("%d %d",&ste[i].first,&ste[i].second);
		ste[i].first--;
	}
	if(n<=200){
		int res=0;
		for(int i=0;i<pro;i++){
			bool flag=0;
			for(int j=0;j<k;j++) pos[j]=st[j];
			for(int j=0;j<=2000;j++){
				int x=j%n;
				pos[ste[x].first]+=ste[x].second;
				if(pos[ste[x].first]<0||pos[ste[x].first]>=w[ste[x].first]){
					flag=1;
					res+=j+1;
					break;
				}
			}
			if(!flag){
				puts("-1");
				return 0;
			}
			for(int j=k-1;j>=0;j--){
				if(st[j]==w[j]-1) st[j]=0;
				else{
					st[j]++;
					break;
				}
			}
		}
		cout<<res;
		return 0;
	}
	else{
		memset(fir,-1,sizeof fir);
		pre[0]=ste[0].second;
		const int mov=1e5+3;
		int mi=pre[0],ma=pre[0];
		fir[pre[0]+mov]=0;
		for(int i=1;i<n;i++){
			pre[i]=pre[i-1]+ste[i].second;
			if(fir[pre[i]+mov]==-1) fir[pre[i]+mov]=i;
			mi=min(pre[i],mi);
			ma=max(pre[i],ma);
		}
		int al=pre[n-1];
		long long res=0;
		for(int i=0;i<w[0];i++){
			long long tmp=1e9;
			if(i+mi<0){
				tmp=min(tmp,(long long)fir[mov-i-1]+1);
			}
			if(i+ma>=w[0]){
				tmp=min(tmp,(long long)fir[mov+w[0]-i]+1);
			}
			if(al==0){
				if(i+mi>=0&&i+ma<w[0]){
					puts("-1");
					return 0;
				}
				if(i+mi<0){
					tmp=min(tmp,(long long)fir[mov-i-1]+1);
				}
				if(i+ma>=w[0]){
					tmp=min(tmp,(long long)fir[mov+w[0]-i]+1);
				}
			}
			else if(al<0){
				int tal=-al;
				long long times1=max(0,i+1+mi)/tal;
				long long re=i+1-times1*tal;
				tmp=min(tmp,times1*n+fir[mov-re]+1);
			}
			else if(al>0){
				long long times1=max(0,(w[0]-i-ma))/al;
				long long re=w[0]-i-times1*al;
				tmp=min(tmp,times1*n+fir[mov+re]+1);
			}
			
			res+=tmp;
			res%=MOD;
		}
		cout<<res;
		return 0;
	}
}

#include<bits/stdc++.h>
using namespace std;
char a[10000007];
int t,cnt,tmp;
int hz[10000007],qz[10000007],ycl[10000007];
bool zm[27];
bool vi[10000007];
bool bj(int n,int mg){
	for(int i=mg;i<n;i++){
		if(a[i]!=a[i%mg]){
			return false;
		}
	}
	return true;
}
long long ans;
void fdans(int now){
	if(vi[now])
		return ;
	vi[now]=1;
	ans+=ycl[cnt/now-1];
//	cout<<now<<":+"<<ycl[cnt/now-1]<<"="<<ans<<endl;
	for(int i=1;i*i<=now;i++){
		if(now%i==0)
		fdans(now/i),fdans(i);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(zm,0,sizeof zm);
		memset(qz,0,sizeof qz);
		memset(hz,0,sizeof hz);
		scanf("%s",a);
		int n=strlen(a);
		qz[0]=1;
		zm[a[0]-'a']^=1;
		for(int i=1;i<n;i++){
			qz[i]=qz[i-1]+((zm[a[i]-'a']^=1)==1?1:-1);
		}
		memset(zm,0,sizeof zm);
		hz[n-1]=1;
		zm[a[n-1]-'a']^=1;
		for(int i=n-2;i>=0;i--){
			hz[i]=hz[i+1]+((zm[a[i]-'a']^=1)==1?1:-1);
		}
//		cout<<"-----qz begin-----\n";
//		for(int i=0;i<n;i++)
//			cout<<qz[i]<<" ";
//		cout<<"\n-----qz end-----\n-----hz begin-----\n";
//		for(int i=0;i<n;i++)
//			cout<<hz[i]<<" ";
//		cout<<"\n-----hz end-----\n";
		for(int c=1;c<n-1;c++){
			memset(ycl,0,sizeof ycl);
			for(int i=1;i<n-c;i++){
				ycl[i]=ycl[i-1]+((hz[n-c]>=qz[i-1])?1:0);
//				cout<<ycl[i]<<" ";
			}
//			cout<<endl;
			cnt=n-c;
			tmp=cnt;
			for(int i=1;i*i<=cnt;i++){
				if(cnt%i==0){
					if(bj(cnt,i)){
						tmp=i;
						break;
					}
					if(bj(cnt,cnt/i)){
						tmp=min(tmp,cnt/i);
					}
				}
			}
//			cout<<"ans:"<<tmp<<" "<<cnt<<endl;
			memset(vi,0,sizeof vi);
			fdans(cnt/tmp);
//			cout<<ans<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}


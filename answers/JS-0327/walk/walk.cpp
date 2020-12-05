#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int read(){
	int r=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-') ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) r=r*10+ch-'0',ch=getchar();
	return r*f;
}
int x[100005],n,k,c[100005],d[100005],maxn,minn,w[100005],ans,mmax[100005],mmin[100005],x1[11][100005];
int now[11],maxn1[11],minn1[11],mmax1[11][100005],mmin1[11][100005],x3[11][100005];
bool check(int mid,int ww){
	return mmax[mid]>=ww;
}
bool check1(int mid,int ww){
	return -mmin[mid]>=ww;
}
bool check2(int mid,int ww,int tt){
	return mmax1[tt][mid]>=ww;
}
bool check3(int mid,int ww,int tt){
	return mmin1[tt][mid]>=ww;
}
void doit(){
//	if (k==1){
//		x[0]=0;maxn=INT_MIN,minn=INT_MAX;
//		memset(mmax,-0x7f,sizeof(mmax));
//		memset(mmin,0x7f,sizeof(mmin));
//		for (int i=1;i<=n;i++) {
//			x[i]=x[i-1]+d[i];
//			maxn=max(maxn,x[i]);
//			minn=min(minn,x[i]);
//			mmax[i]=max(mmax[i-1],x[i]);
//			mmin[i]=min(mmin[i-1],x[i]);
//		}
//		minn=-minn;
//		int i=now[1];
//		if (x[n]>0){
//			int z=(w[1]-i+1-maxn)/x[n];
////			cout<<i<<' '<<z<<' ';
//			ans+=z*n;
//			ans%=mod;
//			if (w[1]+1-i-z*x[n]==0) return ;
////			cout<<ans<<endl;
//			int l=1,r=n,mid,ww=w[1]+1-i-z*x[n],ans1=0;
//			while (l<=r){
//				mid=l+r>>1;
////				cout<<l<<' '<<r<<' '<<mid<<endl;
//				if (check(mid,ww)) r=mid-1,ans1=mid;
//				else l=mid+1;
//			}
//			ans+=ans1;
//			ans%=mod;
//		}
//		else {
//			x[n]=-x[n];
//			int z=(i-minn)/x[n];
//			if (z<0) z=0;
//			ans+=z*n;
//			ans%=mod;
//			if (i-z*x[n]==0) {
//				x[n]=-x[n];return ;
//			}
//			int l=1,r=n,mid,ww=i-z*x[n],ans1=0;
//			while (l<=r){
//				mid=l+r>>1;
//				if (check1(mid,ww)) r=mid-1,ans1=mid;
//				else l=mid+1;
//			}
//			ans+=ans1;
//			ans%=mod;
//			x[n]=-x[n];
//		}
//////		cout<<i<<' '<<ans<<endl;
//		return ;
//	}
//	else {
		memset(mmax1,-0x7f,sizeof(mmax));
		memset(mmin1,0x7f,sizeof(mmin));
		for (int r=1;r<=k;r++)
		for (int i=1;i<=n;i++) {
			mmax1[r][i]=max(mmax1[r][i-1],x1[r][i]);
			mmin1[r][i]=min(mmin1[r][i-1],x1[r][i]);
		}
		for (int r=1;r<=k;r++)
		for (int i=1;i<=n;i++) mmin1[r][i]=-mmin1[r][i];
		int ans3=-1;
		for (int r=1;r<=k;r++){
			for (int i=1;i<=k;i++)
			for (int j=1;j<=n;j++) x3[i][j]=x1[i][j];
			int ans2=0;
//			cout<<r<<' '<<x1[r][n]<<endl;
			if (x1[r][n]==0) continue;
			if (x1[r][n]>0){
				int z=(w[r]-now[r]+1-maxn1[r])/x1[r][n];
				if (w[r]+1-maxn1[r]-now[r]-z*x1[r][n]>0) z++;
				if (z<0) z=0;
//				cout<<now[r]<<' '<<z<<' ';
				ans2+=z*n;
//				cout<<ans2<<' ';
				ans2%=mod;
				if (w[r]+1-now[r]-z*x1[r][n]==0) continue;
//				if (r==2) cout<<ans<<endl;
				int l=1,r1=n,mid,ww=w[r]+1-now[r]-z*x1[r][n],ans1=0;
//				for (int o=1;o<=n;o++){
//					if (mmax1[r][o]>=ww) {
//						ans1=o;
//						break;
//					}
//				}
				while (l<=r1){
					mid=l+r1>>1;
//					cout<<l<<' '<<r1<<' '<<mid<<endl;
					if (check2(mid,ww,r)) r1=mid-1,ans1=mid;
					else l=mid+1;
				}
//				if (ans1==0) ans2+=n;
//				else 
//				int ans4=ans1;
//				ans1++;
//				while (c[ans1]!=c[ans4]&&ans1<=n) ans1++;
//				ans1--;
				ans2+=ans1;
				ans2%=mod;
			}
			else {
				x1[r][n]=-x1[r][n];
				int z=(now[r]-minn1[r])/x1[r][n];
				if (now[r]-minn1[r]-z*x1[r][n]>0) z++;
//				cout<<z<<' ';
				if (z<0) z=0;
				ans2+=z*n;
//				cout<<ans2<<endl;
				ans2%=mod;
				if (now[r]-z*x1[r][n]==0) {
					x1[r][n]=-x1[r][n];for (int i=1;i<=k;i++) for (int j=1;j<=n;j++)x1[i][j]=x3[i][j];continue;
				}
				int l=1,r1=n,mid,ww=now[r]-z*x1[r][n],ans1=0;
//				cout<<"ww:"<<ww<<endl;
//				for (int o=1;o<=n;o++){
//					if (mmin1[r][o]>=ww) {
//						ans1=o;
//						break;
//					}
//				}
				while (l<=r1){
					mid=l+r1>>1;
//					cout<<l<<' '<<r<<' '<<mid<<endl;
					if (check3(mid,ww,r)) r1=mid-1,ans1=mid;
					else l=mid+1;
				}
//				int ans4=ans1;
//				ans1++;
//				while (c[ans1]!=c[ans4]&&ans1<=n) ans1++;
//				ans1--;
//				if (ans1==0) ans2+=n;else 
				ans2+=ans1;
				ans2%=mod;
				x1[r][n]=-x1[r][n];for (int i=1;i<=k;i++) for (int j=1;j<=n;j++) x1[i][j]=x3[i][j];
			}
			if (ans3==-1) ans3=ans2;else ans3=min(ans3,ans2);
//			cout<<r<<' '<<ans2<<' '<<ans3<<endl;
			for (int i=1;i<=k;i++) for (int j=1;j<=n;j++) x1[i][j]=x3[i][j];
		}
		ans+=ans3;
		ans%=mod;
//	}
//	if (k==2){
//		
//	
//		if (x[n]>0){
//			int z=(w[1]-i+1-maxn)/x[n];
////			cout<<i<<' '<<z<<' ';
//			ans+=z*n;
//			ans%=mod;
//			if (w[1]+1-i-z*x[n]==0) continue;
////			cout<<ans<<endl;
//			int l=1,r=n,mid,ww=w[1]+1-i-z*x[n],ans1=0;
//			while (l<=r){
//				mid=l+r>>1;
////				cout<<l<<' '<<r<<' '<<mid<<endl;
//				if (check(mid,ww)) r=mid-1,ans1=mid;
//				else l=mid+1;
//			}
//			ans+=ans1;
//			ans%=mod;
//		}
//		else {
//			x[n]=-x[n];
//			int z=(i-minn)/x[n];
//			if (z<0) z=0;
//			ans+=z*n;
//			ans%=mod;
//			if (i-z*x[n]==0) {
//				x[n]=-x[n];continue;
//			}
//			int l=1,r=n,mid,ww=i-z*x[n],ans1=0;
//			while (l<=r){
//				mid=l+r>>1;
//				if (check1(mid,ww)) r=mid-1,ans1=mid;
//				else l=mid+1;
//			}
//			ans+=ans1;
//			ans%=mod;
//			x[n]=-x[n];
//		}
//////		cout<<i<<' '<<ans<<endl;
//	}
//	}
}
void dfs(int dep){
	if (dep>k){
//		cout<<now[1]<<' '<<now[2]<<endl;
		doit();
//		cout<<endl;
//		cout<<ans<<endl;
		return ;
	}
	for (int i=1;i<=w[dep];i++) now[dep]=i,dfs(dep+1),now[dep]=0;
	return ;
}
int main(){
freopen("walk.in","r",stdin);
freopen("walk.out","w",stdout);
cin>>n>>k;
for (int i=1;i<=k;i++) w[i]=read();
for (int i=1;i<=n;i++) c[i]=read(),d[i]=read();
for (int j=1;j<=k;j++) for (int i=1;i<=n;i++) if (c[i]!=j) x1[j][i]=x1[j][i-1];else x1[j][i]=x1[j][i-1]+d[i];
int f=1;
for (int i=1;i<=k;i++) if (x1[i][n]!=0) {
	f=-1;
	break;
}
if (f==1){
	cout<<-1<<endl;
	return 0;
}
if (n<=100||k==1){
	memset(maxn1,-0x7f,sizeof(maxn1));
	memset(minn1,0x7f,sizeof(minn1));
	for (int j=1;j<=k;j++)
	for (int i=1;i<=n;i++){
		maxn1[j]=max(maxn1[j],x1[j][i]);
		minn1[j]=min(minn1[j],x1[j][i]);
	}
	for (int j=1;j<=k;j++) minn1[j]=-minn1[j];
//	for (int j=1;j<=k;j++){cout<<minn1[j]<<' ';
//		cout<<endl;
//	}
//	cout<<endl;
	dfs(1);
	cout<<ans<<endl;
}
//if (k==1){
//	x[0]=0;maxn=INT_MIN,minn=INT_MAX;
//	memset(mmax,-0x7f,sizeof(mmax));
//	memset(mmin,0x7f,sizeof(mmin));
//	for (int i=1;i<=n;i++) {
//		x[i]=x[i-1]+d[i];
//		maxn=max(maxn,x[i]);
//		minn=min(minn,x[i]);
//		mmax[i]=max(mmax[i-1],x[i]);
//		mmin[i]=min(mmin[i-1],x[i]);
//	}
//	minn=-minn;
//	if (x[n]==0){
//		cout<<-1<<endl;
//		return 0;
//	}
//	for (int i=1;i<=w[1];i++) {
//		if (x[n]>0){
//			int z=(w[1]-i+1-maxn)/x[n];
////			cout<<i<<' '<<z<<' ';
//			ans+=z*n;
//			ans%=mod;
//			if (w[1]+1-i-z*x[n]==0) continue;
////			cout<<ans<<endl;
//			int l=1,r=n,mid,ww=w[1]+1-i-z*x[n],ans1=0;
//			while (l<=r){
//				mid=l+r>>1;
////				cout<<l<<' '<<r<<' '<<mid<<endl;
//				if (check(mid,ww)) r=mid-1,ans1=mid;
//				else l=mid+1;
//			}
//			ans+=ans1;
//			ans%=mod;
//		}
//		else {
//			x[n]=-x[n];
//			int z=(i-minn)/x[n];
//			if (z<0) z=0;
//			ans+=z*n;
//			ans%=mod;
//			if (i-z*x[n]==0) {
//				x[n]=-x[n];continue;
//			}
//			int l=1,r=n,mid,ww=i-z*x[n],ans1=0;
//			while (l<=r){
//				mid=l+r>>1;
//				if (check1(mid,ww)) r=mid-1,ans1=mid;
//				else l=mid+1;
//			}
//			ans+=ans1;
//			ans%=mod;
//			x[n]=-x[n];
//		}
//////		cout<<i<<' '<<ans<<endl;
//	}
//	cout<<ans<<endl;
//	return 0;
//}
	return 0;
}
/*
3 1
3
1 -1
1 -1
1 1


3 2
3 3
1 1
2 -1
1 1

5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1

*/

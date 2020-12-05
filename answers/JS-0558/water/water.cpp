#include<bits/stdc++.h>
using namespace std;
int head,tail,q[100005][1];
bool bb[100005];
int n,m,d,t;
vector<int> a[100005],non;
struct nude{
	int x;
	int y;
}ss[100005];
nude easy(nude a){
	for(int i=2;i<=min(a.x,a.y);){
		if(a.x%i==0&&a.y%i==0){
			a.x/=i;
			a.y/=i;
		}
		else i++;
	}
	return a;
}
nude add(nude a,nude b){
	if(a.x==0) return easy(b);
	if(b.x==0) return easy(a);
	if(a.y==0) a.y=1;
	if(b.y==0) b.y=1;
	nude c;
	c.y=a.y*b.y;
	c.x=a.x*b.y+b.x*a.y;
	return easy(c);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d);
		a[i].push_back(d);
		if(d==0) non.push_back(i);
		for(int j=1;j<=d;j++){
			scanf("%d",&t);
			a[i].push_back(t);
			bb[t]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(bb[i]==0){
			tail++;
			q[tail][0]=i;
			ss[i].x=1;
			ss[i].y=1;
		}
	}
	head=1;
	while(head<=tail){
		int xx=q[head][0];
		if(a[xx][0]==0){
			head++;
			continue;
		}
		ss[xx].y*=a[xx][0];
		for(int i=1;i<=a[xx][0];i++){
			tail++;
			q[tail][0]=a[xx][i];
//			cout<<" ori:"<<ss[tail].x<<" "<<ss[tail].y<<endl;
			ss[a[xx][i]]=add(ss[a[xx][i]],ss[xx]);//ss[xx]: easy
//			cout<<a[xx][i]<<":  "<<ss[a[xx][i]].x<<" "<<ss[a[xx][i]].y<<endl;
		}
		ss[xx].x=0;
		ss[xx].y=1;
		head++;
	}
	for(int i=0;i<non.size();i++){
		printf("%d %d\n",ss[non[i]].x,ss[non[i]].y);
	}
	return 0;
}


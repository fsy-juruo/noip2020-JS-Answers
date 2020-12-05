#include <bits/stdc++.h>
using namespace std;
int n,m,l,r;
struct node{
	int step;
	int a[12][24],cnt[24];
	int actx,acty,last;
}q[400050];
bool check(node x) {
	int i,j;
	for (i=1;i<=m;i++) {
		if (x.cnt[i]==0)  continue;
		if (x.cnt[i]<n)  return 0;
		for (j=1;j<n;j++)
		  if (x.a[i][j]!=x.a[i][j+1])  return 0;
	}
	return 1;
}
void digui(int x,int num) {
	if (q[x].last!=0)  digui(q[x].last,num+1);
	else  cout<<num<<endl;
	cout<<q[x].actx<<" "<<q[x].acty<<endl;
}
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	node x,tmp;
	int h,k,i,j;
	for (i=1;i<=n;i++)
	  for (j=1;j<=m;j++)
	    scanf("%d",&x.a[i][j]);
	x.step=0;
	q[1]=x;
	l=0, r=1;
	while (l<r) {
		l++;
		x=q[l];
		for (i=1;i<=m+1;i++) {
			if (x.cnt[i]==n)  continue;
			for (j=1;j<=m+1;j++) {
				if (i==j||x.cnt[j]==0)  continue;
				q[++r].actx=j;
				q[r].acty=i;
				for (h=1;h<=n;h++)
				  for (k=1;k<=m+1;k++)
				    q[r].a[h][k]=x.a[h][k];
				q[r].a[i][x.cnt[i]+1]=q[r].a[j][x.cnt[j]];
				q[r].cnt[i]++;
				q[r].cnt[j]--;
				q[r].last=l;
				if (check(q[r])) {
					digui(r,0);
					return 0;
				}
			}
		}
		
	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

int n,m;
struct node{
	int num[410];
	int top;
	node operator=(const node &x){
		for(int i=1;i<=x.top;i++)
			num[i]=x.num[i];
		top=x.top;
		return *this;
	}
}zz[110];

struct cst{
	int last;
	int sta,to;
	int step;
	node have[11];
	cst operator=(const cst &x){
		for(int i=1;i<=4;i++)
			have[i]=x.have[i];
		step=x.step+1;
		return *this;
	}
}q[10000];

int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}

void bfs(){
	int head=1,tail=2;
	for(int i=1;i<=n+1;i++)
		q[head].have[i]=zz[i];
	q[head].step=0;
	q[head].last=0;
	while(head<tail){
		cst u=q[head];
		for(int i=1;i<=n+1;i++)
			for(int j=1;j<=n+1;j++){
				if(i==j) continue;
				if(u.have[i].top>0&&u.have[j].top<m){
					cst tem=u;
					tem.have[i].top--;
					tem.have[j].num[++tem.have[j].top]=tem.have[i].num[tem.have[i].top];
					q[tail]=tem;
					q[tail].last=head;
					q[tail].sta=i;
					q[tail].to=j;
					bool flag=true;
					int ji=0;
					for(int w=1;w<=n+1;w++){
						if(tem.have[w].top==0) ji=w;
					}
					if(ji){
						for(int w=1;w<=n+1;w++){
							if(!flag) break;
							if(w!=ji){
								for(int jj=1;jj<m;jj++)
									if(tem.have[w].num[jj]!=tem.have[w].num[jj+1]){
										flag=false;
										break;
									}
							}
						}
					}
					else flag=false;
					if(flag){
						int yes=tail;
						int aaa[10100],bbb[10100];
						int cnt=0;
						while(q[yes].last!=1){
							aaa[++cnt]=q[yes].sta;
							bbb[cnt]=q[yes].to;
							yes=q[yes].last;
						}
						cout<<tem.step<<endl;						
						for(int slx=cnt;slx>0;slx--)
							cout<<aaa[slx]<<" "<<bbb[slx]<<endl;
						return ;
					}
					tail++;
				}
			}
		head++;
	}
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		zz[i].num[i]=read();
		zz[i].top=m;
	}
	if(n==1)
		cout<<0<<endl;
	else bfs();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

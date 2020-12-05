#include<bits/stdc++.h>
using namespace std;

int n,m,c[60][410],js[60];
struct nod{
	int x,y;
};
stack<nod> ss;

void readp(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++)
		js[i]=m;
}

bool check(){
	for(int i=1;i<=n;i++){
		if(js[i]!=m)return false;
		int num=c[i][1];
		for(int j=1;j<=js[i];j++)
			if(c[i][j]!=num)return false;
	}
	return true;
}

void rout(){
        if(ss.empty())return;
        nod a=ss.top();
        ss.pop();
        rout();
        cout<<a.x<<' '<<a.y<<endl;
}

void dfs(int step){
	if(step>10)return;
	if(check()){
		cout<<step-1<<endl;
		rout();
		return;
	}
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=n+1;j++)
			if(i!=j&&js[i]>=1&&js[j]<=m-1){
				nod a;
				int temp=c[i][js[i]];
				c[j][++js[i]]=c[i][js[i]--];
				a.x=i;
				a.y=j;
				ss.push(a);
				dfs(step+1);
				ss.pop();
				c[i][++js[i]]=temp;
				js[j]--;
			}
}

int f=1,t=1,fa[10010];
struct node{
        int s[11][21],step,x,y;
};
node que[10000];

void rout2(int t){
	if(fa[fa[t]]!=0)rout2(fa[t]);
	cout<<que[t].x<<' '<<que[t].y<<endl;
}

bool check2(node ab){
	for(int i=1;i<=n;i++){
                if(ab.s[i][0]!=m)return false;
                int num=ab.s[i][1];
                for(int j=1;j<=ab.s[i][0];j++)
                        if(ab.s[i][j]!=num)return false;
        }
        return true;
}

void bfs(){
        node a;
        a.step=0;
        for(int i=1;i<=n;i++){
                a.s[i][0]=m;
                for(int j=1;j<=m;j++)
                        a.s[i][j]=c[i][j];
        }
        que[++t]=(a);
        while(f<=t&&t<=9999){
                node temp=que[f];
                for(int i=1;i<=n+1;i++)
                        for(int j=1;j<=n+1;j++){
                                if(i!=j&&temp.s[i][0]>=1&&temp.s[j][0]<=m-1){
                                        node xx=temp;
                                        xx.x=i;xx.y=j;
                                        xx.s[j][++xx.s[j][0]]=xx.s[i][xx.s[i][0]--];
                                        xx.step=temp.step+1;
                                        que[++t]=xx;
                                        fa[t]=f;
                                        if(check2(xx)){
						cout<<xx.step<<endl;
                                                rout2(t);
                                                return;
                                        }
                                }
                        }
                f++;
        }
}

int main(){
        freopen("ball.in","r",stdin);
        freopen("ball.out","w",stdout);
	readp();
	//dfs(0);
	if(n>=10)dfs(0);
	else bfs();
        return 0;
}


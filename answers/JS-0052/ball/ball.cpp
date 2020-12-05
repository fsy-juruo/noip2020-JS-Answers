#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define MAXN 405
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef unsigned long long ull;

int n,m;
vector<pair<int,int> > step;
vector<int> bal[MAXN];
int ct[MAXN];
int ans=0;
void move(int x,int y){
    step.push_back(mp(x,y));
    bal[y].push_back(bal[x].back());
    bal[x].pop_back();
    ct[x]--;
    ct[y]++;
}
void ave(){
    while(ct[1]<ct[2])move(2,1);
    while(ct[2]<ct[1])move(1,2);
}

int main(){
    freopen("ball.in","r",stdin);
    freopen("ball.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
	ct[i]=m;
	for(int j=1;j<=m;j++){
	    int t;
	    scanf("%d",&t);
	    bal[i].push_back(t);
	}
    }
    int in=bal[1].back();
    //printf("%d\n",in);
    step.push_back(mp(1,3));
    bal[1].pop_back();
    ct[3]++;
    ct[1]--;
    while(bal[1].back()==in)move(1,3);
    ave();

	int a=999,b=999;
	for(int i=bal[1].size()-1;i>=0;i--){
	    if(bal[1][i]==in){
		a=i;
		break;
	    }
	}

	for(int i=bal[2].size()-1;i>=0;i--){
	    if(bal[2][i]==in){
		b=i;
		break;
	    }
	}
	if(a<b){
	    while(ct[2]<m-1&&a>1){
		move(1,2);
		a--;
	    }
	    int tmp=0;
	    while(a>1){
		move(1,3);
		a--;
		tmp++;
	    }
	    if(tmp){
		move(1,2);
		while(tmp--)move(3,1);
		move(2,3);
	    }
	    else move(1,3);
	    ave();
	}else{
	    while(ct[1]<m-1&&b>1){
		move(2,1);
		b--;
	    }
	    int tmp=0;
	    while(b>1){
		move(2,3);
		b--;
		tmp++;
	    }
	    if(tmp){
		move(2,1);
		while(tmp--)move(3,2);
		move(1,3);
	    }
	    else move(2,3);
	    ave();
	}
    printf("%d\n",step.size());
    for(int i=0;i<step.size();i++){
	printf("%d %d\n",step[i].first,step[i].second);
    }
    return 0;
}

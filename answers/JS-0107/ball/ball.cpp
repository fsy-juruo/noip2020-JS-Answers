#include<bits/stdc++.h>
using namespace std;
int n,m,l[55][55],ans[820005][3],bs,t;
struct node{
	int cl[405],g;
}z[55];
void yd(int a,int b,int c){
	for(int i=1;i<=c;i++){
		bs++;
		ans[bs][1]=a;
		ans[bs][2]=b;
		z[b].g++;
		z[b].cl[z[b].g]=z[a].cl[z[a].g];
		z[a].g--;
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
    	cin >> z[i].cl[j];
    	l[i][z[i].cl[j]]++;
	}
	z[i].g=m;
    }
    if(n==2){
      t=l[2][2];
      yd(1,3,l[2][2]);
      int js=0;
      for(int i=1;i<=m;i++){
      	if(z[2].cl[z[2].g]==2){
      	yd(2,1,1);
      	js++;
	    }
      	else
      	yd(2,3,1);
      	if(js==t)
      	break;
	  }
	  yd(3,2,z[3].g);
	  yd(1,3,t);
	  yd(2,1,t);
	  for(int i=1;i<=m;i++){
      	if(z[1].cl[z[1].g]==2){
      	yd(1,3,1);
	    }
      	else
      	yd(1,2,1);
	  }
	}
	cout << bs << endl;
	for(int i=1;i<=bs;i++)
	cout << ans[i][1] << " " << ans[i][2] << endl;
	return 0;
}

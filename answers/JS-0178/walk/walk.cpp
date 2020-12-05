#include<bits/stdc++.h>
using namespace std;
int n,k,c[100001],d[100001],w[100001];
const int mod=1e9+7;
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=k; i++)scanf("%d",&w[i]);

	for(int i=1; i<=n; i++) {
		scanf("%d%d",&c[i],&d[i]);
	}
	if(k==1) {
		int tx=0,ans=0;

		for(int i=1; i<=w[1]; i++) {
			tx=i;
			bool b=true;
			while(b) {
				for(int k=1; k<=n; k++) {
					tx+=d[k];
					ans++;
					if(tx<1||tx>w[1]) {

						k=n+1;
						b=false;

					}
					ans%=mod;
				}
				if(tx==i) {
					printf("-1");
					return 0;
				}
			}

		}
		printf("%d",ans);
		return 0;
	}


	if(k==2) {
		int tx=0,ty=0,ans=0;

		for(int i=1; i<=w[1]; i++) {
			for(int j=1; j<=w[2]; j++) {
				tx=i,ty=j;
				bool b=true;
				while(b) {
					for(int k=1; k<=n; k++) {
						if(c[k]==1)tx+=d[k];
						if(c[k]==2)ty+=d[k];
						ans++;
						if(tx<1||tx>w[1]||ty<1||ty>w[2]) {

							k=n+1;
							b=false;

						}
						ans%=mod;
					}
					if(tx==i&&ty==j) {
						printf("-1");
						return 0;
					}
				}

			}
		}
		printf("%d",ans);
		return 0;
	}
	if(k==3) {
		int tx=0,ty=0,tz=0,ans=0;

		for(int i=1; i<=w[1]; i++) {
			for(int j=1; j<=w[2]; j++) {
				for(int z=1; z<=w[3]; z++) {
					tx=i,ty=j,tz=z;
					bool b=true;
					while(b) {
						for(int k=1; k<=n; k++) {
							if(c[k]==1)tx+=d[k];
							if(c[k]==2)ty+=d[k];
							if(c[k]==3)tz+=d[k];
							ans++;
							if(tx<1||tx>w[1]||ty<1||ty>w[2]||tz<1||tz>w[3]) {

								k=n+1;
								b=false;

							}
							ans%=mod;
						}
						if(tx==i&&ty==j&&tz==z) {
							printf("-1");
							return 0;
						}
					}
				}


			}
		}
		printf("%d",ans);
		return 0;
	}
	if(k==4) {
		int tx=0,ty=0,tz=0,tk=0,ans=0;

		for(int i=1; i<=w[1]; i++) {
			for(int j=1; j<=w[2]; j++) {
				for(int z=1; z<=w[3]; z++) {
					for(int tt=1; tt<=w[4]; tt++) {
						tx=i,ty=j,tz=z,tk=tt;
						bool b=true;
						while(b) {
							for(int k=1; k<=n; k++) {
								if(c[k]==1)tx+=d[k];
								if(c[k]==2)ty+=d[k];
								if(c[k]==3)tz+=d[k];
								if(c[k]==4)tk+=d[k];
								ans++;
								if(tx<1||tx>w[1]||ty<1||ty>w[2]||tz<1||tz>w[3]||tk<1||tk>w[4]) {

									k=n+1;
									b=false;

								}
								ans%=mod;
							}
							if(tx==i&&ty==j&&tz==z&&tk==tt) {
								printf("-1");
								return 0;
							}
						}
					}

				}


			}
		}
		printf("%d",ans);
		return 0;
	}
	if(k==5) {
		int tx=0,ty=0,tz=0,tk=0,tf=0,ans=0;

		for(int i=1; i<=w[1]; i++) {
			for(int j=1; j<=w[2]; j++) {
				for(int z=1; z<=w[3]; z++) {
					for(int tt=1; tt<=w[4]; tt++) {
						for(int ta=1; ta<=w[5]; ta++) {
							tx=i,ty=j,tz=z,tk=tt,tf=ta;
							bool b=true;
							while(b) {
								for(int k=1; k<=n; k++) {
									if(c[k]==1)tx+=d[k];
									if(c[k]==2)ty+=d[k];
									if(c[k]==3)tz+=d[k];
									if(c[k]==4)tk+=d[k];
									if(c[k]==5)tf+=d[k];
									ans++;
									if(tx<1||tx>w[1]||ty<1||ty>w[2]||tz<1||tz>w[3]||tk<1||tk>w[4]||tf<1||tf>w[5]) {

										k=n+1;
										b=false;

									}
									ans%=mod;
								}
								if(tx==i&&ty==j&&tz==z&&tk==tt&&tf==ta) {
									printf("-1");
									return 0;
								}
							}
						}

					}

				}


			}
		}
		printf("%d",ans);
		return 0;
	}
	printf("-1");
	return 0;
}


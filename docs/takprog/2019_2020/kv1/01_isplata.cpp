#include<bits/stdc++.h>
using namespace std;
char s[20];
int novcanica_za_cifru(int a) {
    int rt=0;
    while(a>=5) {
        a-=5;
        rt++;
    }
    while(a>=2) {
        a-=2;
        rt++;
    }
    while(a>=1) {
        a-=1;
        rt++;
    }
    return rt;
}
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	int ans=0;
	for(int i=0;i<n;i++) ans+=novcanica_za_cifru(s[i]-'0');
	printf("%d",ans);
	return 0;
}

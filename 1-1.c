#include <stdio.h>
int f(int x){
    int m;
    if(x==0||x==1) {
        m=1;
    }
    else{
        m=x*f(x-1);
    }
    return m;
}
int main(){
    int n,k,m,h,i;
    while(scanf("%d %d",&n,&k)!=EOF){
        if(n==k||k==0) printf("%d\n",f(n)/f(n));
        else{
            m=f(n-1);
            h=f(k)*f(n-1-k);
            i=f(k-1)*f(n-k);
            printf("%d\n",m/h+m/i);
        }
    }
    return 0;
}


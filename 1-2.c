#include <math.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int add(int a,int b,FILE *fp){
    int c,d;
    printf("%d+%d=",a,b);
    fprintf(fp,"%d+%d=",a,b);
    scanf("%d",&d);
    fprintf(fp,"%d\n",d);
    c=a+b;
    if(c==d) return 1;
    else return 0;
}

int sub(int a,int b,FILE *fp){
    int c,d;
    printf("%d-%d=",a,b);
    fprintf(fp,"%d-%d=",a,b);
    scanf("%d",&d);
    fprintf(fp,"%d\n",d);
    c=a-b;
    if(c==d) return 1;
    else return 0;
}
int mul(int a,int b,FILE *fp)
{
    int c,d;
    printf("%d*%d=",a,b);
    fprintf(fp,"%d*%d=",a,b);
    scanf("%d",&d);
    fprintf(fp,"%d\n",d);
    c=a*b;
    if(c==d) return 1;
    else return 0;
}
int div_(int a,int b,FILE *fp){
    float c,d;
    int m,n;
    printf("%d/%d=",a,b);
    fprintf(fp,"%d/%d=",a,b);
    scanf("%f",&d);
    fprintf(fp,"%d\n",b);
    c=(a*1.000)/b;
    m=c*1000;
    n=m%10;
    if(n>=5)c=(m+10-n)*(1.00)/1000;
    else c=(c*1000)*(1.00)/1000;
    if(c==d) return 1;
    else return 0;
}
int main() {
    int a, b, r, i, f, k;
    char j;
    FILE *fp;
    fp = fopen("result.txt", "w");
    printf("������ϰ�������������5����Ŀ\n");
    fprintf(fp, "������ϰ�������������5����Ŀ\n");
    printf("��ʮ���ڼӡ������ˡ������������뱣��2λС��),����⣺\n");
    fprintf(fp, "��ʮ���ڼӡ������ˡ������������뱣��2λС��),����⣺\n");
    srand((unsigned) time(NULL));
    while (1) {
        r = 0;
        for (i = 0; i < 5; i++) {
            a = rand() % 21;
            b = rand() % 21;
            f = rand() % 5;
            k = f % 4;
            if (f = 0) {
                i--;
                continue;
            }
            else {
                switch (k) {
                    case 0: {
                        if (a >= b && b != 0) {
                            r = r + div_(a, b, fp);
                        } else {
                            i--;
                        }
                        continue;
                    }
                    case 1:
                        r = r + add(a, b, fp);
                        continue;
                    case 2:
                        r = r + sub(a, b, fp);
                        continue;
                    case 3:
                        r = r + mul(a, b, fp);
                        continue;
                }
            }
        }
        r = r * 20;
        printf("��ȷ��Ϊ%d%%\n",r);
        fprintf(fp, "��ȷ��Ϊ%d%%\n",r);
        printf("�Ƿ���������������Y����������N:\n");
        fprintf(fp,"�Ƿ���������������Y����������N:\n");
        fprintf(fp, "\n");
        fflush(stdin);
        scanf("%c", &j);
        fprintf(fp, "%c\n", j);
        if (j == 'N') break;
    }
    fclose(fp);
    return 0;
}

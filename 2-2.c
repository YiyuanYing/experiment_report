#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <strings.h>
int main(){
    char ch[10][9];
    FILE *fp;
    fp=fopen("aa.txt","w");
    for(int i=1;i<=7;i++){
        fscanf(fp,"%s",&ch[i][9]);
    }
    printf("请输入一个车牌号：");
    scanf("%s",&ch[7]);
    for(int i=0;i<=7;i++){
        int value;
        value = atoi(ch[i] + strlen(ch[i]) - 4);
        printf("%d\n",value);
        if((sqrt(value*1.0)==(int)(sqrt(value*1.0)))&&(value>1000)) printf("%s ",ch[i]);
    }
    fclose(fp);
    return 0;
}

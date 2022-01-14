#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <strings.h>
void squeeze(char*str1,char*str2){
    int i,k;
    int n=strlen(str1);
    char *q;
    char *temp=(char*)malloc(n+1);
    if(!temp) exit(0);
    strcpy(temp,str1);
    q=str2;
    while(*q){
        for(i=0;i<n;i++)
            if(temp[i]==*q) temp[i]='\0';
        q++;
    }
    for(k=0,i=0;i<n;i++)
        if(temp[i]!='\0') str1[k++]=temp[i];
    str1[k]='\0';
    free(temp);
}

int main(){
    char ch1[1000],ch2[1000];
    printf("请输入第一个字符串：");
    scanf("%s",ch1);
    printf("请输入第二个字符串：");
    scanf("%s",ch2);
    squeeze(ch1,ch2);
    printf("%s\n",ch1);
    return 1;
}
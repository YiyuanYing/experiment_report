//12/9/2021
//1.比赛选手信息登记查询
//2.图书信息登记
# include <stdio.h>
# define N 3
# define NI 3
//----------比赛选手信息登记查询----------
struct player{
    int num;
    char name[20];
    char nation[20];
    int score[7];
    float avg;
}player[N];

void input1(){
    int i,j,min,max;float sum;
    printf("请输入三位选手信息：编号、姓名、国籍、7 位评委的打分：\n");
    for (i=0;i<N;i++){
        sum = 0;max = 0;min = 2147483647;
        scanf("%d%s%s",&player[i].num,player[i].name,player[i].nation);
        for (j=0;j<7;j++){
            scanf("%d",&player[i].score[j]);
            sum += player[i].score[j];
            if (player[i].score[j] > max) max=player[i].score[j];
            if (player[i].score[j] < min) min=player[i].score[j];
        }
        player[i].avg = (sum - max - min) / 5;
    }

}
void output1(){
    printf("选手最终成绩：\nNo. Name Nationality Total_Score\n");
    for (int i=0;i<N;i++) printf("%-6d%-11s%-14s%-4.2f\n",player[i].num,\
        player[i].name,player[i].nation,player[i].avg);
}
//----------图书信息登记----------
struct books{
    char name[50];
    char author[20];
    char pub[50];
    int year;
    float price;
    char ISBN[50];
}book[50];

void input2(){
    printf("请输入%d 本图书信息：书名，作者，出版社，出版年，单价，ISBN 编号：\n",NI);
    for (int i=0;i<NI;i++) scanf("%s%s%s%d%f%s",book[i].name,book[i].author,\
        book[i].pub,&book[i].year,&book[i].price,book[i].ISBN);
}

void output2(){
    printf("\n 图书检索结果是：\n 书名\t\t\t 作者\t\t\t 出版社\t\t 出版年 \t 单 价\t\t ISBN\n");
    int max;
    for (int i=0,max;i<NI;i++){
        max = 0;
        for (int j=0;j<NI;j++) if(book[j].year>book[max].year) max = j;
        printf("%-20s%-15s%-20s%-11d%-5.2f%s\n",book[max].name,book[max].author,\
            book[max].pub,book[max].year,book[max].price,book[max].ISBN);
        book[max].year = 0;
    }
}

int main(){
    printf("1.比赛选手信息登记查询\n"
           "2.图书信息登记\n"
           "请输入1或2：");
    int x=0;
    scanf("%d",&x);
    if(x==1){
        input1();output1();//比赛选手信息登记查询
    }
    else if(x==2){
        input2();output2();//图书信息登记
    }
    else{
        printf("您的输入有误！\n");
    }
    return 0;
}
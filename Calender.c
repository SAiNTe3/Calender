#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Date{
    int Year;
    int Month;
    int Day;
};
const char* week[]={"星期天","星期一","星期二","星期三","星期四","星期五","星期六"};
const char* weekreverse[]={"星期六","星期五","星期四","星期三","星期二","星期一","星期天"};
//判断闰年
bool isLeap(int Year){
    if((Year%4==0&&Year%100!=0)||(Year%400==0)){
        return true;
    }
    else return false;
}
//计算年内日期
int Function1(struct Date date){
    int Days=0;
    for(int i=1;i<date.Month;i++){
        if((i==4)||(i==6)||(i==9)||(i==11)){
            Days+=30;
        }
        else if(i==2){
            if(isLeap(date.Year)){
                Days+=29;
            }
            else Days+=28;
        }
        else Days+=31;
    }
    Days+=date.Day;
    return Days;
}
//计算两个日期长度
int MainF(struct Date *p1,struct Date *p2){
    int day1=0,day2=0,length=0;
    if((p1->Year)==(p2->Year)){
        length=Function1(*p2)-Function1(*p1);
    }
    else{
        if(isLeap(p1->Year)){
            day1=366-Function1(*p1);
        }
        else day1=365-Function1(*p1);
        day2=Function1(*p2);
        for(int i=(p1->Year)+1;i<(p2->Year);i++){
            if(isLeap(i)){
                length+=366;
            }
            else length+=365;
        }
        length+=(day1+day2);
    }
    return length;
}
//计算某日为星期几
void Week(struct Date *p){
    struct Date DayStart={1900,1,1};
    if((p->Year)<DayStart.Year){
        int weekday=(MainF(p,&DayStart)+5)%7;
        printf("\n%s",weekreverse[weekday]);
    }
    else{
        int weekday=(MainF(&DayStart,p)+1)%7;
        printf("\n%s",week[weekday]);
    }
}
int main(){
    struct Date date1,date2;
    struct Date *p1,*p2;
    p1=&date1,p2=&date2;
    printf("请输入第一个日期（格式为XXXX-XX-XX）：");
    scanf("%d-%d-%d",&p1->Year,&p1->Month,&p1->Day);
    printf("请输入第二个日期（格式为XXXX-XX-XX）：");
    scanf("%d-%d-%d",&p2->Year,&p2->Month,&p2->Day);
    int length=MainF(p1,p2);
    printf("相距%d日",length);
    Week(p1);
    system("pause");
}
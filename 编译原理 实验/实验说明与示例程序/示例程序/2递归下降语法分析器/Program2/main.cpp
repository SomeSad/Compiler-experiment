#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int j,len;
char Express[50],error;
int errs;


int E();
int EX();
int T();
int TX();
int F();


int F()
{
    if(Express[j]=='i')
        j=j+1;
    else if(Express[j]=='(')
    {
        j++;
        errs=E();
        if(errs>0)return errs;
        if(Express[j]==')')j++;
        else errs=1;//缺少右括号
    }
    else
    {
        error=Express[j];
        errs=2;
    }
    return errs;
}
int EX()
{
    if (Express[j]=='+')
    {
        j=j+1;
        errs=T();
        if (errs>0) return errs;
        errs=EX();
    }
    return errs;
}

int E()
{
    errs=T();
    if(errs>0)return errs;
    errs=EX();
    return errs;
}
int T()
{
    errs=F();
    if(errs>0)
        return errs;
    errs=TX();
    return errs;
}
int TX()
{
    if(Express[j]=='*')
    {
        j++;
        errs=F();
        if(errs>0)return errs;
        errs=TX();
    }
     return errs;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    printf("%s\t\t%s\t%s\n","算术表达式","是否合乎语法","非法原因");
    //每次读一行文本
    while(gets(Express))
    {
        len=strlen(Express);
        errs=0;//初始化没有错误
        j=0;
        errs=E();

        puts(Express);
        if(errs==0&&j==len)
            printf("%-10s\t\t%s\n",Express,"合法");
        else if(errs==1)
            printf("%-10s\t\t%s\t\t%s\n",Express,"非法","缺少右括号");
        else if(errs==2)
            printf("%-10s\t\t%s\t\t%s%s%d%s%c\n",Express,"非法","非法字符--","第",j+1,"位字符：",error);
        else
        {
            printf("%-10s\t\t%s\t\t%s",Express,"非法","前面部分合法");
            Express[j]='\0';
            printf("%s\n",Express);
        }
    }
    return 0;
}

// Drug manage.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define PRINT "%-16d%-16s%-16s%-16.2f%-8d\n",s->id,s->name,s->brand,s->price,s->num
#define PRINT1 "=========================================================================\n"
#define PRINT2 "药品编号\t药品名称\t药品厂家\t药品价格\t药品数量\n"
#define PRINT3 "账户名称\t账户密码\t姓名\t电话号码\t备注\n"
#define PRINT4 "%-16s%-16s%-8s%-16s%-16s\n",p->admin,p->password,p->name,p->phonenum,p->remark
#define maxnum 100
//药品处理
void input_drug(struct druginfo *s);
void print_drug(struct druginfo *s);
void save_drug(struct druginfo *s);
int read_drug(struct druginfo *s);
void search_drug(struct druginfo *s);
void modify_drug(struct druginfo *s);
void delet_drug(struct druginfo *s);
void sort_drug(struct druginfo *s);
int isexisted(int shopnum);
void statistics_drug();
void loaddrug();
//帐户处理
void input_account(struct account *p);
void print_account(struct account *p);
void save_account(struct account *p);
int read_account(struct account *p);
void search_account(struct account *p);
void modify_account(struct account *p);
void delet_account(struct account *p);
int isexisted1(char admin[20]);
void loadaccount();
void account();
void password();
void menu();
struct druginfo
{
	int id;                    //编号
	char name[20];             //名称
	char brand[20];            //品牌
	float price;               //价格
	int num;                   //数量
}drug[100],si[100];
struct account
{
	char admin[20];            //账户
	char password[20];         //密码
	char name[20];             //姓名
	char phonenum[20];         //电话
	char remark[100];         //备注
}acco[10];
int n=0,m=0;
//显示系统主界面
void menu()
{
	int x;
	do
	{
		printf("------------------欢迎进入药店管理系统------------------\n\n");
		printf("========================================================\n\n");
		printf("-------------1.浏览药品信息  2.修改药品信息-------------\n\n");
		printf("-------------3.添加药品信息  4.删除药品信息-------------\n\n");
		printf("-------------5.查找药品信息  6.数据排序-----------------\n\n");
		printf("-------------7.统计药品信息  8.账户管理系统-------------\n\n");
		printf("========================0.退出==========================\n\n");
		printf("========================================================\n\n");
		printf("请在0-7中选择，以回车键结束\n\n");
	    scanf("%d",&x);
		system("cls");
	    switch(x)
		{
	      case 1:
		    print_drug(&drug[0]);
			system("pause");
			system("cls");
	      	break;
	      case 2:
    		loaddrug();
	    	modify_drug(&drug[0]);
			system("cls");
	    	break;
          case 3:
	    	loaddrug();
	    	input_drug(&drug[m]);
			system("cls");
	     	break;
          case 4:
		    loaddrug();
		    delet_drug(&drug[0]);
			system("cls");
		    break;
	      case 5:
		    loaddrug();
		    search_drug(&drug[0]);
			system("cls");
		    break;
		  case 6:
			  sort_drug(&drug[0]);
			  break;
		  case 7:
			  loaddrug();
			  statistics_drug();
			  system("cls");
			  break;
		  case 8:
			  account();
			  break;
	      case 0:
		    break;
		  default:
			  {
				  printf("指令错误\n");
				  system("pause");
			  }
		}
	}while(x!=0);
}
//账户管理系统
void account()
{
	int x;
	do
	{
		printf("------------------欢迎进入账户管理系统------------------\n\n");
		printf("========================================================\n\n");
		printf("-------------1.浏览账户信息  2.修改账户信息-------------\n\n");
		printf("-------------3.添加账户信息  4.删除账户信息-------------\n\n");
		printf("-------------------------0.退出-------------------------\n\n");
		printf("========================================================\n\n");
		printf("请在0-4中选择，以回车键结束\n\n");
	    scanf("%d",&x);
		system("cls");
	    switch(x)
		{
	      case 1:
		    print_account(&acco[0]);
			system("pause");
			system("cls");
	      	break;
	      case 2:
    		loadaccount();
	    	modify_account(&acco[0]);
			system("cls");
	    	break;
          case 3:
	    	loadaccount();
	    	input_account(&acco[n]);
			system("cls");
	     	break;
          case 4:
		    loadaccount();
		    delet_account(&acco[0]);
			system("cls");
		    break;
	      case 0:
		    break;
		  default:
			  {
				  printf("指令错误\n");
				  system("pause");
			  }
		}
	}while(x!=0);
}
//载入药品信息
void loaddrug()
{
	read_drug(&drug[0]);
	if(m!=0)
	{
		print_drug(&drug[0]);
	}
}
//输入药品信息
void input_drug(struct druginfo *s)
{
	int y;
	char a[4]="yes";
	int flag=1;
	int id;
	for(;s<(&drug[0]+maxnum);++s)
	{
		printf("输入药品编号:");
		scanf("%d",&id);
		if(!isexisted(id))                              //判断店面号是否存在
		{
			s->id=id;
			printf("请输入药品名称:");
			scanf("%s",s->name);
			printf("请输入药品厂家:");
			scanf("%s",s->brand);
			printf("请输入药品价格:");
			scanf("%f",&s->price);
			printf("请输入药品数量:");
			scanf("%d",&s->num);
			m++;
			printf("第%d个信息已输入完毕，是否继续？Y键继续，0键结束。\n",m);
			scanf("%d",&y);
			getchar();
			if(y==0)
			{
				save_drug(&drug[0]);
				print_drug(&drug[0]);
				break;
			}
		}
		else
		{
			--s;
			printf("该药品存在！\n");
		}
	}
}
//读取药品信息
int read_drug(struct druginfo *s)
{
	FILE *fp,*fp1;
	int i;
	if((fp=fopen("druginfo.dat","rb"))==NULL)              //打开文件查看是否出错
	{
		printf("没有药品信息，请先输入药品信息！\n");        //打印出错提示
		getchar();
		return -1;
	}
	if((fp1=fopen("drug.dat","rb"))==NULL)              //打开文件查看是否出错
	{
		printf("创建文件失败！\n\n");
		getchar();
		return -1;
	}
	fscanf(fp1,"%d",&m);                                   //获得文件中药品信息的记录数
	fclose(fp1);                                           //关闭文件
	if(m==0)
	{
		printf("没有药品信息！请输入药品信息！\n");
	}
	else
	{
		for(i=0;i<m;i++,s++)
		{
			fread(s,sizeof(struct druginfo),1,fp);          //从文件中读取信息
		}
	}
	fclose(fp);                                             //关闭文件
	return i;
}
//输出药品信息
void print_drug(struct druginfo *s)
{
	int i;
	int min=0;
	int j;
	int k;
	struct druginfo temp;
	if(read_drug(&drug[0])!=-1)                      //调用读取文件函数
	{
		//对药品信息按照数量进行升序排列
		for(j=0;j<m;j++)
		{
			min=j;
			for(k=j+1;k<m;k++)
			{
				if(drug[min].id>drug[k].id)
				{
					min=k;
				}
			}
			if(j!=min)
			{
				temp=drug[j];
				drug[j]=drug[min];
				drug[min]=temp;
			}
		}
		printf(PRINT1);
		printf(PRINT2);
		for(i=0;i<m;i++,s++)
		{
			printf(PRINT);                              //打印信息
		}
		printf("\n");
		printf(PRINT1);
	}
	else
	{
		menu();
	}
}
//保存药品信息到文件
void save_drug(struct druginfo *s)
{
	FILE *fp,*fp1;
    int i;
    if((fp=fopen("druginfo.dat","wb"))==NULL)            //打开文件并判断是否出错
	{
		printf("创建文件失败！\n\n");
	    getchar();
    	return;
	}
	if((fp1=fopen("drug.dat","wb"))==NULL)              //打开文件并判断是否出错
	{
		printf("创建文件失败！\n\n");                   //打印出错提示
		getchar();
		return;
	}
	for(i=0;i<m;i++,s++)
	{
		if(fwrite(s,sizeof(struct druginfo),1,fp)==0)
		{
			printf("向文件输入数据失败！\n\n");
		}
	}
	fprintf(fp1,"%d",m);
	fclose(fp);                                           //关闭文件
	fclose(fp1);                                          //关闭文件
}
//修改药品信息
void modify_drug(struct druginfo *s)
{
	int drug_id;
	char drug_name[20];
	char drug_brand[20];
	float drug_price;
	int drug_num;
	int flag=0,n,i,k;
	float b=0;
	unsigned int a=0;
	while(1)
	{
		do
		{
			printf("你要修改的药品编号为？输入后以回车键结束:\n");
			scanf("%d",&drug_id);
			for(i=0;i<m;i++,s++)
			{
				if(drug[i].id==drug_id)
				{
					flag=1;
					k=i;
				}
			}
			if(flag==0)
			{
				printf("没有该药品信息！\n");
			}
		}while(flag==0);
		if(flag==1)
		{
			printf("请选择修改的地方以回车键结束！\n");
			printf("1.修改药品编号\t\t2.修改药品名称\n\n3.修改药品价格\t\t4.修改药品数量\n\n5.修改药品厂家\t\t0.返回\n\n");
			printf("请在0-5中选择:\n\n");
			scanf("%d",&n);
		}
		if(n==0)
			break;
		else
		{
			switch(n)
			{
			case 1:
				printf("请输入药品编号:\n");
				scanf("%d",&drug_id);
				while(1)
				{
					if(!isexisted(drug_id))
					{
						drug[k].id=drug_id;
						break;
					}
					else
					{
						printf("该药品编号已存在！请重新输入:\n");
						scanf("%d",&drug_id);
					}
				}
				break;
			case 2:
				printf("请输入药品名称:\n");
				scanf("%s",drug_name);
				strcpy(drug[k].name,drug_name);
				break;
			case 3:
				printf("请输入药品价格:\n");
				scanf("%f",&drug_price);
				drug[k].price=drug_price;
				break;
			case 4:
				printf("请输入药品数量:\n");
				scanf("%d",&drug_num);
				drug[k].num=drug_num;
				break;
			case 5:
				printf("请输入药品厂家:\n");
				scanf("%s",drug_brand);
				strcpy(drug[k].brand,drug_brand);
			case 0:
				break;
			default:
				{
					printf("指令错误\n");
					system("pause");
				}
			}
			printf("修改成功！\n");
			save_drug(&drug[0]);
			system("pause");
			system("cls");
			print_drug(&drug[0]);
			break;
		}
	}
}
//删除药品信息
void delet_drug(struct druginfo *s)
{
	int i,j,id;
	int flag=1;
	char c[3];
	do
	{
		do
		{
			printf("请输入药品编号");
			scanf("%d",&id);
			if(!isexisted(id))
			{
				flag=1;
				printf("无该药品信息");
			}
			else
			{
				flag=0;
			}
		}while(flag);
		read_drug(&drug[0]);
		for(i=0;i<m;i++)
		{
			if(drug[i].id==id)
			{
				for(j=i;j<m;j++)
				{
					drug[j]=drug[j+1];
				}
			}
		}
		m--;
		printf("删除成功，是否继续删除?\n");
		printf("请键入yes或no以回车结束\n");
		scanf("%s",c);
		save_drug(&drug[0]);
	}while(strcmp(c,"yes")==0);
}
//查找药品信息
void search_drug(struct druginfo *s)
{
	int n,i,k;
	float min,max;
	int drug_id;
	char drug_name[20];
	char drug_brand[20];
	char c[3];
	do
	{
		k=0;
		printf("请选择查找方式:\n\n");                    //打印查询方式菜单
		printf("1.按药品编号查询\t\t2.按药品名称查询\n3.按药品厂家查询\t\t4.按价格区间查询\n0.返回\n\n");
		printf("请从0-4中选择:\n\n");
		scanf("%d",&n);                                    //读取查找方式
		if(n==0)
			break;
		switch(n)
		{
		case 1:
			printf("请输入药品编号:\n");
			scanf("%d",&drug_id);
			for(i=0;i<m;i++)
			{
				if(drug[i].id==drug_id)
				{
					si[k]=drug[i];
					k++;
				}
			}
			break;
		case 2:
			printf("请输入品药名称:\n");
			scanf("%s",drug_name);
			for(i=0;i<m;i++)
			{
				if(strcmp(drug[i].name,drug_name)==0)
				{
					si[k]=drug[i];
					k++;
				}
			}
			break;
		case 3:
			printf("请输入药品厂家:");
			scanf("%s",drug_brand);
			for(i=0;i<m;i++)
			{
				if(strcmp(drug[i].brand,drug_brand)==0)
				{
					si[k]=drug[i];
					k++;
				}
			}
			break;
		case 4:
			printf("请输入价格区间:");
			scanf("%f%f",&min,&max);
			for(i=0;i<m;i++)
			{
				if(drug[i].price<=max&&drug[i].price>=min)
				{
					si[k]=drug[i];
					k++;
				}
			}
			break;
		case 0:
			break;
		default:
			{
				printf("指令错误\n");
				system("pause");
			}
		}
		system("cls");
		if(k==0)
		{
			printf("================================================\n");
			printf("\n没有你要查找的内容！\n");
			printf("================================================\n");
		}
		else
		{
			printf("=============================================================\n");
			printf("药品编号\t药品名称\t药品厂家\t药品价格\t药品数量\n");
			for(i=0;i<k;i++)
			{
				printf("%-16d%-16s%-16s%-16.2f%-8d\n",si[i].id,si[i].name,si[i].brand,si[i].price,si[i].num);
			}
			printf("==============================================================\n");
			printf("\n以上为查找内容！\n");
		}
		printf("是否继续查找？请键入yes或no以回车键结束:\n");
		scanf("%s",c);
	}while(strcmp(c,"yes")==0);                          //判断结束
}
//数据排序
void sort_drug(struct druginfo *s)
{
	int i;
	int min=0;
	int j;
	int k;
	struct druginfo temp;
	int c;
	printf("--------------------请选择排序方式--------------------\n\n");
	printf("\t1.编号升序\t2.编号降序\n");
	printf("\t3.价格升序\t4.价格降序\n");
	printf("\t5.数量升序\t6.数量降序\n");
	printf("\t0.退出\n");
	printf("请从0-6中选择:\n\n");
	scanf("%d",&c);
	system("cls");
	switch(c)
	{
	case 1:
		if(read_drug(&drug[0])!=-1)                      //调用读取文件函数
		{
		//对药品信息按照编号进行升序排列
		for(j=0;j<m;j++)
		{
			min=j;
			for(k=j+1;k<m;k++)
			{
				if(drug[min].id>drug[k].id)
				{
					min=k;
				}
			}
			if(j!=min)
			{
				temp=drug[j];
				drug[j]=drug[min];
				drug[min]=temp;
			}
		}
		printf(PRINT1);
		printf(PRINT2);
		for(i=0;i<m;i++,s++)
		{
			printf(PRINT);                              //打印信息
		}
		printf("\n");
		printf(PRINT1);
		}
		break;
	case 2:
		if(read_drug(&drug[0])!=-1)                      //调用读取文件函数
		{
		//对药品信息按照编号进行降序排列
		for(j=0;j<m;j++)
		{
			min=j;
			for(k=j+1;k<m;k++)
			{
				if(drug[min].id<drug[k].id)
				{
					min=k;
				}
			}
			if(j!=min)
			{
				temp=drug[j];
				drug[j]=drug[min];
				drug[min]=temp;
			}
		}
		printf(PRINT1);
		printf(PRINT2);
		for(i=0;i<m;i++,s++)
		{
			printf(PRINT);                              //打印信息
		}
		printf("\n");
		printf(PRINT1);
		}
		break;
	case 3:
		if(read_drug(&drug[0])!=-1)                      //调用读取文件函数
		{
		//对药品信息按照价格进行升序排列
		for(j=0;j<m;j++)
		{
			min=j;
			for(k=j+1;k<m;k++)
			{
				if(drug[min].price>drug[k].price)
				{
					min=k;
				}
			}
			if(j!=min)
			{
				temp=drug[j];
				drug[j]=drug[min];
				drug[min]=temp;
			}
		}
		printf(PRINT1);
		printf(PRINT2);
		for(i=0;i<m;i++,s++)
		{
			printf(PRINT);                              //打印信息
		}
		printf("\n");
		printf(PRINT1);
		}
		break;
	case 4:
		if(read_drug(&drug[0])!=-1)                      //调用读取文件函数
		{
		//对药品信息按照价格进行降序排列
		for(j=0;j<m;j++)
		{
			min=j;
			for(k=j+1;k<m;k++)
			{
				if(drug[min].price<drug[k].price)
				{
					min=k;
				}
			}
			if(j!=min)
			{
				temp=drug[j];
				drug[j]=drug[min];
				drug[min]=temp;
			}
		}
		printf(PRINT1);
		printf(PRINT2);
		for(i=0;i<m;i++,s++)
		{
			printf(PRINT);                              //打印信息
		}
		printf("\n");
		printf(PRINT1);
		}
		break;
	case 5:
		if(read_drug(&drug[0])!=-1)                      //调用读取文件函数
		{
		//对药品信息按照数量进行升序排列
		for(j=0;j<m;j++)
		{
			min=j;
			for(k=j+1;k<m;k++)
			{
				if(drug[min].num>drug[k].num)
				{
					min=k;
				}
			}
			if(j!=min)
			{
				temp=drug[j];
				drug[j]=drug[min];
				drug[min]=temp;
			}
		}
		printf(PRINT1);
		printf(PRINT2);
		for(i=0;i<m;i++,s++)
		{
			printf(PRINT);                              //打印信息
		}
		printf("\n");
		printf(PRINT1);
		}
		break;
	case 6:
		if(read_drug(&drug[0])!=-1)                      //调用读取文件函数
		{
		//对药品信息按照数量进行降序排列
		for(j=0;j<m;j++)
		{
			min=j;
			for(k=j+1;k<m;k++)
			{
				if(drug[min].num<drug[k].num)
				{
					min=k;
				}
			}
			if(j!=min)
			{
				temp=drug[j];
				drug[j]=drug[min];
				drug[min]=temp;
			}
		}
		printf(PRINT1);
		printf(PRINT2);
		for(i=0;i<m;i++,s++)
		{
			printf(PRINT);                              //打印信息
		}
		printf("\n");
		printf(PRINT1);
		}
		break;
	case 0:
		break;
	default:
		{
			printf("指令错误\n");
			system("pause");
		}
	}
	system("pause");
	system("cls");
}
//统计药品信息
void statistics_drug()
{
	int x,i;
	int num;
	char brand[20];
	printf("请选择统计方式:\n");
	printf("1.数量\t2.厂家\t0.返回\n");
	scanf("%d",&x);
	system("cls");
	switch(x)
	{
	case 1:
		printf("请输入目标数量:");
		scanf("%d",&num);
		printf(PRINT1);
	    printf(PRINT2);
		for(i=0;i<m;i++)
		{
			if(drug[i].num<=num)
			{
				printf("%-16d%-16s%-16s%-16.2f%-8d\n",drug[i].id,drug[i].name,drug[i].brand,drug[i].price,drug[i].num);
			}
		}
		printf(PRINT1);
		printf("这些药品数量不足，请尽快购入！！\n");
		system("pause");
		break;
	case 2:
		printf("请输入目标厂家:");
		scanf("%s",brand);
		printf(PRINT1);
	    printf(PRINT2);
		for(i=0;i<m;i++)
		{
			if(!strcmp(drug[i].brand,brand))
			{
				printf("%-16d%-16s%-16s%-16.2f%-8d\n",drug[i].id,drug[i].name,drug[i].brand,drug[i].price,drug[i].num);
			}
		}
		printf(PRINT1);
		printf("这些药品来自于%s\n",brand);
		system("pause");
		break;
	case 0:
		break;
	default:
		{
			printf("指令错误\n");
			system("pause");
		}
	}
}
//判断药品是否存在
int isexisted(int drugid)
{
	int f=0;
	int i;
	for(i=0;i<m;i++)
	{
		if(drug[i].id==drugid)
		{
			f=1;
			return f;
		}
	}
	return f;
}
//载入账户信息
void loadaccount()
{
	read_account(&acco[0]);
	if(n!=0)
	{
		print_account(&acco[0]);
	}
}
//输入账户信息
void input_account(struct account *p)
{
	int y;
	char a[4]="yes";
	int flag=1;
	char admin[20];
	for(;p<(&acco[0]+10);++p)
	{
		printf("输入账户名:");
		scanf("%s",admin);
		if(!isexisted1(admin))                              //判断店面号是否存在
		{
			strcpy(p->admin,admin);
			printf("请输入密码:");
			scanf("%s",p->password);
			printf("请输入姓名:");
			scanf("%s",p->name);
			printf("请输入电话号码:");
			scanf("%s",p->phonenum);
			printf("请输入备注:");
			scanf("%s",p->remark);
			n++;
			printf("第%d个账户已添加完毕，是否继续？Y键继续，0键结束。\n",n);
			scanf("%d",&y);
			getchar();
			if(y==0)
			{
				save_account(&acco[0]);
				print_account(&acco[0]);
				break;
			}
		}
		else
		{
			--p;                                 //指针回退
			printf("该账户存在！\n");
		}
	}
}
//读取药品信息
int read_account(struct account *p)
{
	FILE *fp,*fp1;
	int i;
	if((fp=fopen("accountinfo.dat","rb"))==NULL)              //打开文件查看是否出错
	{
		printf("没有账户信息，请先输入账户信息！\n");        //打印出错提示
		getchar();
		return -1;
	}
	if((fp1=fopen("account.dat","rb"))==NULL)              //打开文件查看是否出错
	{
		getchar();
		printf("创建文件失败！\n\n");
		return -1;
	}
	fscanf(fp1,"%d",&n);                                   //获得文件中药品信息的记录数
	fclose(fp1);                                           //关闭文件
	if(n==0)
	{
		printf("没有账户信息！请输入账户信息！\n");
	}
	else
	{
		for(i=0;i<n;i++,p++)
		{
			fread(p,sizeof(struct account),1,fp);          //从文件中读取信息
		}
	}
	fclose(fp);                                             //关闭文件
	return i;
}
//输出账户信息
void print_account(struct account *p)
{
	int i;
	if(read_account(&acco[0])!=-1)                      //调用读取文件函数
	{
		//输出文件中的账户
		printf(PRINT1);
		printf(PRINT3);
		for(i=0;i<n;i++,p++)
		{
			printf(PRINT4);                              //打印信息
		}
		printf("\n");
		printf(PRINT1);
	}
	else
	{
		menu();
	}
}
//保存帐户信息到文件
void save_account(struct account *p)
{
	FILE *fp,*fp1;
    int i;
    if((fp=fopen("accountinfo.dat","wb"))==NULL)            //打开文件并判断是否出错
	{
		printf("创建文件失败！\n\n");
	    getchar();
    	return;
	}
	if((fp1=fopen("account.dat","wb"))==NULL)              //打开文件并判断是否出错
	{
		printf("创建文件失败！\n\n");                   //打印出错提示
		getchar();
		return;
	}
	for(i=0;i<n;i++,p++)
	{
		if(fwrite(p,sizeof(struct account),1,fp)==0)
		{
			printf("向文件输入数据失败！\n\n");
		}
	}
	fprintf(fp1,"%d",n);
	fclose(fp);                                           //关闭文件
	fclose(fp1);                                          //关闭文件
}
//修改账户信息
void modify_account(struct account *p)
{
	char admin[20];
	char password[20];
	char name[20];
	char phonenum[20];
	char remark[100];
	int flag=0,x,i,k;
	float b=0;
	unsigned int a=0;
	while(1)
	{
		do
		{
			printf("你要修改的帐户为？输入后以回车键结束:\n");
			scanf("%s",admin);
			for(i=0;i<n;i++,p++)
			{
				if(!strcmp(acco[i].admin,admin))
				{
					flag=1;
					k=i;
				}
			}
			if(flag==0)
			{
				printf("没有该药品信息！\n");
			}
		}while(flag==0);
		if(flag==1)
		{
			printf("请选择修改的地方以回车键结束！\n");
			printf("1.修改帐户名\t\t2.修改帐户密码\n\n3.修改姓名\t\t4.修改电话号码\n\n5.修改备注\t\t0.返回\n\n");
			printf("请在0-5中选择:\n\n");
			scanf("%d",&x);
		}
		if(n==0)
			break;
		else
		{
			switch(x)
			{
			case 1:
				printf("请输入帐户名称:\n");
				scanf("%s",admin);
				while(1)
				{
					if(!isexisted1(admin))
					{
						strcpy(acco[k].admin,admin);
						break;
					}
					else
					{
						printf("该帐户已存在！请重新输入:\n");
						scanf("%s",admin);
					}
				}
				break;
			case 2:
				printf("请输入帐户密码:\n");
				scanf("%s",password);
				strcpy(acco[k].password,password);
				break;
			case 3:
				printf("请输入姓名:\n");
				scanf("%s",name);
				strcpy(acco[k].name,name);
				break;
			case 4:
				printf("请输入电话:\n");
				scanf("%s",phonenum);
				strcpy(acco[k].phonenum,phonenum);
				break;
			case 5:
				printf("请输入备注:\n");
				scanf("%s",remark);
				strcpy(acco[k].remark,remark);
				break;
			case 0:
				break;
			default:
				{
					printf("指令错误\n");
					system("pause");
				}
			}
			printf("修改成功！\n");
			save_account(&acco[0]);
			system("pause");
			system("cls");
			print_account(&acco[0]);
			break;
		}
	}
}
//删除药品信息
void delet_account(struct account *p)
{
	int i,j;
	char admin[20];
	int flag=1;
	char c[3];
	do
	{
		do
		{
			printf("请输入账户名称:");
			scanf("%s",admin);
			if(!isexisted1(admin))
			{
				flag=1;
				printf("无该账户信息！");
			}
			else
			{
				flag=0;
			}
		}while(flag);
		read_account(&acco[0]);
		for(i=0;i<n;i++)
		{
			if(!strcmp(acco[i].admin,admin))
			{
				for(j=i;j<n;j++)
				{
					acco[j]=acco[j+1];
				}
			}
		}
		n--;
		printf("删除成功，是否继续删除?\n");
		printf("请键入yes或no以回车结束.\n");
		scanf("%s",c);
		save_account(&acco[0]);
	}while(strcmp(c,"yes")==0);
}
//判断账户是否存在
int isexisted1(char admin[20])
{
	int f=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(!strcmp(acco[i].admin,admin))
		{
			f=1;
			return f;
		}
	}
	return f;
}
//登录系统
void password()
{
	int i=0;
	char ch='\0';
	char admin[20];
	char password[20];
	printf("请输入帐号:");
	scanf("%s",admin);
	printf("请输入密码:");
	while(ch!='\r')
	{
		ch=getch();
		if(ch=='\r')
		{
			password[i]='\0';
			break;
		}
		if(ch!='\b')
		{
			putchar('*');
			password[i]=ch;
			i++;
		}
		else
		{
			putchar('\b');
			putchar('\0');
			putchar('\b');
		}
	}
	system("cls");
	if(read_account(&acco[0])!=-1)                      //调用读取文件函数
	{
		for(i=0;i<n;i++)
		{
			if((strcmp(acco[i].admin,admin)==0&&strcmp(acco[i].password,password)==0)||(strcmp(admin,"admin")==0&&strcmp(password,"password")==0))
			{
				printf("\n");
				menu();
			}
		}
	}
}
int main()
{
	printf("--------------欢迎进入药店管理系统--------------\n\n");
	password();
	return 0;
}

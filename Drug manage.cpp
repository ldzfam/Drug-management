// Drug manage.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define PRINT "%-16d%-16s%-16s%-16.2f%-8d\n",s->id,s->name,s->brand,s->price,s->num
#define PRINT1 "=========================================================================\n"
#define PRINT2 "ҩƷ���\tҩƷ����\tҩƷ����\tҩƷ�۸�\tҩƷ����\n"
#define PRINT3 "�˻�����\t�˻�����\t����\t�绰����\t��ע\n"
#define PRINT4 "%-16s%-16s%-8s%-16s%-16s\n",p->admin,p->password,p->name,p->phonenum,p->remark
#define maxnum 100
//ҩƷ����
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
//�ʻ�����
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
	int id;                    //���
	char name[20];             //����
	char brand[20];            //Ʒ��
	float price;               //�۸�
	int num;                   //����
}drug[100],si[100];
struct account
{
	char admin[20];            //�˻�
	char password[20];         //����
	char name[20];             //����
	char phonenum[20];         //�绰
	char remark[100];         //��ע
}acco[10];
int n=0,m=0;
//��ʾϵͳ������
void menu()
{
	int x;
	do
	{
		printf("------------------��ӭ����ҩ�����ϵͳ------------------\n\n");
		printf("========================================================\n\n");
		printf("-------------1.���ҩƷ��Ϣ  2.�޸�ҩƷ��Ϣ-------------\n\n");
		printf("-------------3.���ҩƷ��Ϣ  4.ɾ��ҩƷ��Ϣ-------------\n\n");
		printf("-------------5.����ҩƷ��Ϣ  6.��������-----------------\n\n");
		printf("-------------7.ͳ��ҩƷ��Ϣ  8.�˻�����ϵͳ-------------\n\n");
		printf("========================0.�˳�==========================\n\n");
		printf("========================================================\n\n");
		printf("����0-7��ѡ���Իس�������\n\n");
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
				  printf("ָ�����\n");
				  system("pause");
			  }
		}
	}while(x!=0);
}
//�˻�����ϵͳ
void account()
{
	int x;
	do
	{
		printf("------------------��ӭ�����˻�����ϵͳ------------------\n\n");
		printf("========================================================\n\n");
		printf("-------------1.����˻���Ϣ  2.�޸��˻���Ϣ-------------\n\n");
		printf("-------------3.����˻���Ϣ  4.ɾ���˻���Ϣ-------------\n\n");
		printf("-------------------------0.�˳�-------------------------\n\n");
		printf("========================================================\n\n");
		printf("����0-4��ѡ���Իس�������\n\n");
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
				  printf("ָ�����\n");
				  system("pause");
			  }
		}
	}while(x!=0);
}
//����ҩƷ��Ϣ
void loaddrug()
{
	read_drug(&drug[0]);
	if(m!=0)
	{
		print_drug(&drug[0]);
	}
}
//����ҩƷ��Ϣ
void input_drug(struct druginfo *s)
{
	int y;
	char a[4]="yes";
	int flag=1;
	int id;
	for(;s<(&drug[0]+maxnum);++s)
	{
		printf("����ҩƷ���:");
		scanf("%d",&id);
		if(!isexisted(id))                              //�жϵ�����Ƿ����
		{
			s->id=id;
			printf("������ҩƷ����:");
			scanf("%s",s->name);
			printf("������ҩƷ����:");
			scanf("%s",s->brand);
			printf("������ҩƷ�۸�:");
			scanf("%f",&s->price);
			printf("������ҩƷ����:");
			scanf("%d",&s->num);
			m++;
			printf("��%d����Ϣ��������ϣ��Ƿ������Y��������0��������\n",m);
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
			printf("��ҩƷ���ڣ�\n");
		}
	}
}
//��ȡҩƷ��Ϣ
int read_drug(struct druginfo *s)
{
	FILE *fp,*fp1;
	int i;
	if((fp=fopen("druginfo.dat","rb"))==NULL)              //���ļ��鿴�Ƿ����
	{
		printf("û��ҩƷ��Ϣ����������ҩƷ��Ϣ��\n");        //��ӡ������ʾ
		getchar();
		return -1;
	}
	if((fp1=fopen("drug.dat","rb"))==NULL)              //���ļ��鿴�Ƿ����
	{
		printf("�����ļ�ʧ�ܣ�\n\n");
		getchar();
		return -1;
	}
	fscanf(fp1,"%d",&m);                                   //����ļ���ҩƷ��Ϣ�ļ�¼��
	fclose(fp1);                                           //�ر��ļ�
	if(m==0)
	{
		printf("û��ҩƷ��Ϣ��������ҩƷ��Ϣ��\n");
	}
	else
	{
		for(i=0;i<m;i++,s++)
		{
			fread(s,sizeof(struct druginfo),1,fp);          //���ļ��ж�ȡ��Ϣ
		}
	}
	fclose(fp);                                             //�ر��ļ�
	return i;
}
//���ҩƷ��Ϣ
void print_drug(struct druginfo *s)
{
	int i;
	int min=0;
	int j;
	int k;
	struct druginfo temp;
	if(read_drug(&drug[0])!=-1)                      //���ö�ȡ�ļ�����
	{
		//��ҩƷ��Ϣ��������������������
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
			printf(PRINT);                              //��ӡ��Ϣ
		}
		printf("\n");
		printf(PRINT1);
	}
	else
	{
		menu();
	}
}
//����ҩƷ��Ϣ���ļ�
void save_drug(struct druginfo *s)
{
	FILE *fp,*fp1;
    int i;
    if((fp=fopen("druginfo.dat","wb"))==NULL)            //���ļ����ж��Ƿ����
	{
		printf("�����ļ�ʧ�ܣ�\n\n");
	    getchar();
    	return;
	}
	if((fp1=fopen("drug.dat","wb"))==NULL)              //���ļ����ж��Ƿ����
	{
		printf("�����ļ�ʧ�ܣ�\n\n");                   //��ӡ������ʾ
		getchar();
		return;
	}
	for(i=0;i<m;i++,s++)
	{
		if(fwrite(s,sizeof(struct druginfo),1,fp)==0)
		{
			printf("���ļ���������ʧ�ܣ�\n\n");
		}
	}
	fprintf(fp1,"%d",m);
	fclose(fp);                                           //�ر��ļ�
	fclose(fp1);                                          //�ر��ļ�
}
//�޸�ҩƷ��Ϣ
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
			printf("��Ҫ�޸ĵ�ҩƷ���Ϊ��������Իس�������:\n");
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
				printf("û�и�ҩƷ��Ϣ��\n");
			}
		}while(flag==0);
		if(flag==1)
		{
			printf("��ѡ���޸ĵĵط��Իس���������\n");
			printf("1.�޸�ҩƷ���\t\t2.�޸�ҩƷ����\n\n3.�޸�ҩƷ�۸�\t\t4.�޸�ҩƷ����\n\n5.�޸�ҩƷ����\t\t0.����\n\n");
			printf("����0-5��ѡ��:\n\n");
			scanf("%d",&n);
		}
		if(n==0)
			break;
		else
		{
			switch(n)
			{
			case 1:
				printf("������ҩƷ���:\n");
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
						printf("��ҩƷ����Ѵ��ڣ�����������:\n");
						scanf("%d",&drug_id);
					}
				}
				break;
			case 2:
				printf("������ҩƷ����:\n");
				scanf("%s",drug_name);
				strcpy(drug[k].name,drug_name);
				break;
			case 3:
				printf("������ҩƷ�۸�:\n");
				scanf("%f",&drug_price);
				drug[k].price=drug_price;
				break;
			case 4:
				printf("������ҩƷ����:\n");
				scanf("%d",&drug_num);
				drug[k].num=drug_num;
				break;
			case 5:
				printf("������ҩƷ����:\n");
				scanf("%s",drug_brand);
				strcpy(drug[k].brand,drug_brand);
			case 0:
				break;
			default:
				{
					printf("ָ�����\n");
					system("pause");
				}
			}
			printf("�޸ĳɹ���\n");
			save_drug(&drug[0]);
			system("pause");
			system("cls");
			print_drug(&drug[0]);
			break;
		}
	}
}
//ɾ��ҩƷ��Ϣ
void delet_drug(struct druginfo *s)
{
	int i,j,id;
	int flag=1;
	char c[3];
	do
	{
		do
		{
			printf("������ҩƷ���");
			scanf("%d",&id);
			if(!isexisted(id))
			{
				flag=1;
				printf("�޸�ҩƷ��Ϣ");
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
		printf("ɾ���ɹ����Ƿ����ɾ��?\n");
		printf("�����yes��no�Իس�����\n");
		scanf("%s",c);
		save_drug(&drug[0]);
	}while(strcmp(c,"yes")==0);
}
//����ҩƷ��Ϣ
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
		printf("��ѡ����ҷ�ʽ:\n\n");                    //��ӡ��ѯ��ʽ�˵�
		printf("1.��ҩƷ��Ų�ѯ\t\t2.��ҩƷ���Ʋ�ѯ\n3.��ҩƷ���Ҳ�ѯ\t\t4.���۸������ѯ\n0.����\n\n");
		printf("���0-4��ѡ��:\n\n");
		scanf("%d",&n);                                    //��ȡ���ҷ�ʽ
		if(n==0)
			break;
		switch(n)
		{
		case 1:
			printf("������ҩƷ���:\n");
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
			printf("������Ʒҩ����:\n");
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
			printf("������ҩƷ����:");
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
			printf("������۸�����:");
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
				printf("ָ�����\n");
				system("pause");
			}
		}
		system("cls");
		if(k==0)
		{
			printf("================================================\n");
			printf("\nû����Ҫ���ҵ����ݣ�\n");
			printf("================================================\n");
		}
		else
		{
			printf("=============================================================\n");
			printf("ҩƷ���\tҩƷ����\tҩƷ����\tҩƷ�۸�\tҩƷ����\n");
			for(i=0;i<k;i++)
			{
				printf("%-16d%-16s%-16s%-16.2f%-8d\n",si[i].id,si[i].name,si[i].brand,si[i].price,si[i].num);
			}
			printf("==============================================================\n");
			printf("\n����Ϊ�������ݣ�\n");
		}
		printf("�Ƿ�������ң������yes��no�Իس�������:\n");
		scanf("%s",c);
	}while(strcmp(c,"yes")==0);                          //�жϽ���
}
//��������
void sort_drug(struct druginfo *s)
{
	int i;
	int min=0;
	int j;
	int k;
	struct druginfo temp;
	int c;
	printf("--------------------��ѡ������ʽ--------------------\n\n");
	printf("\t1.�������\t2.��Ž���\n");
	printf("\t3.�۸�����\t4.�۸���\n");
	printf("\t5.��������\t6.��������\n");
	printf("\t0.�˳�\n");
	printf("���0-6��ѡ��:\n\n");
	scanf("%d",&c);
	system("cls");
	switch(c)
	{
	case 1:
		if(read_drug(&drug[0])!=-1)                      //���ö�ȡ�ļ�����
		{
		//��ҩƷ��Ϣ���ձ�Ž�����������
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
			printf(PRINT);                              //��ӡ��Ϣ
		}
		printf("\n");
		printf(PRINT1);
		}
		break;
	case 2:
		if(read_drug(&drug[0])!=-1)                      //���ö�ȡ�ļ�����
		{
		//��ҩƷ��Ϣ���ձ�Ž��н�������
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
			printf(PRINT);                              //��ӡ��Ϣ
		}
		printf("\n");
		printf(PRINT1);
		}
		break;
	case 3:
		if(read_drug(&drug[0])!=-1)                      //���ö�ȡ�ļ�����
		{
		//��ҩƷ��Ϣ���ռ۸������������
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
			printf(PRINT);                              //��ӡ��Ϣ
		}
		printf("\n");
		printf(PRINT1);
		}
		break;
	case 4:
		if(read_drug(&drug[0])!=-1)                      //���ö�ȡ�ļ�����
		{
		//��ҩƷ��Ϣ���ռ۸���н�������
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
			printf(PRINT);                              //��ӡ��Ϣ
		}
		printf("\n");
		printf(PRINT1);
		}
		break;
	case 5:
		if(read_drug(&drug[0])!=-1)                      //���ö�ȡ�ļ�����
		{
		//��ҩƷ��Ϣ��������������������
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
			printf(PRINT);                              //��ӡ��Ϣ
		}
		printf("\n");
		printf(PRINT1);
		}
		break;
	case 6:
		if(read_drug(&drug[0])!=-1)                      //���ö�ȡ�ļ�����
		{
		//��ҩƷ��Ϣ�����������н�������
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
			printf(PRINT);                              //��ӡ��Ϣ
		}
		printf("\n");
		printf(PRINT1);
		}
		break;
	case 0:
		break;
	default:
		{
			printf("ָ�����\n");
			system("pause");
		}
	}
	system("pause");
	system("cls");
}
//ͳ��ҩƷ��Ϣ
void statistics_drug()
{
	int x,i;
	int num;
	char brand[20];
	printf("��ѡ��ͳ�Ʒ�ʽ:\n");
	printf("1.����\t2.����\t0.����\n");
	scanf("%d",&x);
	system("cls");
	switch(x)
	{
	case 1:
		printf("������Ŀ������:");
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
		printf("��ЩҩƷ�������㣬�뾡�칺�룡��\n");
		system("pause");
		break;
	case 2:
		printf("������Ŀ�곧��:");
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
		printf("��ЩҩƷ������%s\n",brand);
		system("pause");
		break;
	case 0:
		break;
	default:
		{
			printf("ָ�����\n");
			system("pause");
		}
	}
}
//�ж�ҩƷ�Ƿ����
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
//�����˻���Ϣ
void loadaccount()
{
	read_account(&acco[0]);
	if(n!=0)
	{
		print_account(&acco[0]);
	}
}
//�����˻���Ϣ
void input_account(struct account *p)
{
	int y;
	char a[4]="yes";
	int flag=1;
	char admin[20];
	for(;p<(&acco[0]+10);++p)
	{
		printf("�����˻���:");
		scanf("%s",admin);
		if(!isexisted1(admin))                              //�жϵ�����Ƿ����
		{
			strcpy(p->admin,admin);
			printf("����������:");
			scanf("%s",p->password);
			printf("����������:");
			scanf("%s",p->name);
			printf("������绰����:");
			scanf("%s",p->phonenum);
			printf("�����뱸ע:");
			scanf("%s",p->remark);
			n++;
			printf("��%d���˻��������ϣ��Ƿ������Y��������0��������\n",n);
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
			--p;                                 //ָ�����
			printf("���˻����ڣ�\n");
		}
	}
}
//��ȡҩƷ��Ϣ
int read_account(struct account *p)
{
	FILE *fp,*fp1;
	int i;
	if((fp=fopen("accountinfo.dat","rb"))==NULL)              //���ļ��鿴�Ƿ����
	{
		printf("û���˻���Ϣ�����������˻���Ϣ��\n");        //��ӡ������ʾ
		getchar();
		return -1;
	}
	if((fp1=fopen("account.dat","rb"))==NULL)              //���ļ��鿴�Ƿ����
	{
		getchar();
		printf("�����ļ�ʧ�ܣ�\n\n");
		return -1;
	}
	fscanf(fp1,"%d",&n);                                   //����ļ���ҩƷ��Ϣ�ļ�¼��
	fclose(fp1);                                           //�ر��ļ�
	if(n==0)
	{
		printf("û���˻���Ϣ���������˻���Ϣ��\n");
	}
	else
	{
		for(i=0;i<n;i++,p++)
		{
			fread(p,sizeof(struct account),1,fp);          //���ļ��ж�ȡ��Ϣ
		}
	}
	fclose(fp);                                             //�ر��ļ�
	return i;
}
//����˻���Ϣ
void print_account(struct account *p)
{
	int i;
	if(read_account(&acco[0])!=-1)                      //���ö�ȡ�ļ�����
	{
		//����ļ��е��˻�
		printf(PRINT1);
		printf(PRINT3);
		for(i=0;i<n;i++,p++)
		{
			printf(PRINT4);                              //��ӡ��Ϣ
		}
		printf("\n");
		printf(PRINT1);
	}
	else
	{
		menu();
	}
}
//�����ʻ���Ϣ���ļ�
void save_account(struct account *p)
{
	FILE *fp,*fp1;
    int i;
    if((fp=fopen("accountinfo.dat","wb"))==NULL)            //���ļ����ж��Ƿ����
	{
		printf("�����ļ�ʧ�ܣ�\n\n");
	    getchar();
    	return;
	}
	if((fp1=fopen("account.dat","wb"))==NULL)              //���ļ����ж��Ƿ����
	{
		printf("�����ļ�ʧ�ܣ�\n\n");                   //��ӡ������ʾ
		getchar();
		return;
	}
	for(i=0;i<n;i++,p++)
	{
		if(fwrite(p,sizeof(struct account),1,fp)==0)
		{
			printf("���ļ���������ʧ�ܣ�\n\n");
		}
	}
	fprintf(fp1,"%d",n);
	fclose(fp);                                           //�ر��ļ�
	fclose(fp1);                                          //�ر��ļ�
}
//�޸��˻���Ϣ
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
			printf("��Ҫ�޸ĵ��ʻ�Ϊ��������Իس�������:\n");
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
				printf("û�и�ҩƷ��Ϣ��\n");
			}
		}while(flag==0);
		if(flag==1)
		{
			printf("��ѡ���޸ĵĵط��Իس���������\n");
			printf("1.�޸��ʻ���\t\t2.�޸��ʻ�����\n\n3.�޸�����\t\t4.�޸ĵ绰����\n\n5.�޸ı�ע\t\t0.����\n\n");
			printf("����0-5��ѡ��:\n\n");
			scanf("%d",&x);
		}
		if(n==0)
			break;
		else
		{
			switch(x)
			{
			case 1:
				printf("�������ʻ�����:\n");
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
						printf("���ʻ��Ѵ��ڣ�����������:\n");
						scanf("%s",admin);
					}
				}
				break;
			case 2:
				printf("�������ʻ�����:\n");
				scanf("%s",password);
				strcpy(acco[k].password,password);
				break;
			case 3:
				printf("����������:\n");
				scanf("%s",name);
				strcpy(acco[k].name,name);
				break;
			case 4:
				printf("������绰:\n");
				scanf("%s",phonenum);
				strcpy(acco[k].phonenum,phonenum);
				break;
			case 5:
				printf("�����뱸ע:\n");
				scanf("%s",remark);
				strcpy(acco[k].remark,remark);
				break;
			case 0:
				break;
			default:
				{
					printf("ָ�����\n");
					system("pause");
				}
			}
			printf("�޸ĳɹ���\n");
			save_account(&acco[0]);
			system("pause");
			system("cls");
			print_account(&acco[0]);
			break;
		}
	}
}
//ɾ��ҩƷ��Ϣ
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
			printf("�������˻�����:");
			scanf("%s",admin);
			if(!isexisted1(admin))
			{
				flag=1;
				printf("�޸��˻���Ϣ��");
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
		printf("ɾ���ɹ����Ƿ����ɾ��?\n");
		printf("�����yes��no�Իس�����.\n");
		scanf("%s",c);
		save_account(&acco[0]);
	}while(strcmp(c,"yes")==0);
}
//�ж��˻��Ƿ����
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
//��¼ϵͳ
void password()
{
	int i=0;
	char ch='\0';
	char admin[20];
	char password[20];
	printf("�������ʺ�:");
	scanf("%s",admin);
	printf("����������:");
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
	if(read_account(&acco[0])!=-1)                      //���ö�ȡ�ļ�����
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
	printf("--------------��ӭ����ҩ�����ϵͳ--------------\n\n");
	password();
	return 0;
}

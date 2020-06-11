#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20
typedef struct LNode{		//结构体类型 
	char book[20];
	int booknumber;
	int nownumber;
	int maxnumber;
	char author[20];
	char authorhouse[20];
	int borrow[20];
	int time[20];
	struct LNode *next;
}LNode;
typedef struct LinkList{		//头结点 
	struct LNode *head;
}LinkList; 
void InitList(LinkList &L){
	L.head=(LNode *)malloc(sizeof(LNode));
	L.head->next=NULL;
}
void InputList(LinkList &la)//尾插法 输入图书信息 
{
	LNode *p,*q;int x;char s[20]; 
	q=la.head;
	while(q->next){
		q=q->next;
	}
	
	p=(LNode *)malloc(sizeof(LNode));
	
			printf("请输入该书籍的书号： ");
			scanf("%d",&x);
			p->booknumber=x;
			printf("\n"); 
	
			printf("请输入该书籍的书名： ");
			scanf("%s",&s);
			strcpy(p->book,s);
			printf("\n"); 
	
			printf("请输入该书籍的作者名： ");
			scanf("%s",&s);
			strcpy(p->author,s);
			printf("\n"); 
	
			printf("请输入该书籍的出版社： ");
			scanf("%s",&s);
			strcpy(p->authorhouse,s);
			printf("\n"); 
			
			printf("请输入该书籍的总存量： ");
			scanf("%d",&x);
			p->maxnumber=x;
			printf("\n"); 
	
			printf("请输入该书籍的现存量： ");
			scanf("%d",&x);
			p->nownumber=x;
			printf("\n"); 
	p->next=NULL;
	q->next=p;
	q=p;
}
void OutputList(LinkList &la)		//排序并输出图书信息 
{
	int n=0,i,j,t;		//用到的临时变量 
	char s[20];
	int data[100];
	LNode *p=la.head->next;
	LNode *q=p;
	if(p==NULL) {
		printf("书籍系统为空\n");	
		return ;
	}
	while(p!=NULL){				//将书号存储在data中进行比较 
		data[n]=p->booknumber;
		p=p->next;
		n++;
	}
	for(i=0;i<n;i++){			//使用冒泡排序进行比较书号 
		for(j=0;j<n-1;j++){
			if(data[j]>data[j+1]){
				t=data[j];
				data[j]=data[j+1];
				data[j+1]=t;
			}
		}
	}
	p=la.head->next;		//初始化p的位置 
	q=p;
	printf("输出： \n");
	for(i=0;i<n;i++){				//外循环n次输出n本书籍 
		while(p!=NULL){				//内循环查找符合data[i]的p->booknumber 获得p 
			if(p->booknumber==data[i]){
				break;
			}
			p=p->next;
		}									
		printf("书号：%d		",p->booknumber);		//输出该图书信息 
		printf("书名《%s》 \n",p->book);
		printf("作者名：%s	",p->author);
		printf("出版社：%s \n",p->authorhouse);
		printf("总存量：%d	",p->maxnumber);
		printf("现存量：%d \n",p->nownumber);
		printf("\n");
		p=q;											//重新赋值p 
	}
		
	printf("\n");
}
void Deletebook(LinkList &la){				//删除图书 
	char bookname[20]; 
	LNode *p=la.head;
	LNode *q=p->next;
	if(q==NULL) {
		printf("书籍系统为空\n");
		return ;
	}
	printf("请输入想要删除书籍的书名： ");
	scanf("%s",bookname); 
	printf("\n");
	while(q!=NULL)
	{
		if(strcmp(q->book,bookname)==0 ){		//找书名满足的q 
			p->next=q->next;					//删除节点 
			printf("书籍注销成功!\n");
			return  ;
		}
		p=p->next;
		q=q->next;
	}
	printf("书籍注销失败!\n");
}
void changebook(LinkList &la){				//修改图书信息 
	char bookname[20]; 
	char s[20];
	int data; 
	int key=1;
	int count=7;
	char a;
	char b='n';
	LNode *p=la.head;
	LNode *q=p->next;
	if(q==NULL) {
		printf("书籍系统为空\n");
		return ;
	}
	printf("请输入想要修改书籍信息的书名： ");
	scanf("%s",bookname); 
	printf("\n");
	while(q!=NULL)								//循环修改图书信息 
	{
		if(strcmp(q->book,bookname)==0 ){		//根据book找到q 
			printf("选择你想要修改的书籍信息\n");
			while(key){
				printf("1.书名\n");
				printf("2.书号\n");
				printf("3.作者名称\n");
				printf("4.出版社名称\n");
				printf("5.总存量\n");
				printf("6.现存量\n");
				printf("7.不进行修改\n");
				printf("请输入需要的功能号:"); 
				scanf("%d",&count);
				switch(count){					//选择需要修改的信息 
					case 1: printf("请输入新的书名：");scanf("%s",&s);strcpy(q->book,s);	break;
					case 2: printf("请输入新的书号：");scanf("%d",&data);q->booknumber=data;break;
					case 3: printf("请输入新的作者名称：");scanf("%s",&s);strcpy(q->author,s);break;
					case 4: printf("请输入新的出版社名称：");scanf("%s",&s);strcpy(q->authorhouse,s);break;
					case 5: printf("请输入新的总存量：");scanf("%d",&data);q->maxnumber=data;break;
					case 6: printf("请输入新的现存量：");scanf("%d",&data);q->nownumber=data;break;
					case 7: break;	
				}
				if(count==7) break; 
				printf("\n");
				printf("继续修改吗？请选择 \n");
			}
			printf("修改成功!\n");
			return  ;
		}
		p=p->next;
		q=q->next;
	}
	printf("修改失败!\n");
}
void borrowList(LinkList &la)				//图书借阅 
{
	char bookname[20]; 
	char borrowchar[5];
	char timechar[8];
	int borrow;
	int time;
	int i=0;
	LNode *p=la.head;
	LNode *q=p->next;
	LNode *w=p->next;
	if(q==NULL) {
		printf("书籍系统为空\n");
		return ;
	}
	printf("请输入想要借阅的书籍的书名： ");
	scanf("%s",bookname); 
	printf("\n");
	while(q!=NULL)						
	{
		if(strcmp(q->book,bookname)==0 ){			//找到book的q 
			if(q->nownumber==0)
			{
				printf("该书已被借完\n"); 
				return ;
			}
			if(q->nownumber>=1){					
			printf("请输入借阅者图书证号： ");
			scanf("%s",&borrowchar);
			borrow=atoi(borrowchar);
			while(q->borrow[i]<99999){				//找到borrow[20]中的空位进行输入 
				i++;
			}
			q->borrow[i]=borrow;
			printf("\n"); 
	
			printf("请输入归还日期： ");
			scanf("%s",&timechar);
			time=atoi(timechar);
			q->time[i]=time;
			printf("\n");
			printf("书籍借阅成功!\n");
			q->nownumber--;
			return  ; 
			} 
		}
		p=p->next;
		q=q->next;
	}
	printf("找不到该书籍!\n");
 } 
 void bookreturn(LinkList &la){				//图书归还 
 	char bookname[20]; 
 	char borrowchar[5];
 	int borrow;
 	int i=0,j; 
	LNode *p=la.head;
	LNode *q=p->next;
	if(q==NULL) {
		printf("书籍系统为空\n");
		return ;
	}
	printf("请输入想要归还的书籍的书名： ");
	scanf("%s",bookname); 
	printf("\n");
	while(q!=NULL)
	{
		if(strcmp(q->book,bookname)==0 ){			//找到book的q 
			if(q->nownumber==q->maxnumber)
			{
				printf("该书没有被借走\n"); 
				return ;
			}
			if(q->nownumber<q->maxnumber){
			printf("请输入借阅者图书证号： ");
			scanf("%s",&borrowchar);
			borrow=atoi(borrowchar);
			for(i=0;i<20;i++){
				if(q->borrow[i]==borrow)		//找到borrow的q并覆盖删除 
				{			
					q->borrow[i]=99999999;
					q->time[i]=99999999;
				break;	
				}
			}
			printf("\n"); 
			printf("书籍归还成功!\n");
			q->nownumber++;
			return  ; 
			} 
		}
		p=p->next;
		q=q->next;
	}
	printf("找不到该书籍!\n");
 }
 void findbook(LinkList &la){		//查找书籍 
	LNode *p=la.head;
	LNode *q=p->next;
	char s1[20];
	int  booknumber,i;
	int key;
	if(q==NULL) {
		printf("书籍系统为空\n");
		return ;
	}
	printf("请选择想要用什么查询书籍信息：\n");
	printf("1.书名\n");
	printf("2.书号\n");
	printf("3.作者\n");
	printf("4.出版社\n");
	printf("请输入功能号："); 
	scanf("%d",&key); 			//输入功能号，确定查找方式 
	if(key==1){
		printf("请输入书名："); 
		scanf("%s",s1);
		printf("\n");
		while(q!=NULL){
			if(strcmp(q->book,s1)==0){			//查找book与输入的字符串相同的q 
				break;
			}
			q=q->next;
		}
	}
	if(key==2){
		printf("请输入书号："); 
		scanf("%d",&booknumber);
		printf("\n");
		while(q!=NULL){
			if(q->booknumber==booknumber){		//查找booknumber与输入的字符串相同的q
				break;
			}
			q=q->next;
		}
	}
	if(key==3){
		printf("请输入作者名："); 
		scanf("%s",s1);
		printf("\n");
		while(q!=NULL){
			if(strcmp(q->author,s1)==0){		//查找author与输入的字符串相同的q
				 ;
			}
			q=q->next;
		}
	}
	if(key==4){
		printf("请输入出版社名："); 		
		scanf("%s",s1);
		printf("\n");
		while(q!=NULL){
			if(strcmp(q->authorhouse,s1)==0){		//查找authorhouse与输入的字符串相同的q
				break;
			}
			q=q->next;
		}
	}
	if(q==NULL){
		printf("没找到\n");
		return ; 
	}
	printf("书号：%d		",q->booknumber);
	printf("书名《%s》 \n",q->book);
	printf("作者名：%s	",q->author);
	printf("出版社：%s \n",q->authorhouse);
	printf("总存量：%d	",q->maxnumber);
	printf("现存量：%d \n",q->nownumber);
	printf("\n");  
	for(i=0;i<max;i++)
	{
		if(q->borrow[i]!=NULL && q->borrow[i]<99999){
			printf("第%d个借书人\n",i+1);
			printf("借阅人借书证号：%d\n",q->borrow[i]); 
			printf("借阅人归还日期：%d\n",q->time[i]);
			printf("\n"); 
		}
	}					
}
int main(){
	LinkList L;
	L.head=(LNode *)malloc(sizeof(LNode));
	L.head->next=NULL;
	int n=1;
	while(n){
		printf("-------------------------------------------------\n");
		printf("/			  			/\n");
		printf("/		图书管理系统			/\n");
		printf("/			  			/\n");
		printf("/		功能1：图书信息录入		/\n");
		printf("/			  			/\n");
		printf("/		功能2：图书查询  		/\n");
		printf("/			  			/\n");
		printf("/		功能3：排序     		/\n");
		printf("/			  			/\n");
		printf("/		功能4：图书修改			/\n");
		printf("/			  			/\n");
		printf("/		功能5：图书删除			/\n");
		printf("/			  			/\n");
		printf("/		功能6：图书借阅			/\n");
		printf("/			  			/\n");
		printf("/		功能7：图书归还			/\n");
		printf("/			  			/\n");
		printf("/		功能8：退出图书管理系统		/\n");
		printf("/			  			/\n");
		printf("-------------------------------------------------\n");
		printf("选择需要使用功能的功能号："); 
	scanf("%d",&n);
	printf("\n");
	switch(n){
		case 1: InputList(L); break;						//图书录入 
		case 2: findbook(L);  break;						//查询图书 
		case 3: OutputList(L); break;						//排序输出图书 
		case 4: changebook(L); break;						//修改图书信息 
		case 5: Deletebook(L); break;						//删除图书 
		case 6: borrowList(L); break;						//借阅图书 
		case 7: bookreturn(L); break;						//归还图书 
		case 8: printf("感谢您的使用!\n");exit(0);			//退出图书管理系统 
		default:
			printf("input error");
			break;
		}
	}
	return 0;
}

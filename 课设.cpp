#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20
typedef struct LNode{		//�ṹ������ 
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
typedef struct LinkList{		//ͷ��� 
	struct LNode *head;
}LinkList; 
void InitList(LinkList &L){
	L.head=(LNode *)malloc(sizeof(LNode));
	L.head->next=NULL;
}
void InputList(LinkList &la)//β�巨 ����ͼ����Ϣ 
{
	LNode *p,*q;int x;char s[20]; 
	q=la.head;
	while(q->next){
		q=q->next;
	}
	
	p=(LNode *)malloc(sizeof(LNode));
	
			printf("��������鼮����ţ� ");
			scanf("%d",&x);
			p->booknumber=x;
			printf("\n"); 
	
			printf("��������鼮�������� ");
			scanf("%s",&s);
			strcpy(p->book,s);
			printf("\n"); 
	
			printf("��������鼮���������� ");
			scanf("%s",&s);
			strcpy(p->author,s);
			printf("\n"); 
	
			printf("��������鼮�ĳ����磺 ");
			scanf("%s",&s);
			strcpy(p->authorhouse,s);
			printf("\n"); 
			
			printf("��������鼮���ܴ����� ");
			scanf("%d",&x);
			p->maxnumber=x;
			printf("\n"); 
	
			printf("��������鼮���ִ����� ");
			scanf("%d",&x);
			p->nownumber=x;
			printf("\n"); 
	p->next=NULL;
	q->next=p;
	q=p;
}
void OutputList(LinkList &la)		//�������ͼ����Ϣ 
{
	int n=0,i,j,t;		//�õ�����ʱ���� 
	char s[20];
	int data[100];
	LNode *p=la.head->next;
	LNode *q=p;
	if(p==NULL) {
		printf("�鼮ϵͳΪ��\n");	
		return ;
	}
	while(p!=NULL){				//����Ŵ洢��data�н��бȽ� 
		data[n]=p->booknumber;
		p=p->next;
		n++;
	}
	for(i=0;i<n;i++){			//ʹ��ð��������бȽ���� 
		for(j=0;j<n-1;j++){
			if(data[j]>data[j+1]){
				t=data[j];
				data[j]=data[j+1];
				data[j+1]=t;
			}
		}
	}
	p=la.head->next;		//��ʼ��p��λ�� 
	q=p;
	printf("����� \n");
	for(i=0;i<n;i++){				//��ѭ��n�����n���鼮 
		while(p!=NULL){				//��ѭ�����ҷ���data[i]��p->booknumber ���p 
			if(p->booknumber==data[i]){
				break;
			}
			p=p->next;
		}									
		printf("��ţ�%d		",p->booknumber);		//�����ͼ����Ϣ 
		printf("������%s�� \n",p->book);
		printf("��������%s	",p->author);
		printf("�����磺%s \n",p->authorhouse);
		printf("�ܴ�����%d	",p->maxnumber);
		printf("�ִ�����%d \n",p->nownumber);
		printf("\n");
		p=q;											//���¸�ֵp 
	}
		
	printf("\n");
}
void Deletebook(LinkList &la){				//ɾ��ͼ�� 
	char bookname[20]; 
	LNode *p=la.head;
	LNode *q=p->next;
	if(q==NULL) {
		printf("�鼮ϵͳΪ��\n");
		return ;
	}
	printf("��������Ҫɾ���鼮�������� ");
	scanf("%s",bookname); 
	printf("\n");
	while(q!=NULL)
	{
		if(strcmp(q->book,bookname)==0 ){		//�����������q 
			p->next=q->next;					//ɾ���ڵ� 
			printf("�鼮ע���ɹ�!\n");
			return  ;
		}
		p=p->next;
		q=q->next;
	}
	printf("�鼮ע��ʧ��!\n");
}
void changebook(LinkList &la){				//�޸�ͼ����Ϣ 
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
		printf("�鼮ϵͳΪ��\n");
		return ;
	}
	printf("��������Ҫ�޸��鼮��Ϣ�������� ");
	scanf("%s",bookname); 
	printf("\n");
	while(q!=NULL)								//ѭ���޸�ͼ����Ϣ 
	{
		if(strcmp(q->book,bookname)==0 ){		//����book�ҵ�q 
			printf("ѡ������Ҫ�޸ĵ��鼮��Ϣ\n");
			while(key){
				printf("1.����\n");
				printf("2.���\n");
				printf("3.��������\n");
				printf("4.����������\n");
				printf("5.�ܴ���\n");
				printf("6.�ִ���\n");
				printf("7.�������޸�\n");
				printf("��������Ҫ�Ĺ��ܺ�:"); 
				scanf("%d",&count);
				switch(count){					//ѡ����Ҫ�޸ĵ���Ϣ 
					case 1: printf("�������µ�������");scanf("%s",&s);strcpy(q->book,s);	break;
					case 2: printf("�������µ���ţ�");scanf("%d",&data);q->booknumber=data;break;
					case 3: printf("�������µ��������ƣ�");scanf("%s",&s);strcpy(q->author,s);break;
					case 4: printf("�������µĳ��������ƣ�");scanf("%s",&s);strcpy(q->authorhouse,s);break;
					case 5: printf("�������µ��ܴ�����");scanf("%d",&data);q->maxnumber=data;break;
					case 6: printf("�������µ��ִ�����");scanf("%d",&data);q->nownumber=data;break;
					case 7: break;	
				}
				if(count==7) break; 
				printf("\n");
				printf("�����޸�����ѡ�� \n");
			}
			printf("�޸ĳɹ�!\n");
			return  ;
		}
		p=p->next;
		q=q->next;
	}
	printf("�޸�ʧ��!\n");
}
void borrowList(LinkList &la)				//ͼ����� 
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
		printf("�鼮ϵͳΪ��\n");
		return ;
	}
	printf("��������Ҫ���ĵ��鼮�������� ");
	scanf("%s",bookname); 
	printf("\n");
	while(q!=NULL)						
	{
		if(strcmp(q->book,bookname)==0 ){			//�ҵ�book��q 
			if(q->nownumber==0)
			{
				printf("�����ѱ�����\n"); 
				return ;
			}
			if(q->nownumber>=1){					
			printf("�����������ͼ��֤�ţ� ");
			scanf("%s",&borrowchar);
			borrow=atoi(borrowchar);
			while(q->borrow[i]<99999){				//�ҵ�borrow[20]�еĿ�λ�������� 
				i++;
			}
			q->borrow[i]=borrow;
			printf("\n"); 
	
			printf("������黹���ڣ� ");
			scanf("%s",&timechar);
			time=atoi(timechar);
			q->time[i]=time;
			printf("\n");
			printf("�鼮���ĳɹ�!\n");
			q->nownumber--;
			return  ; 
			} 
		}
		p=p->next;
		q=q->next;
	}
	printf("�Ҳ������鼮!\n");
 } 
 void bookreturn(LinkList &la){				//ͼ��黹 
 	char bookname[20]; 
 	char borrowchar[5];
 	int borrow;
 	int i=0,j; 
	LNode *p=la.head;
	LNode *q=p->next;
	if(q==NULL) {
		printf("�鼮ϵͳΪ��\n");
		return ;
	}
	printf("��������Ҫ�黹���鼮�������� ");
	scanf("%s",bookname); 
	printf("\n");
	while(q!=NULL)
	{
		if(strcmp(q->book,bookname)==0 ){			//�ҵ�book��q 
			if(q->nownumber==q->maxnumber)
			{
				printf("����û�б�����\n"); 
				return ;
			}
			if(q->nownumber<q->maxnumber){
			printf("�����������ͼ��֤�ţ� ");
			scanf("%s",&borrowchar);
			borrow=atoi(borrowchar);
			for(i=0;i<20;i++){
				if(q->borrow[i]==borrow)		//�ҵ�borrow��q������ɾ�� 
				{			
					q->borrow[i]=99999999;
					q->time[i]=99999999;
				break;	
				}
			}
			printf("\n"); 
			printf("�鼮�黹�ɹ�!\n");
			q->nownumber++;
			return  ; 
			} 
		}
		p=p->next;
		q=q->next;
	}
	printf("�Ҳ������鼮!\n");
 }
 void findbook(LinkList &la){		//�����鼮 
	LNode *p=la.head;
	LNode *q=p->next;
	char s1[20];
	int  booknumber,i;
	int key;
	if(q==NULL) {
		printf("�鼮ϵͳΪ��\n");
		return ;
	}
	printf("��ѡ����Ҫ��ʲô��ѯ�鼮��Ϣ��\n");
	printf("1.����\n");
	printf("2.���\n");
	printf("3.����\n");
	printf("4.������\n");
	printf("�����빦�ܺţ�"); 
	scanf("%d",&key); 			//���빦�ܺţ�ȷ�����ҷ�ʽ 
	if(key==1){
		printf("������������"); 
		scanf("%s",s1);
		printf("\n");
		while(q!=NULL){
			if(strcmp(q->book,s1)==0){			//����book��������ַ�����ͬ��q 
				break;
			}
			q=q->next;
		}
	}
	if(key==2){
		printf("��������ţ�"); 
		scanf("%d",&booknumber);
		printf("\n");
		while(q!=NULL){
			if(q->booknumber==booknumber){		//����booknumber��������ַ�����ͬ��q
				break;
			}
			q=q->next;
		}
	}
	if(key==3){
		printf("��������������"); 
		scanf("%s",s1);
		printf("\n");
		while(q!=NULL){
			if(strcmp(q->author,s1)==0){		//����author��������ַ�����ͬ��q
				 ;
			}
			q=q->next;
		}
	}
	if(key==4){
		printf("���������������"); 		
		scanf("%s",s1);
		printf("\n");
		while(q!=NULL){
			if(strcmp(q->authorhouse,s1)==0){		//����authorhouse��������ַ�����ͬ��q
				break;
			}
			q=q->next;
		}
	}
	if(q==NULL){
		printf("û�ҵ�\n");
		return ; 
	}
	printf("��ţ�%d		",q->booknumber);
	printf("������%s�� \n",q->book);
	printf("��������%s	",q->author);
	printf("�����磺%s \n",q->authorhouse);
	printf("�ܴ�����%d	",q->maxnumber);
	printf("�ִ�����%d \n",q->nownumber);
	printf("\n");  
	for(i=0;i<max;i++)
	{
		if(q->borrow[i]!=NULL && q->borrow[i]<99999){
			printf("��%d��������\n",i+1);
			printf("�����˽���֤�ţ�%d\n",q->borrow[i]); 
			printf("�����˹黹���ڣ�%d\n",q->time[i]);
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
		printf("/		ͼ�����ϵͳ			/\n");
		printf("/			  			/\n");
		printf("/		����1��ͼ����Ϣ¼��		/\n");
		printf("/			  			/\n");
		printf("/		����2��ͼ���ѯ  		/\n");
		printf("/			  			/\n");
		printf("/		����3������     		/\n");
		printf("/			  			/\n");
		printf("/		����4��ͼ���޸�			/\n");
		printf("/			  			/\n");
		printf("/		����5��ͼ��ɾ��			/\n");
		printf("/			  			/\n");
		printf("/		����6��ͼ�����			/\n");
		printf("/			  			/\n");
		printf("/		����7��ͼ��黹			/\n");
		printf("/			  			/\n");
		printf("/		����8���˳�ͼ�����ϵͳ		/\n");
		printf("/			  			/\n");
		printf("-------------------------------------------------\n");
		printf("ѡ����Ҫʹ�ù��ܵĹ��ܺţ�"); 
	scanf("%d",&n);
	printf("\n");
	switch(n){
		case 1: InputList(L); break;						//ͼ��¼�� 
		case 2: findbook(L);  break;						//��ѯͼ�� 
		case 3: OutputList(L); break;						//�������ͼ�� 
		case 4: changebook(L); break;						//�޸�ͼ����Ϣ 
		case 5: Deletebook(L); break;						//ɾ��ͼ�� 
		case 6: borrowList(L); break;						//����ͼ�� 
		case 7: bookreturn(L); break;						//�黹ͼ�� 
		case 8: printf("��л����ʹ��!\n");exit(0);			//�˳�ͼ�����ϵͳ 
		default:
			printf("input error");
			break;
		}
	}
	return 0;
}

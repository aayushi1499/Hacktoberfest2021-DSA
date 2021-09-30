/* Report-7
To implement stack using array */
#include<stdio.h>
#include<stdlib.h>
#define size 10

int top=-1;

void s_push(int s[],int data);
int s_pop(int s[]);
void s_update(int s[]);
void s_peep(int s[]);
void s_traverse(int s[]);


int main()
{
int s[size];
int n,d,value;
do{
printf("\n\nenter choice:\n");
printf("1.push\n2.pop\n3.udpate\n4.traverse\n5.peep\n6.EXIT!\n");
scanf("%d",&n);
switch(n){

	case 1:
		printf("\nenter data:");
		scanf("%d",&d);
		s_push(s,d);
		break;
	
	case 2: d=s_pop(s);
		    printf("\npopped element is:%d",d);
		   break;
	case 3:s_update(s);
	       break;
	case 4:s_traverse(s);
	       break;
	case 5:s_peep(s);
	
	       break;       
	case 6: exit(1);
	default:
			printf("\nenter valid input");
			break;
			}

		
	} while (n!=6);
}

//push
void s_push(int s[],int data)
{
	if(top==size-1)
	{
	printf("\nstack overflow");
	return;
	}
	s[++top]=data;
	}

//pop
int s_pop(int s[])
{
int p;
if(top==-1)
{
  printf("\nunderflow\n");
  p=0;	
}

else 
{
	p=s[top];
	top--;
}
return p;
}
			
//traverse
void s_traverse(int s[])
{
	int k,back_stack[size];
 while(top!=-1)
     {
     	k++;
     	printf("%d\t",s[top]);
     	back_stack[k]=s[top];
     	top--;
     	
	 }
  	for(int i=k;i>0;i--)
  	{ 
  	top++;
  	s[top]=back_stack[k];
  	k--;
}
}
//peep
void s_peep(int s[])
{
int j,d;
	if(top==-1)
	{
	printf("\nstack is empty!");
	return;
	}
	int back_stack[size];
	printf("\nenter data:");
	scanf("%d",&d);
	int k=0,flag=0;
	for(j=top;j>=0;j--)
	{
		if(s[j]!=d)
		{
		back_stack[k++]=s[j];
		s[j]=0;
		}
		else 
		{
		flag=1;
		break;
		}		
		}

	if(flag==1)
	{
	printf("\n%d is present in stack!",d);
	}
	else
	{
	printf("\n%d is not present in stack!",d);
	}

k=k-1;
	//reconstruct stack
	for(j=j+1;j<=top;j++)
		s[j]=back_stack[k--];
}

//update
void s_update(int s[]){
int loc,d;
	if(top==-1){printf("\nstack is empty!");return;}
	int back_stack[size];
	printf("\nenter location:");
	scanf("%d",&loc);

	if((top-loc+1)<0){
		printf("element does not exist!");
		}

	else{printf("\nenter new value:");
	scanf("%d",&d);

	int k=0;
	for(int j=top;j>loc;j--)
		{back_stack[k++]=s[j];s[j]=0;}

	s[loc]=d;
k=k-1;	
	//reconstruct stack
	for(int j=loc+1;j<=top;j++)
		s[j]=back_stack[k--];
		}
}


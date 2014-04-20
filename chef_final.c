#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<unistd.h>

struct mcd
{
        long int my_msg_type;
        int dish_no[10];
        int quant[10];
        char identity;
        struct mcd *next;
}*head;

struct mcd *get_node()
{
        struct mcd *p;
        int i=0;
        p=(struct mcd*)malloc(sizeof(struct mcd));
        p->next = NULL;
        /*for(i=0;i<10;i++)
        {
        	p->dish_no[i]=0;
        	p->quant[i]=0;
        } */
        return p;
}

int main()
{
	int running=1;
	int msgid,i=0;;
	long int msg=0;
	struct mcd* try;
	try=NULL;
	
	msgid=msgget((key_t)1234, 0666 | IPC_CREAT);
	
	if(msgid == -1)
	{
		printf("Failed!!!");
		exit(0);
	}
		
	while(running)
	{
		if(msgrcv(msgid, (void *)&head,(sizeof(struct mcd)-4),msg,0) == -1)
		{
			printf("\nFailure!!!");
			exit(0);
		}
		try=get_node();
		
		try=head;
		while(try->dish_no[i]!=0)
		{
			printf("\n%d - ",try->dish_no[i]);
			printf("%d\n",try->quant[i]);
			i++;
		}	
		
	}
	
	if(msgctl(msgid, IPC_RMID, 0)==-1)
	{
		printf("Failed!!!");
		exit(0);
	}
	return(0);
}

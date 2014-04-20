#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/msg.h>


struct mcd
{
        long int my_msg_type;
        int dish_no[10];
        int quant[10];
        char identity;
        struct mcd *next;
} *head=NULL, *order=NULL, *end=NULL;

struct mcd *get_node()
{
        struct mcd *p;
        int i=0;
        p=(struct mcd*)malloc(sizeof(struct mcd));
        p->next = NULL;
        for(i=0;i<10;i++)
        {
        	p->dish_no[i]=0;
        	p->quant[i]=0;
        } 
        return p;
}

int main()
{
        int msgid, norder=0, i=0, j=0,k=1;
        char ch;
        struct mcd* try;
        while(k)
        {
                ch='y';
                order=get_node();
                while(ch == 'y' || ch == 'Y')
                {
                        printf("\nPlease enter the serial number of the dish you want to order : ");
                        scanf("%d", &(order->dish_no[i]));
                        printf("Please enter the quantity of the dish you want to order : ");
                        scanf("%d", &(order->quant[i]));
                        i++;
                        printf("Do you want to order more ? (y/n) : ");
                        scanf("%s", &ch);
                }
                if(head == NULL)
                {
                        head=order;
                        order->my_msg_type=1;
                        end=order;
                }
                else
                {
                        end->next=order;
                        end=order;
                }
                norder++;
                printf("%d\n",norder);
                try=get_node();
                try=head;
                
                while(try!=NULL)
                {
                	j=0;
                	while(try->dish_no[j]!=0)
                	{
                       		printf("%d - ", try->dish_no[j]);
                        	printf("%d\n", try->quant[j]);
                        	j++;
                        }
                        try=try->next;
                        printf("\n");
                }
                
                msgid=msgget((key_t)1234, 0666 | IPC_CREAT);
	
		if(msgid == -1)
		{
			printf("Failed!!!");
			exit(0);
		}
                
                if(msgsnd(msgid, (void *)&head, (sizeof(struct mcd)-4), 0) ==-1)
		{
			printf("\nFailure!!!!");
			exit(0);
		}
		
                if(norder == 2)
                        k=0;
                i=0;
        }
        return 0;
}

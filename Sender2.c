# include <stdio.h>
# include <stdlib.h>

# include "common.h"
# include <sys/msg.h>

int main()
{
        int msgid, i=0, j=0, size;
        char ch;
        struct mcd order;
        order.identity = 25;
        size = sizeof(struct mcd) - sizeof(long int);

        // setting up the msg queue
        msgid=msgget((key_t)1234, 0666 | IPC_CREAT);
        if(msgid == -1)
        {
                printf("msgid() Failed!!!");
                exit(0);
        }

        while(1)
        {
                ch='y';
                order.count=0;
                order.my_msg_type = 1;
                zero(order.dish_no);
                zero(order.quant);
                menu();
                while(ch == 'y' || ch == 'Y')
                {
                        printf("\nPlease enter the serial number of the dish you want to order : ");
                        scanf("%d", &(order.dish_no[order.count]));
                        printf("Please enter the quantity of the dish you want to order : ");
                        scanf("%d", &(order.quant[order.count]));
                        order.count++;
                        printf("Do you want to order more ? (y/n) : ");
                        scanf("%s", &ch);
                }
                //receipt(order.dish_no, order.quant, order.id);
                j=0;
                /*
                while(order.quant[j]>0)
                {
                	printf("\n%d\n",order.dish_no[j]);
                	printf("%d\n",order.quant[j]);
                	j++;
                }
                //sleep(10);*/

                if(msgsnd(msgid, (void *)&order, size, 0) == -1)
                {
                        printf("\nmsgsnd() Failure!!!!");
                        exit(0);
                }
                i=0;
                order.identity += 1;
                if(order.dish_no[0] <= 0)
                        break;
                system("clear");
        }
        return 0;
}

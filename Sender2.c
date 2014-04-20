# include <stdio.h>
# include <stdlib.h>
# include <sys/msg.h>

# include "common.h"

int main()
{
        int msgid, i=0, j=0, size;
        char ch;
        struct mcd order;
        order.identity = 75;
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
                order.my_msg_type = 1;
                zero(order.dish_no);
                zero(order.quant);
                menu();
                while(ch == 'y' || ch == 'Y')
                {
                        printf("\nPlease enter the serial number of the dish you want to order : ");
                        scanf("%d", &(order.dish_no[i]));
                        printf("Please enter the quantity of the dish you want to order : ");
                        scanf("%d", &(order.quant[i]));
                        i++;
                        printf("Do you want to order more ? (y/n) : ");
                        scanf("%s", &ch);
                }
                //receipt(order.dish_no, order.quant, order.id);

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

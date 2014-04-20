# include <stdio.h>
# include <stdlib.h>
# include <sys/msg.h>

# include "common.h"

int main()
{
        int msgid, msgid1, count=0, j, size;
        long int msg=0;
        struct mcd order;
        size = sizeof(struct mcd) - sizeof(long int);

        // setting up the msg queue
        msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
        if(msgid == -1)
        {
                printf("msgid() Failed!!!");
                exit(0);
        }
        msgid1 = msgget((key_t)1243, 0666 | IPC_CREAT);
        if(msgid1 == -1)
        {
                printf("2nd msgid() Failed!!!");
                exit(0);
        }

        while(1)
        {
                // Order received to be prepeared
                if(msgrcv(msgid, (void *)&order, size, msg, 0) == -1)
                {
                        printf("\nmsgrcv() Failure!!!");
                        exit(0);
                }

                j=0;
                printf("\nOrder being prepeared for : %d\n", order.identity);
                while(order.dish_no[j] > 0)
                {
                        printf("Dish No: %d", order.dish_no[j]);
                        printf("\nQuantity: %d\n", order.quant[j]);
                        j++;
                }
                sleep(5);

                // Order sent to be delivered.
                if(msgsnd(msgid1, (void *)&order, size, 0) == -1)
                {
                        printf("\nmsgsnd() Failure!!!!");
                        exit(0);
                }
                // count++;
                if(order.dish_no[0] <= 0)
                        break;
                system("clear");
        }

        if(msgctl(msgid, IPC_RMID, 0)==-1)
        {
                printf("Failed!!!");
                exit(0);
        }
        return(0);
}

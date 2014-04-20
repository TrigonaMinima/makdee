# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/msg.h>

# include "common.h"

int main()
{
        int msgid, i=0, count=0, j, size;
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

        while(1)
        {
                if(msgrcv(msgid, (void *)&order, size, msg, 0) == -1)
                {
                        printf("\nmsgrcv() Failure!!!");
                        exit(0);
                }

                j=0;
                while(j<i)
                {
                        printf("%d - ", order.dish_no[j]);
                        printf("Rs %d\n", order.quant[j]);
                        j++;
                }
                count++;
                if (count==2)
                        break;
        }

        if(msgctl(msgid, IPC_RMID, 0)==-1)
        {
                printf("Failed!!!");
                exit(0);
        }
        return(0);
}

# include <stdio.h>
# include <sys/msg.h>
# include <stdlib.h>


# include "common.h"

int
main()
{
        int msgid, j, size;
        long int msg=0;
        struct mcd delivery;
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
                if(msgrcv(msgid, (void *)&delivery, size, msg, 0) == -1)
                {
                        printf("\nmsgrcv() Failure!!!");
                        exit(0);
                }
                if(delivery.identity <= 0)
                        break;
                printf("Order completed : %d\n", delivery.identity);
                j=0;
                while(delivery.dish_no[j] > 0)
                {
                        printf("%d - ", delivery.dish_no[j]);
                        printf("Rs %d\n", delivery.quant[j]);
                        j++;
                }
        }
        return 0;
}
# include <stdio.h>
# include <stdlib.h>
# include <sys/msg.h>

# include "common.h"

int
main()
{
        int msgid, j, size;
        long int msg=0;
        struct mcd delivery;
        size = sizeof(struct mcd) - sizeof(long int);

        // setting up the msg queue
        msgid = msgget((key_t)1243, 0666 | IPC_CREAT);
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
                if(delivery.dish_no[0] <= 0)
                        break;
                printf("\nOrder completed : %d\n", delivery.identity);
                receipt(delivery.dish_no, delivery.quant, delivery.identity);
                system("clear");
        }
        return 0;
}

# include <stdio.h>
# include <stdlib.h>

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
        p=(struct mcd*)malloc(sizeof(struct mcd));
        p->next = NULL;
        return p;
}

int
main()
{
        int msgid, order_no=0, i=0, j=0;
        char ch;
        while(1)
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
                        end=order;
                }
                else
                {
                        end->next=order;
                        end=order;
                }
                order_no++;
                for(j=0; j<i; j++)
                {
                        printf("\n%d - ", order->dish_no[j]);
                        printf("%d\n", order->quant[j]);
                }
                if(order_no == 2)
                        break;
                i=0;
        }
        return 0;
}
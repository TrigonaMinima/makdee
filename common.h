
struct mcd
{
        long int my_msg_type;
        int dish_no[10];
        int quant[10];
        int identity;
        // char identity;
        // struct mcd *next;
};

void
zero(int arr[10])
{
        int i;
        for(i=0; i<10; i++)
                arr[i]=0;
}

void
menu()
{
        printf("Menu - \n");
        printf("#\tProd\t\t\tCost\n");
        printf("1\tMcAaloo\tRs 35\n");
        printf("2\tBig Mac\n" );
        printf("\n" );
        printf("\n" );
        printf("\n" );
        printf("\n" );
        printf("\n" );
        printf("\n" );
        printf("\n" );
}

void
receipt()
{}
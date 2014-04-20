
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
menu()
{
        printf("Menu - \n");
        printf("#\tProd\t\t\tCost\n");
        printf("1\tMcAaloo tikki\tRs 35\n");
}
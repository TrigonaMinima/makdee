
struct mcd
{
        long int my_msg_type;
        int dish_no[20];
        int quant[20];
        int identity;
};

void
zero(int arr[20])
{
        int i;
        for(i=0; i<20; i++)
                arr[i]=0;
}

char arr[20][20] = { "Econo-meal",
                                "Happy Meal",
                                "McAaloo",
                                "Big Mac",
                                "Cheezeburger",
                                "McChicken",
                                "McVeggie",
                                "McEgg",
                                "Egg McMuffin",
                                "Big Breakfast",
                                "Hotcakes",
                                "World Famous Fries",
                                "McCaffe Coffee",
                                "McCaffe Latte",
                                "Iced Tea",
                                "Diet Coke",
                                "Sprite",
                                "Straberry Sundae",
                                "McFlurry with Oreo",
                                "Soft Serve Cone"}

int price[20] = { 70, 100, 30, 120, 80, 60, 50, 35, 100, 50, 45, 60, 70, 70, 65, 55, 55, 95, 45, 20};

void
menu()
{
        printf("Menu - \n");
        printf("Burgers and Sandwiches\n");
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
{
        int j=0;
        printf("Your order details : %d\n", norder);
        printf("\nOrder ID : %d\n", order.identity);
        while(delivery.dish_no[j] > 0)
        {
                printf("%02d - ", delivery.dish_no[j]);
                printf("Rs %03.d\n", delivery.quant[j]);
                j++;
        }
}
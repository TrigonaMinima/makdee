
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

char arr[20][20] = { "Econo-meal", "Happy Meal", "McAaloo", 
                                "Big Mac", "Cheezeburger", "McChicken", 
                                "McVeggie", "McEgg", "Egg McMuffin", 
                                "Big Breakfast", "Hotcakes", "World Famous Fries", 
                                "McCaffe Coffee", "McCaffe Latte", "Iced Tea", 
                                "Diet Coke", "Sprite", "Straberry Sundae", 
                                "McFlurry with Oreo", "Soft Serve Cone"};

int price[20] = { 70, 100, 30, 120, 80, 60, 50, 35, 100, 50, 45, 60, 70, 70, 65, 55, 55, 95, 45, 20};

void
menu()
{
        int i;
        printf("Menu - \n");
        for (i = 0; i < 20; ++i)
        {
                printf("%s \t %-d\n", arr[i], price[i]);
        }
}

void
receipt()
{
        int j=0, sum;
        // printf("----------------------------------------------------------------------------------------\n");
        printf("Order ID : %d\n", order.identity);
        printf("\nOrder details : \n",);
        printf("#   Eatable\t Quantity\t Cost\n");
        while(delivery.dish_no[j] > 0)
        {
                printf("%2d. %s \t %03d\t %d", j, arr[delivery.dish_no[j]], delivery.quant[j], (delivery.quant[j]*price[delivery.dish_no[j]]));
                sum+=(delivery.quant[j]*price[delivery.dish_no[j]]);
                j++;
        }
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("Sum Total : %d\n", sum);
}
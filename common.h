
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

char arr[20][20] = { "1. Econo-meal", "2. Happy Meal", "3. McAaloo", 
                                "4. Big Mac", "5. Cheezeburger", "6. McChicken", 
                                "7. McVeggie", "8. McEgg Burger","9. McPaneer", 
                                "10. Breakfast", "11. Hotcakes", "12.Famous Fries", 
                                "13. McCaffe", "14. Choco Latte", "15. Ice Tea", 
                                "16. Diet Coke", "17. Soft Drink", "18. HCF Sundae", 
                                "19. McFlurry", "20. Soft Serve"};

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

void receipt(int dish_no[],int quant[],int id)
{
        int j=0, sum;
        // printf("----------------------------------------------------------------------------------------\n");
        printf("Order ID : %d\n", id);
        printf("\nOrder details : \n");
        printf("#   Eatable\t Quantity\t Cost\n");
        while(dish_no[j] > 0)
        {
                printf("%d %s \t %d\t %d", j, arr[dish_no[j]], quant[j], (quant[j]*price[dish_no[j]]));
                sum+=(quant[j]*price[dish_no[j]]);
                j++;
        }
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("Sum Total : %d\n", sum);
}



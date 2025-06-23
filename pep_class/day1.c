#include <stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<math.h>
void show_menu(){
    bool reddem;
    printf("water bottle , price = 10 rupees\n");
    printf("tea , price = 15 rupees\n");
    printf("coffee , price= 20 rupees\n");
}
int ordering(){
    int total_order_value =0;
     int ordering=1;
            while(ordering){
                printf("press 1 for water \n2 for tea or \n3 for coffee \n4 to qitting the order mode\n");
                int choice_2;
                scanf("%d",&choice_2);
                int quantity;
                switch (choice_2)
                {
                case 1:
                    printf ("enter the quantity of the water bottles");
                    scanf("%d",&quantity);
                    total_order_value+=(quantity*10);
                    printf("you have successfully ordered %d water bottles and current total of orders is %d\n",quantity,total_order_value);
                    break;
                case 2:
                    printf ("enter the quantity of the tea cups");
                    // int quantity;
                    scanf("%d",&quantity);
                    total_order_value+=(quantity*15);
                    printf("you have successfully ordered %d cup tea and current total of orders is %d",quantity,total_order_value);
                    break;
                case 3:
                 printf ("enter the quantity of the coffee cups");
                    // int quantity;
                    scanf("%d",&quantity);
                    total_order_value+=(quantity*20);
                    printf("you have successfully ordered %d cup coffee and current total of orders is %d",quantity,total_order_value);
                    break;
                case 4 :
                    printf(" thanks for ordering ");
                    ordering=0;
                    break;
                default:
                printf("enter a valid input");
                    break;
                }
            }
            return total_order_value;
}
int main(){
    printf("--food order website--\n");
    printf("do you have a coupon code ? press 1 for yes and 2 for no\n");
    int coupon_code;
    scanf("%d",&coupon_code);
    int total_order_value=0;
    while(1){

        printf("press 1 for showing menu \n2 for ordering and \n3 for exiting the program\n");
        int choice ;
        
        scanf("%d",&choice);
        switch (choice){
            case 1:
            show_menu();
            break;
            case 2:
            total_order_value= ordering();
            break;
            case 3 :
            if (coupon_code){
                int disc=(total_order_value*7)/100;
                printf (" total bill to pay after the coupon code discount rupees %d is  : %d \n",disc ,total_order_value-disc);
            }
            else if(total_order_value>=300){
                int disc=(total_order_value*30)/100;
                printf (" total bill to pay after the discount is : %d \n",total_order_value-disc);
            }else{
                printf (" total bill to pay : %d \n",total_order_value);
            }
            
            printf (" thanks for using our program visit again!");
            return 0;
            default:
            printf("enter valid input \n");
        }
    }
}
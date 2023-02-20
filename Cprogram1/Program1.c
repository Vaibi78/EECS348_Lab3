/*
  Program1.c
  Author: Vaibhav Venkatesh
  Date: 2/19/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MONTHS 12
#define NAME_LENGTH 10

typedef struct
{
    char name[NAME_LENGTH];
    float sales;
} Sale;

void print_sales_report(Sale sales[]);
void sort_sales(Sale sales[]);
float average_sales(Sale sales[]);
float min_sales(Sale sales[]);
float max_sales(Sale sales[]);
void six_month_average(Sale sales[]);

int main()
{
    Sale sales[MONTHS];
    char *months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July ", "August", "September", "October", "November", "December"};
    FILE *fpter;
    int i;
    float sales_value;

    fpter = fopen("input.txt", "r");
    if (!fpter)
    {
        printf("Error opening the input file!\n");
        exit(1);
    }

    for (i = 0; i < MONTHS; i++)
    {
        fscanf(fpter, "%f", &sales_value);
        strcpy(sales[i].name, months[i]);
        sales[i].sales = sales_value;
    }
    fclose(fpter);

    print_sales_report(sales);

    return 0;
}

void print_sales_report(Sale sales[])
{
    int i;

    printf("Monthly sales report for 2022\n");
    printf("Month\t\tSales\n");
    for (i = 0; i < MONTHS; i++)
    {
        printf("%-15s$%.2f\n", sales[i].name, sales[i].sales);
    }

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min_sales(sales), sales[0].name);
    printf("Maximum sales: $%.2f (%s)\n", max_sales(sales), sales[MONTHS - 1].name);
    printf("Average sales: $%.2f\n", average_sales(sales));

    printf("\nSix-Month moving average report:\n");
    six_month_average(sales);

    sort_sales(sales);

    printf("\nSales report (highest to lowest):\n");
    printf("Month\t\tSales\n");
    for (i = 0; i < MONTHS; i++)
    {
        printf("%-15s$%.2f\n", sales[i].name, sales[i].sales);
    }
}

void sort_sales(Sale sales[])
{
    int i, j;
    Sale temp;

    for (i = 0; i < MONTHS - 1; i++)
    {
        for (j = 0; j < MONTHS - i - 1; j++)
        {
            if (sales[j].sales < sales[j + 1].sales)
            {
                temp = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = temp;
            }
        }
    }
}

float average_sales(Sale sales[])
{
    int i;
    float sum = 0;
    for (i = 0; i < MONTHS; i++)
    {
        sum += sales[i].sales;
    }
    return sum / MONTHS;
}

float min_sales(Sale sales[])
{
    return sales[0].sales;
}

float max_sales(Sale sales[])
{
    return sales[MONTHS - 1].sales;
}

void six_month_average(Sale sales[])
{
    int i;
    float sum;

    for (i = 0; i < MONTHS - 5; i++)
    {
        sum = sales[i].sales + sales[i + 1].sales + sales[i + 2].sales + sales[i + 3].sales + sales[i + 4].sales + sales[i + 5].sales;
        printf("%s-%s\t$%.2f \n", sales[i].name, sales[i + 5].name, sum / 6);
    }
}
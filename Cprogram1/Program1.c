/*
 * Program1.c
 *
 *  Created on: Feb 10, 2023
 *      Author: Vaibhav
 */

#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

void get_data(double sales[MONTHS]);
void display_sales(double sales[MONTHS]);
void sales_summary(double sales[MONTHS]);
void swap(double *a, double *b);
void sort_descending(double sales[MONTHS]);
double average_of_array(double sales[MONTHS], int size);
double moving_average(double sales[MONTHS], int start, int end);

int main() {
    double sales[MONTHS];

    get_data(sales);
    display_sales(sales);
    sales_summary(sales);

    return 0;
}

void get_data(double sales[MONTHS]) {
    int i;
    for (i = 0; i < MONTHS; i++) {
        printf("Enter sales for month %d: ", i + 1);
        scanf("%lf", &sales[i]);
    }
}

void display_sales(double sales[MONTHS]) {
    int i;
    printf("\nMonth\tSales\n");
    for (i = 0; i < MONTHS; i++) {
        printf("%d\t%.2lf\n", i + 1, sales[i]);
    }
}

void sales_summary(double sales[MONTHS]) {
    int i;
    double min_sales = sales[0];
    double max_sales = sales[0];
    double sum = 0;
    double avg;

    for (i = 0; i < MONTHS; i++) {
        if (sales[i] < min_sales) {
            min_sales = sales[i];
        }
        if (sales[i] > max_sales) {
            max_sales = sales[i];
        }
        sum += sales[i];
    }

    avg = sum / MONTHS;

    printf("\nSales Summary\n");
    printf("Minimum sales: %.2lf\n", min_sales);
    printf("Maximum sales: %.2lf\n", max_sales);
    printf("Average sales: %.2lf\n", avg);

    printf("\nSix-Month Moving Averages\n");
    for (i = 0; i < MONTHS - 5; i++) {
        printf("Month %d - Month %d: %.2lf\n", i + 1, i + 6, moving_average(sales, i, i + 5));
    }
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void sort_descending(double sales[MONTHS]) {
    int i, j;
    for (i = 0; i < MONTHS - 1; i++) {
        for (j = 0; j < MONTHS - i - 1; j++) {
            if (sales[j] < sales[j + 1])


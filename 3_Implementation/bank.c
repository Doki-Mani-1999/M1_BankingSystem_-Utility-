/**
 * @file bank.c
 * @author Manikanta Doki (manikantadoki1999@gmail.com)
 * @brief Project on Banking System
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

struct customer
{
    int account_no;
    char name[80];
    int balance;
};


void show(struct customer[], int);
void get(struct customer[], int);
void collect(struct customer[], int, int, int);
void getout(struct customer[], int, int, int);
int find(struct customer[], int, int);


int main()
{
    struct customer data[20];
    int n, choice, account_no, amount, index;

    printf("Banking System\n\n");
    printf("Number of customer records you want to enter? : ");
    scanf("%d", &n);
    get(data, n);
    do
    {

        printf("\nBanking System Menu :\n");
        printf("Press 1 to show all records.\n");
        printf("Press 2 to find a record.\n");
        printf("Press 3 to collect amount.\n");
        printf("Press 4 to getout amount.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-4) : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                show(data, n);
                break;
            case 2:
                printf("Enter account number to find : ");
                scanf("%d", &account_no);
                index = find(data, n, account_no);
                if (index ==  - 1)
                {
                    printf("Record not found : ");
                }
                else
                {
                    printf("A/c Number: %d\nName: %s\nBalance: %d\n",
                        data[index].account_no, data[index].name,
                        data[index].balance);
                }
                break;
            case 3:
                printf("Enter account number : ");
                scanf("%d", &account_no);
                printf("Enter amount to collect : ");
                scanf("%d", &amount);
                collect(data, n, account_no, amount);
                break;
            case 4:
                printf("Enter account number : ");
                scanf("%d", &account_no);
                printf("Enter amount to getout : ");
                scanf("%d", &amount);
                getout(data, n, account_no, amount);
        }
    }
    while (choice != 0);

    return 0;
}

void get(struct customer list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\nEnter data for Record #%d", i + 1);

        printf("\nEnter account_no : ");
        scanf("%d", &list[i].account_no);
        fflush(stdin);
        printf("Enter name : ");
        gets(list[i].name);
        list[i].balance = 0;
    } 
}

void show(struct customer list[80], int s)
{
    int i;

    printf("\n\nA/c No\tName\tBalance\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t%s\t%d\n", list[i].account_no, list[i].name,
            list[i].balance);
    } 
}

int find(struct customer list[80], int s, int number)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].account_no == number)
        {
            return i;
        } 
    }
    return  - 1;
}

void collect(struct customer list[], int s, int number, int amt)
{
    int i = find(list, s, number);
    if (i ==  - 1)
    {
        printf("Record that not found");
    } 
    else
    {
        list[i].balance += amt;
    }
}

void getout(struct customer list[], int s, int number, int amt)
{
    int i = find(list, s, number);
    if (i ==  - 1)
    {
        printf("Record that not found\n");
    } 
    else if (list[i].balance < amt)
    {
        printf("Insufficient balance in your account\n");
    }
    else
    {
        list[i].balance -= amt;
    }
}
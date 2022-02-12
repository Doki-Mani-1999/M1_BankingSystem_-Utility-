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
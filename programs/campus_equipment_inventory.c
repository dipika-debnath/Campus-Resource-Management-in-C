#include <stdio.h>
#define MAX 100

void display(int a[], int n)
{
    int i;
    if (n == 0)
        printf("No equipment IDs available\n");
    else
    {
        printf("Equipment IDs: ");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
}

void insert_begin(int a[], int *n, int x)
{
    int i;
    if (*n == MAX)
    {
        printf("Inventory is full\n");
        return;
    }
    for (i = *n; i > 0; i--)
        a[i] = a[i - 1];
    a[0] = x;
    (*n)++;
    printf("Equipment added\n");
}

void insert_end(int a[], int *n, int x)
{
    if (*n == MAX)
    {
        printf("Inventory is full\n");
        return;
    }
    a[*n] = x;
    (*n)++;
    printf("Equipment added\n");
}

void insert_position(int a[], int *n, int x, int pos)
{
    int i;
    if (*n == MAX)
    {
        printf("Inventory is full\n");
        return;
    }
    if (pos < 1 || pos > *n + 1)
    {
        printf("Invalid position\n");
        return;
    }
    for (i = *n; i >= pos; i--)
        a[i] = a[i - 1];
    a[pos - 1] = x;
    (*n)++;
    printf("Equipment added\n");
}

void delete_begin(int a[], int *n)
{
    int i;
    if (*n == 0)
    {
        printf("Inventory is empty\n");
        return;
    }
    for (i = 0; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
    printf("Equipment removed\n");
}

void delete_end(int a[], int *n)
{
    if (*n == 0)
    {
        printf("Inventory is empty\n");
        return;
    }
    (*n)--;
    printf("Equipment removed\n");
}

void delete_position(int a[], int *n, int pos)
{
    int i;
    if (*n == 0)
    {
        printf("Inventory is empty\n");
        return;
    }
    if (pos < 1 || pos > *n)
    {
        printf("Invalid position\n");
        return;
    }
    for (i = pos - 1; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
    printf("Equipment removed\n");
}

int search_iterative(int a[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return -1;
}

int search_recursive(int a[], int n, int x, int i)
{
    if (i == n)
        return -1;
    if (a[i] == x)
        return i;
    return search_recursive(a, n, x, i + 1);
}

int main()
{
    int a[MAX], n, i, ch, x, pos, result;

    printf("CAMPUS EQUIPMENT INVENTORY\n");
    printf("Enter number of equipment IDs: ");
    scanf("%d", &n);
    if (n < 0 || n > MAX)
    {
        printf("Invalid size\n");
        return 0;
    }
    printf("Enter equipment IDs:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do
    {
        printf("\n1. Add at beginning");
        printf("\n2. Add at end");
        printf("\n3. Add at position");
        printf("\n4. Remove from beginning");
        printf("\n5. Remove from end");
        printf("\n6. Remove from position");
        printf("\n7. Iterative search");
        printf("\n8. Recursive search");
        printf("\n9. Display inventory");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
            case 2:
            case 3:
                printf("Enter equipment ID: ");
                scanf("%d", &x);
                if (ch == 1)
                    insert_begin(a, &n, x);
                else if (ch == 2)
                    insert_end(a, &n, x);
                else
                {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    insert_position(a, &n, x, pos);
                }
                display(a, n);
                break;
            case 4:
                delete_begin(a, &n);
                display(a, n);
                break;
            case 5:
                delete_end(a, &n);
                display(a, n);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_position(a, &n, pos);
                display(a, n);
                break;
            case 7:
            case 8:
                printf("Enter equipment ID to search: ");
                scanf("%d", &x);
                if (ch == 7)
                    result = search_iterative(a, n, x);
                else
                    result = search_recursive(a, n, x, 0);
                if (result == -1)
                    printf("Equipment ID not found\n");
                else
                    printf("Equipment ID found at position %d\n", result + 1);
                break;
            case 9:
                display(a, n);
                break;
            case 10:
                printf("Program ended\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 10);

    return 0;
}

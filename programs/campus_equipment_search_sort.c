#include <stdio.h>
#define MAX 100

void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

int binary_search_iterative(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binary_search_recursive(int a[], int low, int high, int key)
{
    int mid;
    if (low > high) return -1;
    mid = (low + high) / 2;
    if (a[mid] == key) return mid;
    if (a[mid] < key)
        return binary_search_recursive(a, mid + 1, high, key);
    return binary_search_recursive(a, low, mid - 1, key);
}

int main()
{
    int a[MAX], n, i, ch, key, result;
    printf("CAMPUS EQUIPMENT SEARCH AND SORT\n");
    printf("Enter number of equipment IDs: ");
    scanf("%d", &n);
    if (n < 0 || n > MAX)
    {
        printf("Invalid size\n");
        return 0;
    }
    printf("Enter equipment IDs:\n");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    bubble_sort(a, n);
    do
    {
        printf("\n1. Display IDs in ascending order");
        printf("\n2. Iterative binary search");
        printf("\n3. Recursive binary search");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Sorted equipment IDs: ");
                for (i = 0; i < n; i++) printf("%d ", a[i]);
                printf("\n");
                break;
            case 2:
            case 3:
                printf("Enter equipment ID to find: ");
                scanf("%d", &key);
                if (ch == 2) result = binary_search_iterative(a, n, key);
                else result = binary_search_recursive(a, 0, n - 1, key);
                if (result == -1) printf("Equipment ID not found\n");
                else printf("Equipment ID found at sorted position %d\n", result + 1);
                break;
            case 4:
                printf("Program ended\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);
    return 0;
}

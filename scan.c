#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[20], n, head, disk, i, j, temp;
    int seek = 0;

    printf("Enter Number of Requests: ");
    scanf("%d", &n);

    printf("Enter Request Queue:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter Initial Head Position: ");
    scanf("%d", &head);

    printf("Enter Disk Size: ");
    scanf("%d", &disk);

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(req[i] > req[j])
            {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(req[i] >= head)
        {
            seek += abs(req[i] - head);
            head = req[i];
        }
    }

    seek += abs((disk - 1) - head);
    head = disk - 1;

    for(i = n - 1; i >= 0; i--)
    {
        if(req[i] < head)
        {
            seek += abs(req[i] - head);
            head = req[i];
        }
    }

    printf("Total Head Movement = %d\n", seek);

    return 0;
}

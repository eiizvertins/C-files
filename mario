# include <stdio.h>

int main(void)
{
    int height;
    int c = 0;
    int k = 0;
    // prompts user for input (max height = 8)
    do
    {
        printf("Height:");
        scanf("%d", &height);
    }
    while (height < 1 || height > 8);

    //loop for rows
    for (int j = height; j > 0; j--)
    {
        k++;
        // spaces
        for (int i = height - k ; i > 0 ; i --)
        {
            c++;
            printf(" ");
        }
        // hashtags
        for (int  g = height - c ; g > 0 ; g--)
        {
            printf("#");
        }

        // space between pyramids
        printf("  ");

        // second hastags
        for (int  f = height - c ; f > 0 ; f--)
        {
            printf("#");
        }
        c = 0;
        printf("\n");
    }
    return 0;
}

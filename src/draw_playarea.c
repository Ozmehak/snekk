// draw the playarea
int i, j, height = 40, width = 40;

void draw()
{
    system("cls");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == width - 1 || j == 0 || j == width - 1)
            {
                printf("#");
            }
            else
            {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitX && j == fruitY)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("score%d", score);
    printf("\n");
    printf("Press X to quit");
}

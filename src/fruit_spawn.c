void logic()
{
    sleep(0.05);
    switch (flag)
    {
        case 1:
            y--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y++;
            break;
        case 4:
            x--;
            break;
    }
    // if snake goes outside boundries
    if (x < 0 || x > height || y < 0 || y > width)
        gameover = 1;

    if (x == fruitX && y == fruitY)
    label3:
        fruitX = rand() % 40;
    if (fruitX == 0)
        goto label3;

label4:
    fruitY = rand() % 40;
    if (fruitY == 0)
        goto label4;

    score += 10;
}
int x, y, fruitX, fruitY, flag;

// generate fruit within borders

void setup()
{
    gameover = 0;

    x = height / 2;
    y = width / 2;

label1:
    fruitX = rand() % 40;
    if (fruitX == 0)
        goto label1;

label2:
    fruitY = rand() % 40;
    if (fruitY == 0)
        goto label2;
    score = 0;
}

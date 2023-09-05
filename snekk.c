#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// using _t for types
// GameStates 
typedef enum
{
    IDLE_STATE,
    PLAY_STATE,
    PAUSE_STATE,
    GAMEOVER_STATE,
    HIGHSCORE_STATE,
} gameState_t;

// Gameplay Events
typedef enum
{
    START_GAME_EVEMT,
    MOVE_SNAKE_EVENT,
    EAT_FRUIT_EVENT,
    PAUSE_GAME_EVENT,
    RESUME_GAME_EVENT,
    END_GAME_EVENT,
    CALCULATE_SCORE_EVENT,
} gameEvent_t;

gameState_t state = IDLE_STATE;

void changeGameState(gameState_t, nextGameState)
{

}

int i, j, height = 40, width = 40;
int gameover, score;
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

// draw the playarea

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

void input()
{
    if (kbhit())
    {
        switch (getchar())
        {
            case 'a':
                flag = 1;
                break;
            case 's':
                flag = 2;
                break;
            case 'd':
                flag = 3;
                break;
            case 'w':
                flag = 4;
                break;
            case 'x':
                gameover = 1;
                break;
        }
    }
}

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

void main()
{
    int m, n;

    // generate boundries
    setup();

    while (!gameover)
    {
        draw();
        input();
        logic();
    }
}

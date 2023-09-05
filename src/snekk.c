#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Declaration = tells compiler something exists. in .h
// Definition = what that something does. in .c
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
    state = nextGameState;
}

int main()
{
    while (1)
    {
        switch (state)
        {
            case IDLE_STATE:
                // do nothin
                if ()
                {
                } /* if user presses x change to PLAY_STATE  */
                break;
            case PLAY_STATE:
                // main gameplay loop here
                //
                break;
        }
    }
    // int m, n;
    //
    // // generate boundries
    // setup();
    //
    // while (!gameover)
    // {
    //     draw();
    //     input();
    //     logic();
    // }
}

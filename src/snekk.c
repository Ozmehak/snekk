#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Declaration = tells compiler something exists. in .h
// Definition = what that something does. in .c
// GameStates
typedef enum
{
    IDLE_STATE,
    PLAY_STATE,
    PAUSE_STATE,
    GAMEOVER_STATE,
    HIGHSCORE_STATE,
} game_state;

// Gameplay Events
typedef enum
{
    START_GAME_EVENT,
    MOVE_SNAKE_EVENT,
    EAT_FRUIT_EVENT,
    PAUSE_GAME_EVENT,
    RESUME_GAME_EVENT,
    END_GAME_EVENT,
    CALCULATE_SCORE_EVENT,
} game_event;

game_state state = IDLE_STATE;

void change_game_state(game_state, next_game_state)
{
    state = next_game_state;
}

void handle_start()
{
    if (state == IDLE_STATE)
    {
        change_game_state(PLAY_STATE);
    }
}

typedef void (*event_handler)();

#define EVENT_HANDLERS_SIZE 5
// clang-format off
event_handler event_handlers[EVENT_HANDLERS_SIZE] = 
{
  [START_GAME_EVENT] = handle_start,
  [PAUSE_GAME_EVENT] = handle_pause,
  [EAT_FRUIT_EVENT] = handle_fruit,
  [MOVE_SNAKE_EVENT] = handle_movement,
  [END_GAME_EVENT] = handle_gameover                                 
};
// clang-format on

void handle_event(game_event event)
{
    event_handler handler = event_handlers[event];
    if (handler)
    {
        handler();
    }
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

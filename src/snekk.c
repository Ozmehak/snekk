#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

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

int ch;

void *check_keys(void *args){
  while (1) {
sleep(1)  ;
  ch = getch();
}
};
game_state state = IDLE_STATE;

void change_game_state(game_state next_game_state)
{
    state = next_game_state;
}

void handle_start()
{//getchar from ncurses lib
    if (ch == KEY_LEFT && state == IDLE_STATE)
    {
        change_game_state(PLAY_STATE);
    }
}

void handle_pause()
{
    if (state == PLAY_STATE)
    {
        change_game_state(PAUSE_STATE);
    }
    else if (state == PAUSE_STATE)
    {
        change_game_state(PLAY_STATE);
    }
}

void handle_fruit()
{
    // add to score
    // add to snake
    // new fruit
}

void handle_movement()
{
    // call move snake function
}

void handle_gameover()
{
    if (state == PLAY_STATE)
    {
        change_game_state(GAMEOVER_STATE);
    }
    // show highscore screen
}

typedef void (*event_handler)();

#define EVENT_HANDLERS_SIZE 5
// clang-format off
event_handler event_handlers[EVENT_HANDLERS_SIZE + 1] = 
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
  //nurses setup cbreak for passing through every key instead of lines

  pthread_t key_thread;
  pthread_create(&key_thread, NULL, check_keys, NULL);
  initscr();
  cbreak();
  noecho();//getchar from ncurses lib
    while (1)
    {
        switch (state)
        {
            case IDLE_STATE:
                int time = 0;
               printf("%d\n", ch); 
                break;

            case PLAY_STATE:
                // main gameplay loop here
                printf("game is now in playstate%d\n", ch); 
                break;
        }
    sleep(1);
    }
  // remember mutex.
  pthread_join(key_thread, NULL);

    }

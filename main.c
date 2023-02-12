#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <econio.h>
#include <Play_Functions.h>
#include <List_and_Entities.h>
#include <Menus.h>
#include <File_System.h>
#include <Driving_System.h>
#include <GameState.h>
#include <Map.h>

int GameState = 0;

void Road_Text(int P_DST) //Tells the player when a turn comes up
{
    int i;
    int Distance = 0;
    int End = 10300;
    for(i = 0; i < 19; i++)
    {
        if(i == 18)
        {
            Distance = (P_DST - 10300) - C1[0].T_DST + 10;
            i = 0;
            break;
        }
        Distance = P_DST - C1[i].T_DST + 10;
        if(Distance < 0)
        {
            break;
        }
    }

    Distance *= -1;

    switch (C1[i].Limit)
        {
        case 150:
            printf("Red ");
            break;
        case 250:
            printf("Orange ");
            break;
        case 300:
            printf("Green ");
            break;
        }
    if(Distance >= 0)
        {
            printf("turn in %dm\n\n", Distance);
        }
    return;
}

int main()
{
    srand(time(NULL));

    int LoadState = 0;

    FILE * F = fopen("Turns.txt", "r");
    int i=0;
    for (;i<18; i++)
    {
        int dist, limit;
        fscanf(F, "%d %d\n", &dist,&limit);
        C1[i].T_DST=dist;
        C1[i].Limit=limit;
    }
    fclose(F);

    Machine *Player;

    while(1)
    {

        switch(GameState)
        {
        case 0:
            Menu(LoadState);
            break;
        case 1:
            Prologue();
            break;
        case 2:
            Player = P_Creation(LoadState);
            break;
        case 3:
            Play(Player, LoadState);
            break;
        case 4:
            Intermission();
            break;


        }
    }

    Inventory_Free(Player->Inventory);
    free(Player);
    return 0;
}

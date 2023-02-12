#include <List_and_Entities.h>
#include <stdbool.h>
#include <File_System.h>
#include <Map.h>
#include <stdlib.h>
#include <GameState.h>

void Play(Machine *Player, int Load_State) //Main Play System
{

    static int Win_Count = 0;   //Basic set up
    static int Pride_Points = 0;
    static int Win;
    static int P_DST = 0;
    static int P_SPD;
    static int O_DST;
    static int O_SPD;
    static int P_SP;
    static int O_SP;
    static int ADV;
    static bool Running = true;
    static bool Focus;
    static int Crash;
    static int Timer;
    int P_Lap;
    int O_Lap;
    static int Level = 1;

    Win = 0;    //Set up for new race
    P_SPD = 100;
    O_SPD = 100;
    P_SP = 1000;
    O_SP = 1000;
    ADV = 0;
    Focus = false;
    Crash = 0;
    P_Lap = 0;
    O_Lap = 0;
    Timer = 60;
    Running = true;

    int Loading = 0;
    if(LoadState == 1)
    {
        Loading = Load(Player, &Level, &P_DST, &Pride_Points, &Win_Count);
    }
    LoadState = 0;

    O_DST = P_DST;

    Machine *Opponent;
    Opponent = O_Creation(Player->HP, Player->Top, Player->A, Player->B, Level);

    clrscr();
    printf("Rage your Dream\n");
    getchar();
    getchar();
    clrscr();

    do
    {
        int Option = 0;
        int i;
        Play_Menu(Player, Opponent, P_DST, P_SPD, ADV, P_SP, O_SP, Timer, O_SPD, Level);
        P_SPD = Driving(Player, Opponent, P_DST, O_DST, P_SPD, &Focus);
        P_DST = P_DST + (P_SPD/3.6);
        if(P_DST > 10300)
        {
            int Temp = P_DST - 10300;
            P_DST = Temp;
            P_Lap++;
        }
        int Restart = 0;
        for (i = 0; i<18; i++)
        {
            if (P_DST < C1[i].T_DST-10 && C1[i].T_DST+10 <( P_DST + (P_SPD/3.6)))
                {
                if (P_SPD > C1[i].Limit)
                    {
                    PlayerCrash();
                    Restart = Start(&Win, &P_SPD, &P_DST, &O_SPD, &O_DST, &P_SP, &O_SP, &ADV, &Focus, &Crash, &Win_Count, &Pride_Points, &Level);
                    Running = false;
                    }
                }


        }
        if(Restart)
        {
            continue;
        }
        O_SPD = AI_Driving(Opponent, O_SPD, ADV);
        O_DST = O_DST + (O_SPD/3.6);
        for (i = 0; i<18; i++)
        {
            if (O_DST < C1[i].T_DST-50 && C1[i].T_DST+50 <( O_DST + (P_SPD/3.6)))
            {
                if (O_SPD > C1[i].Limit)
                {
                    O_SPD -= 75;
                }
            }
        }
        if(O_DST > 10300)
        {
            int Temp = O_DST - 10300;
            O_DST = Temp;
            O_Lap++;
        }
        ADV = (P_DST + (P_Lap * 1030)) - (O_DST + (O_Lap * 1030));
            if(ADV >= 0)
            {
                O_SP -= ADV;
            }
            else
            {
                if(Focus == true)
                {
                    P_SP += (ADV/2);
                }
                else
                {
                P_SP += ADV;
                }
            }
            if(Timer == 0)
            {
                if (ADV > 0)
                {
                    Win = 1;
                }
                else
                {
                    Win = -1;
                }
            }
            if(O_SP <= 0)
            {
                Win = 1;
            }
            if(P_SP <= 0)
            {
                Win = -1;
            }
        Focus = false;
        if(Win == 1)
        {
            printf("\nSpirit Defeated!\n");
            Win_Count++;
            Pride_Points += 500;
            printf("Your Pride Points: %d\n", Pride_Points);
            printf("Number of Spirits Defeated: %d\n\n", Win_Count);

            if(Player->Inventory == NULL)
            {
                Player->Inventory = Part_Acquired(Level);
            }
            else
            {
                Pushback(Player->Inventory, Level);
            }
            printf("[%s] Parts Acquired!\n", Player->Inventory->Item_Level);

            Inventory_Menu(Player->Inventory, Player);

            getchar();
            getchar();
            Save(Player, Level, P_DST, Pride_Points, Win_Count);

            Story(Level);
            Level++;
            GameState = 4;
            Running = false;
        }
        if(Win == -1)
        {
            printf("\nYou have been Defeated!\n");
            GameState = 4;
            Running = false;
            Save(Player, Level, P_DST, Pride_Points, Win_Count);
        }
        Timer--;
    } while(Running == true);

    free(Opponent);

}


void Play_Menu(Machine *Player, Machine *Opponent, int P_DST, int P_SPD, int ADV, int P_SP, int O_SP, int Timer, int O_SPD, int Level) //In-game User Interface
{
    clrscr();
    if(Level < 9)
        {
           printf("[%s%s] - Shingetsu - [%d]SP\n", Player->Tuner, Player->Car, P_SP);
        }
    if(Level == 9)
        {
           printf("[%s%s] - <Shingetsu> - [%d]SP\n", Player->Tuner, Player->Car, P_SP);
        }
    if(Level == 10)
        {
            printf("[%s%s] - <<Shingetsu>> - [%d]SP\n", Player->Tuner, Player->Car, P_SP);
        }
    if(Level > 10)
        {
            printf("[GodMachine %s%s] - <<<Shingetsu>>> - [%d]SP\n", Player->Tuner, Player->Car, P_SP);
        }
    printf("[%d]HP [%d]A [%d]B [%d]KM/H\n", Player->HP, Player->A, Player->B, P_SPD);
    if(Timer > 99)
    {
        printf("\n[--]TIME [VS] [%d]ADVANTAGE [%d]LEVEL\n\n", ADV, Level);
    }
    if(Timer < 10)
    {
        printf("\n[0%d]TIME [VS] [%d]ADVANTAGE [%d]LEVEL\n\n", Timer, ADV, Level);
    }
    if(Timer <= 99 || Timer >= 10)
    {
        printf("\n[%d]TIME [VS] [%d]ADVANTAGE [%d]LEVEL\n\n", Timer, ADV, Level);
    }
    printf("[%s%s] %s- [%d]SP\n",Opponent->Tuner, Opponent->Car, Opponent->Name, O_SP);
    printf("[%d]HP", Opponent->HP);
    printf("\n\n");
    Road_Text(P_DST);
    printf("[1] Accelerate\n[2] Stay at Speed\n[3] Brake\n[4] Focus\n");
            printf("\n%d", P_DST);
}

int Start(int *Win, int *P_SPD, int *P_DST, int *O_SPD, int *O_DST, int *P_SP, int *O_SP, int *ADV, bool *Focus, int *Crash, int *Win_Count, int *Pride_Points, int *Level) //Function used for restart
{
    *Win = 0;    //Set up for new race
    *P_SPD = 100;
    *P_DST = 0;
    *O_DST = 0;
    *O_SPD = 100;
    *P_SP = 1000;
    *O_SP = 1000;
    *ADV = 0;
    *Focus = false;
    *Crash = 0;
    *Win_Count = 0;
    *Pride_Points = 0;
    *Level = 1;

    GameState = 0;

    return 1;
}

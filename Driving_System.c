#include <stdbool.h>
#include <List_and_Entities.h>



int Driving(Machine *Player, Machine *Opponent, int P_DST, int O_DST, int P_SPD, bool *Focus)   //Driving system
{
    int option;
    int level = 0;

    int Traffic = rand()%1000;
    if(Traffic >= 850)
    {
        int Slow = rand()%31;
        P_SPD = P_SPD-Slow;
        if(P_SPD < 0)
        {
            P_SPD = 0;
        }
    }

    scanf("%d", &option);
    switch (option)
    {
    case 1:
        level = 0;
        printf("\nLevel 1-10\n");
        scanf("%d", &level);
        if(level > 10)
        {
            level = 10;
        }
        if(level < 10)
        {
            level = 1;
        }

        P_SPD = P_SPD + (Player->A/(11-level));
        if(P_SPD > Player->Top)
        {
            P_SPD = Player->Top;
        }
        if(O_DST - P_DST <= 100 && O_DST - P_DST >= 1)
        {
            P_SPD+=10;

            if(P_SPD > Player->Top)
            {
                P_SPD = Player->Top+10;
            }
        }

        return P_SPD;
        break;
    case 2:
        return P_SPD;
        break;
    case 3:
        level = 0;
        printf("\nLevel 1-10\n");
        scanf("%d", &level);
        if(level > 10)
        {
            level = 10;
        }
        if(level < 10)
        {
            level = 1;
        }

        P_SPD = P_SPD - (Player->B/(11-level));
        if(P_SPD < 0)
        {
            P_SPD = 0;
        }
        return P_SPD;
        break;
    case 4:
        *Focus = true;
        return P_SPD;
        break;
    default:
        Driving(Player, Opponent, P_DST, O_DST, P_SPD, &Focus);
        break;
    }
}

int AI_Driving(Machine *Opponent, int O_SPD, int ADV) //AI Driving System
{
    int i;
    int Distance;
    int A = Opponent->A;
    int B = Opponent->B;
    B *= -1;
    if (ADV >= 0)
    {
        O_SPD += A;
    }
    if (ADV < 0)
    {
        O_SPD += random_range(B, A/4);
    }
    if (O_SPD > Opponent->Top)
    {
        O_SPD = Opponent->Top;
    }
    if (O_SPD < 0)
    {
        O_SPD = 0;
    }

    int Traffic = rand()%1000;
    if(Traffic >= 800)
    {
        int Slow = rand()%21;
        O_SPD = O_SPD-Slow;
        if(O_SPD < 0)
        {
            O_SPD = 0;
        }
    }

    return O_SPD;
}


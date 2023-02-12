#include <econio.h>
#include <GameState.h>
#include <File_System.h>

void Menu(int *Load_State) //Main menu for the game
{
    clrscr();
    int option;
    textcolor(WHITE);
    printf("Express Battle Midnight\n\n");
    printf("[1] Let the Battle begin\n[2] Continue your Battle\n[3] Leave the Battle\n\n");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        GameState = 1;
        return;
        break;
    case 2:
        LoadState = 1;
        GameState = 2;
        return;
        break;
    case 3:
        exit(0);
        break;
    default:
        clrscr();
        printf("Please choose an option with the number keys\n");
        getchar();
        getchar();
        Menu(Load_State);
        break;
    }

    return;
}

void Intermission() //Intermission between levels
{
    int option;
    int option2;
    printf("\nKeep on Fighting?\n[1] Yes\n[2] No\n");
    scanf("%d", &option);
    switch(option)
    {
    case 1:
        GameState = 3;
        return;
        break;
    case 2:
        exit(0);
        break;
    default:
        Intermission();
    }
}

void Prologue()    //Prints the prologue for the game
{

    clrscr();
    textcolor(WHITE);
    printf("1999. An era is coming to an end.\nWith ");
    textcolor(RED);
    printf("Them ");
    textcolor (WHITE);
    printf("gone, what is left.\nThe roaring beast awakened, new monsters are taking over.\nUnchained, untamed, unbounded.\nThree names linger in the air,\nthree who are most capable of taking over.\n");
    textcolor (LIGHTRED);
    printf("Akuma, Faust, Belladonna.\n");
    textcolor (WHITE);
    printf("The time is now, it is your calling.\nThe ");
    textcolor (LIGHTMAGENTA);
    printf("Shuto Kosoku Doro ");
    textcolor (WHITE);
    printf("is calling your name,\nyour soul burns with the flame, the only limit\nis your own doubt. You are the one they call\n");
    textcolor (YELLOW);
    printf("Shingetsu.\n");
    textcolor(WHITE);

    GameState = 2;

    getchar();
    getchar();
}

void Story(int Level) //Contains story text for the game
{
    switch (Level)
    {
    case 1:
        clrscr();
        printf("This is how it begins.\nThe first Spirit of the C1 has fallen,\nbut there's many more to go.\nA New Moon is rising.\n");
        getchar();
        break;
    case 2:
        clrscr();
        printf("Another fallen Spirit. The Machine's power is growing.\nIt is asking for more. It is asking You.\n");
        getchar();
        break;
    case 3:
        clrscr();
        printf("Is the Machine fighting with, or againts you?\nHard to tell, is it?\nThere's only one way to find out.\nKeep the pressure on.");
        getchar();
        break;
    case 4:
        clrscr();
        printf("The Machine accepted you.\nThe question is, did you accept yourself?");
        getchar();
        break;
    case 5:
        clrscr();
        printf("The Monster under your is growling.\nOr is it the Monster inside you?\nCan you keep it under control?");
        getchar();
        break;
    case 6:
        clrscr();
        printf("The mighty 300 is withing reach. Don't dissapoint.");
        getchar();
        break;
    case 7:
        clrscr();
        printf("You did it. You have unleashed the Beast.\nJust don't let it destroy you.");
        getchar();
        break;
    case 8:
        clrscr();
        printf("This is it.");
        textcolor(LIGHTRED);
        printf("\n<Akuma>\n");
        textcolor(WHITE);
        printf("The third fastest warrior on the C1. You are getting near your goal.\nDefeating him will get you one step closer to what you want.");
        getchar();
        break;
    case 9:
        clrscr();
        textcolor(LIGHTRED);
        printf("<<Faust>>\n");
        textcolor(WHITE);
        printf("One down. Two to go.\nThe Machine is on your side.\nTime to come to terms with your fears.");
        getchar();
        break;
    case 10:
        clrscr();
        textcolor(LIGHTRED);
        printf("<<<Belladonna>>>\n");
        printf("The fastest warrior on the C1.\nShe has one weakness though.\nThe weakness of not being able to control the storm.\nDeep within, inside all of us.\nCan you?");
        textcolor(WHITE);
        getchar();
        break;
    case 11:
        clrscr();
        printf("Power and power.");
        getchar();
        clrscr();
        printf("The fantasy ends.");
        getchar();
        clrscr();
        printf("You have arrived at the apex and achieved\na glorious and solitary state of mind.");
        getchar();
        clrscr();
        printf("Do you want to take a rest here,\nor do you want to continue racing?");
        getchar();
        clrscr();
        printf("Only the Machine knows that answer.");
        getchar();
        break;


    }

    return;
}

void PlayerCrash()   //Used when player crashes, ends the game
{
    clrscr();
    textcolor(LIGHTRED);
    printf("Metal body crumbles\nA gentle scream\nThe Moon sets\n");
    textcolor(WHITE);
    printf("\nWether the Monster took you,\nor you took it with yourself,\nno one will ever know.\nYour adventure ends here.\n");
    getchar();
    getchar();
    GameState = 0;
}

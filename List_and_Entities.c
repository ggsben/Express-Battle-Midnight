#include <File_System.h>
#include <stdlib.h>
#include <GameState.h>

int random_range(int min, int max) //Used for random number generation
{
     return rand() % (max + 1 - min ) + min;
}

Machine* P_Creation() //Creates the player
{
    clrscr();
    int i;
    int choice;
    int choice2;

    char *Cars[10];
    Cars[0]="Nissan Skyline R32 GT-R";
    Cars[1]="Nissan Skyline R33 GT-R";
    Cars[2]="Nissan 300ZX";
    Cars[3]="Efini RX-7 FD";
    Cars[4]="Acura NSX";
    Cars[5]="Porsche 964 Turbo";
    Cars[6]="Ferrari Testarossa";
    Cars[7]="Ferrari F40";
    Cars[8]="Toyota Supra";
    Cars[9]="Chevrolet Corvette C4";

    if(LoadState == 0)
    {
    printf("Time to choose your destiny:\n\n");
    for(i = 0; i < 10; i++)
        {
            printf("[%d] %s\n",i+1, Cars[i]);
        }
        printf("\n");

        scanf("%d", &choice);
        choice--;
        if (choice > 10 || choice < 0)
        {
            clrscr;
            printf("Please choose an option with the number keys\n");
            P_Creation();
        }

    }
    Machine *Player = (Machine*)malloc(sizeof(Machine));
    if (Player == NULL)
    {
        printf("MEMORY ERROR: Player");
        return 401;
    }

    if(LoadState == 0)
    {
    Player->Tuner = "";
    Player->TunerPoint = 99;
    Player->Car = Cars[choice];
    Player->CarPoint = choice;
    Player->HP = 300;
    Player->Top = 250;
    Player->A = 10;
    Player->B = 10;
    Player->Inventory = NULL;
    }
    if(LoadState == 1)
    {
    Player->Tuner = NULL;
    Player->TunerPoint = NULL;
    Player->Car = NULL;
    Player->CarPoint = NULL;
    Player->HP = NULL;
    Player->Top = NULL;
    Player->A = NULL;
    Player->B = NULL;
    Player->Inventory = NULL;
    }

    GameState = 3;

    return Player;
}

Machine* O_Creation(int HP, int Top, int A, int B, int Level) //Creates an Opponent for every race
{
    char *Cars[17];
    Cars[0]="Nissan Skyline R32 GT-R";
    Cars[1]="Nissan Skyline R33 GT-R";
    Cars[2]="Nissan 300ZX";
    Cars[3]="Efini RX-7 FD";
    Cars[4]="Efini RX-7 FC";
    Cars[5]="Acura NSX";
    Cars[6]="Acura Integra Type-R";
    Cars[7]="Toyota Supra";
    Cars[8]="Toyota MR2";
    Cars[9]="Mitsubishi 3000 GT";
    Cars[10]="Mitsubishi Lancer Evolution IV";
    Cars[11]="Mitsubishi Lancer Evolution V";
    Cars[12]="Mitsubishi Lancer Evolution VI";
    Cars[13]="Mitsubishi GTO";
    Cars[14]="Subaru Impreza WRX STI";
    Cars[15]="Honda EK9 Civic";
    Cars[16]="Honda S2000";

    char *Tuners[21];
    Tuners[0]="HKS ";
    Tuners[1]="Top Secret ";
    Tuners[2]="VeilSide ";
    Tuners[3]="GReddy ";
    Tuners[4]="RE-Amemiya ";
    Tuners[5]="AEM ";
    Tuners[6]="APEX ";
    Tuners[7]="Mines ";
    Tuners[8]="Power Enterprise ";
    Tuners[9]="C-West ";
    Tuners[10]="Amuse ";
    Tuners[11]="Yashio Factory ";
    Tuners[12]="RGO ";
    Tuners[13]="ACE ";
    Tuners[14]="Tominaga Speed ";
    Tuners[15]="Yamamoto Speed ";
    Tuners[16]="Works-R ";
    Tuners[17]="ZERO ";
    Tuners[18]="SpeedShop Mach ";
    Tuners[19]="FLAT Racing ";
    Tuners[20]="Trust ";

    int r1, r2, r3, r4;
    r1 = rand()%17;
    r2 = HP + 10*random_range(-3, 3);

    if(r2 < 300)
    {
        r2 = 300;
    }
    if(r2 > 830)
    {
        r2 = 830;
    }

    r3 = Top;
    r4 = rand()%21;

    Machine *Opponent = (Machine*)malloc(sizeof(Machine));
    if (Opponent == NULL)
    {
        printf("MEMORY ERROR: Opponent");
        return 402;
    }

    switch (Level)
    {
    case 8:
        Opponent->Tuner = "";
        Opponent->Car = "Lamborghini Diablo";
        Opponent->HP = 830;
        Opponent->Top = 340;
        Opponent->A = 20;
        Opponent->B = 20;
        Opponent->Name = "- <Akuma> ";
        break;
    case 9:
        Opponent->Tuner = "Baku " ;
        Opponent->Car = "Nissan Skyline R32 GT-R";
        Opponent->HP = 850;
        Opponent->Top = 350;
        Opponent->A = 22;
        Opponent->B = 22;
        Opponent->Name = "- <<Faust>> ";
        break;
    case 10:
        Opponent->Tuner = "Deadly Nightshade " ;
        Opponent->Car = "Efini RX-7 FD3S";
        Opponent->HP = 900;
        Opponent->Top = 360;
        Opponent->A = 25;
        Opponent->B = 25;
        Opponent->Name = "- <<<Belladonna>>> ";
        break;

    default:
        Opponent->Tuner = Tuners[r4];
        Opponent->Car = Cars[r1];
        Opponent->HP = r2;
        Opponent->Top = r3;
        Opponent->A = A;
        Opponent->B = B;
        Opponent->Name = "";
        break;
    }



    return Opponent;
}

Item* Part_Acquired(int Level)
{
    Item *Parts = NULL;
    Parts = (Item*)malloc(sizeof(Item));
    if (Parts == NULL)
    {
        printf("MEMORY ERROR: Item");
    }
    char *Item_Level_Name;
    int Item_Int;

    switch (Level)
    {
    case 1:
        Item_Level_Name = "Level I";
        Item_Int = 1;
        break;
    case 2:
        Item_Level_Name = "Level II";
        Item_Int = 2;
        break;
    case 3:
        Item_Level_Name = "Level III";
        Item_Int = 3;
        break;
    case 4:
        Item_Level_Name = "Level IV";
        Item_Int = 4;
        break;
    case 5:
        Item_Level_Name = "Level V";
        Item_Int = 5;
        break;
    case 6:
        Item_Level_Name = "Level VI";
        Item_Int = 6;
        break;
    case 7:
        Item_Level_Name = "Level VII";
        Item_Int = 7;
        break;
    case 8:
        Item_Level_Name = "Level VIII";
        Item_Int = 8;
        break;
    case 9:
        Item_Level_Name = "Level IX";
        Item_Int = 9;
        break;
    default:
        Item_Level_Name = "Level MAXIMUM TUNE";
        Item_Int = 10;
        break;
    }

    char *Tuners[21];
    Tuners[0]="HKS ";
    Tuners[1]="Top Secret ";
    Tuners[2]="VeilSide ";
    Tuners[3]="GReddy ";
    Tuners[4]="RE-Amemiya ";
    Tuners[5]="AEM ";
    Tuners[6]="APEX ";
    Tuners[7]="Mines ";
    Tuners[8]="Power Enterprise ";
    Tuners[9]="C-West ";
    Tuners[10]="Amuse ";
    Tuners[11]="Yashio Factory ";
    Tuners[12]="RGO ";
    Tuners[13]="ACE Parts ";
    Tuners[14]="Tominaga Speed ";
    Tuners[15]="Yamamoto Speed ";
    Tuners[16]="Works-R ";
    Tuners[17]="ZERO ";
    Tuners[18]="SpeedShop Mach ";
    Tuners[19]="FLAT Racing ";
    Tuners[20]="Trust ";

    int r = rand()%22;
    r--;

    Parts->Item_Level = Item_Level_Name;
    Parts->Item_Tuner = Tuners[r];
    Parts->Item_Tuner_Index = r;
    Parts->Item_Level_Int = Item_Int;
    Parts->next = NULL;

    return Parts;
}

Item* Pushback(Item* Inventory, int Level)
{
    Item *Part = Inventory;
    while (Part->next!=NULL)
    {
        Part=Part->next;
    }
    Part->next=Part_Acquired(Level);
}

void Inventory_Menu(Item* Inventory, Machine *Player)
{
    clrscr();
    printf("Choose an option!\n\n");
    int i = 1;
    int end;
    int choice;
    Item *Part = Inventory;
    while (Part != NULL)
    {
        printf("[%d] %sParts %s\n", i, Part->Item_Tuner, Part->Item_Level);
        Part=Part->next;
        i++;
        end = i;
    }

    scanf("%d", &choice);

    Part = Inventory;

    int Level_Int;
    if(choice >= end)
    {
        Inventory_Menu(Inventory, Player);
    }
    for(i = 1; i < choice; i++)
    {
        Part = Part->next;
    }
    Level_Int = Part->Item_Level_Int;

    if(Level_Int == 1)
    {
        Player->HP = 350;
        Player->A = 11;
        Player->B = 11;
        Player->Top =  259;
        Player->Tuner = Part->Item_Tuner;
    }
    if(Level_Int == 2)
    {
        Player->HP = 400;
        Player->A = 12;
        Player->B = 12;
        Player->Top = 268;
        Player->Tuner = Part->Item_Tuner;
    }
    if(Level_Int == 3)
    {
        Player->HP = 450;
        Player->A = 13;
        Player->B = 13;
        Player->Top = 277;
        Player->Tuner = Part->Item_Tuner;
    }
    if(Level_Int == 4)
    {
        Player->HP = 450;
        Player->A = 14;
        Player->B = 14;
        Player->Top = 286;
        Player->Tuner = Part->Item_Tuner;
    }
    if(Level_Int == 5)
    {
        Player->HP = 500;
        Player->A = 15;
        Player->B = 15;
        Player->Top = 295;
        Player->Tuner = Part->Item_Tuner;
    }
    if(Level_Int == 6)
    {
        Player->HP = 550;
        Player->A = 16;
        Player->B = 16;
        Player->Top = 304;
        Player->Tuner = Part->Item_Tuner;
    }
    if(Level_Int == 7)
    {
        Player->HP = 600;
        Player->A = 17;
        Player->B = 17;
        Player->Top = 313;
        Player->Tuner = Part->Item_Tuner;
    }
    if(Level_Int == 8)
    {
        Player->HP = 650;
        Player->A = 18;
        Player->B = 18;
        Player->Top = 322;
        Player->Tuner = Part->Item_Tuner;
    }
    if(Level_Int == 9)
    {
        Player->HP = 700;
        Player->A = 19;
        Player->B = 19;
        Player->Top = 331;
        Player->Tuner = Part->Item_Tuner;
    }
    if(Level_Int >= 10)
    {
        Player->HP = 830;
        Player->A = 20;
        Player->B = 20;
        Player->Top = 340;
        Player->Tuner = Part->Item_Tuner;
    }

    return;
}

int Inventory_Free(Item* Inventory)
{
    Item *Part = Inventory;
    if (Part->next!=NULL)
    {
        Inventory_Free(Part->next);
    }
    free(Part);

    return 1;
}

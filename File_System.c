#include <File_System.h>
#include <stdio.h>

int LoadState = 0;

int Load(Machine *Player, int *Level, int *P_DST, int *Pride_Points, int *Win_Count)
{
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

    FILE* fp;
    fp = fopen("Save.txt", "r");
    if (fp != NULL)
    {
        int Tuner, Car, HP, A, B, Top;
        fscanf(fp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &Tuner, &Car, &HP, &A, &B, &Top, Level, P_DST, Pride_Points, Win_Count);



        Player->Tuner = Tuners[Tuner];
        Player->Car = Cars[Car];
        Player->HP = HP;
        Player->A = A;
        Player->B = B;
        Player->Top = Top;

        fclose(fp);
    }
    else
    {
        perror("NO SAVE FOUND");
    }

    Item *Part = Player->Inventory;

    fp = fopen("Inventory.txt", "r");
    if (fp != NULL)
    {
    Item *Part = Player->Inventory;
    while (Part != NULL)
        {
        int Index, Level;
        fscanf(fp, "%d %d\n", Index, Level);
        Index = Part->Item_Tuner_Index;
        Part->Item_Tuner = Tuners[Index];
        Level = Part->Item_Level_Int;
        Part = Part->next;
        }
        fclose(fp);
    }
    else
    {
        perror("NO INVENTORY SAVE FOUND");
    }
    return 1;
}

int Save(Machine *Player, int Level, int P_DST, int Pride_Points, int Win_Count)
{
    FILE* fp;
    fp = fopen("Save.txt", "w");
    if (fp != NULL)
    {
        fprintf(fp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", Player->TunerPoint, Player->CarPoint, Player->HP, Player->A, Player->B, Player->Top, Level, P_DST, Pride_Points, Win_Count);
        fclose(fp);
    }
    else
    {
        perror("SAVE FAILED");
    }

    fp = fopen("Inventory.txt", "w");
    if (fp != NULL)
    {

    Item *Part = Player->Inventory;
    while (Part != NULL)
        {
        fprintf(fp, "%d %d\n", Part->Item_Tuner_Index, Part->Item_Level_Int);
        Part=Part->next;
        }
        fclose(fp);
    }
    else
    {
        perror("INVENTORY SAVE FAILED");
    }

    return 0;
}

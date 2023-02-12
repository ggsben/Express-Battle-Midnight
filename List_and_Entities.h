#ifndef LIST_AND_ENTITIES_H_INCLUDED
#define LIST_AND_ENTITIES_H_INCLUDED

typedef struct Item
{
    char *Item_Level;
    char *Item_Tuner;
    int Item_Tuner_Index;
    int Item_Level_Int;

    struct Item *next;
} Item;


typedef struct Machine  //Structure which represents the player and the opponents in the game
{
    char *Tuner;
    int TunerPoint;
    char *Car;
    int CarPoint;
    char *Name;
    int HP;
    int Top;
    int A;
    int B;
    Item *Inventory;
} Machine;

int random_range(int min, int max);

Machine* P_Creation();

Machine* O_Creation(int HP, int Top, int A, int B, int Level);

Item* Part_Acquired(int Level);

Item* Pushback(Item* Inventory, int Level);

void Inventory_Menu(Item* Inventory, Machine *Player);

int Inventory_Free(Item* Inventory);


#endif // LIST_AND_ENTITIES_H_INCLUDED

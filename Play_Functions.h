#ifndef PLAY_FUNCTIONS_H_INCLUDED
#define PLAY_FUNCTIONS_H_INCLUDED
#include <List_and_Entities.h>
#include <Map.h>
#include <stdbool.h>

int Start(int *Win, int *P_SPD, int *P_DST, int *O_SPD, int *O_DST, int *P_SP, int *O_SP, int *ADV, bool *Focus, int *Crash, int *Win_Count, int *Pride_Points, int *Level);

void Play_Menu(Machine *Player, Machine *Opponent, int P_DST, int P_SPD, int ADV, int P_SP, int O_SP, int Timer, int O_SPD, int Level);

void Play(Machine *Player, int Load_State);



#endif // PLAY_FUNCTIONS_H_INCLUDED

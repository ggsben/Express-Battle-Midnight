#ifndef FILES_SYSTEM_H_INCLUDED
#define FILES_SYSTEM_H_INCLUDED
#include <List_and_Entities.h>

extern int LoadState;

int Load(Machine *Player, int *Level, int *P_DST, int *Pride_Points, int *Win_Count);

int Save(Machine *Player, int Level, int P_DST, int Pride_Points, int Win_Count);

#endif // FILES_SYSTEM_H_INCLUDED

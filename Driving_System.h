#ifndef DRIVING_SYSTEM_H_INCLUDED
#define DRIVING_SYSTEM_H_INCLUDED


int Driving(Machine *Player, Machine *Opponent, int P_DST, int O_DST, int P_SPD, bool *Focus);

int AI_Driving(Machine *Opponent, int O_SPD, int ADV);

#endif // DRIVING_SYSTEM_H_INCLUDED

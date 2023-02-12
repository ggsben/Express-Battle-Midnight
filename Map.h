#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

typedef struct Turns    //Structure used for track layout
{
    int T_DST;
    int Limit;
} Turns;

static Turns C1[18];

void Road_Text(int P_DST);

#endif // MAP_H_INCLUDED

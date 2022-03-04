#pragma once
#include "figures.h"



void GetMovesIn(Peshka*** peshka, Tower*** tower, Horse*** horse, Slon*** slon, Ferz*** ferz, King*** king, Field*** field);
void SepForQ(Field*** field);
int GetCost(int x, int y, Field*** field);
int GetLost(int x, int y, Field*** field);
void GetMove(Peshka*** peshka, Tower*** tower, Horse*** horse, Slon*** slon, Ferz*** ferz, King*** king, Field*** field);
void Clear(Peshka*** peshka, Tower*** tower, Horse*** horse, Slon*** slon, Ferz*** ferz, King*** king, Field*** field);
void FindMoveFor(Peshka*** peshka, Tower*** tower, Horse*** horse, Slon*** slon, Ferz*** ferz, King*** king, Field*** field, int max);
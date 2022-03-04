#include "AI.h"
#include <iostream>

void GetMovesIn(Peshka*** peshka, Tower*** tower, Horse*** horse, Slon*** slon, Ferz*** ferz, King*** king, Field*** field)
{
    //пешки
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!peshka[i][j]->dead)
            {
                int indi = peshka[i][j]->x;
                int indj = peshka[i][j]->y;
                if (peshka[i][j]->white == true)
                {
                    if (peshka[i][j]->y == 6)
                    {
                        if (field[peshka[i][j]->x][peshka[i][j]->y - 1]->fig == 0) field[peshka[i][j]->x][peshka[i][j]->y - 1]->list.push_back(peshka[i][j]);
                        for (int k = -1; k < 2; k += 2)
                        {
                            if (peshka[i][j]->x + k >= 0 && peshka[i][j]->x + k <= 7)
                               // if ((field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->fig == 1 && peshka[i][j]->white == true) || (field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->fig == 2 && peshka[i][j]->white == false))
                                {
                                    field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->list.push_back(peshka[i][j]);
                                    Point* p = new Point(indi + k, indj - 1);
                                    peshka[i][j]->canGo.push_back(p);
                                }

                        }

                        if (field[peshka[i][j]->x][peshka[i][j]->y - 1]->fig == 0)
                            if (field[peshka[i][j]->x][peshka[i][j]->y - 2]->fig == 0)
                            {
                                field[peshka[i][j]->x][peshka[i][j]->y - 2]->list.push_back(peshka[i][j]);
                                Point* p = new Point(indi, indj - 2);
                                peshka[i][j]->canGo.push_back(p);
                            }

                    }
                    else
                    {
                        if (field[peshka[i][j]->x][peshka[i][j]->y - 1]->fig == 0) field[peshka[i][j]->x][peshka[i][j]->y - 1]->list.push_back(peshka[i][j]);
                        for (int k = -1; k < 2; k += 2) {
                            if ( (peshka[i][j]->x + k) >= 0 && (peshka[i][j]->x + k <= 7) )
                               // if ((field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->fig == 1 && peshka[i][j]->white == true) || (field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->fig == 2 && peshka[i][j]->white == false) || field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->fig == 0)
                                {
                                    field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->list.push_back(peshka[i][j]);
                                    Point* p = new Point(indi + k, indj - 1);
                                    peshka[i][j]->canGo.push_back(p);
                                }
                        }
                    }
                }
                else
                {
                    if (peshka[i][j]->y == 1)
                    {
                        if (field[peshka[i][j]->x][peshka[i][j]->y + 1]->fig == 0) field[peshka[i][j]->x][peshka[i][j]->y + 1]->list.push_back(peshka[i][j]);
                        for (int k = -1; k < 2; k += 2) {
                            if (peshka[i][j]->x + k >= 0 && peshka[i][j]->x + k <= 7)
                            {
                                if ((field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->fig == 1 && peshka[i][j]->white == true) || (field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->fig == 2 && peshka[i][j]->white == false))
                                {

                                    Point* p = new Point(indi + k, indj + 1);
                                    peshka[i][j]->canGo.push_back(p);
                                }
                                if (field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->fig != 0) field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->list.push_back(peshka[i][j]);




                            }
                            
                        }

                        if (field[peshka[i][j]->x][peshka[i][j]->y + 1]->fig == 0)
                            if (field[peshka[i][j]->x][peshka[i][j]->y + 2]->fig == 0)
                            {
                                field[peshka[i][j]->x][peshka[i][j]->y + 2]->list.push_back(peshka[i][j]);
                                Point* p = new Point(indi, indj + 2);
                                peshka[i][j]->canGo.push_back(p);
                            }
                    }
                    else
                    {
                        if (field[peshka[i][j]->x][peshka[i][j]->y + 1]->fig == 0) field[peshka[i][j]->x][peshka[i][j]->y + 1]->list.push_back(peshka[i][j]);
                        for (int k = -1; k < 2; k += 2) {
                            if (peshka[i][j]->x + k >= 0 && peshka[i][j]->x + k <= 7)
                            {
                                if ((field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->fig == 1  && peshka[i][j]->white == true) || (field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->fig == 2 && peshka[i][j]->white == false))
                                {
   
                                    Point* p = new Point(indi + k, indj + 1);
                                    peshka[i][j]->canGo.push_back(p);
                                }
                                if (field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->fig != 0 ) field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->list.push_back(peshka[i][j]);
                                
                            }
                        }
                    }
                }
            }
        }
    }

    //башни
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!tower[i][j]->dead)
            {
                int indi = tower[i][j]->x;
                int indj = tower[i][j]->y;
                bool flag1 = true;
                bool flag2 = true;
                bool flag3 = true;
                bool flag4 = true;
                for (int k = 1; k < 8; k++)
                {
                    if (indi + k >= 0 && indi + k <= 7)
                        if (flag1)
                            if (field[indi + k][indj]->fig == 0)
                            {
                                field[indi + k][indj]->list.push_back(tower[i][j]);
                                Point* p = new Point(indi + k, indj);
                                tower[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi + k][indj]->fig == 1  && tower[i][j]->white == true) || (field[indi + k][indj]->fig == 2  && tower[i][j]->white == false))
                                {

                                    Point* p = new Point(indi + k, indj);
                                    tower[i][j]->canGo.push_back(p);
                                }
                                if (field[indi + k][indj]->fig != 0) field[indi + k][indj]->list.push_back(tower[i][j]);
                                flag1 = false;
                            }

                    if (indj + k >= 0 && indj + k <= 7)
                        if (flag2)
                            if (field[indi][indj + k]->fig == 0)
                            {
                                field[indi][indj + k]->list.push_back(tower[i][j]);
                                Point* p = new Point(indi, indj + k);
                                tower[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi][indj + k]->fig == 1  && tower[i][j]->white == true) || (field[indi][indj + k]->fig == 2  && tower[i][j]->white == false))
                                {

                                    Point* p = new Point(indi, indj + k);
                                    tower[i][j]->canGo.push_back(p);
                                }
                                if (field[indi][indj + k]->fig != 0) field[indi][indj + k]->list.push_back(tower[i][j]);
                                flag2 = false;
                            }
                    if (indi - k >= 0 && indi - k <= 7)
                        if (flag3)
                            if (field[indi - k][indj]->fig == 0)
                            {
                                field[indi - k][indj]->list.push_back(tower[i][j]);
                                Point* p = new Point(indi - k, indj);
                                tower[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi - k][indj]->fig == 1  && tower[i][j]->white == true) || (field[indi - k][indj]->fig == 2  && tower[i][j]->white == false))
                                {
                                    Point* p = new Point(indi - k, indj);
                                    tower[i][j]->canGo.push_back(p);
                                }
                                if (field[indi - k][indj]->fig != 0) field[indi - k][indj]->list.push_back(tower[i][j]);
                                flag3 = false;
                            }

                    if (indj - k >= 0 && indj - k <= 7)
                        if (flag4)
                            if (field[indi][indj - k]->fig == 0)
                            {
                                field[indi][indj - k]->list.push_back(tower[i][j]);
                                Point* p = new Point(indi, indj - k);
                                tower[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi][indj - k]->fig == 1  && tower[i][j]->white == true) || (field[indi][indj - k]->fig == 2  && tower[i][j]->white == false))
                                {
                                    
                                    Point* p = new Point(indi, indj - k);
                                    tower[i][j]->canGo.push_back(p);
                                }
                                if (field[indi][indj - k]->fig != 0) field[indi][indj - k]->list.push_back(tower[i][j]);
                                flag4 = false;
                            }
                }
            }
        }
    }

    //конь
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!horse[i][j]->dead)
            {
                int indi = horse[i][j]->x;
                int indj = horse[i][j]->y;
                if (indi + 2 >= 0 && indi + 2 <= 7 && indj + 1 >= 0 && indj + 1 <= 7) if (field[indi + 2][indj + 1]->fig == 0)
                {
                    field[indi + 2][indj + 1]->list.push_back(horse[i][j]);
                    Point* p = new Point(indi + 2, indj + 1);
                    horse[i][j]->canGo.push_back(p);
                }
                else
                {
                    if ((field[indi + 2][indj + 1]->fig == 1 && horse[i][j]->white == true) || (field[indi + 2][indj + 1]->fig == 2 && horse[i][j]->white == false))
                    {
                        
                        Point* p = new Point(indi + 2, indj + 1);
                        horse[i][j]->canGo.push_back(p);
                    }
                    if (field[indi + 2][indj + 1]->fig != 0) field[indi + 2][indj + 1]->list.push_back(horse[i][j]);
                }
                if (indi + 2 >= 0 && indi + 2 <= 7 && indj - 1 >= 0 && indj - 1 <= 7) if (field[indi + 2][indj - 1]->fig == 0)
                {
                    field[indi + 2][indj - 1]->list.push_back(horse[i][j]);
                    Point* p = new Point(indi + 2, indj - 1);
                    horse[i][j]->canGo.push_back(p);
                }
                else
                {
                    if ((field[indi + 2][indj - 1]->fig == 1 && horse[i][j]->white == true) || (field[indi + 2][indj - 1]->fig == 2 && horse[i][j]->white == false))
                    {
                        
                        Point* p = new Point(indi + 2, indj - 1);
                        horse[i][j]->canGo.push_back(p);
                    }
                    if (field[indi + 2][indj - 1]->fig != 0) field[indi + 2][indj - 1]->list.push_back(horse[i][j]);
                }

                if (indi - 2 >= 0 && indi - 2 <= 7 && indj + 1 >= 0 && indj + 1 <= 7) if (field[indi - 2][indj + 1]->fig == 0)
                {
                    field[indi - 2][indj + 1]->list.push_back(horse[i][j]);
                    Point* p = new Point(indi - 2, indj + 1);
                    horse[i][j]->canGo.push_back(p);
                }
                else
                {
                    if ((field[indi - 2][indj + 1]->fig == 1 && horse[i][j]->white == true) || (field[indi - 2][indj + 1]->fig == 2 && horse[i][j]->white == false))
                    {
                        
                        Point* p = new Point(indi - 2, indj + 1);
                        horse[i][j]->canGo.push_back(p);
                    }
                    if (field[indi - 2][indj + 1]->fig != 0) field[indi - 2][indj + 1]->list.push_back(horse[i][j]);
                }

                if (indi - 2 >= 0 && indi - 2 <= 7 && indj - 1 >= 0 && indj - 1 <= 7) if (field[indi - 2][indj - 1]->fig == 0)
                {
                    field[indi - 2][indj - 1]->list.push_back(horse[i][j]);
                    Point* p = new Point(indi - 2, indj - 1);
                    horse[i][j]->canGo.push_back(p);
                }
                else
                {
                    if ((field[indi - 2][indj - 1]->fig == 1 && horse[i][j]->white == true) || (field[indi - 2][indj - 1]->fig == 2 && horse[i][j]->white == false))
                    {
                        
                        Point* p = new Point(indi - 2, indj - 1);
                        horse[i][j]->canGo.push_back(p);
                    }
                    if (field[indi - 2][indj - 1]->fig != 0) field[indi - 2][indj - 1]->list.push_back(horse[i][j]);
                }

                if (indi + 1 >= 0 && indi + 1 <= 7 && indj + 2 >= 0 && indj + 2 <= 7) if (field[indi + 1][indj + 2]->fig == 0)
                {
                    field[indi + 1][indj + 2]->list.push_back(horse[i][j]);
                    Point* p = new Point(indi + 1, indj + 2);
                    horse[i][j]->canGo.push_back(p);
                }
                else
                {
                    if ((field[indi + 1][indj + 2]->fig == 1 && horse[i][j]->white == true) || (field[indi + 1][indj + 2]->fig == 2 && horse[i][j]->white == false))
                    {
                        
                        Point* p = new Point(indi + 1, indj + 2);
                        horse[i][j]->canGo.push_back(p);
                    }
                    if (field[indi + 1][indj + 2]->fig != 0) field[indi + 1][indj + 2]->list.push_back(horse[i][j]);
                }

                if (indi - 1 >= 0 && indi - 1 <= 7 && indj + 2 >= 0 && indj + 2 <= 7) if (field[indi - 1][indj + 2]->fig == 0)
                {
                    field[indi - 1][indj + 2]->list.push_back(horse[i][j]);
                    Point* p = new Point(indi - 1, indj + 2);
                    horse[i][j]->canGo.push_back(p);
                }
                else
                {
                    if ((field[indi - 1][indj + 2]->fig == 1 && horse[i][j]->white == true) || (field[indi - 1][indj + 2]->fig == 2 && horse[i][j]->white == false))
                    {
                        
                        Point* p = new Point(indi - 1, indj + 2);
                        horse[i][j]->canGo.push_back(p);
                    }
                    if (field[indi - 1][indj + 2]->fig != 0) field[indi - 1][indj + 2]->list.push_back(horse[i][j]);
                }

                if (indi + 1 >= 0 && indi + 1 <= 7 && indj - 2 >= 0 && indj - 2 <= 7) if (field[indi + 1][indj - 2]->fig == 0)
                {
                    field[indi + 1][indj - 2]->list.push_back(horse[i][j]);
                    Point* p = new Point(indi + 1, indj - 2);
                    horse[i][j]->canGo.push_back(p);
                }
                else
                {
                    if ((field[indi + 1][indj - 2]->fig == 1 && horse[i][j]->white == true) || (field[indi + 1][indj - 2]->fig == 2 && horse[i][j]->white == false))
                    {
                        
                        Point* p = new Point(indi + 1, indj - 2);
                        horse[i][j]->canGo.push_back(p);
                    }
                    if (field[indi + 1][indj - 2]->fig != 0) field[indi + 1][indj - 2]->list.push_back(horse[i][j]);
                }

                if (indi - 1 >= 0 && indi - 1 <= 7 && indj - 2 >= 0 && indj - 2 <= 7) if (field[indi - 1][indj - 2]->fig == 0)
                {
                    field[indi - 1][indj - 2]->list.push_back(horse[i][j]);
                    Point* p = new Point(indi - 1, indj - 2);
                    horse[i][j]->canGo.push_back(p);
                }
                else
                {
                    if ((field[indi - 1][indj - 2]->fig == 1 && horse[i][j]->white == true) || (field[indi - 1][indj - 2]->fig == 2 && horse[i][j]->white == false))
                    {
                        
                        Point* p = new Point(indi - 1, indj - 2);
                        horse[i][j]->canGo.push_back(p);
                    }
                    if (field[indi - 1][indj - 2]->fig != 0) field[indi - 1][indj - 2]->list.push_back(horse[i][j]);
                }
            }
        }
    }

    //офицер
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!slon[i][j]->dead)
            {

                int indi = slon[i][j]->x;
                int indj = slon[i][j]->y;
                bool flag1 = true;
                bool flag2 = true;
                bool flag3 = true;
                bool flag4 = true;
                for (int k = 1; k < 8; k++)
                {
                    if (flag1)
                        if (indi + k >= 0 && indi + k <= 7 && indj + k >= 0 && indj + k <= 7)
                            if (field[indi + k][indj + k]->fig == 0)
                            {
                                field[indi + k][indj + k]->list.push_back(slon[i][j]);
                                Point* p = new Point(indi + k, indj + k);
                                slon[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi + k][indj + k]->fig == 1  && slon[i][j]->white == true) || (field[indi + k][indj + k]->fig == 2  && slon[i][j]->white == false))
                                {
                                    
                                    Point* p = new Point(indi + k, indj + k);
                                    slon[i][j]->canGo.push_back(p);
                                }
                                if (field[indi + k][indj + k]->fig != 0) field[indi + k][indj + k]->list.push_back(slon[i][j]);
                                flag1 = false;
                            }

                    if (flag2)
                        if (indi + k >= 0 && indi + k <= 7 && indj - k >= 0 && indj - k <= 7)
                            if (field[indi + k][indj - k]->fig == 0)
                            {
                                field[indi + k][indj - k]->list.push_back(slon[i][j]);
                                Point* p = new Point(indi + k, indj - k);
                                slon[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi + k][indj - k]->fig == 1  && slon[i][j]->white == true) || (field[indi + k][indj - k]->fig == 2  && slon[i][j]->white == false))
                                {
                                    
                                    Point* p = new Point(indi + k, indj - k);
                                    slon[i][j]->canGo.push_back(p);
                                }
                                if (field[indi + k][indj - k]->fig != 0) field[indi + k][indj - k]->list.push_back(slon[i][j]);
                                flag2 = false;
                            }

                    if (flag3)
                        if (indi - k >= 0 && indi - k <= 7 && indj + k >= 0 && indj + k <= 7)
                            if (field[indi - k][indj + k]->fig == 0)
                            {
                                field[indi - k][indj + k]->list.push_back(slon[i][j]);
                                Point* p = new Point(indi - k, indj + k);
                                slon[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi - k][indj + k]->fig == 1  && slon[i][j]->white == true) || (field[indi - k][indj + k]->fig == 2  && slon[i][j]->white == false))
                                {
                                  
                                    Point* p = new Point(indi - k, indj + k);
                                    slon[i][j]->canGo.push_back(p);
                                }
                                if (field[indi - k][indj + k]->fig != 0) field[indi - k][indj + k]->list.push_back(slon[i][j]);
                                flag3 = false;
                            }

                    if (flag4)
                        if (indi - k >= 0 && indi - k <= 7 && indj - k >= 0 && indj - k <= 7)
                            if (field[indi - k][indj - k]->fig == 0)
                            {
                                field[indi - k][indj - k]->list.push_back(slon[i][j]);
                                Point* p = new Point(indi - k, indj - k);
                                slon[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi - k][indj - k]->fig == 1  && slon[i][j]->white == true) || (field[indi - k][indj - k]->fig == 2  && slon[i][j]->white == false))
                                {
                                    
                                    Point* p = new Point(indi - k, indj - k);
                                    slon[i][j]->canGo.push_back(p);
                                }
                                if (field[indi - k][indj - k]->fig != 0) field[indi - k][indj - k]->list.push_back(slon[i][j]);
                                flag4 = false;
                            }

                }

            }
        }
    }

    //королева
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!ferz[i][j]->dead)
            {
                int indi = ferz[i][j]->x;
                int indj = ferz[i][j]->y;
                bool flag1 = true;
                bool flag2 = true;
                bool flag3 = true;
                bool flag4 = true;
                bool flag5 = true;
                bool flag6 = true;
                bool flag7 = true;
                bool flag8 = true;


                for (int k = 1; k < 8; k++) //диагональ
                {
                    if (flag1)
                        if (indi + k >= 0 && indi + k <= 7 && indj + k >= 0 && indj + k <= 7)
                            if (field[indi + k][indj + k]->fig == 0)
                            {
                                field[indi + k][indj + k]->list.push_back(ferz[i][j]);
                                Point* p = new Point(indi + k, indj + k);
                                ferz[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi + k][indj + k]->fig == 1  && ferz[i][j]->white == true) || (field[indi + k][indj + k]->fig == 2  && ferz[i][j]->white == false))

                                {
                                    
                                    Point* p = new Point(indi + k, indj + k);
                                    ferz[i][j]->canGo.push_back(p);
                                }
                                if (field[indi + k][indj + k]->fig != 0) field[indi + k][indj + k]->list.push_back(ferz[i][j]);
                                flag1 = false;
                            }

                    if (flag2)
                        if (indi + k >= 0 && indi + k <= 7 && indj - k >= 0 && indj - k <= 7)
                            if (field[indi + k][indj - k]->fig == 0)
                            {
                                field[indi + k][indj - k]->list.push_back(ferz[i][j]);
                                Point* p = new Point(indi + k, indj - k);
                                ferz[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi + k][indj - k]->fig == 1 && ferz[i][j]->white == true) || (field[indi + k][indj - k]->fig == 2  && ferz[i][j]->white == false))
                                {
                                    
                                    Point* p = new Point(indi + k, indj - k);
                                    ferz[i][j]->canGo.push_back(p);
                                }
                                if (field[indi + k][indj - k]->fig != 0) field[indi + k][indj - k]->list.push_back(ferz[i][j]);
                                flag2 = false;
                            }

                    if (flag3)
                        if (indi - k >= 0 && indi - k <= 7 && indj + k >= 0 && indj + k <= 7)
                            if (field[indi - k][indj + k]->fig == 0)
                            {
                                field[indi - k][indj + k]->list.push_back(ferz[i][j]);
                                Point* p = new Point(indi - k, indj + k);
                                ferz[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi - k][indj + k]->fig == 1  && ferz[i][j]->white == true) || (field[indi - k][indj + k]->fig == 2  && ferz[i][j]->white == false))
                                {
                                    
                                    Point* p = new Point(indi - k, indj + k);
                                    ferz[i][j]->canGo.push_back(p);
                                }
                                if (field[indi - k][indj + k]->fig != 0) field[indi - k][indj + k]->list.push_back(ferz[i][j]);
                                flag3 = false;
                            }

                    if (flag4)
                        if (indi - k >= 0 && indi - k <= 7 && indj - k >= 0 && indj - k <= 7)
                            if (field[indi - k][indj - k]->fig == 0)
                            {
                                field[indi - k][indj - k]->list.push_back(ferz[i][j]);
                                Point* p = new Point(indi - k, indj - k);
                                ferz[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi - k][indj - k]->fig == 1  && ferz[i][j]->white == true) || (field[indi - k][indj - k]->fig == 2  && ferz[i][j]->white == false))
                                {
                                   
                                    Point* p = new Point(indi - k, indj - k);
                                    ferz[i][j]->canGo.push_back(p);
                                }
                                if (field[indi - k][indj - k]->fig != 0)  field[indi - k][indj - k]->list.push_back(ferz[i][j]);
                                flag4 = false;
                            }
                }


                for (int k = 1; k < 8; k++) //верх-низ-лево-право
                {
                    if (indi + k >= 0 && indi + k <= 7)
                        if (flag5)
                            if (field[indi + k][indj]->fig == 0)
                            {
                                field[indi + k][indj]->list.push_back(ferz[i][j]);
                                Point* p = new Point(indi + k, indj);
                                ferz[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi + k][indj]->fig == 1  && ferz[i][j]->white == true) || (field[indi + k][indj]->fig == 2  && ferz[i][j]->white == false))
                                {
                                    
                                    Point* p = new Point(indi + k, indj);
                                    ferz[i][j]->canGo.push_back(p);
                                }
                                if (field[indi + k][indj]->fig != 0) field[indi + k][indj]->list.push_back(ferz[i][j]);
                                flag5 = false;
                            }

                    if (indj + k >= 0 && indj + k <= 7)
                        if (flag6)
                            if (field[indi][indj + k]->fig == 0)
                            {
                                field[indi][indj + k]->list.push_back(ferz[i][j]);
                                Point* p = new Point(indi, indj + k);
                                ferz[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi][indj + k]->fig == 1  && ferz[i][j]->white == true) || (field[indi][indj + k]->fig == 2  && ferz[i][j]->white == false))
                                {
                                    
                                    Point* p = new Point(indi, indj + k);
                                    ferz[i][j]->canGo.push_back(p);
                                }
                                if (field[indi][indj + k]->fig != 0) field[indi][indj + k]->list.push_back(ferz[i][j]);
                                flag6 = false;
                            }
                    if (indi - k >= 0 && indi - k <= 7)
                        if (flag7)
                            if (field[indi - k][indj]->fig == 0)
                            {
                                field[indi - k][indj]->list.push_back(ferz[i][j]);
                                Point* p = new Point(indi - k, indj);
                                ferz[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi - k][indj]->fig == 1  && ferz[i][j]->white == true) || (field[indi - k][indj]->fig == 2  && ferz[i][j]->white == false))
                                {
                                    
                                    Point* p = new Point(indi - k, indj);
                                    ferz[i][j]->canGo.push_back(p);
                                }
                                if (field[indi - k][indj]->fig != 0)field[indi - k][indj]->list.push_back(ferz[i][j]);
                                flag7 = false;
                            }

                    if (indj - k >= 0 && indj - k <= 7)
                        if (flag8)
                            if (field[indi][indj - k]->fig == 0)
                            {
                                field[indi][indj - k]->list.push_back(ferz[i][j]);
                                Point* p = new Point(indi, indj - k);
                                ferz[i][j]->canGo.push_back(p);
                            }
                            else
                            {
                                if ((field[indi][indj - k]->fig == 1  && ferz[i][j]->white == true) || (field[indi][indj - k]->fig == 2  && ferz[i][j]->white == false))
                                {
                                    
                                    Point* p = new Point(indi, indj - k);
                                    ferz[i][j]->canGo.push_back(p);
                                }
                                if (field[indi][indj - k]->fig != 0) field[indi][indj - k]->list.push_back(ferz[i][j]);
                                flag8 = false;
                            }
                }
            }

        }
    }


    //король
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!king[i][j]->dead)
            {
                int indi = king[i][j]->x;
                int indj = king[i][j]->y;
                for (int c = -1; c < 2; c++)
                {
                    for (int k = -1; k < 2; k++)
                    {
                        if (c == 0 && k == 0) continue;
                        if (indi + c >= 0 && indi + c <= 7 && indj + k >= 0 && indj + k <= 7)
                        {
                            if (field[indi + c][indj + k]->fig == 0)
                            {
                                field[indi + c][indj + k]->list.push_back(king[i][j]);
                                Point* p = new Point(indi + c, indj + k);
                                king[i][j]->canGo.push_back(p);
                            }
                            if ((field[indi + c][indj + k]->fig == 1  && king[i][j]->white == true) || (field[indi + c][indj + k]->fig == 2  && king[i][j]->white == false))
                            {
                                
                                Point* p = new Point(indi + c, indj + k);
                                king[i][j]->canGo.push_back(p);
                            }
                            if (field[indi + c][indj + k]->fig != 0) field[indi + c][indj + k]->list.push_back(ferz[i][j]);
                        }
                    }
                }

            }
        }
    }
    //std::cout << "*\n";
}


void SepForQ(Field*** field)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < field[i][j]->list.size(); k++)
            {
                if (field[i][j]->list[k]->white == true) field[i][j]->qen.push(field[i][j]->list[k]);
                else field[i][j]->qal.push(field[i][j]->list[k]);
            }
        }
    }
    /*
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            while (!field[i][j]->qal.empty())
            {
                std::cout << field[i][j]->qal.top()->cost << " ";
                field[i][j]->qal.pop();
            }
            std::cout << "\n";
        }
    }
    */
}

int GetCost(int x, int y, Field*** field)
{
    int cost = field[x][y]->cost;
    if ((field[x][y]->el) && (!field[x][y]->qal.empty()))
    {
        cost += field[x][y]->el->cost;
        //field[x][y]->qal.pop();
    }
    while (!field[x][y]->qen.empty() && !field[x][y]->qal.empty())
    {
        cost -= field[x][y]->qal.top()->cost;
        field[x][y]->qal.pop();

        if (!field[x][y]->qal.empty())
        {
            cost += field[x][y]->qen.top()->cost;
            field[x][y]->qen.pop();
        }
    }
    
    //std::cout << cost << "\n";
    return cost;
}

int GetLost(int x, int y, Field*** field)
{
    int lost = 0;
    if (!field[x][y]->qen.empty())
        lost += field[x][y]->el->cost;
    while (!field[x][y]->qen.empty() && !field[x][y]->qal.empty())
    {
        lost -= field[x][y]->qen.top()->cost;
        field[x][y]->qen.pop();
        if (!field[x][y]->qen.empty())
        {
            lost += field[x][y]->qal.top()->cost;
            field[x][y]->qal.pop();
        }
    }
    return lost;
}


void GetMove(Peshka*** peshka, Tower*** tower, Horse*** horse, Slon*** slon, Ferz*** ferz, King*** king, Field*** field)
{
    int max = 0;
    int indi = 0;
    int indj = 0;
    int cost;
    bool flag = true;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ( (field[i][j]->fig == 0 || field[i][j]->fig == 2) && !field[i][j]->qal.empty())
            {
                cost = GetCost(i, j, field);
                if (cost > max)
                {
                    max = cost;
                    indi = i;
                    indj = j;
                    flag = true;
                }
               
            } 
            if (field[i][j]->fig == 1)
            {
                cost = GetLost(i, j, field);
                if (cost > max)
                {
                    max = cost;
                    indi = i;
                    indj = j;
                    flag = false;
                }

            }
        }
    }
    if (flag == true)
    {

        std::cout << "cost: " << max << "\n";

        Clear(peshka, tower, horse, slon, ferz, king, field);
        GetMovesIn(peshka, tower, horse, slon, ferz, king, field);
        SepForQ(field);
        std::cout << "sizes: " << field[indi][indj]->qal.size() << " " << field[indi][indj]->qen.size() << "\n";


        if (field[indi][indj]->fig == 2)
        {
            field[indi][indj]->el->death();
        }



        int x = field[indi][indj]->qal.top()->x; //кем ходить
        int y = field[indi][indj]->qal.top()->y; //кем ходить

        field[x][y]->el->sprite.setPosition(125 + 100 * indi, 125 + 100 * indj);
        field[x][y]->el->x = indi;
        field[x][y]->el->y = indj;

        field[indi][indj]->fig = field[x][y]->fig;
        field[indi][indj]->el = field[x][y]->el;
        field[x][y]->fig = 0;
        field[x][y]->el = nullptr;
        field[x][y]->box.setFillColor(sf::Color::Green);
        field[indi][indj]->box.setFillColor(sf::Color::Green);

        std::cout << "from-to:\n" << x << " " << y << "\n" << indi << " " << indj << "\n-------------------------------------------------\n";
        Clear(peshka, tower, horse, slon, ferz, king, field);
    }
    else if (flag == false)
    {
        std::cout << "false\n";
        std::cout << "oldcost: " << max << "\n";
        Clear(peshka, tower, horse, slon, ferz, king, field);
        GetMovesIn(peshka, tower, horse, slon, ferz, king, field);
        SepForQ(field);
        std::cout << "oldsizes: " << field[indi][indj]->qal.size() << " " << field[indi][indj]->qen.size() << "\n";
        std::cout << "field: " << indi << " " << indj << "\n";
        FindMoveFor(peshka, tower, horse, slon, ferz, king, field, max);
    }
    
}


void FindMoveFor(Peshka*** peshka, Tower*** tower, Horse*** horse, Slon*** slon, Ferz*** ferz, King*** king, Field*** field, int max)
{
    int retx = 0;
    int rety = 0;
    
    int maxx = 0;
    int forDeath = 0;
    int cost;
    int indi;
    int indj;
    int x = 0 ;
    int y = 0 ;
    bool saveDeath;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (field[i][j]->fig == 1)
            {
                for (int k = 0; k < field[i][j]->el->canGo.size(); k++)
                {
                    forDeath = 0;
                    indi = field[i][j]->el->canGo[k]->x;
                    indj = field[i][j]->el->canGo[k]->y;

                    int saveFigInd = field[indi][indj]->fig;
                    int saveFigI = field[i][j]->fig;
                    Element* saveElInd = field[indi][indj]->el;
                    Element* saveElI = field[i][j]->el;
                    if (field[indi][indj]->fig != 0)  saveDeath = field[indi][indj]->el->dead;

                    
                    if (field[indi][indj]->fig == 2)
                    {
                        field[indi][indj]->el->death();
                        forDeath = field[indi][indj]->el->cost;
                    }
                    field[i][j]->el->x = indi;
                    field[i][j]->el->y = indj;
                    field[indi][indj]->fig = field[i][j]->fig;
                    field[indi][indj]->el = field[i][j]->el;
                    field[i][j]->fig = 0;
                    field[i][j]->el = nullptr;
                    Clear(peshka, tower, horse, slon, ferz, king, field);
                    GetMovesIn(peshka, tower, horse, slon, ferz, king, field);
                    SepForQ(field);
                    maxx = 0;
                    for (int f = 0; f < 8; f++)
                    {
                        for (int g = 0; g < 8; g++)
                        {
                            if (field[f][g]->fig == 1)
                            {
                                cost = GetLost(f, g, field);
                                if (cost > maxx)
                                {
                                    maxx = cost;
                                }

                            }
                        }
                    }
                    
                    if (maxx - forDeath <= max)
                    {
                        max = maxx - forDeath;
                        retx = indi;
                        rety = indj;
                        x = i;
                        y = j;
                    }
                    
                    field[indi][indj]->el->x =i;
                    field[indi][indj]->el->y = j;
                    field[i][j]->fig = saveFigI;
                    field[i][j]->el = saveElI;
                    field[indi][indj]->fig = saveFigInd;
                    field[indi][indj]->el = saveElInd;
                    if (field[indi][indj]->fig != 0)field[indi][indj]->el->dead = saveDeath;
                    Clear(peshka, tower, horse, slon, ferz, king, field);
                    GetMovesIn(peshka, tower, horse, slon, ferz, king, field);
                    SepForQ(field);
                }
            }
        }
    }
    indi = retx;
    indj = rety;
    

    std::cout << "cost: " << max << "\n";

    Clear(peshka, tower, horse, slon, ferz, king, field);
    GetMovesIn(peshka, tower, horse, slon, ferz, king, field);
    SepForQ(field);
    std::cout << "sizes: " << field[indi][indj]->qal.size() << " " << field[indi][indj]->qen.size() << "\n";


    if (field[indi][indj]->fig == 2)
    {
        field[indi][indj]->el->death();
    }



   // int x = field[indi][indj]->qal.top()->x; //кем ходить
   // int y = field[indi][indj]->qal.top()->y; //кем ходить

    field[x][y]->el->sprite.setPosition(125 + 100 * indi, 125 + 100 * indj);
    field[x][y]->el->x = indi;
    field[x][y]->el->y = indj;

    field[indi][indj]->fig = field[x][y]->fig;
    field[indi][indj]->el = field[x][y]->el;
    field[x][y]->fig = 0;
    field[x][y]->el = nullptr;

    field[x][y]->box.setFillColor(sf::Color::Green);
    field[indi][indj]->box.setFillColor(sf::Color::Green);

    std::cout << "from-to:\n" << x << " " << y << "\n" << indi << " " << indj << "\n----------------------------------\n";
    Clear(peshka, tower, horse, slon, ferz, king, field);
}


void Clear(Peshka*** peshka, Tower*** tower, Horse*** horse, Slon*** slon, Ferz*** ferz, King*** king, Field*** field)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            peshka[i][j]->canGo.clear();
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            tower[i][j]->canGo.clear();
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            horse[i][j]->canGo.clear();
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            slon[i][j]->canGo.clear();
        }
    }
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ferz[i][j]->canGo.clear();
        }
    }
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            king[i][j]->canGo.clear();
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            field[i][j]->list.clear();
            while (!field[i][j]->qal.empty()) field[i][j]->qal.pop();
            while (!field[i][j]->qen.empty()) field[i][j]->qen.pop();
        }
    }
}





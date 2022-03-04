#include <SFML/Graphics.hpp>
#include <iostream>
#include "figures.h"
#include "AI.h"


int main() //убрать коллизии
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    //поле 
    
    Field*** field;
    field = new Field * *[8];
    for (int i = 0; i < 8; i++)
    {
        field[i] = new Field * [8];
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            field[i][j] = new Field(i, j);
        }
    }

//пешка
    Peshka*** peshka;
    peshka = new Peshka**[8];
    for (int i = 0; i < 8; i++)
    {
        peshka[i] = new Peshka * [2];
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            bool white;
            if (j == 0) white = false;
            if (j == 1) white = true;
            peshka[i][j] = new Peshka(i, j, white,field);
        }
    }

     //башня
    Tower*** tower;
    tower = new Tower * *[2];
    for (int i = 0; i < 2; i++)
    {
        tower[i] = new Tower * [2];
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            bool white;
            if (j == 0) white = false;
            if (j == 1) white = true;
            tower[i][j] = new Tower(i, j, white, field);
        }
    }

    //кони
    Horse*** horse;
    horse = new Horse * *[2];
    for (int i = 0; i < 2; i++)
    {
        horse[i] = new Horse * [2];
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            bool white;
            if (j == 0) white = false;
            if (j == 1) white = true;
            horse[i][j] = new Horse(i, j, white, field);
        }
    }

    //офицер
    Slon*** slon;
    slon = new Slon * *[2];
    for (int i = 0; i < 2; i++)
    {
        slon[i] = new Slon * [2];
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            bool white;
            if (j == 0) white = false;
            if (j == 1) white = true;
            slon[i][j] = new Slon(i, j, white, field);
        }
    }
    //ферзь
    Ferz*** ferz;
    ferz = new Ferz * *[1];
    ferz[0] = new Ferz * [2];
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            bool white;
            if (j == 0) white = false;
            if (j == 1) white = true;
            ferz[i][j] = new Ferz(i, j, white, field);
        }
    }

    //король
    King*** king;
    king = new King * *[1];
    king[0] = new King * [2];
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            bool white;
            if (j == 0) white = false;
            if (j == 1) white = true;
            king[i][j] = new King(i, j, white, field);
        }
    }

bool pressed = false;
int indi = 0;
int indj = 0;
bool turn = true;
bool play = true;

sf::Texture txtend;
sf::Sprite spritend;
sf::Texture txtadv;
sf::Sprite spritadv;

while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if (king[0][0]->dead)
    {
        
        txtend.loadFromFile("images/winw.png");
        spritend.setTexture(txtend);
        spritend.setPosition(300, 300);

        txtadv.loadFromFile("images/adv.png");
        spritadv.setTexture(txtadv);
        spritadv.setPosition(0, 0);
        play = false;
        //return 0;
    }
    if (king[0][1]->dead)
    {
        txtend.loadFromFile("images/winb.png");
        spritend.setTexture(txtend);
        spritend.setPosition(300, 300);

        txtadv.loadFromFile("images/adv.png");
        spritadv.setTexture(txtadv);
        spritadv.setPosition(0, 0);
        play = false;
    }
    if (play)
    {
        if (turn)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pressed == true)
            {
                pressed = false;
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if ((i + j) % 2 == 1)
                            field[i][j]->box.setFillColor(sf::Color::Blue);
                        else
                            field[i][j]->box.setFillColor(sf::Color::White);
                    }
                }
            }

            //пешки
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (!peshka[i][j]->dead && peshka[i][j]->white == turn)
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pressed == false)
                            if (sf::IntRect(peshka[i][j]->sprite.getPosition().x, peshka[i][j]->sprite.getPosition().y, peshka[i][j]->sprite.getLocalBounds().width, peshka[i][j]->sprite.getLocalBounds().height).contains(sf::Mouse::getPosition(window)))
                            {
                                pressed = true;
                                indi = peshka[i][j]->x;
                                indj = peshka[i][j]->y;
                                if (peshka[i][j]->white == true)
                                {
                                    if (peshka[i][j]->y == 6)
                                    {
                                        if (field[peshka[i][j]->x][peshka[i][j]->y - 1]->fig == 0) field[peshka[i][j]->x][peshka[i][j]->y - 1]->box.setFillColor(sf::Color::Yellow);
                                        for (int k = -1; k < 2; k += 2)
                                        {
                                            if (peshka[i][j]->x + k >= 0 && peshka[i][j]->x + k <= 7)
                                                if ((field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->fig == 1 && peshka[i][j]->white == true) || (field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->fig == 2 && peshka[i][j]->white == false))
                                                    field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->box.setFillColor(sf::Color::Red);
                                        }

                                        if (field[peshka[i][j]->x][peshka[i][j]->y - 1]->fig == 0)
                                            if (field[peshka[i][j]->x][peshka[i][j]->y - 2]->fig == 0) field[peshka[i][j]->x][peshka[i][j]->y - 2]->box.setFillColor(sf::Color::Yellow);

                                    }
                                    else
                                    {
                                        if (field[peshka[i][j]->x][peshka[i][j]->y - 1]->fig == 0) field[peshka[i][j]->x][peshka[i][j]->y - 1]->box.setFillColor(sf::Color::Yellow);
                                        for (int k = -1; k < 2; k += 2) {
                                            if (peshka[i][j]->x + k >= 0 && peshka[i][j]->x + k <= 7)
                                                if ((field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->fig == 1 && peshka[i][j]->white == true) || (field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->fig == 2 && peshka[i][j]->white == false))
                                                    field[peshka[i][j]->x + k][peshka[i][j]->y - 1]->box.setFillColor(sf::Color::Red);
                                        }
                                    }
                                }
                                else
                                {
                                    if (peshka[i][j]->y == 1)
                                    {
                                        if (field[peshka[i][j]->x][peshka[i][j]->y + 1]->fig == 0) field[peshka[i][j]->x][peshka[i][j]->y + 1]->box.setFillColor(sf::Color::Yellow);
                                        for (int k = -1; k < 2; k += 2) {
                                            if (peshka[i][j]->x + k >= 0 && peshka[i][j]->x + k <= 7)
                                                if ((field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->fig == 1 && peshka[i][j]->white == true) || (field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->fig == 2 && peshka[i][j]->white == false))
                                                    field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->box.setFillColor(sf::Color::Red);
                                        }

                                        if (field[peshka[i][j]->x][peshka[i][j]->y + 1]->fig == 0)
                                            if (field[peshka[i][j]->x][peshka[i][j]->y + 2]->fig == 0) field[peshka[i][j]->x][peshka[i][j]->y + 2]->box.setFillColor(sf::Color::Yellow);
                                    }
                                    else
                                    {
                                        if (field[peshka[i][j]->x][peshka[i][j]->y + 1]->fig == 0) field[peshka[i][j]->x][peshka[i][j]->y + 1]->box.setFillColor(sf::Color::Yellow);
                                        for (int k = -1; k < 2; k += 2) {
                                            if (peshka[i][j]->x + k >= 0 && peshka[i][j]->x + k <= 7)
                                                if ((field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->fig == 1 && peshka[i][j]->white == true) || (field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->fig == 2 && peshka[i][j]->white == false))
                                                    field[peshka[i][j]->x + k][peshka[i][j]->y + 1]->box.setFillColor(sf::Color::Red);
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
                    if (!tower[i][j]->dead && tower[i][j]->white == turn)
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pressed == false)
                            if (sf::IntRect(tower[i][j]->sprite.getPosition().x, tower[i][j]->sprite.getPosition().y, tower[i][j]->sprite.getLocalBounds().width, tower[i][j]->sprite.getLocalBounds().height).contains(sf::Mouse::getPosition(window)))
                            {
                                pressed = true;
                                indi = tower[i][j]->x;
                                indj = tower[i][j]->y;
                                bool flag1 = true;
                                bool flag2 = true;
                                bool flag3 = true;
                                bool flag4 = true;
                                for (int k = 1; k < 8; k++)
                                {
                                    if (indi + k >= 0 && indi + k <= 7)
                                        if (flag1)
                                            if (field[indi + k][indj]->fig == 0) field[indi + k][indj]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi + k][indj]->fig == 1 && tower[i][j]->white == true) || (field[indi + k][indj]->fig == 2 && tower[i][j]->white == false))
                                                    field[indi + k][indj]->box.setFillColor(sf::Color::Red);
                                                flag1 = false;
                                            }

                                    if (indj + k >= 0 && indj + k <= 7)
                                        if (flag2)
                                            if (field[indi][indj + k]->fig == 0) field[indi][indj + k]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi][indj + k]->fig == 1 && tower[i][j]->white == true) || (field[indi][indj + k]->fig == 2 && tower[i][j]->white == false))
                                                    field[indi][indj + k]->box.setFillColor(sf::Color::Red);
                                                flag2 = false;
                                            }
                                    if (indi - k >= 0 && indi - k <= 7)
                                        if (flag3)
                                            if (field[indi - k][indj]->fig == 0) field[indi - k][indj]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi - k][indj]->fig == 1 && tower[i][j]->white == true) || (field[indi - k][indj]->fig == 2 && tower[i][j]->white == false))
                                                    field[indi - k][indj]->box.setFillColor(sf::Color::Red);
                                                flag3 = false;
                                            }

                                    if (indj - k >= 0 && indj - k <= 7)
                                        if (flag4)
                                            if (field[indi][indj - k]->fig == 0) field[indi][indj - k]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi][indj - k]->fig == 1 && tower[i][j]->white == true) || (field[indi][indj - k]->fig == 2 && tower[i][j]->white == false))
                                                    field[indi][indj - k]->box.setFillColor(sf::Color::Red);
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
                    if (!horse[i][j]->dead && horse[i][j]->white == turn)
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pressed == false)
                            if (sf::IntRect(horse[i][j]->sprite.getPosition().x, horse[i][j]->sprite.getPosition().y, horse[i][j]->sprite.getLocalBounds().width, horse[i][j]->sprite.getLocalBounds().height).contains(sf::Mouse::getPosition(window)))
                            {
                                pressed = true;
                                indi = horse[i][j]->x;
                                indj = horse[i][j]->y;
                                if (indi + 2 >= 0 && indi + 2 <= 7 && indj + 1 >= 0 && indj + 1 <= 7) if (field[indi + 2][indj + 1]->fig == 0) field[indi + 2][indj + 1]->box.setFillColor(sf::Color::Yellow);
                                else if ((field[indi + 2][indj + 1]->fig == 1 && horse[i][j]->white == true) || (field[indi + 2][indj + 1]->fig == 2 && horse[i][j]->white == false)) field[indi + 2][indj + 1]->box.setFillColor(sf::Color::Red);

                                if (indi + 2 >= 0 && indi + 2 <= 7 && indj - 1 >= 0 && indj - 1 <= 7) if (field[indi + 2][indj - 1]->fig == 0) field[indi + 2][indj - 1]->box.setFillColor(sf::Color::Yellow);
                                else if ((field[indi + 2][indj - 1]->fig == 1 && horse[i][j]->white == true) || (field[indi + 2][indj - 1]->fig == 2 && horse[i][j]->white == false)) field[indi + 2][indj - 1]->box.setFillColor(sf::Color::Red);

                                if (indi - 2 >= 0 && indi - 2 <= 7 && indj + 1 >= 0 && indj + 1 <= 7) if (field[indi - 2][indj + 1]->fig == 0) field[indi - 2][indj + 1]->box.setFillColor(sf::Color::Yellow);
                                else if ((field[indi - 2][indj + 1]->fig == 1 && horse[i][j]->white == true) || (field[indi - 2][indj + 1]->fig == 2 && horse[i][j]->white == false)) field[indi - 2][indj + 1]->box.setFillColor(sf::Color::Red);

                                if (indi - 2 >= 0 && indi - 2 <= 7 && indj - 1 >= 0 && indj - 1 <= 7) if (field[indi - 2][indj - 1]->fig == 0) field[indi - 2][indj - 1]->box.setFillColor(sf::Color::Yellow);
                                else if ((field[indi - 2][indj - 1]->fig == 1 && horse[i][j]->white == true) || (field[indi - 2][indj - 1]->fig == 2 && horse[i][j]->white == false)) field[indi - 2][indj - 1]->box.setFillColor(sf::Color::Red);

                                if (indi + 1 >= 0 && indi + 1 <= 7 && indj + 2 >= 0 && indj + 2 <= 7) if (field[indi + 1][indj + 2]->fig == 0) field[indi + 1][indj + 2]->box.setFillColor(sf::Color::Yellow);
                                else if ((field[indi + 1][indj + 2]->fig == 1 && horse[i][j]->white == true) || (field[indi + 1][indj + 2]->fig == 2 && horse[i][j]->white == false)) field[indi + 1][indj + 2]->box.setFillColor(sf::Color::Red);

                                if (indi - 1 >= 0 && indi - 1 <= 7 && indj + 2 >= 0 && indj + 2 <= 7) if (field[indi - 1][indj + 2]->fig == 0) field[indi - 1][indj + 2]->box.setFillColor(sf::Color::Yellow);
                                else if ((field[indi - 1][indj + 2]->fig == 1 && horse[i][j]->white == true) || (field[indi - 1][indj + 2]->fig == 2 && horse[i][j]->white == false)) field[indi - 1][indj + 2]->box.setFillColor(sf::Color::Red);

                                if (indi + 1 >= 0 && indi + 1 <= 7 && indj - 2 >= 0 && indj - 2 <= 7) if (field[indi + 1][indj - 2]->fig == 0) field[indi + 1][indj - 2]->box.setFillColor(sf::Color::Yellow);
                                else if ((field[indi + 1][indj - 2]->fig == 1 && horse[i][j]->white == true) || (field[indi + 1][indj - 2]->fig == 2 && horse[i][j]->white == false)) field[indi + 1][indj - 2]->box.setFillColor(sf::Color::Red);

                                if (indi - 1 >= 0 && indi - 1 <= 7 && indj - 2 >= 0 && indj - 2 <= 7) if (field[indi - 1][indj - 2]->fig == 0) field[indi - 1][indj - 2]->box.setFillColor(sf::Color::Yellow);
                                else if ((field[indi - 1][indj - 2]->fig == 1 && horse[i][j]->white == true) || (field[indi - 1][indj - 2]->fig == 2 && horse[i][j]->white == false)) field[indi - 1][indj - 2]->box.setFillColor(sf::Color::Red);
                            }

                }
            }

            //офицер
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (!slon[i][j]->dead && slon[i][j]->white == turn)
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pressed == false)
                            if (sf::IntRect(slon[i][j]->sprite.getPosition().x, slon[i][j]->sprite.getPosition().y, slon[i][j]->sprite.getLocalBounds().width, slon[i][j]->sprite.getLocalBounds().height).contains(sf::Mouse::getPosition(window)))
                            {
                                pressed = true;
                                indi = slon[i][j]->x;
                                indj = slon[i][j]->y;
                                bool flag1 = true;
                                bool flag2 = true;
                                bool flag3 = true;
                                bool flag4 = true;
                                for (int k = 1; k < 8; k++)
                                {
                                    if (flag1)
                                        if (indi + k >= 0 && indi + k <= 7 && indj + k >= 0 && indj + k <= 7)
                                            if (field[indi + k][indj + k]->fig == 0) field[indi + k][indj + k]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi + k][indj + k]->fig == 1 && slon[i][j]->white == true) || (field[indi + k][indj + k]->fig == 2 && slon[i][j]->white == false))
                                                    field[indi + k][indj + k]->box.setFillColor(sf::Color::Red);
                                                flag1 = false;
                                            }

                                    if (flag2)
                                        if (indi + k >= 0 && indi + k <= 7 && indj - k >= 0 && indj - k <= 7)
                                            if (field[indi + k][indj - k]->fig == 0) field[indi + k][indj - k]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi + k][indj - k]->fig == 1 && slon[i][j]->white == true) || (field[indi + k][indj - k]->fig == 2 && slon[i][j]->white == false))
                                                    field[indi + k][indj - k]->box.setFillColor(sf::Color::Red);
                                                flag2 = false;
                                            }

                                    if (flag3)
                                        if (indi - k >= 0 && indi - k <= 7 && indj + k >= 0 && indj + k <= 7)
                                            if (field[indi - k][indj + k]->fig == 0) field[indi - k][indj + k]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi - k][indj + k]->fig == 1 && slon[i][j]->white == true) || (field[indi - k][indj + k]->fig == 2 && slon[i][j]->white == false))
                                                    field[indi - k][indj + k]->box.setFillColor(sf::Color::Red);
                                                flag3 = false;
                                            }

                                    if (flag4)
                                        if (indi - k >= 0 && indi - k <= 7 && indj - k >= 0 && indj - k <= 7)
                                            if (field[indi - k][indj - k]->fig == 0) field[indi - k][indj - k]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi - k][indj - k]->fig == 1 && slon[i][j]->white == true) || (field[indi - k][indj - k]->fig == 2 && slon[i][j]->white == false))
                                                    field[indi - k][indj - k]->box.setFillColor(sf::Color::Red);
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
                    if (!ferz[i][j]->dead && ferz[i][j]->white == turn)
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pressed == false)
                            if (sf::IntRect(ferz[i][j]->sprite.getPosition().x, ferz[i][j]->sprite.getPosition().y, ferz[i][j]->sprite.getLocalBounds().width, ferz[i][j]->sprite.getLocalBounds().height).contains(sf::Mouse::getPosition(window)))
                            {
                                pressed = true;
                                indi = ferz[i][j]->x;
                                indj = ferz[i][j]->y;
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
                                            if (field[indi + k][indj + k]->fig == 0) field[indi + k][indj + k]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi + k][indj + k]->fig == 1 && ferz[i][j]->white == true) || (field[indi + k][indj + k]->fig == 2 && ferz[i][j]->white == false))
                                                    field[indi + k][indj + k]->box.setFillColor(sf::Color::Red);
                                                flag1 = false;
                                            }

                                    if (flag2)
                                        if (indi + k >= 0 && indi + k <= 7 && indj - k >= 0 && indj - k <= 7)
                                            if (field[indi + k][indj - k]->fig == 0) field[indi + k][indj - k]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi + k][indj - k]->fig == 1 && ferz[i][j]->white == true) || (field[indi + k][indj - k]->fig == 2 && ferz[i][j]->white == false))
                                                    field[indi + k][indj - k]->box.setFillColor(sf::Color::Red);
                                                flag2 = false;
                                            }

                                    if (flag3)
                                        if (indi - k >= 0 && indi - k <= 7 && indj + k >= 0 && indj + k <= 7)
                                            if (field[indi - k][indj + k]->fig == 0) field[indi - k][indj + k]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi - k][indj + k]->fig == 1 && ferz[i][j]->white == true) || (field[indi - k][indj + k]->fig == 2 && ferz[i][j]->white == false))
                                                    field[indi - k][indj + k]->box.setFillColor(sf::Color::Red);
                                                flag3 = false;
                                            }

                                    if (flag4)
                                        if (indi - k >= 0 && indi - k <= 7 && indj - k >= 0 && indj - k <= 7)
                                            if (field[indi - k][indj - k]->fig == 0) field[indi - k][indj - k]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi - k][indj - k]->fig == 1 && ferz[i][j]->white == true) || (field[indi - k][indj - k]->fig == 2 && ferz[i][j]->white == false))
                                                    field[indi - k][indj - k]->box.setFillColor(sf::Color::Red);
                                                flag4 = false;
                                            }
                                }


                                for (int k = 1; k < 8; k++) //верх-низ-лево-право
                                {
                                    if (indi + k >= 0 && indi + k <= 7)
                                        if (flag5)
                                            if (field[indi + k][indj]->fig == 0) field[indi + k][indj]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi + k][indj]->fig == 1 && ferz[i][j]->white == true) || (field[indi + k][indj]->fig == 2 && ferz[i][j]->white == false))
                                                    field[indi + k][indj]->box.setFillColor(sf::Color::Red);
                                                flag5 = false;
                                            }

                                    if (indj + k >= 0 && indj + k <= 7)
                                        if (flag6)
                                            if (field[indi][indj + k]->fig == 0) field[indi][indj + k]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi][indj + k]->fig == 1 && ferz[i][j]->white == true) || (field[indi][indj + k]->fig == 2 && ferz[i][j]->white == false))
                                                    field[indi][indj + k]->box.setFillColor(sf::Color::Red);
                                                flag6 = false;
                                            }
                                    if (indi - k >= 0 && indi - k <= 7)
                                        if (flag7)
                                            if (field[indi - k][indj]->fig == 0) field[indi - k][indj]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi - k][indj]->fig == 1 && ferz[i][j]->white == true) || (field[indi - k][indj]->fig == 2 && ferz[i][j]->white == false))
                                                    field[indi - k][indj]->box.setFillColor(sf::Color::Red);
                                                flag7 = false;
                                            }

                                    if (indj - k >= 0 && indj - k <= 7)
                                        if (flag8)
                                            if (field[indi][indj - k]->fig == 0) field[indi][indj - k]->box.setFillColor(sf::Color::Yellow);
                                            else
                                            {
                                                if ((field[indi][indj - k]->fig == 1 && ferz[i][j]->white == true) || (field[indi][indj - k]->fig == 2 && ferz[i][j]->white == false))
                                                    field[indi][indj - k]->box.setFillColor(sf::Color::Red);
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
                    if (!king[i][j]->dead && king[i][j]->white == turn)
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pressed == false)
                            if (sf::IntRect(king[i][j]->sprite.getPosition().x, king[i][j]->sprite.getPosition().y, king[i][j]->sprite.getLocalBounds().width, king[i][j]->sprite.getLocalBounds().height).contains(sf::Mouse::getPosition(window)))
                            {
                                pressed = true;
                                indi = king[i][j]->x;
                                indj = king[i][j]->y;
                                for (int c = -1; c < 2; c++)
                                {
                                    for (int k = -1; k < 2; k++)
                                    {
                                        if (c == 0 && k == 0) continue;
                                        if (indi + c >= 0 && indi + c <= 7 && indj + k >= 0 && indj + k <= 7)
                                        {
                                            if (field[indi + c][indj + k]->fig == 0) field[indi + c][indj + k]->box.setFillColor(sf::Color::Yellow);
                                            if ((field[indi + c][indj + k]->fig == 1 && king[i][j]->white == true) || (field[indi + c][indj + k]->fig == 2 && king[i][j]->white == false)) field[indi + c][indj + k]->box.setFillColor(sf::Color::Red);
                                        }
                                    }
                                }
                            }

                }
            }

            //пермещение
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && pressed == true)
                    {
                        if (sf::IntRect(field[i][j]->box.getPosition().x, field[i][j]->box.getPosition().y, field[i][j]->box.getLocalBounds().width, field[i][j]->box.getLocalBounds().height).contains(sf::Mouse::getPosition(window)))
                        {
                            if (field[i][j]->box.getFillColor() == sf::Color::Yellow || field[i][j]->box.getFillColor() == sf::Color::Red)
                            {
                                if (field[i][j]->box.getFillColor() == sf::Color::Red)
                                {
                                    field[i][j]->el->death();
                                }

                                pressed = false;
                                turn = !turn;
                                int x = indi;
                                int y = indj;
                                field[x][y]->el->sprite.setPosition(125 + 100 * i, 125 + 100 * j);
                                for (int k = -7; k < 8; k++)
                                {
                                    for (int c = -7; c < 8; c++)
                                    {
                                        if (y + k < 0 || y + k > 7 || x + c < 0 || x + c > 7) continue;
                                        if ((x + y + k + c) % 2 == 1) field[x + c][y + k]->box.setFillColor(sf::Color::Blue);
                                        else field[x + c][y + k]->box.setFillColor(sf::Color::White);
                                    }
                                }
                                field[x][y]->el->x = i;
                                field[x][y]->el->y = j;
                                field[i][j]->fig = field[x][y]->fig;
                                field[i][j]->el = field[x][y]->el;
                                field[x][y]->fig = 0;
                                field[x][y]->el = nullptr;

                            }

                        }
                    }
                }
            }
        }
        else
        {
        GetMovesIn(peshka,  tower,  horse, slon, ferz, king,  field);
        SepForQ(field);
        GetMove(peshka, tower, horse, slon, ferz, king, field);
        turn = !turn;
        }
    }
    


    window.clear();
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            window.draw(field[i][j]->box);
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!peshka[i][j]->dead) window.draw(peshka[i][j]->sprite);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!tower[i][j]->dead) window.draw(tower[i][j]->sprite);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!horse[i][j]->dead) window.draw(horse[i][j]->sprite);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!slon[i][j]->dead) window.draw(slon[i][j]->sprite);
        }
    }

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!ferz[i][j]->dead) window.draw(ferz[i][j]->sprite);
        }
    }

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!king[i][j]->dead) window.draw(king[i][j]->sprite);
        }
    }

    if (!play)
    {
        window.draw(spritend);
        //window.draw(spritadv);
    }

    window.display();
}

    return 0;
}
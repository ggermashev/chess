#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <queue>


class Point
{
public:
	int x;
	int y;
	Point(int x_, int y_)
	{
		x = x_;
		y = y_;
	}

};

class Element
{
public:
	int cost;
	bool white;
	bool dead = false;
	void death()
	{
		dead = true;
	}
	sf::Sprite sprite;
	int x = 0;
	int y = 0;
	std::vector<Point*> canGo;
	
	
};

struct Comp
{
	bool operator()(Element* el1, Element* el2)
	{
		return el1->cost > el2->cost;
	}
};

class Field
{
public:
	int cost;
	int fig;
	Element* el = nullptr;;
	sf::RectangleShape box;
	std::vector<Element*> list;

	std::priority_queue<Element*, std::vector<Element*>, Comp> qen;
	std::priority_queue<Element*, std::vector<Element*>, Comp> qal;

	Field(int i, int j)
	{
		fig = 0;
		if (j <= 1) fig = 1;
		if (j >= 6) fig = 2;
		if ((i + j) % 2 == 1)
		{
			box.setFillColor(sf::Color::Blue);
		}
		box.setPosition(100 + i * 100, 100 + j * 100);
		box.setSize(sf::Vector2f(100, 100));

		if (j <= 3) cost = j + 1;
		if (j >= 4) cost = 8 - j;
		if (i <=3) cost += i + 1;
		if (i >= 4) cost += (8 - i);
	}

	void Count();
};


class Peshka: public Element
{
public:
	//bool white;
	sf::Texture txt;
	Peshka(int i, int j, bool white_, Field*** field)
	{
		x = i;
		if (j == 0) y = 1;
		if (j == 1) y = 6;
		field[x][y]->el = this;
		white = white_;
		dead = false;

		if (white)
			txt.loadFromFile("images/peshkaw.jpg");
		else
			txt.loadFromFile("images/peshkab.png");
		sprite.setTexture(txt);
		if (white) sprite.setPosition(125 + 100 * x, 725);
		if (!white) sprite.setPosition(125 + 100 * x, 225);
		cost = 50;

	}
};

class Tower : public Element
{
public:
	sf::Texture txt;
	Tower(int i, int j, bool white_, Field*** field)
	{
		if (j == 0)
		{
			if (i == 0)
			{
				x = 0;
				y = 0;
			}
			if (i == 1)
			{
				x = 7;
				y = 0;
			}
		}
		if (j == 1)
		{
			if (i == 0)
			{
				x = 0;
				y = 7;
			}
			if (i == 1)
			{
				x = 7;
				y = 7;
			}
		}
		field[x][y]->el = this;
		white = white_;
		dead = false;

		if (white)
			txt.loadFromFile("images/towerw.png");
		else
			txt.loadFromFile("images/towerb.png");
		sprite.setTexture(txt);
		sprite.setPosition(125 + 100 * x, 125 + 100 * y);
		cost = 500;
		
	}
};

class Horse : public Element
{
public:
	sf::Texture txt;
	Horse(int i, int j, bool white_, Field*** field)
	{
		if (j == 0)
		{
			if (i == 0)
			{
				x = 1;
				y = 0;
			}
			if (i == 1)
			{
				x = 6;
				y = 0;
			}
		}
		if (j == 1)
		{
			if (i == 0)
			{
				x = 1;
				y = 7;
			}
			if (i == 1)
			{
				x = 6;
				y = 7;
			}
		}

		field[x][y]->el = this;
		white = white_;
		dead = false;

		if (white)
			txt.loadFromFile("images/horsew.jpg");
		else
			txt.loadFromFile("images/horseb.jpg");
		sprite.setTexture(txt);
		sprite.setPosition(125 + 100 * x, 125 + 100 * y);
		cost = 300;
		
	}
};

class Slon : public Element
{
public:
	sf::Texture txt;
	Slon(int i, int j, bool white_, Field*** field)
	{
		if (j == 0)
		{
			if (i == 0)
			{
				x = 2;
				y = 0;
			}
			if (i == 1)
			{
				x = 5;
				y = 0;
			}
		}
		if (j == 1)
		{
			if (i == 0)
			{
				x = 2;
				y = 7;
			}
			if (i == 1)
			{
				x = 5;
				y = 7;
			}
		}

		field[x][y]->el = this;
		white = white_;
		dead = false;

		if (white)
			txt.loadFromFile("images/slonw.jpg");
		else
			txt.loadFromFile("images/slonb.png");
		sprite.setTexture(txt);
		sprite.setPosition(125 + 100 * x, 125 + 100 * y);
		cost = 200;
		
	}
};

class Ferz : public Element
{
public:
	sf::Texture txt;
	Ferz(int i, int j, bool white_, Field*** field)
	{
		if (j == 0)
		{
			y = 0;
		}
		if (j == 1)
		{
			y = 7;
		}
		x = 3;

		field[x][y]->el = this;
		white = white_;
		dead = false;

		if (white)
			txt.loadFromFile("images/ferzw.jpg");
		else
			txt.loadFromFile("images/ferzb.jpeg");
		sprite.setTexture(txt);
		sprite.setPosition(125 + 100 * x, 125 + 100 * y);
		cost = 2000;
		
	}
};

class King : public Element
{
public:
	sf::Texture txt;
	King(int i, int j, bool white_, Field*** field)
	{
		if (j == 0)
		{
			y = 0;
		}
		if (j == 1)
		{
			y = 7;
		}
		x = 4;

		field[x][y]->el = this;
		white = white_;
		dead = false;

		if (white)
			txt.loadFromFile("images/kingw.png");
		else
			txt.loadFromFile("images/kingb.jpg");
		sprite.setTexture(txt);
		sprite.setPosition(125 + 100 * x, 125 + 100 * y);
		cost = 999999;
		
	}
};
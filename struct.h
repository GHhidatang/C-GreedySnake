#pragma once

#define MAX_SIZE 100

enum Dir
{
	up = 72,
	down = 80,
	left = 75,
	right = 77
};

struct Coor
{
	int x;
	int y;
};

struct Snake
{
	int n;
	Dir dir;
	Coor szb[MAX_SIZE];
};

struct Food
{
	int x;
	int y;

	int flag;
};














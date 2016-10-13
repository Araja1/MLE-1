#pragma once
#include <iostream>

class Climber
{
public:
	Climber();
	void start();
	double threshold;
	double stoppingCriterion;
	double hypothesis[100];
	double startingPoint;
	double lastFitness;
	double fitness();
	double table[10][10];

	void copy(double);
	void moveOnStepAtRandom(double);
	void undoMove(double);
	virtual ~Climber();
};


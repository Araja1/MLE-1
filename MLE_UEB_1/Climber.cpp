#include "Climber.h"
using namespace std;

Climber::Climber()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == j)
				table[i][j] = 0;
			else
				table[i][j] = rand() % 101;
		}
	}
	for (int i = 0; i < 100; i++) {
		hypothesis[i] = i + 1;
	}
	stoppingCriterion = 1000;
	threshold = 0;
}



double Climber::fitness() {
	//double length = hypotheses[(int)hypo];
	double city1;
	double city2;
	double count = 0;
	for (int i = 0; i < 9; i++) {
		int city1 = hypothesis[i];
		int city2 = hypothesis[i + 1];
		count += table[city1][city2];
	}
	cout << count;
	return count;
}

void Climber::start() {
	lastFitness = fitness();
}

/*threshold is stopping criterion
hypothesis is startingPoint in the hyotheses space
lastFitness = fitness(hypothesis)
do
copy(hypothesis) // copy hypothesis into saveState
moveOneStepAtRandom(hypothesis)
if fitness(hypothesis)>lastFitness then
lastFitness = fitness(hypothesis)
else
undoMove(hyothesis) // copy saveState back into hypothesis
endif
While lastFitness < threshold*/

Climber::~Climber()
{
}



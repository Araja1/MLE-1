#include "Climber.h"
using namespace std;

Climber::Climber()
{
	cout << "Table: " << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == j)
				table[i][j] = 0;
			else
				table[i][j] = rand() % 10;
			cout << table[i][j] << "|";
		}
		cout << endl;
	}
	for (int i = 0; i < 100; i++) {
		hypothesis[i] = rand() % 10;
	}
	threshold = 10;
	
}

double Climber::fitness() {
	//double length = hypotheses[];
	double city1;
	double city2;
	double count = 100;
	for (int i = 0; i < 8; i++) {
		int city1 = hypothesis[i];
		int city2 = hypothesis[i+1];
		if (count > table[city1][city2]) {
			count = table[city1][city2];
		}
	}
	
	cout << endl << "Wert: " << count;
	return count;
}

void Climber::start() {
	int x1 = 0;
	while (x1 < threshold) {
		lastFitness = fitness();
		x1++;
	} 
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



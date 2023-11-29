#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int calculateFitness(vector<vector<int>>& distanceMatrix, vector<int>& chromosomes) {
    int fitness = 0;

    for (int i = 0; i < chromosomes.size() - 1; i++) {
        int city1 = chromosomes[i];
        int city2 = chromosomes[i + 1];

        fitness += distanceMatrix[city1][city2];
    }

    fitness += distanceMatrix[chromosomes.back()][chromosomes[0]];

    return fitness;
}

void mutateChromosomes(vector<int>& chromosomes) {
    srand(time(0));

    int pos1 = rand() % chromosomes.size();
    int pos2 = rand() % chromosomes.size();

    int temp = chromosomes[pos1];
    chromosomes[pos1] = chromosomes[pos2];
    chromosomes[pos2] = temp;
}

int main() {
    vector<vector<int>> distanceMatrix = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };

    vector<int> chromosomes = {0, 1, 2, 3};

    cout << "Chromosomes: ";
    for (int i : chromosomes) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Fitness of Chromosomes: " << calculateFitness(distanceMatrix, chromosomes) << endl;

    mutateChromosomes(chromosomes);

    cout << "Chromosomes: ";
    for (int i : chromosomes) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Fitness of Chromosomes: " << calculateFitness(distanceMatrix, chromosomes) << endl;

    return 0;
}

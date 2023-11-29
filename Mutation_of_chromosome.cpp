#include <bits/stdc++.h>

using namespace std;


vector<int> tspMutation(const vector<int>& chromosome, double mutationRate) {
    vector<int> mutatedChromosome = chromosome;
    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < mutatedChromosome.size(); i++) {
        // Perform mutation with probability mutationRate
        if (rand() / static_cast<double>(RAND_MAX) < mutationRate) {
            // Swap two random cities
            int j = rand() % mutatedChromosome.size();
            swap(mutatedChromosome[i], mutatedChromosome[j]);
        }
    }

    return mutatedChromosome;
}

int main() {
    // Example usage
    vector<vector<int>> distanceMatrix = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

vector<int> initialChromosome = {0, 1, 2, 3};  // Initial order of cities
    double mutationRate = 0.5;  // Probability of mutation for each gene

vector<int> mutatedChromosome = tspMutation(initialChromosome, mutationRate);

    cout << "Initial Chromosome: ";
    for (int city : initialChromosome) {
        cout << city << " ";
    }
    cout << endl;

    cout << "Mutated Chromosome: ";
    for (int city : mutatedChromosome) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

const int NUM_CITIES = 4;
const int MAX_GENERATIONS = 100;
const int POPULATION_SIZE = 10;
const double MUTATION_RATE = 0.1;

class City {
public:
    int x;
    int y;

    City(int x, int y) : x(x), y(y) {}
};

class Route {
public:
    std::vector<int> path;
    double fitness;

    Route(const std::vector<int>& path) : path(path) {}
};

double calculateDistance(const City& city1, const City& city2) {
    int dx = city1.x - city2.x;
    int dy = city1.y - city2.y;
    return std::sqrt(dx * dx + dy * dy);
}

Route generateRandomRoute(int numCities) {
    std::vector<int> path;
    for (int i = 0; i < numCities; ++i) {
        path.push_back(i);
    }
    std::random_shuffle(path.begin(), path.end());
    return Route(path);
}

void calculateFitness(Route& route, const std::vector<City>& cities, const std::vector<std::vector<int>>& adjacencyMatrix) {
    double totalDistance = 0.0;
    int numCities = route.path.size();

    for (int i = 0; i < numCities - 1; ++i) {
        int cityIndex1 = route.path[i];
        int cityIndex2 = route.path[i + 1];
        totalDistance += adjacencyMatrix[cityIndex1][cityIndex2];
    }

    int lastCityIndex = route.path[numCities - 1];
    totalDistance += adjacencyMatrix[lastCityIndex][route.path[0]];
    route.fitness = totalDistance;
}

Route crossover(const Route& parent1, const Route& parent2) {
    std::vector<int> childPath(parent1.path.size(), -1);
    int startPos = std::rand() % parent1.path.size();
    int endPos = std::rand() % parent1.path.size();

    for (int i = 0; i < parent1.path.size(); ++i) {
        if (startPos < endPos && i > startPos && i < endPos) {
            childPath[i] = parent1.path[i];
        } else if (startPos > endPos && !(i < startPos && i > endPos)) {
            childPath[i] = parent1.path[i];
        }
    }

    for (int i = 0; i < parent2.path.size(); ++i) {
        if (std::find(childPath.begin(), childPath.end(), parent2.path[i]) == childPath.end()) {
            auto it = std::find(childPath.begin(), childPath.end(), -1);
            *it = parent2.path[i];
        }
    }

    return Route(childPath);
}

void mutate(Route& route, double mutationRate) {
    for (int i = 0; i < route.path.size(); ++i) {
        if (static_cast<double>(std::rand()) / RAND_MAX < mutationRate) {
            int swapIndex = std::rand() % route.path.size();
            std::swap(route.path[i], route.path[swapIndex]);
        }
    }
}

Route findBestRoute(const std::vector<Route>& population) {
    double bestFitness = std::numeric_limits<double>::max();
    int bestIndex = -1;
    for (int i = 0; i < population.size(); ++i) {
        if (population[i].fitness < bestFitness) {
            bestFitness = population[i].fitness;
            bestIndex = i;
        }
    }
    return population[bestIndex];
}

int main() {
    std::vector<City> cities = { {0, 0}, {10, 15}, {35, 25}, {15, 35} };

    std::vector<std::vector<int>> adjacencyMatrix = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    std::vector<Route> population;
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        Route randomRoute = generateRandomRoute(NUM_CITIES);
        calculateFitness(randomRoute, cities, adjacencyMatrix);
        population.push_back(randomRoute);
    }

    for (int generation = 0; generation < MAX_GENERATIONS; ++generation) {
        std::vector<Route> newPopulation;

        for (int i = 0; i < POPULATION_SIZE; ++i) {
            Route parent1 = findBestRoute(population);
            Route parent2 = findBestRoute(population);
            Route child = crossover(parent1, parent2);
            mutate(child, MUTATION_RATE);
            calculateFitness(child, cities, adjacencyMatrix);
            newPopulation.push_back(child);
        }

        population = newPopulation;
    }

    Route bestRoute = findBestRoute(population);

    std::cout << "Best Route: ";
    for (int cityIndex : bestRoute.path) {
        std::cout << cityIndex << " ";
    }
    std::cout << std::endl;

    std::cout << "Total Distance: " << bestRoute.fitness << std::endl;

    return 0;
}

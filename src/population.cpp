#include <random>
#include "raylib.h"
#include "population.hpp"

Population::Population() {
    active = true;
    for (int i = 0; i < POPULATION_SIZE; i++) {
        pop.push_back(Dot());
    }
}

bool Population::alive() const {
    return active;
}

void Population::draw() {
    for (int i = 0; i < pop.size(); i++) {
        pop[i].draw();
    }
    int size = (GetScreenHeight() > GetScreenWidth()) ? GetScreenWidth() : GetScreenHeight();
    int drawX = size*GOAL.x;
    int drawY = size*GOAL.y;
    DrawCircle(drawX, drawY, size*RADIUS, BLUE);
}

void Population::update() {
    if (active) {
        active = false;
        for (int i = 0; i < pop.size(); i++) {
            pop[i].update();
            active |= pop[i].alive();
        }
    }
}

float Population::sumFitness() const {
    float sum = 0;
    for (int i = 0; i < pop.size(); i++) {
        sum += pop[i].fitness();
    }
    return sum;
}

void Population::naturalSelection() {
    const float TOTAL_FITNESS = sumFitness();
    std::vector<Dot> newPop;
    
    for (int i = 0; i < pop.size(); i++) {
        float fitThres = float(rand())/float(RAND_MAX) * TOTAL_FITNESS;
        float runningFit = pop[0].fitness();
        int ind = 0;
        
        for (int j = 1; j < pop.size(); j++) {
            runningFit += pop[j].fitness();
            if(runningFit >= fitThres) {
                ind = j;
                j = pop.size();
            }
        }
        newPop.push_back(pop[ind].mutate());
    }
    
    pop = newPop;
    active = true;
}
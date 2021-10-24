#include "../include/game/GoldenCoins.hpp"

#include <limits>

GoldenCoins::GoldenCoins() {}

GoldenCoins::GoldenCoins(int goldenCoinsAmount)
    : goldenCoinsAmount_{goldenCoinsAmount}
{}

int GoldenCoins::addGoldenCoins(int amount) {
    if (goldenCoinsAmount_ + amount < std::numeric_limits<int>::max()) {
        return goldenCoinsAmount_ + amount;
    }
    return goldenCoinsAmount_;
}

int GoldenCoins::subtractGoldenCoins(int amount) {
    if (goldenCoinsAmount_ - amount > 0) {
        return goldenCoinsAmount_ - amount;
    }
    return goldenCoinsAmount_;
}

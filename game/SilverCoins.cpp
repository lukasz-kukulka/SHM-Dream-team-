#include "../include/game/SilverCoins.hpp"

#include <limits>

SilverCoins::SilverCoins() {}

SilverCoins::SilverCoins(int silverCoinsAmount)
    : silverCoinsAmount_{silverCoinsAmount}
{}

int SilverCoins::addSilverCoins(SilverCoins amount) {
    if (silverCoinsAmount_ + amount.silverCoinsAmount_ < std::numeric_limits<int>::max()) {
        return silverCoinsAmount_ + amount.silverCoinsAmount_;
    }
    return silverCoinsAmount_;
}

int SilverCoins::subtrackSilverCoins(SilverCoins amount) {
        return silverCoinsAmount_ - amount.silverCoinsAmount_;   
}

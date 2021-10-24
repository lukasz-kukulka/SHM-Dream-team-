# pragma once

struct SilverCoins {
    SilverCoins();
    SilverCoins(int silverCoinsAmount);

    int addSilverCoins(SilverCoins amount);
    int subtrackSilverCoins(SilverCoins amount);

    int silverCoinsAmount_{};
};
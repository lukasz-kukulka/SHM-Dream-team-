#pragma once

struct GoldenCoins {
    GoldenCoins();
    GoldenCoins(int GoldenCoinsAmount);

    int addGoldenCoins(int amount);
    int subtractGoldenCoins(int amount);
private:
    int goldenCoinsAmount_{};
};
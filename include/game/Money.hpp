#pragma once

#include "GoldenCoins.hpp"
#include "SilverCoins.hpp"

constexpr auto exchange_currency = 100;

enum class MoneyResponse {
    aboveLimit,
    belowZero,
    done
};

class Money : public GoldenCoins, public SilverCoins {
public:
    Money(GoldenCoins goldenCoins, SilverCoins silverCoins);

    MoneyResponse subtractCoins(SilverCoins silverCoins) {
        auto resultSilver = silverCoins_.subtrackSilverCoins(silverCoins);
        if (resultSilver < 0) {
            auto conversion = -resultSilver / exchange_currency;
            goldenCoins_.subtractGoldenCoins(conversion + 1);
            silverCoins_.addSilverCoins(exchange_currency * (conversion + 1));
        }
        return MoneyResponse::done;
    }
    
private:
    GoldenCoins goldenCoins_{};
    SilverCoins silverCoins_{};
};

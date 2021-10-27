#include <gtest/gtest.h>

#include <array>

#include "game/Ship.hpp"
#include "game/ShipJson.hpp"
#include "../utility/json/JsonSerializer.hpp"

constexpr size_t defaultNumberOfCycles{5};
Ship ship("galleon", Speed{20}, Turning{10}, Crew{100}, Capacity{200}, Cannons{15}, HP{100}, Upkeep{220}, Cost{12000});

TEST(ShipTest, IncreasingTheNumberOfCrew) {
    Crew crew(10,10);

    for(size_t i = 1; i <= defaultNumberOfCycles; i++) {
        auto response = ship.addCrew(crew);
        ASSERT_EQ(ship.getCrew().currentNumber, (crew.currentNumber * i));
        ASSERT_EQ(response == ShipResponse::done, true);
    }
}

TEST(ShipTest, IncreasingTheNumberOfCrew_ExceedingTheUpperLimit) {
    Crew crew(100,100);
    auto currentCrew = ship.getCrew().currentNumber;
    auto response = ship.addCrew(crew);
    ASSERT_EQ(ship.getCrew().currentNumber == (currentCrew+crew.currentNumber), false);
    ASSERT_EQ(response == ShipResponse::overcrowdedBoard, true);

}

TEST(ShipTest, DecreasingTheNumberOfCrew) {
    Crew crew(10,10);
    auto currentCrew = ship.getCrew().currentNumber;
    for(size_t i = 1; i <= defaultNumberOfCycles; i++) {
        auto response = ship.subtractCrew(crew);
        ASSERT_EQ(ship.getCrew().currentNumber, currentCrew-(crew.currentNumber * i));
        ASSERT_EQ(response == ShipResponse::done, true);
    }
}

TEST(ShipTest, DecreasingTheNumberOfCrew_ExceedingTheLowerLimit) {
    Crew crew(100,100);
    auto currentCrew = ship.getCrew().currentNumber;
    auto response = ship.subtractCrew(crew);
    ASSERT_EQ(ship.getCrew().currentNumber == (currentCrew-crew.currentNumber), false);
    ASSERT_EQ(response == ShipResponse::warningMoreThanYouCan, true);
}


TEST(ShipTest, IncreasingOfUsedCapacity) {
    Capacity capacity(10,10);

    for(size_t i = 1; i <= defaultNumberOfCycles; i++) {
        auto response = ship.addCapacity(capacity);
        ASSERT_EQ(ship.getCapacity().currentUsed, (capacity.currentUsed * i));
        ASSERT_EQ(response == ShipResponse::done, true);
    }
}

TEST(ShipTest, IncreasingOfUsedCapacity_ExceedingTheUpperLimit) {
    Capacity capacity(200,200);
    auto usedCapacity = ship.getCapacity().currentUsed;
    auto response = ship.addCapacity(capacity);
    ASSERT_EQ(ship.getCapacity().currentUsed == (usedCapacity+capacity.currentUsed), false);
    ASSERT_EQ(response == ShipResponse::lackOfSpace, true);
}

TEST(ShipTest, DecreasingOfUsedCapacity) {
    Capacity capacity(10,10);
    auto usedCapacity = ship.getCapacity().currentUsed;
    for(size_t i = 1; i <= defaultNumberOfCycles; i++) {
        auto response = ship.subtractCapacity(capacity);
        ASSERT_EQ(ship.getCapacity().currentUsed, usedCapacity-(capacity.currentUsed * i));
        ASSERT_EQ(response == ShipResponse::done, true);
    }
}

TEST(ShipTest, DecreasingOfUsedCapacity_ExceedingTheLowerLimit) {
    Capacity capacity(200,200);
    auto usedCapacity = ship.getCapacity().currentUsed;
    auto response = ship.subtractCapacity(capacity);
    ASSERT_EQ(ship.getCapacity().currentUsed == (usedCapacity-capacity.currentUsed), false);
    ASSERT_EQ(response == ShipResponse::warningMoreThanYouCan, true);
}

TEST(ShipTest, IncreasingTheNumberOfCannons) {
    Cannons cannons(2,2);

    for(size_t i = 1; i <= defaultNumberOfCycles; i++) {
        auto response = ship.addCannons(cannons);
        ASSERT_EQ(ship.getCannons().currentNumber, (cannons.currentNumber * i));
        ASSERT_EQ(response == ShipResponse::done, true);
    }
}

TEST(ShipTest, IncreasingTheNumberOfCannons_ExceedingTheUpperLimit) {
    Cannons cannons(50,50);
    auto currentCannons = ship.getCannons().currentNumber;
    auto response = ship.addCannons(cannons);
    ASSERT_EQ(ship.getCannons().currentNumber == (currentCannons+cannons.currentNumber), false);
    ASSERT_EQ(response == ShipResponse::lackOfSpace, true);
}


TEST(ShipTest, DecreasingTheNumberOfCannons) {
    Cannons cannons(2,2);
    auto currentCannons = ship.getCannons().currentNumber;
    for(size_t i = 1; i <= defaultNumberOfCycles; i++) {
        auto response = ship.subtractCannons(cannons);
        ASSERT_EQ(ship.getCannons().currentNumber, (currentCannons - cannons.currentNumber * i));
        ASSERT_EQ(response == ShipResponse::done, true);
    }
}

TEST(ShipTest, DecreasingTheNumberOfCannons_ExceedingTheLowerLimit) {
    Cannons cannons(50,50);
    auto currentCannons = ship.getCannons().currentNumber;
    auto response = ship.subtractCannons(cannons);
    ASSERT_EQ(ship.getCannons().currentNumber == (currentCannons-cannons.currentNumber), false);
    ASSERT_EQ(response == ShipResponse::warningMoreThanYouCan, true);
}

TEST(ShipTest, IncreasingTheNumberOfHP) {
    HP hp(10,10);

    for(size_t i = 1; i <= defaultNumberOfCycles; i++) {
        auto response = ship.addHP(hp);
        ASSERT_EQ(ship.getHP().currentValue, (hp.currentValue * i));
        ASSERT_EQ(response == ShipResponse::done, true);
    }
}

TEST(ShipTest, IncreasingTheNumberOfHP_ExceedingTheUpperLimit) {
    HP hp(150,150);
    auto currentHP = ship.getHP().currentValue;
    auto response = ship.addHP(hp);
    ASSERT_EQ(ship.getHP().currentValue, ship.getHP().max);
    ASSERT_EQ(response == ShipResponse::done, true);
}


TEST(ShipTest, DecreasingTheNumberOfHP) {
    HP hp(10,10);
    auto currentHP = ship.getHP().currentValue;
    for(size_t i = 1; i <= defaultNumberOfCycles; i++) {
        auto response = ship.subtractHP(hp);
        ASSERT_EQ(ship.getHP().currentValue, (currentHP - hp.currentValue * i));
        ASSERT_EQ(response == ShipResponse::done, true);
    }
}

TEST(ShipTest, DecreasingTheNumberOfHP_ExceedingTheLowerLimit) {
    HP hp(100, 100);
    auto currentHP = ship.getHP().currentValue;
    auto response = ship.subtractHP(hp);
    ASSERT_EQ(ship.getHP().currentValue, (currentHP - hp.currentValue));
    ASSERT_EQ(response == ShipResponse::done, true);
}

TEST(ShipTest, GivingNameToTheShip) {
    std::array<std::string, defaultNumberOfCycles> names {"Ocean's Queen", "Black Pearl", "The Henrietta", "General Grant", "Albatross" };
    for(size_t i = 0; i < defaultNumberOfCycles; i++) {
        ship.setName(names[i]);
        ASSERT_EQ(ship.getName(), (names[i]));
    }
}
////////////// Convertion from Json and to Json ///////////////

TEST(ShipTest, ConvertionFromJsonToJson) {
    std::array<std::unique_ptr<Ship>, defaultNumberOfCycles> ships{
        std::make_unique<Ship>("Frigate", Speed{11}, Turning{80}, Crew{130}, Capacity{400}, Cannons{26}, HP{220}, Upkeep{220}, Cost{70000}),
        std::make_unique<Ship>("Caravel", Speed{11}, Turning{75}, Crew{200}, Capacity{500}, Cannons{40}, HP{300}, Upkeep{300}, Cost{160000}),
        std::make_unique<Ship>("Trade Fluyt", Speed{10}, Turning{80}, Crew{40}, Capacity{800}, Cannons{8}, HP{300}, Upkeep{240}, Cost{50000}),
        std::make_unique<Ship>("Galeon", Speed{10}, Turning{75}, Crew{180}, Capacity{600}, Cannons{36}, HP{280}, Upkeep{280}, Cost{120000}),
        std::make_unique<Ship>("Carrack", Speed{12}, Turning{75}, Crew{200}, Capacity{550}, Cannons{12}, HP{320}, Upkeep{320}, Cost{140000})};
   
    for(size_t i = 0; i < defaultNumberOfCycles; i++) {
        JsonSerializer::put("ships", ships[i]);
    }

    auto isSaved = JsonSerializer::save("ShipTest.json");
    ASSERT_EQ(isSaved, true);

    JsonSerializer::clear();

    auto isLoaded = JsonSerializer::load("ShipTest.json");
    ASSERT_EQ(isLoaded, true);

    std::array<std::unique_ptr<Ship>, defaultNumberOfCycles> shipsFromJson;
    auto size = JsonSerializer::getSize("ships");
    for (size_t i = 0; i < size; i++) {
        auto isShip = JsonSerializer::get<std::unique_ptr<Ship>>("ships", i);
        if (isShip) {
            shipsFromJson[i] = std::move(isShip.value());
        }
        ASSERT_EQ((ships[i])->getShipType(), (shipsFromJson[i])->getShipType());
    }
}


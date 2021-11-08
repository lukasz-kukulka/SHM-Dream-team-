#include "../include/game/Ship.hpp"
#include "../include/game/ShipBuilder.hpp"


ShipBuilder& ShipBuilder::addFactorySettings() {
    return *this;
}
ShipBuilder& ShipBuilder::setShipType(const std::string& type){
    ship_.shipType_ = type;
    return *this;
}
ShipBuilder& ShipBuilder::setSpeed(const Speed& speed) {
        ship_.speed_ = speed;
        return *this;
}
ShipBuilder& ShipBuilder::setTurning(const Turning& turning) {
        ship_.turning_ = turning;
        return *this;
}
ShipBuilder& ShipBuilder::setMaxCrew(const Crew& crew) {
        ship_.crew_.max = crew.max;
        return *this;
}
ShipBuilder& ShipBuilder::setMaxCapacity(const Capacity& capacity) {
        ship_.capacity_.max = capacity.max;
        return *this;
}
ShipBuilder& ShipBuilder::setMaxCannons(const Cannons& cannons) {
        ship_.cannons_.max = cannons.max;
        return *this;
}
ShipBuilder& ShipBuilder::setUpkeep(const Upkeep& upkeep) {
        ship_.upkeep_ = upkeep;
        return *this;
}
ShipBuilder& ShipBuilder::setCost(const Cost& cost) {
        ship_.cost_ = cost;
        return *this;
}


ShipBuilder& ShipBuilder::addOwnSettings() {
    return *this;
}
ShipBuilder& ShipBuilder::setName(const std::string& name) {
        ship_.name_ = name;
        return *this;
}
ShipBuilder& ShipBuilder::setCrew(const Crew& crew) {
        ship_.crew_.currentNumber = crew.currentNumber;
        return *this;
}
ShipBuilder& ShipBuilder::setCapacity(const Capacity& capacity) {
        ship_.capacity_.currentUsed = capacity.currentUsed;
        return *this;
}
ShipBuilder& ShipBuilder::setCannons(const Cannons& cannons) {
        ship_.cannons_.currentNumber = cannons.currentNumber;
        return *this;
}
ShipBuilder& ShipBuilder::setHP(const HP& hp) {
        ship_.hp_.currentValue = hp.currentValue;
        return *this;
}


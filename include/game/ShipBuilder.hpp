#pragma once 
#include "Ship.hpp"

class ShipBuilder {
    Ship ship_;
    
    public:
    ShipBuilder() = default;
    
    operator Ship() const {
        return std::move(ship_);
    }

    ShipBuilder& addFactorySettings();
    ShipBuilder& setShipType(const std::string&);
    ShipBuilder& setSpeed(const Speed&);
    ShipBuilder& setTurning(const Turning&);
    ShipBuilder& setMaxCrew(const Crew&);
    ShipBuilder& setMaxCapacity(const Capacity&);
    ShipBuilder& setMaxCannons(const Cannons&);
    ShipBuilder& setUpkeep(const Upkeep&);
    ShipBuilder& setCost(const Cost&);

    ShipBuilder& addOwnSettings();
    ShipBuilder& setName(const std::string&);
    ShipBuilder& setCrew(const Crew&);
    ShipBuilder& setCapacity(const Capacity&);
    ShipBuilder& setCannons(const Cannons&);
    ShipBuilder& setHP(const HP&);
};

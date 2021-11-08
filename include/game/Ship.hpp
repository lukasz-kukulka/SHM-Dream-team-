#pragma once
#include <cstddef>
#include <string>

#include "ShipInterface.hpp"
#include "StructsForShip.hpp"

class ShipBuilder;

enum class ShipResponse {
    done,
    lackOfSpace,
    overcrowdedBoard,
    warningMoreThanYouCan
};

class Ship : public ShipInterface {
    friend ShipBuilder;
public:
  ~Ship() override = default;

  static ShipBuilder create();

  const std::string& getShipType() const override;
  const Speed& getSpeed() const override;
  const Turning& getTurning() const override;
  const Crew& getCrew() const override;
  const Capacity& getCapacity() const override;
  const Cannons& getCannons() const override;
  const HP& getHP() const override;
  const Upkeep& getUpkeep() const override;
  const Cost& getCost() const override;
  const std::string& getName() const override;

  void setName( const std::string& name ) override;

  ShipResponse subtractCrew(Crew crewNum) override;  
  ShipResponse subtractCapacity(Capacity capacityNum) override; 
  ShipResponse subtractCannons(Cannons cannonsNum) override; 
  ShipResponse subtractHP(HP hpNum) override;

  ShipResponse addCrew(Crew crewNum) override;  
  ShipResponse addCapacity(Capacity capacityNum) override;  
  ShipResponse addCannons(Cannons cannonsNum) override; 
  ShipResponse addHP(HP hpNum) override;

private:
  Ship();

  std::string shipType_{};
  Speed speed_{};
  Turning turning_{};
  Crew crew_;
  Capacity capacity_;
  Cannons cannons_;
  HP hp_;
  Upkeep upkeep_{};
  Cost cost_{};
  std::string name_{};
};

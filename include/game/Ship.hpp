#pragma once
#include <cstddef>
#include <string>

#include "ShipInterface.hpp"
#include "StructsForShip.hpp"

enum class ShipResponse {
    done,
    lackOfSpace,
    overcrowdedBoard,
    warningMoreThanYouCan
};

class Ship : public ShipInterface {
public:
  Ship( const std::string& shipType, Speed speed, Turning turning,
        const Crew& crew, const Capacity& capacity, const Cannons& cannons, 
        const HP& hp, Upkeep upkeep, Cost cost, const std::string& name );
  Ship( const std::string& shipType, Speed speed, Turning turning,
        const Crew& crew, const Capacity& capacity, const Cannons& cannons,
        const HP& hp, Upkeep upkeep, Cost cost );

  ~Ship() override = default;

  const std::string& getShipType() const override { return shipType_; }
  Speed getSpeed() const override { return speed_; }
  Turning getTurning() const override { return turning_; }
  const Crew& getCrew() const override { return crew_; }
  const Capacity& getCapacity() const override { return capacity_; }
  const Cannons& getCannons() const override { return cannons_; }
  const HP& getHP() const override { return hp_; }
  Upkeep getUpkeep() const override { return upkeep_; }
  Cost getCost() const override { return cost_; }
  const std::string& getName() const override { return name_; }

  void setName( const std::string& name ) override { name_ = name; }

  ShipResponse subtructCrew(Crew crewNum) override;  
  ShipResponse subtructCapacity(Capacity capacityNum) override; 
  ShipResponse subtructCannons(Cannons cannonsNum) override; 
  ShipResponse subtructHP(HP hpNum) override;

  ShipResponse addCrew(Crew crewNum) override;  
  ShipResponse addCapacity(Capacity capacityNum) override;  
  ShipResponse addCannons(Cannons cannonsNum) override; 
  ShipResponse addHP(HP hpNum) override;

private:
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

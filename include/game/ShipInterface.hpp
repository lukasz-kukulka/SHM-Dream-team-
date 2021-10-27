#pragma once
#include <cstddef>
#include <string>

struct Speed;
struct Turning;
struct Crew;
struct Capacity;
struct Cannons;
struct HP;
struct Upkeep;
struct Cost;

enum class ShipResponse;

class ShipInterface {
public:
  virtual ~ShipInterface() = default; 
  
  virtual const std::string &getShipType() const = 0;
  virtual Speed getSpeed() const = 0;
  virtual Turning getTurning() const = 0;
  virtual const Crew& getCrew() const = 0;
  virtual const Capacity& getCapacity() const = 0;
  virtual const Cannons& getCannons() const = 0;
  virtual const HP& getHP() const = 0;
  virtual Upkeep getUpkeep() const = 0;
  virtual Cost getCost() const = 0;
  virtual const std::string &getName() const = 0;

  virtual void setName(const std::string &name) = 0;

  virtual ShipResponse subtractCrew(Crew crewNum) = 0;  
  virtual ShipResponse subtractCapacity(Capacity capacityNum) = 0; 
  virtual ShipResponse subtractCannons(Cannons cannonsNum) = 0; 
  virtual ShipResponse subtractHP(HP hpNum) = 0;

  virtual ShipResponse addCrew(Crew crewNum) = 0;  
  virtual ShipResponse addCapacity(Capacity capacityNum) = 0;  
  virtual ShipResponse addCannons(Cannons cannonsNum) = 0; 
  virtual ShipResponse addHP(HP hpNum) = 0;
};

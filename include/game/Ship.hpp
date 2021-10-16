#pragma once
#include <cstddef>
#include <string>

struct Speed {
  operator size_t() { return value; }

  size_t value{};
};

struct Turning {
  operator size_t() { return value; }

  size_t value{};
};

struct Crew {
  Crew(size_t maxCrew) : max(maxCrew) {}
  Crew(size_t crewNumber, size_t maxCrew)
      : currentNumber(crewNumber), max(maxCrew) {}

  bool operator<(const Crew &other) const {
    return currentNumber < other.currentNumber;
  }

  size_t currentNumber{};
  size_t max{};
};

struct Capacity {
  Capacity(size_t maxCapacity) : max(maxCapacity) {}
  Capacity(size_t usedCapacity, size_t maxCapacity)
      : currentUsed(usedCapacity), max(maxCapacity) {}

  bool operator<(const Capacity &other) const {
    return currentUsed < other.currentUsed;
  }

  size_t currentUsed{};
  size_t max{};
};

struct Cannons {
  Cannons(size_t maxCannons) : max(maxCannons) {}
  Cannons(size_t currentCannonsNumber, size_t maxCannons)
      : currentNumber(currentCannonsNumber), max(maxCannons) {}

  bool operator<(const Cannons &other) const {
    return currentNumber < other.currentNumber;
  }

  size_t currentNumber{};
  size_t max;
};

struct HP {
  HP(int maxHP) : max(maxHP) {}
  HP(int currentHPValue, int maxHP)
      : currentValue(currentHPValue), max(maxHP) {}

  int currentValue{};
  int max{};
};

struct Upkeep {
  operator size_t() { return value; }

  size_t value{};
};

struct Cost {
  operator size_t() { return value; }

  size_t value{};
};

class Ship {
public:
  Ship() = default;
  Ship(const std::string &shipType, Speed speed, Turning turning, Crew crew,
       Capacity capacity, Cannons cannons, HP hp, Upkeep upkeep, Cost cost);
  Ship(const std::string &shipType, Speed speed, Turning turning, Crew crew,
       Capacity capacity, Cannons cannons, HP hp, Upkeep upkeep, Cost cost,
       const std::string &name);

  const std::string &getShipType() const;
  Speed getSpeed() const;
  Turning getTurning() const;
  size_t getCrew() const;
  size_t getMaxCrew() const;
  size_t getCapacity() const;
  size_t getMaxCapacity() const;
  size_t getCannons() const;
  size_t getMaxCannons() const;
  int getHP() const;
  int getMaxHP() const;
  Upkeep getUpkeep() const;
  Cost getCost() const;
  const std::string &getName() const;

  void setName(const std::string &name);

  Ship &operator-=(Crew crewNum); // Throw exception 
  Ship &operator-=(Capacity capacityNum); // Throw exception 
  Ship &operator-=(Cannons cannonsNum); // Throw exception
  Ship &operator-=(HP hpNum);

  Ship &operator+=(Crew crewNum); // Throw exception 
  Ship &operator+=(Capacity capacityNum); // Throw exception 
  Ship &operator+=(Cannons cannonsNum); // Throw exception 
  Ship &operator+=(HP hpNum);

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

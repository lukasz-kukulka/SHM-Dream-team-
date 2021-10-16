#include <algorithm>
#include <stdexcept>

#include "../include/game/Ship.hpp"

Ship::Ship(const std::string &shipType, Speed speed, Turning turning, Crew crew,
           Capacity capacity, Cannons cannons, HP hp, Upkeep upkeep, Cost cost)
    : shipType_(shipType), speed_(speed), turning_(turning), crew_(crew),
      capacity_(capacity), cannons_(cannons), hp_(hp), upkeep_(upkeep),
      cost_(cost) {}

Ship::Ship(const std::string &shipType, Speed speed, Turning turning, Crew crew,
           Capacity capacity, Cannons cannons, HP hp, Upkeep upkeep, Cost cost,
           const std::string &name)
    : shipType_(shipType), speed_(speed), turning_(turning), crew_(crew),
      capacity_(capacity), cannons_(cannons), hp_(hp), upkeep_(upkeep),
      cost_(cost), name_(name) {}

const std::string &Ship::getShipType() const { return shipType_; }

Speed Ship::getSpeed() const { return speed_; }

Turning Ship::getTurning() const { return turning_; }

size_t Ship::getCrew() const { return crew_.currentNumber; }

size_t Ship::getMaxCrew() const { return crew_.max; }

size_t Ship::getCapacity() const { return capacity_.currentUsed; }

size_t Ship::getMaxCapacity() const { return capacity_.max; }

size_t Ship::getCannons() const { return cannons_.currentNumber; }

size_t Ship::getMaxCannons() const { return cannons_.max; }

int Ship::getHP() const { return hp_.currentValue; }

int Ship::getMaxHP() const { return hp_.max; }

Upkeep Ship::getUpkeep() const { return upkeep_; }

Cost Ship::getCost() const { return cost_; }

const std::string &Ship::getName() const { return name_; }

void Ship::setName(const std::string &name) { name_ = name; }

Ship &Ship::operator-=(Crew crewNum) {
  if (crew_ < crewNum) {
    throw std::invalid_argument("Not allowed! You will be below zero!");
  }
  crew_.currentNumber -= crewNum.currentNumber;
  return *this;
}

Ship &Ship::operator-=(Capacity capacityNum) {
  if (capacity_ < capacityNum) {
    throw std::invalid_argument("Not allowed! You will be below zero!");
  }
  capacity_.currentUsed -= capacityNum.currentUsed;
  return *this;
}

Ship &Ship::operator-=(Cannons cannonsNum) {
  if (cannons_ < cannonsNum) {
    throw std::invalid_argument("Not allowed! You will be below zero!");
  }
  cannons_.currentNumber -= cannonsNum.currentNumber;
  return *this;
}

// I assume that ship can take big hit during battle and HP can drop below 0 - I
// decide to implement it without any exception - in our game there should be
// some mechanism which will be observe current value of HP
Ship &Ship::operator-=(HP hpNum) {
  hp_.currentValue -= hpNum.currentValue;
  return *this;
}

Ship &Ship::operator+=(Crew crewNum) {
  if (crew_.max - crew_.currentNumber < crewNum.currentNumber) {
    throw std::invalid_argument(
        "Not allowed! There is not enough space on board!");
  }
  crew_.currentNumber += crewNum.currentNumber;
  return *this;
}

Ship &Ship::operator+=(Capacity capacityNum) {
  if (capacity_.max - capacity_.currentUsed < capacityNum.currentUsed) {
    throw std::invalid_argument(
        "Not allowed! There is not enough space on board!");
  }
  capacity_.currentUsed += capacityNum.currentUsed;
  return *this;
}

Ship &Ship::operator+=(Cannons cannonsNum) {
  if (cannons_.max - cannons_.currentNumber < cannonsNum.currentNumber) {
    throw std::invalid_argument(
        "Not allowed! There is not enough space on board!");
  }
  cannons_.currentNumber += cannonsNum.currentNumber;
  return *this;
}

Ship &Ship::operator+=(HP hpNum) {
  hp_.currentValue += hpNum.currentValue;
  hp_.currentValue = std::min(hp_.currentValue, hp_.max);
  return *this;
}

#pragma once
#include <memory>

#include "../../utility/json/JsonSerializer.hpp"
#include "Ship.hpp"

template <> Json JsonConvert::to_json(const std::unique_ptr<Ship> &object) {

  Json json;
  json.putValue("shipType", object->getShipType());
  json.putValue("speed", object->getSpeed().value);
  json.putValue("turning", object->getTurning().value);
  json.putValue("maxCrew", object->getCrew().max);
  json.putValue("capacity", object->getCapacity().max);
  json.putValue("maxCannons", object->getCannons().max);
  json.putValue("maxHP", object->getHP().max);
  json.putValue("upkeep", object->getUpkeep().value);
  json.putValue("cost", object->getCost().value);

  return json;
}

template <> std::unique_ptr<Ship> JsonConvert::from_json(const Json &json) {

  const auto shipType = json.getValue<std::string>("shipType");
  const auto speed = json.getValue<size_t>("speed");
  const auto turning = json.getValue<size_t>("turning");
  const auto maxCrew = json.getValue<size_t>("maxCrew");
  const auto capacity = json.getValue<size_t>("capacity");
  const auto maxCannons = json.getValue<size_t>("maxCannons");
  const auto maxHP = json.getValue<int>("maxHP");
  const auto upkeep = json.getValue<size_t>("upkeep");
  const auto cost = json.getValue<size_t>("cost");

  return std::make_unique<Ship>(shipType, Speed{speed}, Turning{turning},
                                Crew{maxCrew}, Capacity{capacity},
                                Cannons{maxCannons}, HP{maxHP}, Upkeep{upkeep},
                                Cost{cost});
}

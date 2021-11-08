#include <iostream>

#include "../include/game/Ship.hpp"
#include "../include/game/ShipBuilder.hpp"

int main() {
    auto ship = Ship::create()
                            .addFactorySettings().setShipType("Galleon")
                                                 .setSpeed(Speed{20})
                                                 .setTurning(Turning{85});
    std::cout << typeid(ship).name() << '\n';
    return 0;

}



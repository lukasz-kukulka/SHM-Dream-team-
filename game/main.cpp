#include <iostream>

#include "../include/game/Ship.hpp"

int main() {

    Ship ship("galleon", Speed{20}, Turning{10}, Crew{100}, Capacity{200}, Cannons{15}, HP{100}, Upkeep{220}, Cost{12000});
    Crew crew(10,10);

    for (int i = 1; i <=11; i++) {
        ship.addCrew(crew);
        std::cout<<std::boolalpha << (ship.getCrew().currentNumber == crew.currentNumber * i) << '\n';

    }
    std::cout << "current: " << ship.getCrew().currentNumber << "  max: " << ship.getCrew().max << '\n';
    return 0;

}



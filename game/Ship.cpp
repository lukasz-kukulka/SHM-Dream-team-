#include "../include/game/Ship.hpp"

#include <algorithm>
#include <stdexcept>

Ship::Ship( const std::string& shipType, Speed speed, Turning turning,const Crew& crew, const Capacity& capacity,
            const Cannons& cannons, const HP& hp, Upkeep upkeep, Cost cost, const std::string& name )
    : shipType_( shipType )
    , speed_( speed )
    , turning_( turning )
    , crew_( crew )
    , capacity_( capacity )
    , cannons_( cannons )
    , hp_( hp )
    , upkeep_( upkeep )
    , cost_( cost )
    , name_( name ) 
    {}
Ship::Ship( const std::string& shipType, Speed speed, Turning turning,const Crew& crew, const Capacity& capacity,
            const Cannons& cannons, const HP& hp, Upkeep upkeep, Cost cost )
    : Ship( shipType, speed, turning, crew, capacity, cannons, hp, upkeep, cost, "" ) 
    {}

ShipResponse Ship::subtructCrew( Crew crewNum ) {
    if ( crew_ < crewNum ) {
        return ShipResponse::warningMoreThanYouCan;
    }
    crew_.currentNumber -= crewNum.currentNumber;
    return ShipResponse::done;
}

ShipResponse Ship::subtructCapacity( Capacity capacityNum ) {
    if ( capacity_ < capacityNum ) {
        return ShipResponse::warningMoreThanYouCan;
    }
    capacity_.currentUsed -= capacityNum.currentUsed;
    return ShipResponse::done;
}

ShipResponse Ship::subtructCannons( Cannons cannonsNum ) {
    if ( cannons_ < cannonsNum ) {
        return ShipResponse::warningMoreThanYouCan;
    }
    cannons_.currentNumber -= cannonsNum.currentNumber;
    return ShipResponse::done;
}

// I assume that ship can take big hit during battle and HP can drop below 0
// - in our game there should be
// some mechanism which will be observe current value of HP
ShipResponse Ship::subtructHP( HP hpNum ) {
    hp_.currentValue -= hpNum.currentValue;
    return ShipResponse::done;
}

ShipResponse Ship::addCrew( Crew crewNum ) {
    if ( crew_.max - crew_.currentNumber < crewNum.currentNumber ) {
        return ShipResponse::overcrowdedBoard;
    }
    crew_.currentNumber += crewNum.currentNumber;
    return ShipResponse::done;
}

ShipResponse Ship::addCapacity( Capacity capacityNum ) {
    if ( capacity_.max - capacity_.currentUsed < capacityNum.currentUsed ) {
        return ShipResponse::lackOfSpace;
    }
    capacity_.currentUsed += capacityNum.currentUsed;
    return ShipResponse::done;
}

ShipResponse Ship::addCannons( Cannons cannonsNum ) {
    if ( cannons_.max - cannons_.currentNumber < cannonsNum.currentNumber ) {
        return ShipResponse::lackOfSpace;
    }
    cannons_.currentNumber += cannonsNum.currentNumber;
    return ShipResponse::done;
}

ShipResponse Ship::addHP( HP hpNum ) {
    hp_.currentValue += hpNum.currentValue;
    hp_.currentValue = std::min( hp_.currentValue, hp_.max );
    return ShipResponse::done;
}

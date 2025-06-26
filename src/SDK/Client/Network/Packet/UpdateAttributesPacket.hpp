#pragma once

#include "../../../../Utils/Memory/Memory.hpp"
#include "Packet.hpp"
#include <string>

class PlayerAttributesModifierType {
public:
    std::string Id;
    std::string Name;
    float Amount;
    int32_t Operation;
    int32_t Operand;
    bool Serializable;
};

class PlayerAttributesType {
public:
    float Min;
    float Max;
    float Current;
    float DefaultMin;
    float DefaultMax;
    float Default;
    std::string name;
    std::vector<PlayerAttributesModifierType> Modifiers;
};



class UpdateAttributesPacket : public Packet {
public:
    int64_t RuntimeEntityID;
    std::vector<PlayerAttributesType> PlayerAttributes;
    int64_t Tick;

    UpdateAttributesPacket() = default;

};

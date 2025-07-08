#pragma once

#include "../Module.hpp"
#include "Events/Network/PacketEvent.hpp"


class PacketLogger : public Module {
private:

public:
    PacketLogger();;

    void onEnable() override;

    void onDisable() override;

    void defaultConfig() override;

    void onPacketReceive(PacketEvent& event);
};

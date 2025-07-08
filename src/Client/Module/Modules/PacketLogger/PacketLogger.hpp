#pragma once

#include "../Module.hpp"
#include "Events/Network/PacketEvent.hpp"
#include <string>
#include <cstring> // memcpy
#include <cstdio>



class PacketLogger : public Module {
private:
    std::string buffer;
    size_t write_offset = 0;
public:
    PacketLogger();;

    void onEnable() override;

    void onDisable() override;

    void defaultConfig() override;

    void onPacketReceive(PacketEvent& event);
};

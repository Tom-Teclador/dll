#pragma once

#include "../Module.hpp"
#include "Events/Network/PacketEvent.hpp"
#include "Events/Network/PacketSendEvent.hpp"
#include <string>
#include <cstring> // memcpy
#include <cstdio>



class PacketLogger : public Module {
private:
    std::string buffer;
    size_t write_offset = 0;

    void appendHex(int value);

    void appendInt(int value);
public:
    PacketLogger();;

    void onEnable() override;

    void onDisable() override;

    void defaultConfig() override;

    void onPacketReceive(PacketEvent& event);

    void onPacketSend(PacketSendEvent& event);

    void onPacket(Packet& packet, bool serverbound);
};

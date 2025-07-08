#include "PacketLogger.hpp"

#include "Events/EventManager.hpp"

PacketLogger::PacketLogger(): Module("PacketLogger", "Logs clientbound and serverbound packets.", IDR_REACH_PNG, "")
{

}

void PacketLogger::onEnable()
{
    Listen(this, PacketEvent, &PacketLogger::onPacketReceive)
    Module::onEnable();
}

void PacketLogger::onDisable()
{
    Deafen(this, PacketEvent, &PacketLogger::onPacketReceive)
    Module::onDisable();
}

void PacketLogger::defaultConfig()
{
    Module::defaultConfig("core");
    
}

void PacketLogger::onPacketReceive(PacketEvent& event) {

}
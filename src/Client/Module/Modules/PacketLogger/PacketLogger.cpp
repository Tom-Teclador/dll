#include "PacketLogger.hpp"

#include "Events/EventManager.hpp"


PacketLogger::PacketLogger(): Module("PacketLogger", "Logs clientbound and serverbound packets.", IDR_REACH_PNG, "")
{
    buffer.resize(1 << 26); //64MB
    write_offset = 0;
}

void PacketLogger::onEnable()
{
    Listen(this, PacketEvent, &PacketLogger::onPacketReceive)
    Module::onEnable();
}

void PacketLogger::onDisable()
{
    FlarialGUI::Notify("Disabled!");
    FILE* f = std::fopen((Utils::getClientPath() + "\\logs\\packet.log").data(), "wb");
    if (f) {
        FlarialGUI::Notify("Disabled! 2");
        std::memcpy(&buffer[write_offset], "Hello", 5);
        write_offset += 5;
        buffer[write_offset++] = '\n';
        buffer[write_offset++] = '\n';

        std::fwrite(buffer.data(), 1, write_offset, f);
        std::fclose(f);
    }

    Deafen(this, PacketEvent, &PacketLogger::onPacketReceive)
    Module::onDisable();
}

void PacketLogger::defaultConfig()
{
    Module::defaultConfig("core");
    
}

void PacketLogger::onPacketReceive(PacketEvent& event) {
    FlarialGUI::Notify("Event!");
    if (!this->isEnabled()) return;
    FlarialGUI::Notify("Event! 2");
    std::memcpy(&buffer[write_offset], "Hello", 5);
    write_offset += 5;
    buffer[write_offset++] = '\n';
    buffer[write_offset++] = '\n';
}
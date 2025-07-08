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
    FILE* f = std::fopen("C:\\Users\\tom\\Desktop\\Log MCBE.txt", "wb");
    if (f) {
        std::fwrite(buffer, 1, write_offset, f);
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
    if (!this->isEnabled()) return;

    std::memcpy(&buffer[write_offset], "Hello", 5);
    write_offset += 5;
    buffer[write_offset++] = '\n';
    buffer[write_offset++] = '\n';
}
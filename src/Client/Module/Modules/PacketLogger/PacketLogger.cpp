#include "PacketLogger.hpp"

#include "Events/EventManager.hpp"


PacketLogger::PacketLogger(): Module("PacketLogger", "Logs clientbound and serverbound packets.", IDR_REACH_PNG, "")
{
    buffer.resize(1 << 26); //64MB
    write_offset = 0;
}

void PacketLogger::onEnable()
{
    Listen(this, PacketEvent, &PacketLogger::onPacketReceive);
    Listen(this, PacketSendEvent, &PacketLogger::onPacketSend);
    Module::onEnable();
}

void PacketLogger::onDisable()
{
    FILE* f = std::fopen((Utils::getClientPath() + "\\logs\\packet.log").data(), "wb");
    if (f) {
        std::fwrite(buffer.data(), 1, write_offset, f);
        std::fclose(f);
    }

    Deafen(this, PacketEvent, &PacketLogger::onPacketReceive);
    Deafen(this, PacketSendEvent, &PacketLogger::onPacketSend);
    Module::onDisable();
}

void PacketLogger::defaultConfig()
{
    Module::defaultConfig("core");
    
}

void PacketLogger::onPacketReceive(PacketEvent& event) {
    if (!this->isEnabled()) return;

    std::memcpy(&buffer[write_offset], "Clientbound ", 12);
    write_offset += 12;

    onPacket(*event.getPacket(), false);

    std::memcpy(&buffer[write_offset], "}\n\n", 3);
    write_offset += 3;
}

void PacketLogger::onPacketSend(PacketSendEvent& event) {
    if (!this->isEnabled()) return;

    std::memcpy(&buffer[write_offset], "Serverbound ", 12);
    write_offset += 12;

    onPacket(*event.getPacket(), true);

    std::memcpy(&buffer[write_offset], "}\n\n", 3);
    write_offset += 3;
}

void PacketLogger::onPacket(Packet& packet, bool serverbound) {

    int id = static_cast<int>(packet.getId());
    
    appendInt(id);
    std::memcpy(&buffer[write_offset++], " ", 1);
    appendHex(id);
    std::memcpy(&buffer[write_offset], " {\n", 3);
    write_offset += 3;
    
}

inline void PacketLogger::appendInt(int value) {
    uint32_t uval = static_cast<uint32_t>(value);
    char* out = buffer.data() + write_offset -1;
    uint32_t tmp = uval;
    size_t digits = (uval == 0) ? 1 : 0;
    while (tmp) {
        tmp /= 10;
        ++digits;
    }

    size_t pos = digits;

    do {
        out[pos--] = '0' + (uval % 10);
        uval /= 10;
    } while (uval);

    write_offset += digits;
}

inline void PacketLogger::appendHex(int value) {
    constexpr char hex_digits[] = "0123456789abcdef";

    uint32_t val = static_cast<uint32_t>(value);
    size_t digits = (val == 0) ? 1 : 0;
    uint32_t tmp = val;
    while (tmp) {
        tmp >>= 4;
        ++digits;
    }

    char* out = buffer.data() + write_offset + 1;
    out[0] = '0';
    out[1] = 'x';

    size_t pos = digits;
    if (val == 0) {
        out[2] = '0';
    }
    else {
        while (val) {
            out[pos--] = hex_digits[val & 0xF];
            val >>= 4;
        }
    }

    write_offset += 2 + digits;
}
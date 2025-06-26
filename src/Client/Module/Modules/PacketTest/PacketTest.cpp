#include "PacketTest.hpp"

#include "Events/EventManager.hpp"


void PacketTest::onEnable() {
    Listen(this, PacketEvent, &AutoGG::onPacketReceive)
    Module::onEnable();
}

void PacketTest::onDisable() {
    Deafen(this, PacketEvent, &AutoGG::onPacketReceive)
    Module::onDisable();
}

void PacketTest::defaultConfig() {
    Module::defaultConfig("core");
    setDef("text", (std::string)"GG");
    
}

void PacketTest::settingsRender(float settingsOffset) {

}

void PacketTest::onPacketReceive(PacketEvent& event) {
    if (!this->isEnabled()) return;
    MinecraftPacketIds id = event.getPacket()->getId();

    // TODO: add support for other servers (look for "won the game" text)
    if (id == MinecraftPacketIds::UpdateAttributes) {
        auto* pkt = reinterpret_cast<UpdateAttributesPacket*>(event.getPacket());
        FlarialGUI::Notify(pkt->RuntimeEntityID);
    }
}

void PacketTest::SendGG() {

};
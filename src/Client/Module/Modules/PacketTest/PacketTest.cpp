#include "PacketTest.hpp"
#include <string>
#include "Events/EventManager.hpp"


void PacketTest::onEnable() {
    Listen(this, PacketEvent, &PacketTest::onPacketReceive)
    Module::onEnable();
}

void PacketTest::onDisable() {
    Deafen(this, PacketEvent, &PacketTest::onPacketReceive)
    Module::onDisable();
}

void PacketTest::defaultConfig() {
    Module::defaultConfig("core");
    setDef("text", (std::string)"GG");
    
}

void PacketTest::settingsRender(float settingsOffset) {


    float x = Constraints::PercentageConstraint(0.019, "left");
    float y = Constraints::PercentageConstraint(0.10, "top");

    const float scrollviewWidth = Constraints::RelativeConstraint(0.12, "height", true);


    FlarialGUI::ScrollBar(x, y, 140, Constraints::SpacingConstraint(5.5, scrollviewWidth), 2);
    FlarialGUI::SetScrollView(x - settingsOffset, Constraints::PercentageConstraint(0.00, "top"),
        Constraints::RelativeConstraint(1.0, "width"),
        Constraints::RelativeConstraint(0.88f, "height"));

    addHeader("Auto GG");
    addTextBox("Text", "The text to send.", 0, "text");

    FlarialGUI::UnsetScrollView();

    resetPadding();
}

void PacketTest::onPacketReceive(PacketEvent& event) {
    if (!this->isEnabled()) return;
    MinecraftPacketIds id = event.getPacket()->getId();

    // TODO: add support for other servers (look for "won the game" text)
    if (id == MinecraftPacketIds::UpdateAttributes) {
        auto* pkt = reinterpret_cast<UpdateAttributesPacket*>(event.getPacket());
        FlarialGUI::Notify(std::to_string(pkt->RuntimeEntityID) );
    }
}

void PacketTest::SendGG() {

};
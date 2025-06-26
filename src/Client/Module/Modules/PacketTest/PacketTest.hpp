#pragma once

#include "../Module.hpp"
#include "../../../../SDK/Client/Network/Packet/PlaySoundPacket.hpp"
#include "../../../../SDK/Client/Network/Packet/TextPacket.hpp"
#include "../../../../SDK/Client/Network/Packet/UpdateAttributesPacket.hpp"
#include "../../../../SDK/Client/Network/Packet/SetTitlePacket.hpp"
#include "Events/Network/PacketEvent.hpp"


class PacketTest : public Module {

public:
	PacketTest() : Module("Packet Text", " ",
		IDR_LIKE_PNG, "") {
		
	};

	void onEnable() override;

	void onDisable() override;

	void defaultConfig() override;

	void settingsRender(float settingsOffset) override;

	void onPacketReceive(PacketEvent& event);

	void SendGG();
};


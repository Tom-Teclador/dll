#include "PacketHooks.hpp"

// text
void SendPacketHook::callback(LoopbackPacketSender *pSender, Packet *pPacket) {
    auto event = nes::make_holder<PacketSendEvent>(pPacket);

    if(SDK::clientInstance) {
        eventMgr.trigger(event);
    }

    if (!event->isCancelled()) {
        sendOriginal(pSender, pPacket);
    }
}

void SendPacketHook::receiveCallbackPlayStatus(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketPlayStatusOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackServerToClientHandshake(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketServerToClientHandshakeOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackDisconnect(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketDisconnectOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackRescourcePacksInfo(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketRescourcePacksInfoOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackRescourcePackStack(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketRescourcePackStackOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackText(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketTextOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetTime(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketSetTimeOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackStartGame(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketStartGameOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAddPlayer(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketAddPlayerOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAddEntity(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketAddEntityOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackRemoveEntity(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketRemoveEntityOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAddItemActor(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketAddItemActorOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackTakeItemActor(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketTakeItemActorOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackMoveAbsoluteActor(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketMoveAbsoluteActorOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackMovePlayer(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketMovePlayerOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackPassengerJump(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketPassengerJumpOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackUpdateBlock(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketUpdateBlockOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAddPainting(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketAddPaintingOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackTickSync(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketTickSyncOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackLevelSoundEventV1(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketLevelSoundEventV1Original(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackLevelEvent(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketLevelEventOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackTileEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketTileEventOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackActorEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketActorEventOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackMobEffect(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketMobEffectOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackUpdateAttributes(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketUpdateAttributesOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackInventoryTransaction(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketInventoryTransactionOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackPlayerEquipment(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketPlayerEquipmentOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackMobArmorEquipment(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketMobArmorEquipmentOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackInteract(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketInteractOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackHurtArmor(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketHurtArmorOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetActorData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketSetActorDataOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetActorMotion(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketSetActorMotionOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetActorLink(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketSetActorLinkOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetHealth(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketSetHealthOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetSpawnPosition(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketSetSpawnPositionOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAnimate(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketAnimateOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackRespawn(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketRespawnOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackContainerOpen(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketContainerOpenOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackContainerClose(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketContainerCloseOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackPlayerHotbar(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketPlayerHotbarOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackInventoryContent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketInventoryContentOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackInventorySlot(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketInventorySlotOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackContainerSetData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketContainerSetDataOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackCraftingData(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketCraftingDataOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackCraftingEvent(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketCraftingEventOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackGuiDataPickItem(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketGuiDataPickItemOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAdventureSettings_Deprecated(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketAdventureSettings_DeprecatedOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackBlockActorData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketBlockActorDataOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackFullChunkData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketFullChunkDataOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetCommandsEnabled(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketSetCommandsEnabledOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetDifficulty(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketSetDifficultyOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetPlayerGameType(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketSetPlayerGameTypeOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackPlayerList(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketPlayerListOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSimpleEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketSimpleEventOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackMapData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketMapDataOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackMapInfoRequest(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketMapInfoRequestOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackRequestChunkRadius(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketRequestChunkRadiusOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackChunkRadiusUpdated(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketChunkRadiusUpdatedOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackGameRulesChanged(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketGameRulesChangedOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackBossEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketBossEventOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackShowCredits(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketShowCreditsOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackCommandOutput(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketCommandOutputOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackUpdateTrade(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketUpdateTradeOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackUpdateEquip(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketUpdateEquipOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackResourcePackDataInfo(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketResourcePackDataInfoOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackResourcePackChunkData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketResourcePackChunkDataOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackTransfer(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketTransferOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackStopSound(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketStopSoundOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAddBehaviorTree(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketAddBehaviorTreeOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackStructureBlockUpdate(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketStructureBlockUpdateOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackShowStoreOffer(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketShowStoreOfferOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetLastHurtBy(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketSetLastHurtByOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackNPCRequest(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketNPCRequestOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackChangeDimension(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketChangeDimensionOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void
SendPacketHook::receiveCallbackSetTitle(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                        const std::shared_ptr<Packet>& packet) {

    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketSetTitleOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void
SendPacketHook::receiveCallbackPlaySound(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);
    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketPlaySoundOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackEntityEvent(void *packetHandlerDispatcher, void *networkIdentifier,
                                                void *netEventCallback, const std::shared_ptr<Packet> &packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);
    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketEntityEventOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);

}

void SendPacketHook::receiveCallbackModalFormRequest(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                                    const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);
    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketModalFormRequestOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackPlayerSkin(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                                    const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);
    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketPlayerSkinOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}


void SendPacketHook::enableHook() {
    /*for (int num = 1; num <= (int)MinecraftPacketIds::PacketViolationWarning; num++) {

        std::string bru;
        std::shared_ptr<Packet> packet = SDK::createPacket(num);
        Memory::hookFunc((void*) packet->packetHandler->vTable[1], receiveCallback, (void**)&receivePacketkOriginal, *packet.get()->getName(&bru));

        Sleep(300);
    }*/


    std::shared_ptr<Packet> playStatusPacket = SDK::createPacket((int)MinecraftPacketIds::PlayStatus);
    Memory::hookFunc((void*)playStatusPacket->packetHandler->vTable[1], (void*)receiveCallbackPlayStatus,
        (void**)&receivePacketPlayStatusOriginal, "ReceivePacketHook");

    /*std::shared_ptr<Packet> serverToClientHandshakePacket = SDK::createPacket((int)MinecraftPacketIds::ServerToClientHandshake);
    Memory::hookFunc((void *) serverToClientHandshakePacket->packetHandler->vTable[1], (void*)receiveCallbackServerToClientHandshake,
                     (void **) &receivePacketServerToClientHandshakeOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> disconnectPacket = SDK::createPacket((int) MinecraftPacketIds::Disconnect);
    Memory::hookFunc((void *) disconnectPacket->packetHandler->vTable[1], (void*)receiveCallbackDisconnect,
                     (void **) &receivePacketDisconnectOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> rescourcePacksInfoPacket = SDK::createPacket((int) MinecraftPacketIds::ResourcePacksInfo);
    Memory::hookFunc((void *) rescourcePacksInfoPacket->packetHandler->vTable[1], (void*)receiveCallbackRescourcePacksInfo,
                     (void **) &receivePacketRescourcePacksInfoOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> rescourcePackStackPacket = SDK::createPacket((int) MinecraftPacketIds::ResourcePackStack);
    Memory::hookFunc((void *) rescourcePackStackPacket->packetHandler->vTable[1], (void*)receiveCallbackRescourcePackStack,
                     (void **) &receivePacketRescourcePackStackOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> textPacket = SDK::createPacket((int) MinecraftPacketIds::Text);
    Memory::hookFunc((void *) textPacket->packetHandler->vTable[1], (void*)receiveCallbackText,
                     (void **) &receivePacketTextOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setTimePacket = SDK::createPacket((int) MinecraftPacketIds::SetTime);
    Memory::hookFunc((void *) setTimePacket->packetHandler->vTable[1], (void*)receiveCallbackSetTime,
                     (void **) &receivePacketSetTimeOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> startGamePacket = SDK::createPacket((int) MinecraftPacketIds::StartGame);
    Memory::hookFunc((void *) startGamePacket->packetHandler->vTable[1], (void*)receiveCallbackStartGame,
                     (void **) &receivePacketStartGameOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> addPlayerPacket = SDK::createPacket((int) MinecraftPacketIds::AddPlayer);
    Memory::hookFunc((void *) addPlayerPacket->packetHandler->vTable[1], (void*)receiveCallbackAddPlayer,
                     (void **) &receivePacketAddPlayerOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> addEntityPacket = SDK::createPacket((int) MinecraftPacketIds::AddEntity);
    Memory::hookFunc((void *) addEntityPacket->packetHandler->vTable[1], (void*)receiveCallbackAddEntity,
                     (void **) &receivePacketAddEntityOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> removeEntityPacket = SDK::createPacket((int) MinecraftPacketIds::RemoveEntity);
    Memory::hookFunc((void *) removeEntityPacket->packetHandler->vTable[1], (void*)receiveCallbackRemoveEntity,
                     (void **) &receivePacketRemoveEntityOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> addItemActorPacket = SDK::createPacket((int) MinecraftPacketIds::AddItemActor);
    Memory::hookFunc((void *) addItemActorPacket->packetHandler->vTable[1], (void*)receiveCallbackAddItemActor,
                     (void **) &receivePacketAddItemActorOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> takeItemActorPacket = SDK::createPacket((int) MinecraftPacketIds::TakeItemActor);
    Memory::hookFunc((void *) takeItemActorPacket->packetHandler->vTable[1], (void*)receiveCallbackTakeItemActor,
                     (void **) &receivePacketTakeItemActorOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> moveAbsoluteActorPacket = SDK::createPacket((int) MinecraftPacketIds::MoveAbsoluteActor);
    Memory::hookFunc((void *) moveAbsoluteActorPacket->packetHandler->vTable[1], (void*)receiveCallbackMoveAbsoluteActor,
                     (void **) &receivePacketMoveAbsoluteActorOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> movePlayerPacket = SDK::createPacket((int) MinecraftPacketIds::MovePlayer);
    Memory::hookFunc((void *) movePlayerPacket->packetHandler->vTable[1], (void*)receiveCallbackMovePlayer,
                     (void **) &receivePacketMovePlayerOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> passengerJumpPacket = SDK::createPacket((int) MinecraftPacketIds::PassengerJump);
    Memory::hookFunc((void *) passengerJumpPacket->packetHandler->vTable[1], (void*)receiveCallbackPassengerJump,
                     (void **) &receivePacketPassengerJumpOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> updateBlockPacket = SDK::createPacket((int) MinecraftPacketIds::UpdateBlock);
    Memory::hookFunc((void *) updateBlockPacket->packetHandler->vTable[1], (void*)receiveCallbackUpdateBlock,
                     (void **) &receivePacketUpdateBlockOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> addPaintingPacket = SDK::createPacket((int) MinecraftPacketIds::AddPainting);
    Memory::hookFunc((void *) addPaintingPacket->packetHandler->vTable[1], (void*)receiveCallbackAddPainting,
                     (void **) &receivePacketAddPaintingOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> tickSyncPacket = SDK::createPacket((int) MinecraftPacketIds::TickSync);
    Memory::hookFunc((void *) tickSyncPacket->packetHandler->vTable[1], (void*)receiveCallbackTickSync,
                     (void **) &receivePacketTickSyncOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> levelSoundEventV1Packet = SDK::createPacket((int) MinecraftPacketIds::LevelSoundEventV1);
    Memory::hookFunc((void *) levelSoundEventV1Packet->packetHandler->vTable[1], (void*)receiveCallbackLevelSoundEventV1,
                     (void **) &receivePacketLevelSoundEventV1Original, "ReceivePacketHook");

    */std::shared_ptr<Packet> levelEventPacket = SDK::createPacket((int)MinecraftPacketIds::LevelEvent);
    Memory::hookFunc((void *) levelEventPacket->packetHandler->vTable[1], (void*)receiveCallbackLevelEvent,
                     (void **) &receivePacketLevelEventOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> tileEventPacket = SDK::createPacket((int) MinecraftPacketIds::TileEvent);
    Memory::hookFunc((void *) tileEventPacket->packetHandler->vTable[1], (void*)receiveCallbackTileEvent,
                     (void **) &receivePacketTileEventOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> actorEventPacket = SDK::createPacket((int) MinecraftPacketIds::ActorEvent);
    Memory::hookFunc((void *) actorEventPacket->packetHandler->vTable[1], (void*)receiveCallbackActorEvent,
                     (void **) &receivePacketActorEventOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> mobEffectPacket = SDK::createPacket((int) MinecraftPacketIds::MobEffect);
    Memory::hookFunc((void *) mobEffectPacket->packetHandler->vTable[1], (void*)receiveCallbackMobEffect,
                     (void **) &receivePacketMobEffectOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> updateAttributesPacket = SDK::createPacket((int) MinecraftPacketIds::UpdateAttributes);
    Memory::hookFunc((void *) updateAttributesPacket->packetHandler->vTable[1], (void*)receiveCallbackUpdateAttributes,
                     (void **) &receivePacketUpdateAttributesOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> inventoryTransactionPacket = SDK::createPacket((int) MinecraftPacketIds::InventoryTransaction);
    Memory::hookFunc((void *) inventoryTransactionPacket->packetHandler->vTable[1], (void*)receiveCallbackInventoryTransaction,
                     (void **) &receivePacketInventoryTransactionOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> playerEquipmentPacket = SDK::createPacket((int) MinecraftPacketIds::PlayerEquipment);
    Memory::hookFunc((void *) playerEquipmentPacket->packetHandler->vTable[1], (void*)receiveCallbackPlayerEquipment,
                     (void **) &receivePacketPlayerEquipmentOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> mobArmorEquipmentPacket = SDK::createPacket((int) MinecraftPacketIds::MobArmorEquipment);
    Memory::hookFunc((void *) mobArmorEquipmentPacket->packetHandler->vTable[1], (void*)receiveCallbackMobArmorEquipment,
                     (void **) &receivePacketMobArmorEquipmentOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> interactPacket = SDK::createPacket((int) MinecraftPacketIds::Interact);
    Memory::hookFunc((void *) interactPacket->packetHandler->vTable[1], (void*)receiveCallbackInteract,
                     (void **) &receivePacketInteractOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> hurtArmorPacket = SDK::createPacket((int) MinecraftPacketIds::HurtArmor);
    Memory::hookFunc((void *) hurtArmorPacket->packetHandler->vTable[1], (void*)receiveCallbackHurtArmor,
                     (void **) &receivePacketHurtArmorOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setActorDataPacket = SDK::createPacket((int) MinecraftPacketIds::SetActorData);
    Memory::hookFunc((void *) setActorDataPacket->packetHandler->vTable[1], (void*)receiveCallbackSetActorData,
                     (void **) &receivePacketSetActorDataOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setActorMotionPacket = SDK::createPacket((int) MinecraftPacketIds::SetActorMotion);
    Memory::hookFunc((void *) setActorMotionPacket->packetHandler->vTable[1], (void*)receiveCallbackSetActorMotion,
                     (void **) &receivePacketSetActorMotionOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setActorLinkPacket = SDK::createPacket((int) MinecraftPacketIds::SetActorLink);
    Memory::hookFunc((void *) setActorLinkPacket->packetHandler->vTable[1], (void*)receiveCallbackSetActorLink,
                     (void **) &receivePacketSetActorLinkOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setHealthPacket = SDK::createPacket((int) MinecraftPacketIds::SetHealth);
    Memory::hookFunc((void *) setHealthPacket->packetHandler->vTable[1], (void*)receiveCallbackSetHealth,
                     (void **) &receivePacketSetHealthOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setSpawnPositionPacket = SDK::createPacket((int) MinecraftPacketIds::SetSpawnPosition);
    Memory::hookFunc((void *) setSpawnPositionPacket->packetHandler->vTable[1], (void*)receiveCallbackSetSpawnPosition,
                     (void **) &receivePacketSetSpawnPositionOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> animatePacket = SDK::createPacket((int) MinecraftPacketIds::Animate);
    Memory::hookFunc((void *) animatePacket->packetHandler->vTable[1], (void*)receiveCallbackAnimate,
                     (void **) &receivePacketAnimateOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> respawnPacket = SDK::createPacket((int) MinecraftPacketIds::Respawn);
    Memory::hookFunc((void *) respawnPacket->packetHandler->vTable[1], (void*)receiveCallbackRespawn,
                     (void **) &receivePacketRespawnOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> containerOpenPacket = SDK::createPacket((int)MinecraftPacketIds::ContainerOpen);
    Memory::hookFunc((void *) containerOpenPacket->packetHandler->vTable[1], (void*)receiveCallbackContainerOpen,
                     (void **) &receivePacketContainerOpenOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> containerClosePacket = SDK::createPacket((int) MinecraftPacketIds::ContainerClose);
    Memory::hookFunc((void *) containerClosePacket->packetHandler->vTable[1], (void*)receiveCallbackContainerClose,
                     (void **) &receivePacketContainerCloseOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> playerHotbarPacket = SDK::createPacket((int)MinecraftPacketIds::PlayerHotbar);
    Memory::hookFunc((void *) playerHotbarPacket->packetHandler->vTable[1], (void*)receiveCallbackPlayerHotbar,
                     (void **) &receivePacketPlayerHotbarOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> inventoryContentPacket = SDK::createPacket((int) MinecraftPacketIds::InventoryContent);
    Memory::hookFunc((void *) inventoryContentPacket->packetHandler->vTable[1], (void*)receiveCallbackInventoryContent,
                     (void **) &receivePacketInventoryContentOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> inventorySlotPacket = SDK::createPacket((int)MinecraftPacketIds::InventorySlot);
    Memory::hookFunc((void *) inventorySlotPacket->packetHandler->vTable[1], (void*)receiveCallbackInventorySlot,
                     (void **) &receivePacketInventorySlotOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> containerSetDataPacket = SDK::createPacket((int)MinecraftPacketIds::ContainerSetData);
    Memory::hookFunc((void *) containerSetDataPacket->packetHandler->vTable[1], (void*)receiveCallbackContainerSetData,
                     (void **) &receivePacketContainerSetDataOriginal, "ReceivePacketHook");

    /*std::shared_ptr<Packet> craftingDataPacket = SDK::createPacket((int)MinecraftPacketIds::CraftingData);
    Memory::hookFunc((void *) craftingDataPacket->packetHandler->vTable[1], (void*)receiveCallbackCraftingData,
                     (void **) &receivePacketCraftingDataOriginal, "ReceivePacketHook");*/

    std::shared_ptr<Packet> craftingEventPacket = SDK::createPacket((int)MinecraftPacketIds::CraftingEvent);
    Memory::hookFunc((void *) craftingEventPacket->packetHandler->vTable[1], (void*)receiveCallbackCraftingEvent,
                     (void **) &receivePacketCraftingEventOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> guiDataPickItemPacket = SDK::createPacket((int)MinecraftPacketIds::GuiDataPickItem);
    Memory::hookFunc((void *) guiDataPickItemPacket->packetHandler->vTable[1], (void*)receiveCallbackGuiDataPickItem,
                     (void **) &receivePacketGuiDataPickItemOriginal, "ReceivePacketHook");

    /*std::shared_ptr<Packet> adventureSettings_DeprecatedPacket = SDK::createPacket((int)MinecraftPacketIds::AdventureSettings_Deprecated);
    Memory::hookFunc((void *) adventureSettings_DeprecatedPacket->packetHandler->vTable[1], (void*)receiveCallbackAdventureSettings_Deprecated,
                     (void **) &receivePacketAdventureSettings_DeprecatedOriginal, "ReceivePacketHook");*/

    std::shared_ptr<Packet> blockActorDataPacket = SDK::createPacket((int) MinecraftPacketIds::BlockActorData);
    Memory::hookFunc((void *) blockActorDataPacket->packetHandler->vTable[1], (void*)receiveCallbackBlockActorData,
                     (void **) &receivePacketBlockActorDataOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> fullChunkDataPacket = SDK::createPacket((int) MinecraftPacketIds::FullChunkData);
    Memory::hookFunc((void *) fullChunkDataPacket->packetHandler->vTable[1], (void*)receiveCallbackFullChunkData,
                     (void **) &receivePacketFullChunkDataOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setCommandsEnabledPacket = SDK::createPacket((int) MinecraftPacketIds::SetCommandsEnabled);
    Memory::hookFunc((void *) setCommandsEnabledPacket->packetHandler->vTable[1], (void*)receiveCallbackSetCommandsEnabled,
                     (void **) &receivePacketSetCommandsEnabledOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setDifficultyPacket = SDK::createPacket((int) MinecraftPacketIds::SetDifficulty);
    Memory::hookFunc((void *) setDifficultyPacket->packetHandler->vTable[1], (void*)receiveCallbackSetDifficulty,
                     (void **) &receivePacketSetDifficultyOriginal, "ReceivePacketHook");
    
    std::shared_ptr<Packet> setPlayerGameType = SDK::createPacket((int)MinecraftPacketIds::SetPlayerGameType);
    Memory::hookFunc((void *) setPlayerGameType->packetHandler->vTable[1], (void *)receiveCallbackSetPlayerGameType,
                 (void **) &receivePacketSetPlayerGameTypeOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> playerList = SDK::createPacket((int) MinecraftPacketIds::PlayerList);
    Memory::hookFunc((void *) playerList->packetHandler->vTable[1], (void *)receiveCallbackPlayerList,
                 (void **) &receivePacketPlayerListOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> simpleEvent = SDK::createPacket((int) MinecraftPacketIds::SimpleEvent);
    Memory::hookFunc((void *) simpleEvent->packetHandler->vTable[1], (void *)receiveCallbackSimpleEvent,
                 (void **) &receivePacketSimpleEventOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> mapData = SDK::createPacket((int) MinecraftPacketIds::MapData);
    Memory::hookFunc((void *) mapData->packetHandler->vTable[1], (void *)receiveCallbackMapData,
                 (void **) &receivePacketMapDataOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> mapInfoRequest = SDK::createPacket((int) MinecraftPacketIds::MapInfoRequest);
    Memory::hookFunc((void *) mapInfoRequest->packetHandler->vTable[1], (void *)receiveCallbackMapInfoRequest,
                 (void **) &receivePacketMapInfoRequestOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> requestChunkRadius = SDK::createPacket((int) MinecraftPacketIds::RequestChunkRadius);
    Memory::hookFunc((void *) requestChunkRadius->packetHandler->vTable[1], (void *)receiveCallbackRequestChunkRadius,
                 (void **) &receivePacketRequestChunkRadiusOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> chunkRadiusUpdated = SDK::createPacket((int) MinecraftPacketIds::ChunkRadiusUpdated);
    Memory::hookFunc((void *) chunkRadiusUpdated->packetHandler->vTable[1], (void *)receiveCallbackChunkRadiusUpdated,
                 (void **) &receivePacketChunkRadiusUpdatedOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> gameRulesChanged = SDK::createPacket((int) MinecraftPacketIds::GameRulesChanged);
    Memory::hookFunc((void *) gameRulesChanged->packetHandler->vTable[1], (void *)receiveCallbackGameRulesChanged,
                 (void **) &receivePacketGameRulesChangedOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> bossEvent = SDK::createPacket((int) MinecraftPacketIds::BossEvent);
    Memory::hookFunc((void *) bossEvent->packetHandler->vTable[1], (void *)receiveCallbackBossEvent,
                 (void **) &receivePacketBossEventOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> showCredits = SDK::createPacket((int) MinecraftPacketIds::ShowCredits);
    Memory::hookFunc((void *) showCredits->packetHandler->vTable[1], (void *)receiveCallbackShowCredits,
                 (void **) &receivePacketShowCreditsOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> commandOutput = SDK::createPacket((int) MinecraftPacketIds::CommandOutput);
    Memory::hookFunc((void *) commandOutput->packetHandler->vTable[1], (void *)receiveCallbackCommandOutput,
                 (void **) &receivePacketCommandOutputOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> updateTrade = SDK::createPacket((int) MinecraftPacketIds::UpdateTrade);
    Memory::hookFunc((void *) updateTrade->packetHandler->vTable[1], (void *)receiveCallbackUpdateTrade,
                 (void **) &receivePacketUpdateTradeOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> updateEquip = SDK::createPacket((int) MinecraftPacketIds::UpdateEquip);
    Memory::hookFunc((void *) updateEquip->packetHandler->vTable[1], (void *)receiveCallbackUpdateEquip,
                 (void **) &receivePacketUpdateEquipOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> resourcePackDataInfo = SDK::createPacket((int) MinecraftPacketIds::ResourcePackDataInfo);
    Memory::hookFunc((void *) resourcePackDataInfo->packetHandler->vTable[1], (void *)receiveCallbackResourcePackDataInfo,
                 (void **) &receivePacketResourcePackDataInfoOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> resourcePackChunkData = SDK::createPacket((int) MinecraftPacketIds::ResourcePackChunkData);
    Memory::hookFunc((void *) resourcePackChunkData->packetHandler->vTable[1], (void *)receiveCallbackResourcePackChunkData,
                 (void **) &receivePacketResourcePackChunkDataOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> transfer = SDK::createPacket((int) MinecraftPacketIds::Transfer);
    Memory::hookFunc((void *) transfer->packetHandler->vTable[1], (void *)receiveCallbackTransfer,
                 (void **) &receivePacketTransferOriginal, "ReceivePacketHook");
    

    std::shared_ptr<Packet> stopSound = SDK::createPacket((int) MinecraftPacketIds::StopSound);
    Memory::hookFunc((void *) stopSound->packetHandler->vTable[1], (void *)receiveCallbackStopSound,
                 (void **) &receivePacketStopSoundOriginal, "ReceivePacketHook");

   

    std::shared_ptr<Packet> addBehaviorTree = SDK::createPacket((int)MinecraftPacketIds::AddBehaviorTree);
    Memory::hookFunc((void *) addBehaviorTree->packetHandler->vTable[1], (void *)receiveCallbackAddBehaviorTree,
                 (void **) &receivePacketAddBehaviorTreeOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> structureBlockUpdate = SDK::createPacket((int) MinecraftPacketIds::StructureBlockUpdate);
    Memory::hookFunc((void *) structureBlockUpdate->packetHandler->vTable[1], (void *)receiveCallbackStructureBlockUpdate,
                 (void **) &receivePacketStructureBlockUpdateOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> showStoreOffer = SDK::createPacket((int) MinecraftPacketIds::ShowStoreOffer);
    Memory::hookFunc((void *) showStoreOffer->packetHandler->vTable[1], (void *)receiveCallbackShowStoreOffer,
                 (void **) &receivePacketShowStoreOfferOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setLastHurtBy = SDK::createPacket((int)MinecraftPacketIds::SetLastHurtBy);
    Memory::hookFunc((void *) setLastHurtBy->packetHandler->vTable[1], (void *)receiveCallbackSetLastHurtBy,
                 (void **) &receivePacketSetLastHurtByOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> npcRequest = SDK::createPacket((int) MinecraftPacketIds::NPCRequest);
    Memory::hookFunc((void *) npcRequest->packetHandler->vTable[1], (void *)receiveCallbackNPCRequest,
                 (void **) &receivePacketNPCRequestOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> changeDimensionPacket = SDK::createPacket((int) MinecraftPacketIds::ChangeDimension);
    Memory::hookFunc((void *) changeDimensionPacket->packetHandler->vTable[1], (void*)receiveCallbackChangeDimension,
                     (void **) &receivePacketChangeDimensionOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setTitlePacket = SDK::createPacket((int) MinecraftPacketIds::SetTitle);
    Memory::hookFunc((void *) setTitlePacket->packetHandler->vTable[1], (void*)receiveCallbackSetTitle,
                     (void **) &receivePacketSetTitleOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> playSoundPacket = SDK::createPacket((int) MinecraftPacketIds::PlaySoundPacket);
    Memory::hookFunc((void *) playSoundPacket->packetHandler->vTable[1], (void*)receiveCallbackPlaySound,
                     (void **) &receivePacketPlaySoundOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> EntityEventPacket = SDK::createPacket((int) MinecraftPacketIds::ActorEvent);
    Memory::hookFunc((void *) EntityEventPacket->packetHandler->vTable[1], (void*)receiveCallbackEntityEvent,
                     (void **) &receivePacketEntityEventOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> ModalFormRequestPacket = SDK::createPacket((int) MinecraftPacketIds::ShowModalForm);
    Memory::hookFunc((void *) ModalFormRequestPacket->packetHandler->vTable[1], (void *)receiveCallbackModalFormRequest,
                     (void **) &receivePacketModalFormRequestOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> SkinPacket = SDK::createPacket((int) MinecraftPacketIds::PlayerSkin);
    Memory::hookFunc((void *) SkinPacket->packetHandler->vTable[1], (void *)receiveCallbackPlayerSkin,
                     (void **) &receivePacketPlayerSkinOriginal, "ReceivePacketHook");

    this->autoHook((void *) callback, (void **) &sendOriginal);
}

void SendPacketHook::setVariables(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback) {
    SendPacketHook::NetworkIdentifier = networkIdentifier;
    SendPacketHook::PacketHandlerDispatcher = packetHandlerDispatcher;
    SendPacketHook::NetEventCallback = netEventCallback;
}
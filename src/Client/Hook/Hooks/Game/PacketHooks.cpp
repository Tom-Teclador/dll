#include "PacketHooks.hpp"

// text
void SendPacketHook::callback(LoopbackPacketSender *pSender, Packet *pPacket) {
    auto event = nes::make_holder<PacketSendEvent>(pPacket);

    if(SDK::clientInstance) {
        eventMgr.trigger(event);
    }

    if (!event->isCancelled()) {
        sendPacketOriginal(pSender, pPacket);
    }
}

void SendPacketHook::receiveCallbackPlayStatus(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePlayStatusPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackServerToClientHandshake(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveServerToClientHandshakePacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackDisconnect(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveDisconnectPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackRescourcePacksInfo(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveRescourcePacksInfoPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackRescourcePackStack(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveRescourcePackStackPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackText(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveTextPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetTime(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveSetTimePacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackStartGame(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveStartGamePacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAddPlayer(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveAddPlayerPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAddEntity(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveAddEntityPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackRemoveEntity(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveRemoveEntityPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAddItemActor(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveAddItemActorPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackTakeItemActor(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveTakeItemActorPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackMoveAbsoluteActor(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveMoveAbsoluteActorPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackMovePlayer(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveMovePlayerPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackPassengerJump(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePassengerJumpPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackUpdateBlock(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveUpdateBlockPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAddPainting(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveAddPaintingPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackTickSync(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveTickSyncPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackLevelSoundEventV1(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveLevelSoundEventV1PacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackLevelEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveLevelEventPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackTileEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveTileEventPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackActorEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveActorEventPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackMobEffect(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveMobEffectPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackUpdateAttributes(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveUpdateAttributesPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackInventoryTransaction(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveInventoryTransactionPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackPlayerEquipment(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePlayerEquipmentPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackMobArmorEquipment(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveMobArmorEquipmentPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackInteract(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveInteractPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackHurtArmor(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveHurtArmorPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetActorData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveSetActorDataPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetActorMotion(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveSetActorMotionPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetActorLink(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveSetActoryLinkPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetHealth(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveSetHealthPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetSpawnPosition(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveSetSpawnPositionPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAnimate(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveAnimatePacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackRespawn(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveRespawnPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackContainerOpen(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveContainerOpenPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackContainerClose(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveContainerClosePacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackPlayerHotbar(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePlayerHotbarPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackInventoryContent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveInventoryContentPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackInventorySlot(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveInventorySlotPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackContainerSetData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveContainerSetDataPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackCraftingData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveCraftingDataPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackCraftingEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveCraftingEventPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackGuiDataPickItem(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveGuiDataPickItemPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackAdventureSettings_Deprecated(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveAdventureSettings_DeprecatedPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackBlockActorData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveBlockActorDataPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackFullChunkData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveFullChunkDataPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetCommandsEnabled(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveSetCommandsEnabledPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackSetDifficulty(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveSetDifficultyPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackChangeDimension(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveChangeDimensionPacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void
SendPacketHook::receiveCallbackSetTitle(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                        const std::shared_ptr<Packet>& packet) {

    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);

    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receiveSetTitlePacketOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
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

void SendPacketHook::receiveCallbackInteract(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                             const std::shared_ptr<Packet> &packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);
    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketInteractOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackContainerOpen(void *packetHandlerDispatcher, void *networkIdentifier,
                                                  void *netEventCallback, const std::shared_ptr<Packet> &packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);
    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketContainerOpenOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackContainerClose(void *packetHandlerDispatcher, void *networkIdentifier,
                                                   void *netEventCallback, const std::shared_ptr<Packet> &packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);
    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketContainerCloseOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
}

void SendPacketHook::receiveCallbackChangeDimension(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                                    const std::shared_ptr<Packet>& packet) {
    SendPacketHook::setVariables(packetHandlerDispatcher, networkIdentifier, netEventCallback);
    auto event = nes::make_holder<PacketEvent>(packet.get());
    eventMgr.trigger(event);
    if (!event->isCancelled())
        receivePacketChangeDimensionOriginal(packetHandlerDispatcher, networkIdentifier, netEventCallback, packet);
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
        (void**)&receivePlayStatusPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> serverToClientHandshakePacket = SDK::createPacket((int) MinecraftPacketIds::ServerToClientHandshake);
    Memory::hookFunc((void *) serverToClientHandshakePacket->packetHandler->vTable[1], (void*)receiveCallbackServerToClientHandshake,
                     (void **) &receiveServerToClientHandshakePacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> disconnectPacket = SDK::createPacket((int) MinecraftPacketIds::Disconnect);
    Memory::hookFunc((void *) disconnectPacket->packetHandler->vTable[1], (void*)receiveCallbackDisconnect,
                     (void **) &receiveDisconnectPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> rescourcePacksInfoPacket = SDK::createPacket((int) MinecraftPacketIds::ResourcePacksInfo);
    Memory::hookFunc((void *) rescourcePacksInfoPacket->packetHandler->vTable[1], (void*)receiveCallbackRescourcePacksInfo,
                     (void **) &receiveRescourcePacksInfoPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> rescourcePackStackPacket = SDK::createPacket((int) MinecraftPacketIds::ResourcePackStack);
    Memory::hookFunc((void *) rescourcePackStackPacket->packetHandler->vTable[1], (void*)receiveCallbackRescourcePackStack,
                     (void **) &receiveRescourcePackStackPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> textPacket = SDK::createPacket((int) MinecraftPacketIds::Text);
    Memory::hookFunc((void *) textPacket->packetHandler->vTable[1], (void*)receiveCallbackText,
                     (void **) &receiveTextPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setTimePacket = SDK::createPacket((int) MinecraftPacketIds::SetTime);
    Memory::hookFunc((void *) setTimePacket->packetHandler->vTable[1], (void*)receiveCallbackSetTime,
                     (void **) &receiveSetTimePacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> startGamePacket = SDK::createPacket((int) MinecraftPacketIds::StartGame);
    Memory::hookFunc((void *) startGamePacket->packetHandler->vTable[1], (void*)receiveCallbackStartGame,
                     (void **) &receiveStartGamePacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> addPlayerPacket = SDK::createPacket((int) MinecraftPacketIds::AddPlayer);
    Memory::hookFunc((void *) addPlayerPacket->packetHandler->vTable[1], (void*)receiveCallbackAddPlayer,
                     (void **) &receiveAddPlayerPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> addEntityPacket = SDK::createPacket((int) MinecraftPacketIds::AddEntity);
    Memory::hookFunc((void *) addEntityPacket->packetHandler->vTable[1], (void*)receiveCallbackAddEntity,
                     (void **) &receiveAddEntityPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> removeEntityPacket = SDK::createPacket((int) MinecraftPacketIds::RemoveEntity);
    Memory::hookFunc((void *) removeEntityPacket->packetHandler->vTable[1], (void*)receiveCallbackRemoveEntity,
                     (void **) &receiveRemoveEntityPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> addItemActorPacket = SDK::createPacket((int) MinecraftPacketIds::AddItemActor);
    Memory::hookFunc((void *) addItemActorPacket->packetHandler->vTable[1], (void*)receiveCallbackAddItemActor,
                     (void **) &receiveAddItemActorPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> takeItemActorPacket = SDK::createPacket((int) MinecraftPacketIds::TakeItemActor);
    Memory::hookFunc((void *) takeItemActorPacket->packetHandler->vTable[1], (void*)receiveCallbackTakeItemActor,
                     (void **) &receiveTakeItemActorPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> moveAbsoluteActorPacket = SDK::createPacket((int) MinecraftPacketIds::MoveAbsoluteActor);
    Memory::hookFunc((void *) moveAbsoluteActorPacket->packetHandler->vTable[1], (void*)receiveCallbackMoveAbsoluteActor,
                     (void **) &receiveMoveAbsoluteActorPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> movePlayerPacket = SDK::createPacket((int) MinecraftPacketIds::MovePlayer);
    Memory::hookFunc((void *) movePlayerPacket->packetHandler->vTable[1], (void*)receiveCallbackMovePlayer,
                     (void **) &receiveMovePlayerPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> passengerJumpPacket = SDK::createPacket((int) MinecraftPacketIds::PassengerJump);
    Memory::hookFunc((void *) passengerJumpPacket->packetHandler->vTable[1], (void*)receiveCallbackPassengerJump,
                     (void **) &receivePassengerJumpPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> updateBlockPacket = SDK::createPacket((int) MinecraftPacketIds::UpdateBlock);
    Memory::hookFunc((void *) updateBlockPacket->packetHandler->vTable[1], (void*)receiveCallbackUpdateBlock,
                     (void **) &receiveUpdateBlockPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> addPaintingPacket = SDK::createPacket((int) MinecraftPacketIds::AddPainting);
    Memory::hookFunc((void *) addPaintingPacket->packetHandler->vTable[1], (void*)receiveCallbackAddPainting,
                     (void **) &receiveAddPaintingPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> tickSyncPacket = SDK::createPacket((int) MinecraftPacketIds::TickSync);
    Memory::hookFunc((void *) tickSyncPacket->packetHandler->vTable[1], (void*)receiveCallbackTickSync,
                     (void **) &receiveTickSyncPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> levelSoundEventV1Packet = SDK::createPacket((int) MinecraftPacketIds::LevelSoundEventV1);
    Memory::hookFunc((void *) levelSoundEventV1Packet->packetHandler->vTable[1], (void*)receiveCallbackLevelSoundEventV1,
                     (void **) &receiveLevelSoundEventV1PacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> levelEventPacket = SDK::createPacket((int) MinecraftPacketIds::LevelEvent);
    Memory::hookFunc((void *) levelEventPacket->packetHandler->vTable[1], (void*)receiveCallbackLevelEvent,
                     (void **) &receiveLevelEventPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> tileEventPacket = SDK::createPacket((int) MinecraftPacketIds::TileEvent);
    Memory::hookFunc((void *) tileEventPacket->packetHandler->vTable[1], (void*)receiveCallbackTileEvent,
                     (void **) &receiveTileEventPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> actorEventPacket = SDK::createPacket((int) MinecraftPacketIds::ActorEvent);
    Memory::hookFunc((void *) actorEventtPacket->packetHandler->vTable[1], (void*)receiveCallbackActorEvent,
                     (void **) &receiveActorEventPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> mobEffectPacket = SDK::createPacket((int) MinecraftPacketIds::MobEffect);
    Memory::hookFunc((void *) mobEffectPacket->packetHandler->vTable[1], (void*)receiveCallbackMobEffect,
                     (void **) &receiveMobEffectPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> updateAttributesPacket = SDK::createPacket((int) MinecraftPacketIds::UpdateAttributes);
    Memory::hookFunc((void *) updateAttributesPacket->packetHandler->vTable[1], (void*)receiveCallbackUpdateAttributes,
                     (void **) &receiveUpdateAttributesPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> inventoryTransactionPacket = SDK::createPacket((int) MinecraftPacketIds::InventoryTransaction);
    Memory::hookFunc((void *) inventoryTransactionPacket->packetHandler->vTable[1], (void*)receiveCallbackInventoryTransaction,
                     (void **) &receiveInventoryTransactionPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> playerEquipmentPacket = SDK::createPacket((int) MinecraftPacketIds::PlayerEquipment);
    Memory::hookFunc((void *) playerEquipmentPacket->packetHandler->vTable[1], (void*)receiveCallbackPlayerEquipment,
                     (void **) &receivePlayerEquipmentPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> mobArmorEquipmentPacket = SDK::createPacket((int) MinecraftPacketIds::MobArmorEquipment);
    Memory::hookFunc((void *) mobArmorEquipmentPacket->packetHandler->vTable[1], (void*)receiveCallbackMobArmorEquipment,
                     (void **) &receiveMobArmorEquipmentPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> interactPacket = SDK::createPacket((int) MinecraftPacketIds::Interact);
    Memory::hookFunc((void *) interactPacket->packetHandler->vTable[1], (void*)receiveCallbackInteract,
                     (void **) &receiveInteractPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> hurtArmorPacket = SDK::createPacket((int) MinecraftPacketIds::HurtArmor);
    Memory::hookFunc((void *) hurtArmorPacket->packetHandler->vTable[1], (void*)receiveCallbackHurtArmor,
                     (void **) &receiveHurtArmorPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setActorDataPacket = SDK::createPacket((int) MinecraftPacketIds::SetActorData);
    Memory::hookFunc((void *) setActorDataPacket->packetHandler->vTable[1], (void*)receiveCallbackSetActorData,
                     (void **) &receiveSetActorDataPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setActorMotionPacket = SDK::createPacket((int) MinecraftPacketIds::SetActorMotion);
    Memory::hookFunc((void *) setActorMotionPacket->packetHandler->vTable[1], (void*)receiveCallbackSetActorMotion,
                     (void **) &receiveSetActorMotionPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setActorLinkPacket = SDK::createPacket((int) MinecraftPacketIds::SetActorLink);
    Memory::hookFunc((void *) setActorLinkPacket->packetHandler->vTable[1], (void*)receiveCallbackSetActorLink,
                     (void **) &receiveSetActorLinkPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setHealthPacket = SDK::createPacket((int) MinecraftPacketIds::SetHealth);
    Memory::hookFunc((void *) setHealthPacket->packetHandler->vTable[1], (void*)receiveCallbackSetHealth,
                     (void **) &receiveSetHealthPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setSpawnPositionPacket = SDK::createPacket((int) MinecraftPacketIds::SetSpawnPosition);
    Memory::hookFunc((void *) setSpawnPositionPacket->packetHandler->vTable[1], (void*)receiveCallbackSetSpawnPosition,
                     (void **) &receiveSetSpawnPositionPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> animatePacket = SDK::createPacket((int) MinecraftPacketIds::Animate);
    Memory::hookFunc((void *) animatePacket->packetHandler->vTable[1], (void*)receiveCallbackAnimate,
                     (void **) &receiveAnimatePacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> respawnPacket = SDK::createPacket((int) MinecraftPacketIds::Respawn);
    Memory::hookFunc((void *) respawnPacket->packetHandler->vTable[1], (void*)receiveCallbackRespawn,
                     (void **) &receiveRespawnPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> containerOpenPacket = SDK::createPacket((int) MinecraftPacketIds::ContainerOpen);
    Memory::hookFunc((void *) containerOpenPacket->packetHandler->vTable[1], (void*)receiveCallbackContainerOpen,
                     (void **) &receiveContainerOpenPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> containerClosePacket = SDK::createPacket((int) MinecraftPacketIds::ContainerClose);
    Memory::hookFunc((void *) containerClosePacket->packetHandler->vTable[1], (void*)receiveCallbackContainerClose,
                     (void **) &receiveContainerClosePacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> playerHotbarPacket = SDK::createPacket((int) MinecraftPacketIds::PlayerHotbar);
    Memory::hookFunc((void *) playerHotbarPacket->packetHandler->vTable[1], (void*)receiveCallbackPlayerHotbar,
                     (void **) &receivePlayerHotbarPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> inventoryContentPacket = SDK::createPacket((int) MinecraftPacketIds::InventoryContent);
    Memory::hookFunc((void *) inventoryContentPacket->packetHandler->vTable[1], (void*)receiveCallbackInventoryContent,
                     (void **) &receiveInventoryContentPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> inventorySlotPacket = SDK::createPacket((int) MinecraftPacketIds::InventorySlot);
    Memory::hookFunc((void *) inventorySlotPacket->packetHandler->vTable[1], (void*)receiveCallbackInventorySlot,
                     (void **) &receiveInventorySlotPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> containerSetDataPacket = SDK::createPacket((int) MinecraftPacketIds::ContainerSetData);
    Memory::hookFunc((void *) containerSetDataPacket->packetHandler->vTable[1], (void*)receiveCallbackContainerSetData,
                     (void **) &receiveContainerSetDataPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> craftingDataPacket = SDK::createPacket((int) MinecraftPacketIds::CraftingData);
    Memory::hookFunc((void *) craftingDataPacket->packetHandler->vTable[1], (void*)receiveCallbackCraftingData,
                     (void **) &receiveCraftingDataPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> craftingEventPacket = SDK::createPacket((int) MinecraftPacketIds::CraftingEvent);
    Memory::hookFunc((void *) craftingEventPacket->packetHandler->vTable[1], (void*)receiveCallbackCraftingEvent,
                     (void **) &receiveCraftingEventPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> guiDataPickItemPacket = SDK::createPacket((int) MinecraftPacketIds::GuiDataPickItem);
    Memory::hookFunc((void *) guiDataPickItemPacket->packetHandler->vTable[1], (void*)receiveCallbackGuiDataPickItem,
                     (void **) &receiveGuiDataPickItemPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> adventureSettings_DeprecatedPacket = SDK::createPacket((int) MinecraftPacketIds::AdventureSettings_Deprecated);
    Memory::hookFunc((void *) adventureSettings_DeprecatedPacket->packetHandler->vTable[1], (void*)receiveCallbackAdventureSettings_Deprecated,
                     (void **) &receiveAdventureSettings_DeprecatedsPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> blockActorDataPacket = SDK::createPacket((int) MinecraftPacketIds::BlockActorData);
    Memory::hookFunc((void *) blockActorDataPacket->packetHandler->vTable[1], (void*)receiveCallbackBlockActorData,
                     (void **) &receiveBlockActorDataPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> fullChunkDataPacket = SDK::createPacket((int) MinecraftPacketIds::FullChunkData);
    Memory::hookFunc((void *) fullChunkDataPacket->packetHandler->vTable[1], (void*)receiveCallbackFullChunkData,
                     (void **) &receiveFullChunkDataPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setCommandsEnabledPacket = SDK::createPacket((int) MinecraftPacketIds::SetCommandsEnabled);
    Memory::hookFunc((void *) setCommandsEnabledPacket->packetHandler->vTable[1], (void*)receiveCallbackSetCommandsEnabled,
                     (void **) &receiveSetCommandsEnabledPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setDifficultyPacket = SDK::createPacket((int) MinecraftPacketIds::SetDifficulty);
    Memory::hookFunc((void *) setDifficultyPacket->packetHandler->vTable[1], (void*)receiveCallbackSetDifficulty,
                     (void **) &receiveSetDifficultyPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> changeDimensionPacket = SDK::createPacket((int) MinecraftPacketIds::ChangeDimension);
    Memory::hookFunc((void *) changeDimensionPacket->packetHandler->vTable[1], (void*)receiveCallbackChangeDimension,
                     (void **) &receiveChangeDimensionPacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> setTitlePacket = SDK::createPacket((int) MinecraftPacketIds::SetTitle);
    Memory::hookFunc((void *) setTitlePacket->packetHandler->vTable[1], (void*)receiveCallbackSetTitle,
                     (void **) &receiveSetTitlePacketOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> playSoundPacket = SDK::createPacket((int) MinecraftPacketIds::PlaySoundPacket);
    Memory::hookFunc((void *) playSoundPacket->packetHandler->vTable[1], (void*)receiveCallbackPlaySound,
                     (void **) &receivePacketPlaySoundOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> EntityEventPacket = SDK::createPacket((int) MinecraftPacketIds::ActorEvent);
    Memory::hookFunc((void *) EntityEventPacket->packetHandler->vTable[1], (void*)receiveCallbackEntityEvent,
                     (void **) &receivePacketEntityEventOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> InteractPacket = SDK::createPacket((int) MinecraftPacketIds::Interact);
    Memory::hookFunc((void *) InteractPacket->packetHandler->vTable[1], (void*)receiveCallbackInteract,
                     (void **) &receivePacketInteractOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> ContainerOpenPacket = SDK::createPacket((int) MinecraftPacketIds::ContainerOpen);
    Memory::hookFunc((void *) ContainerOpenPacket->packetHandler->vTable[1], (void *)receiveCallbackContainerOpen,
                     (void **) &receivePacketContainerOpenOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> ContainerClosePacket = SDK::createPacket((int) MinecraftPacketIds::ContainerClose);
    Memory::hookFunc((void *) ContainerClosePacket->packetHandler->vTable[1], (void *)receiveCallbackContainerClose,
                     (void **) &receivePacketContainerCloseOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> changeDimensionPacket = SDK::createPacket((int) MinecraftPacketIds::ChangeDimension);
    Memory::hookFunc((void *) changeDimensionPacket->packetHandler->vTable[1], (void *)receiveCallbackChangeDimension,
                     (void **) &receivePacketChangeDimensionOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> ModalFormRequestPacket = SDK::createPacket((int) MinecraftPacketIds::ShowModalForm);
    Memory::hookFunc((void *) ModalFormRequestPacket->packetHandler->vTable[1], (void *)receiveCallbackModalFormRequest,
                     (void **) &receivePacketModalFormRequestOriginal, "ReceivePacketHook");

    std::shared_ptr<Packet> SkinPacket = SDK::createPacket((int) MinecraftPacketIds::PlayerSkin);
    Memory::hookFunc((void *) SkinPacket->packetHandler->vTable[1], (void *)receiveCallbackPlayerSkin,
                     (void **) &receivePacketPlayerSkinOriginal, "ReceivePacketHook");

    this->autoHook((void *) callback, (void **) &sendPacketOriginal);
}

void SendPacketHook::setVariables(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback) {
    SendPacketHook::NetworkIdentifier = networkIdentifier;
    SendPacketHook::PacketHandlerDispatcher = packetHandlerDispatcher;
    SendPacketHook::NetEventCallback = netEventCallback;
}
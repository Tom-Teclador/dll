#pragma once

#include "../Hook.hpp"
#include "../../../../SDK/Client/Network/Packet/LoopbackPacketSender.hpp"
#include "../../../../SDK/Client/Network/Packet/Packet.hpp"
#include "../../../../Utils/Memory/Game/SignatureAndOffsetManager.hpp"

class SendPacketHook : public Hook {

private:
    static void setVariables(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback);

    static void callback(LoopbackPacketSender *pSender, Packet *pPacket);
    
    static void receiveCallbackPlayStatus(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackServerToClientHandshake(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                const std::shared_ptr<Packet>& packet);

    static void receiveCallbackDisconnect(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackRescourcePacksInfo(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackRescourcePackStack(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackText(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSetTime(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackStartGame(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackAddPlayer(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackAddEntity(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackRemoveEntity(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackAddItemActor(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackTakeItemActor(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackMoveAbsoluteActor(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackMovePlayer(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackPassengerJump(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackUpdateBlock(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackAddPainting(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackTickSync(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackLevelSoundEventV1(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackLevelEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackTileEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackActorEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackMobEffect(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackUpdateAttributes(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackInventoryTransaction(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackPlayerEquipment(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackMobArmorEquipment(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackInteract(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackHurtArmor(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSetActorData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSetActorMotion(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSetActorLink(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSetHealth(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSetSpawnPosition(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackAnimate(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackRespawn(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackContainerOpen(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackContainerClose(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackPlayerHotbar(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackInventoryContent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackInventorySlot(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackContainerSetData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackCraftingData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackCraftingEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackGuiDataPickItem(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackAdventureSettings_Deprecated(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackBlockActorData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackFullChunkData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSetCommandsEnabled(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSetDifficulty(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackChangeDimension(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSetTitle(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                        const std::shared_ptr<Packet>& packet);

    static void receiveCallbackPlaySound(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                         const std::shared_ptr<Packet>& packet);

    static void receiveCallbackEntityEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                           const std::shared_ptr<Packet>& packet);


    static void receiveCallbackChangeDimension(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackModalFormRequest(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackPlayerSkin(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

public:

    static inline void* NetworkIdentifier;
    static inline void* PacketHandlerDispatcher;
    static inline void* NetEventCallback;

    typedef void(__thiscall *original)(LoopbackPacketSender *, Packet *);

    typedef void(__thiscall *receive)(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                      std::shared_ptr<Packet> packet);

    static inline original sendPacketOriginal = nullptr;
    static inline receive receivePlayStatusPacketOriginal = nullptr;
    static inline receive receiveServerToClientHandshakePacketOriginal = nullptr;
    static inline receive receiveDisconnectPacketOriginal = nullptr;
    static inline receive receiveRescourcePacksInfoPacketOriginal = nullptr;
    static inline receive receiveRescourcePackStackPacketOriginal = nullptr;
    static inline receive receiveTextPacketOriginal = nullptr;
    static inline receive receiveSetTimePacketOriginal = nullptr;
    static inline receive receiveStartGamePacketOriginal = nullptr;
    static inline receive receiveAddPlayerPacketOriginal = nullptr;
    static inline receive receiveAddEntityPacketOriginal = nullptr;
    static inline receive receiveRemoveEntityPacketOriginal = nullptr;
    static inline receive receiveAddItemActorPacketOriginal = nullptr;
    static inline receive receiveTakeItemActorPacketOriginal = nullptr;
    static inline receive receiveMoveAbsoluteActorPacketOriginal = nullptr;
    static inline receive receiveMovePlayerPacketOriginal = nullptr;
    static inline receive receivePassengerJumpPacketOriginal = nullptr;
    static inline receive receiveUpdateBlockPacketOriginal = nullptr;
    static inline receive receiveAddPaintingPacketOriginal = nullptr;
    static inline receive receiveTickSyncPacketOriginal = nullptr;
    static inline receive receiveLevelSoundEventV1PacketOriginal = nullptr;
    static inline receive receiveLevelEventPacketOriginal = nullptr;
    static inline receive receiveTileEventPacketOriginal = nullptr;
    static inline receive receiveActorEventPacketOriginal = nullptr;
    static inline receive receiveMobEffectPacketOriginal = nullptr;
    static inline receive receiveUpdateAttributesPacketOriginal = nullptr;
    static inline receive receiveInventoryTransactionPacketOriginal = nullptr;
    static inline receive receivePlayerEquipmentPacketOriginal = nullptr;
    static inline receive receiveMobArmorEquipmentPacketOriginal = nullptr;
    static inline receive receiveInteractPacketOriginal = nullptr;
    static inline receive receiveHurtArmorPacketOriginal = nullptr;
    static inline receive receiveSetActorDataPacketOriginal = nullptr;
    static inline receive receiveSetActorMotionPacketOriginal = nullptr;
    static inline receive receiveSetActorLinkPacketOriginal = nullptr;
    static inline receive receiveSetHealthPacketOriginal = nullptr;
    static inline receive receiveSetSpawnPositionPacketOriginal = nullptr;
    static inline receive receiveAnimatePacketOriginal = nullptr;
    static inline receive receiveRespawnPacketOriginal = nullptr;
    static inline receive receiveContainerOpenPacketOriginal = nullptr;
    static inline receive receiveContainerClosePacketOriginal = nullptr;
    static inline receive receivePlayerHotbarPacketOriginal = nullptr;
    static inline receive receiveInventoryContentPacketOriginal = nullptr;
    static inline receive receiveInventorySlotPacketOriginal = nullptr;
    static inline receive receiveContainerSetDataPacketOriginal = nullptr;
    static inline receive receiveCraftingDataPacketOriginal = nullptr;
    static inline receive receiveCraftingEventPacketOriginal = nullptr;
    static inline receive receiveGuiDataPickItemPacketOriginal = nullptr;
    static inline receive receiveAdventureSettings_DeprecatedPacketOriginal = nullptr;
    static inline receive receiveBlockActorDataPacketOriginal = nullptr;
    static inline receive receiveFullChunkDataPacketOriginal = nullptr;
    static inline receive receiveSetCommandsEnabledPacketOriginal = nullptr;
    static inline receive receiveSetDifficultyPacketOriginal = nullptr;
    static inline receive receiveChangeDimensionPacketOriginal = nullptr;
    static inline receive receiveSetTitlePacketOriginal = nullptr;
    static inline receive receivePacketPlaySoundOriginal = nullptr;
    static inline receive receivePacketEntityEventOriginal = nullptr;
    static inline receive receivePacketChangeDimensionOriginal = nullptr;
    static inline receive receivePacketModalFormRequestOriginal = nullptr;
    static inline receive receivePacketPlayerSkinOriginal = nullptr;

    SendPacketHook() : Hook("sendPacket", GET_SIG_ADDRESS("LoopbackPacketSender::sendPacket")) {}

    void enableHook() override;


};
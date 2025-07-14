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

    static void receiveCallbackServerToClientHandshake(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
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

    static void receiveCallbackLevelEvent(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
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

    static void receiveCallbackPlayerHotbar(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackInventoryContent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackInventorySlot(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackContainerSetData(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackCraftingData(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackCraftingEvent(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackGuiDataPickItem(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackAdventureSettings_Deprecated(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackBlockActorData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackFullChunkData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSetCommandsEnabled(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSetDifficulty(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                    const std::shared_ptr<Packet>& packet);

        static void receiveCallbackSetPlayerGameType(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackPlayerList(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSimpleEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackMapData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackMapInfoRequest(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackRequestChunkRadius(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackChunkRadiusUpdated(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackGameRulesChanged(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackBossEvent(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackShowCredits(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackCommandOutput(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackUpdateTrade(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackUpdateEquip(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackResourcePackDataInfo(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackResourcePackChunkData(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackTransfer(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackPlaySound(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackStopSound(void* packetHandlerDispatcher, void* networkIdentifier, void* netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackAddBehaviorTree(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackStructureBlockUpdate(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackShowStoreOffer(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackPlayerSkin(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackSetLastHurtBy(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
                                               const std::shared_ptr<Packet>& packet);

    static void receiveCallbackNPCRequest(void *packetHandlerDispatcher, void *networkIdentifier, void *netEventCallback,
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

    static inline original sendOriginal = nullptr;
    static inline receive receivePacketPlayStatusOriginal = nullptr;
    static inline receive receivePacketServerToClientHandshakeOriginal = nullptr;
    static inline receive receivePacketDisconnectOriginal = nullptr;
    static inline receive receivePacketRescourcePacksInfoOriginal = nullptr;
    static inline receive receivePacketRescourcePackStackOriginal = nullptr;
    static inline receive receivePacketTextOriginal = nullptr;
    static inline receive receivePacketSetTimeOriginal = nullptr;
    static inline receive receivePacketStartGameOriginal = nullptr;
    static inline receive receivePacketAddPlayerOriginal = nullptr;
    static inline receive receivePacketAddEntityOriginal = nullptr;
    static inline receive receivePacketRemoveEntityOriginal = nullptr;
    static inline receive receivePacketAddItemActorOriginal = nullptr;
    static inline receive receivePacketTakeItemActorOriginal = nullptr;
    static inline receive receivePacketMoveAbsoluteActorOriginal = nullptr;
    static inline receive receivePacketMovePlayerOriginal = nullptr;
    static inline receive receivePacketPassengerJumpOriginal = nullptr;
    static inline receive receivePacketUpdateBlockOriginal = nullptr;
    static inline receive receivePacketAddPaintingOriginal = nullptr;
    static inline receive receivePacketTickSyncOriginal = nullptr;
    static inline receive receivePacketLevelSoundEventV1Original = nullptr;
    static inline receive receivePacketLevelEventOriginal = nullptr;
    static inline receive receivePacketTileEventOriginal = nullptr;
    static inline receive receivePacketActorEventOriginal = nullptr;
    static inline receive receivePacketMobEffectOriginal = nullptr;
    static inline receive receivePacketUpdateAttributesOriginal = nullptr;
    static inline receive receivePacketInventoryTransactionOriginal = nullptr;
    static inline receive receivePacketPlayerEquipmentOriginal = nullptr;
    static inline receive receivePacketMobArmorEquipmentOriginal = nullptr;
    static inline receive receivePacketInteractOriginal = nullptr;
    static inline receive receivePacketHurtArmorOriginal = nullptr;
    static inline receive receivePacketSetActorDataOriginal = nullptr;
    static inline receive receivePacketSetActorMotionOriginal = nullptr;
    static inline receive receivePacketSetActorLinkOriginal = nullptr;
    static inline receive receivePacketSetHealthOriginal = nullptr;
    static inline receive receivePacketSetSpawnPositionOriginal = nullptr;
    static inline receive receivePacketAnimateOriginal = nullptr;
    static inline receive receivePacketRespawnOriginal = nullptr;
    static inline receive receivePacketContainerOpenOriginal = nullptr;
    static inline receive receivePacketContainerCloseOriginal = nullptr;
    static inline receive receivePacketPlayerHotbarOriginal = nullptr;
    static inline receive receivePacketInventoryContentOriginal = nullptr;
    static inline receive receivePacketInventorySlotOriginal = nullptr;
    static inline receive receivePacketContainerSetDataOriginal = nullptr;
    static inline receive receivePacketCraftingDataOriginal = nullptr;
    static inline receive receivePacketCraftingEventOriginal = nullptr;
    static inline receive receivePacketGuiDataPickItemOriginal = nullptr;
    static inline receive receivePacketAdventureSettings_DeprecatedOriginal = nullptr;
    static inline receive receivePacketBlockActorDataOriginal = nullptr;
    static inline receive receivePacketFullChunkDataOriginal = nullptr;
    static inline receive receivePacketSetCommandsEnabledOriginal = nullptr;
    static inline receive receivePacketSetDifficultyOriginal = nullptr;
    static inline receive receivePacketSetPlayerGameTypeOriginal = nullptr;
    static inline receive receivePacketPlayerListOriginal = nullptr;
    static inline receive receivePacketSimpleEventOriginal = nullptr;
    static inline receive receivePacketMapDataOriginal = nullptr;
    static inline receive receivePacketMapInfoRequestOriginal = nullptr;
    static inline receive receivePacketRequestChunkRadiusOriginal = nullptr;
    static inline receive receivePacketChunkRadiusUpdatedOriginal = nullptr;
    static inline receive receivePacketGameRulesChangedOriginal = nullptr;
    static inline receive receivePacketBossEventOriginal = nullptr;
    static inline receive receivePacketShowCreditsOriginal = nullptr;
    static inline receive receivePacketCommandOutputOriginal = nullptr;
    static inline receive receivePacketUpdateTradeOriginal = nullptr;
    static inline receive receivePacketUpdateEquipOriginal = nullptr;
    static inline receive receivePacketResourcePackDataInfoOriginal = nullptr;
    static inline receive receivePacketResourcePackChunkDataOriginal = nullptr;
    static inline receive receivePacketTransferOriginal = nullptr;
    static inline receive receivePacketStopSoundOriginal = nullptr;
    static inline receive receivePacketAddBehaviorTreeOriginal = nullptr;
    static inline receive receivePacketStructureBlockUpdateOriginal = nullptr;
    static inline receive receivePacketShowStoreOfferOriginal = nullptr;
    static inline receive receivePacketPlayerSkinOriginal = nullptr;
    static inline receive receivePacketSetLastHurtByOriginal = nullptr;
    static inline receive receivePacketChangeDimensionOriginal = nullptr;
    static inline receive receivePacketSetTitleOriginal = nullptr;
    static inline receive receivePacketPlaySoundOriginal = nullptr;
    static inline receive receivePacketEntityEventOriginal = nullptr;
    static inline receive receivePacketModalFormRequestOriginal = nullptr;
    static inline receive receivePacketPlayerSkinOriginal = nullptr;
    
    SendPacketHook() : Hook("sendPacket", GET_SIG_ADDRESS("LoopbackPacketSender::sendPacket")) {}

    void enableHook() override;


};
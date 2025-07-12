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

    std::memcpy(&buffer[write_offset], "\n}\n\n", 4);
    write_offset += 4;
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
    MinecraftPacketIds id = packet.getId();
    int id_int = static_cast<int>(id);
    
    appendInt(id_int);
    std::memcpy(&buffer[write_offset++], " ", 1);
    appendHex(id_int);
    std::memcpy(&buffer[write_offset], " {\n", 3);
    write_offset += 3;

    switch (id) {
        case MinecraftPacketIds::KeepAlive: {
            std::memcpy(&buffer[write_offset], "/* KeepAlive */", 15);
            write_offset += 15;
            break;
        }


        case MinecraftPacketIds::Login: {
            std::memcpy(&buffer[write_offset], "/* Login */", 11);
            write_offset += 11;
            break;
        }


        case MinecraftPacketIds::PlayStatus: {
            std::memcpy(&buffer[write_offset], "/* PlayStatus */", 16);
            write_offset += 16;
            break;
        }


        case MinecraftPacketIds::ServerToClientHandshake: {
            std::memcpy(&buffer[write_offset], "/* ServerToClientHandshake */", 29);
            write_offset += 29;
            break;
        }


        case MinecraftPacketIds::ClientToServerHandshake: {
            std::memcpy(&buffer[write_offset], "/* ClientToServerHandshake */", 29);
            write_offset += 29;
            break;
        }


        case MinecraftPacketIds::Disconnect: {
            std::memcpy(&buffer[write_offset], "/* Disconnect */", 16);
            write_offset += 16;
            break;
        }


        case MinecraftPacketIds::ResourcePacksInfo: {
            std::memcpy(&buffer[write_offset], "/* ResourcePacksInfo */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::ResourcePackStack: {
            std::memcpy(&buffer[write_offset], "/* ResourcePackStack */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::ResourcePackClientResponse: {
            std::memcpy(&buffer[write_offset], "/* ResourcePackClientResponse */", 32);
            write_offset += 32;
            break;
        }


        case MinecraftPacketIds::Text: {
            std::memcpy(&buffer[write_offset], "/* Text */", 10);
            write_offset += 10;
            break;
        }


        case MinecraftPacketIds::SetTime: {
            std::memcpy(&buffer[write_offset], "/* SetTime */", 13);
            write_offset += 13;
            break;
        }


        case MinecraftPacketIds::StartGame: {
            std::memcpy(&buffer[write_offset], "/* StartGame */", 15);
            write_offset += 15;
            break;
        }


        case MinecraftPacketIds::AddPlayer: {
            std::memcpy(&buffer[write_offset], "/* AddPlayer */", 15);
            write_offset += 15;
            break;
        }


        case MinecraftPacketIds::AddActor: {
            std::memcpy(&buffer[write_offset], "/* AddActor */", 14);
            write_offset += 14;
            break;
        }


        case MinecraftPacketIds::RemoveActor: {
            std::memcpy(&buffer[write_offset], "/* RemoveActor */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::AddItemActor: {
            std::memcpy(&buffer[write_offset], "/* AddItemActor */", 18);
            write_offset += 18;
            break;
        }


        case MinecraftPacketIds::UNUSED: {
            std::memcpy(&buffer[write_offset], "/* UNUSED */", 12);
            write_offset += 12;
            break;
        }


        case MinecraftPacketIds::TakeItemActor: {
            std::memcpy(&buffer[write_offset], "/* TakeItemActor */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::MoveAbsoluteActor: {
            std::memcpy(&buffer[write_offset], "/* MoveAbsoluteActor */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::MovePlayer: {
            std::memcpy(&buffer[write_offset], "/* MovePlayer */", 16);
            write_offset += 16;
            break;
        }


        case MinecraftPacketIds::PassengerJump: {
            std::memcpy(&buffer[write_offset], "/* PassengerJump */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::UpdateBlock: {
            std::memcpy(&buffer[write_offset], "/* UpdateBlock */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::AddPainting: {
            std::memcpy(&buffer[write_offset], "/* AddPainting */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::TickSync: {
            std::memcpy(&buffer[write_offset], "/* TickSync */", 14);
            write_offset += 14;
            break;
        }


        case MinecraftPacketIds::LevelSoundEventV1: {
            std::memcpy(&buffer[write_offset], "/* LevelSoundEventV1 */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::LevelEvent: {
            std::memcpy(&buffer[write_offset], "/* LevelEvent */", 16);
            write_offset += 16;
            break;
        }


        case MinecraftPacketIds::TileEvent: {
            std::memcpy(&buffer[write_offset], "/* TileEvent */", 15);
            write_offset += 15;
            break;
        }


        case MinecraftPacketIds::ActorEvent: {
            std::memcpy(&buffer[write_offset], "/* ActorEvent */", 16);
            write_offset += 16;
            break;
        }


        case MinecraftPacketIds::MobEffect: {
            std::memcpy(&buffer[write_offset], "/* MobEffect */", 15);
            write_offset += 15;
            break;
        }


        case MinecraftPacketIds::UpdateAttributes: {
            std::memcpy(&buffer[write_offset], "/* UpdateAttributes */", 22);
            write_offset += 22;
            break;
        }


        case MinecraftPacketIds::InventoryTransaction: {
            std::memcpy(&buffer[write_offset], "/* InventoryTransaction */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::PlayerEquipment: {
            std::memcpy(&buffer[write_offset], "/* PlayerEquipment */", 21);
            write_offset += 21;
            break;
        }


        case MinecraftPacketIds::MobArmorEquipment: {
            std::memcpy(&buffer[write_offset], "/* MobArmorEquipment */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::Interact: {
            std::memcpy(&buffer[write_offset], "/* Interact */", 14);
            write_offset += 14;
            break;
        }


        case MinecraftPacketIds::BlockPickRequest: {
            std::memcpy(&buffer[write_offset], "/* BlockPickRequest */", 22);
            write_offset += 22;
            break;
        }


        case MinecraftPacketIds::ActorPickRequest: {
            std::memcpy(&buffer[write_offset], "/* ActorPickRequest */", 22);
            write_offset += 22;
            break;
        }


        case MinecraftPacketIds::PlayerAction: {
            std::memcpy(&buffer[write_offset], "/* PlayerAction */", 18);
            write_offset += 18;
            break;
        }


        case MinecraftPacketIds::ActorFall_deprecated: {
            std::memcpy(&buffer[write_offset], "/* ActorFall_deprecated */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::HurtArmor: {
            std::memcpy(&buffer[write_offset], "/* HurtArmor */", 15);
            write_offset += 15;
            break;
        }


        case MinecraftPacketIds::SetActorData: {
            std::memcpy(&buffer[write_offset], "/* SetActorData */", 18);
            write_offset += 18;
            break;
        }


        case MinecraftPacketIds::SetActorMotion: {
            std::memcpy(&buffer[write_offset], "/* SetActorMotion */", 20);
            write_offset += 20;
            break;
        }


        case MinecraftPacketIds::SetActorLink: {
            std::memcpy(&buffer[write_offset], "/* SetActorLink */", 18);
            write_offset += 18;
            break;
        }


        case MinecraftPacketIds::SetHealth: {
            std::memcpy(&buffer[write_offset], "/* SetHealth */", 15);
            write_offset += 15;
            break;
        }


        case MinecraftPacketIds::SetSpawnPosition: {
            std::memcpy(&buffer[write_offset], "/* SetSpawnPosition */", 22);
            write_offset += 22;
            break;
        }


        case MinecraftPacketIds::Animate: {
            std::memcpy(&buffer[write_offset], "/* Animate */", 13);
            write_offset += 13;
            break;
        }


        case MinecraftPacketIds::Respawn: {
            std::memcpy(&buffer[write_offset], "/* Respawn */", 13);
            write_offset += 13;
            break;
        }


        case MinecraftPacketIds::ContainerOpen: {
            std::memcpy(&buffer[write_offset], "/* ContainerOpen */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::ContainerClose: {
            std::memcpy(&buffer[write_offset], "/* ContainerClose */", 20);
            write_offset += 20;
            break;
        }


        case MinecraftPacketIds::PlayerHotbar: {
            std::memcpy(&buffer[write_offset], "/* PlayerHotbar */", 18);
            write_offset += 18;
            break;
        }


        case MinecraftPacketIds::InventoryContent: {
            std::memcpy(&buffer[write_offset], "/* InventoryContent */", 22);
            write_offset += 22;
            break;
        }


        case MinecraftPacketIds::InventorySlot: {
            std::memcpy(&buffer[write_offset], "/* InventorySlot */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::ContainerSetData: {
            std::memcpy(&buffer[write_offset], "/* ContainerSetData */", 22);
            write_offset += 22;
            break;
        }


        case MinecraftPacketIds::CraftingData: {
            std::memcpy(&buffer[write_offset], "/* CraftingData */", 18);
            write_offset += 18;
            break;
        }


        case MinecraftPacketIds::CraftingEvent: {
            std::memcpy(&buffer[write_offset], "/* CraftingEvent */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::GuiDataPickItem: {
            std::memcpy(&buffer[write_offset], "/* GuiDataPickItem */", 21);
            write_offset += 21;
            break;
        }


        case MinecraftPacketIds::AdventureSettings_Deprecated: {
            std::memcpy(&buffer[write_offset], "/* AdventureSettings_Deprecated */", 34);
            write_offset += 34;
            break;
        }


        case MinecraftPacketIds::BlockActorData: {
            std::memcpy(&buffer[write_offset], "/* BlockActorData */", 20);
            write_offset += 20;
            break;
        }


        case MinecraftPacketIds::PlayerInput: {
            std::memcpy(&buffer[write_offset], "/* PlayerInput */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::FullChunkData: {
            std::memcpy(&buffer[write_offset], "/* FullChunkData */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::SetCommandsEnabled: {
            std::memcpy(&buffer[write_offset], "/* SetCommandsEnabled */", 24);
            write_offset += 24;
            break;
        }


        case MinecraftPacketIds::SetDifficulty: {
            std::memcpy(&buffer[write_offset], "/* SetDifficulty */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::ChangeDimension: {
            std::memcpy(&buffer[write_offset], "/* ChangeDimension */", 21);
            write_offset += 21;
            break;
        }


        case MinecraftPacketIds::SetPlayerGameType: {
            std::memcpy(&buffer[write_offset], "/* SetPlayerGameType */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::PlayerList: {
            std::memcpy(&buffer[write_offset], "/* PlayerList */", 16);
            write_offset += 16;
            break;
        }


        case MinecraftPacketIds::SimpleEvent: {
            std::memcpy(&buffer[write_offset], "/* SimpleEvent */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::Event: {
            std::memcpy(&buffer[write_offset], "/* Event */", 11);
            write_offset += 11;
            break;
        }


        case MinecraftPacketIds::SpawnExperienceOrb: {
            std::memcpy(&buffer[write_offset], "/* SpawnExperienceOrb */", 24);
            write_offset += 24;
            break;
        }


        case MinecraftPacketIds::MapData: {
            std::memcpy(&buffer[write_offset], "/* MapData */", 13);
            write_offset += 13;
            break;
        }


        case MinecraftPacketIds::MapInfoRequest: {
            std::memcpy(&buffer[write_offset], "/* MapInfoRequest */", 20);
            write_offset += 20;
            break;
        }


        case MinecraftPacketIds::RequestChunkRadius: {
            std::memcpy(&buffer[write_offset], "/* RequestChunkRadius */", 24);
            write_offset += 24;
            break;
        }


        case MinecraftPacketIds::ChunkRadiusUpdated: {
            std::memcpy(&buffer[write_offset], "/* ChunkRadiusUpdated */", 24);
            write_offset += 24;
            break;
        }


        case MinecraftPacketIds::ItemFrameDropItem: {
            std::memcpy(&buffer[write_offset], "/* ItemFrameDropItem */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::GameRulesChanged: {
            std::memcpy(&buffer[write_offset], "/* GameRulesChanged */", 22);
            write_offset += 22;
            break;
        }


        case MinecraftPacketIds::Camera: {
            std::memcpy(&buffer[write_offset], "/* Camera */", 12);
            write_offset += 12;
            break;
        }


        case MinecraftPacketIds::BossEvent: {
            std::memcpy(&buffer[write_offset], "/* BossEvent */", 15);
            write_offset += 15;
            break;
        }


        case MinecraftPacketIds::ShowCredits: {
            std::memcpy(&buffer[write_offset], "/* ShowCredits */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::AvailableCommands: {
            std::memcpy(&buffer[write_offset], "/* AvailableCommands */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::CommandRequest: {
            std::memcpy(&buffer[write_offset], "/* CommandRequest */", 20);
            write_offset += 20;
            break;
        }


        case MinecraftPacketIds::CommandBlockUpdate: {
            std::memcpy(&buffer[write_offset], "/* CommandBlockUpdate */", 24);
            write_offset += 24;
            break;
        }


        case MinecraftPacketIds::CommandOutput: {
            std::memcpy(&buffer[write_offset], "/* CommandOutput */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::UpdateTrade: {
            std::memcpy(&buffer[write_offset], "/* UpdateTrade */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::UpdateEquip: {
            std::memcpy(&buffer[write_offset], "/* UpdateEquip */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::ResourcePackDataInfo: {
            std::memcpy(&buffer[write_offset], "/* ResourcePackDataInfo */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::ResourcePackChunkData: {
            std::memcpy(&buffer[write_offset], "/* ResourcePackChunkData */", 27);
            write_offset += 27;
            break;
        }


        case MinecraftPacketIds::ResourcePackChunkRequest: {
            std::memcpy(&buffer[write_offset], "/* ResourcePackChunkRequest */", 30);
            write_offset += 30;
            break;
        }


        case MinecraftPacketIds::Transfer: {
            std::memcpy(&buffer[write_offset], "/* Transfer */", 14);
            write_offset += 14;
            break;
        }


        case MinecraftPacketIds::PlaySoundPacket: {
            std::memcpy(&buffer[write_offset], "/* PlaySoundPacket */", 21);
            write_offset += 21;
            break;
        }


        case MinecraftPacketIds::StopSound: {
            std::memcpy(&buffer[write_offset], "/* StopSound */", 15);
            write_offset += 15;
            break;
        }


        case MinecraftPacketIds::SetTitle: {
            std::memcpy(&buffer[write_offset], "/* SetTitle */", 14);
            write_offset += 14;
            break;
        }


        case MinecraftPacketIds::AddBehaviorTree: {
            std::memcpy(&buffer[write_offset], "/* AddBehaviorTree */", 21);
            write_offset += 21;
            break;
        }


        case MinecraftPacketIds::StructureBlockUpdate: {
            std::memcpy(&buffer[write_offset], "/* StructureBlockUpdate */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::ShowStoreOffer: {
            std::memcpy(&buffer[write_offset], "/* ShowStoreOffer */", 20);
            write_offset += 20;
            break;
        }


        case MinecraftPacketIds::PurchaseReceipt: {
            std::memcpy(&buffer[write_offset], "/* PurchaseReceipt */", 21);
            write_offset += 21;
            break;
        }


        case MinecraftPacketIds::PlayerSkin: {
            std::memcpy(&buffer[write_offset], "/* PlayerSkin */", 16);
            write_offset += 16;
            break;
        }


        case MinecraftPacketIds::SubclientLogin: {
            std::memcpy(&buffer[write_offset], "/* SubclientLogin */", 20);
            write_offset += 20;
            break;
        }


        case MinecraftPacketIds::AutomationClientConnect: {
            std::memcpy(&buffer[write_offset], "/* AutomationClientConnect */", 29);
            write_offset += 29;
            break;
        }


        case MinecraftPacketIds::SetLastHurtBy: {
            std::memcpy(&buffer[write_offset], "/* SetLastHurtBy */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::BookEdit: {
            std::memcpy(&buffer[write_offset], "/* BookEdit */", 14);
            write_offset += 14;
            break;
        }


        case MinecraftPacketIds::NPCRequest: {
            std::memcpy(&buffer[write_offset], "/* NPCRequest */", 16);
            write_offset += 16;
            break;
        }


        case MinecraftPacketIds::PhotoTransfer: {
            std::memcpy(&buffer[write_offset], "/* PhotoTransfer */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::ShowModalForm: {
            std::memcpy(&buffer[write_offset], "/* ShowModalForm */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::ModalFormResponse: {
            std::memcpy(&buffer[write_offset], "/* ModalFormResponse */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::ServerSettingsRequest: {
            std::memcpy(&buffer[write_offset], "/* ServerSettingsRequest */", 27);
            write_offset += 27;
            break;
        }


        case MinecraftPacketIds::ServerSettingsResponse: {
            std::memcpy(&buffer[write_offset], "/* ServerSettingsResponse */", 28);
            write_offset += 28;
            break;
        }


        case MinecraftPacketIds::ShowProfile: {
            std::memcpy(&buffer[write_offset], "/* ShowProfile */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::SetDefaultGameType: {
            std::memcpy(&buffer[write_offset], "/* SetDefaultGameType */", 24);
            write_offset += 24;
            break;
        }


        case MinecraftPacketIds::RemoveObjective: {
            std::memcpy(&buffer[write_offset], "/* RemoveObjective */", 21);
            write_offset += 21;
            break;
        }


        case MinecraftPacketIds::SetDisplayObjective: {
            std::memcpy(&buffer[write_offset], "/* SetDisplayObjective */", 25);
            write_offset += 25;
            break;
        }


        case MinecraftPacketIds::SetScore: {
            std::memcpy(&buffer[write_offset], "/* SetScore */", 14);
            write_offset += 14;
            break;
        }


        case MinecraftPacketIds::LabTable: {
            std::memcpy(&buffer[write_offset], "/* LabTable */", 14);
            write_offset += 14;
            break;
        }


        case MinecraftPacketIds::UpdateBlockSynced: {
            std::memcpy(&buffer[write_offset], "/* UpdateBlockSynced */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::MoveDeltaActor: {
            std::memcpy(&buffer[write_offset], "/* MoveDeltaActor */", 20);
            write_offset += 20;
            break;
        }


        case MinecraftPacketIds::SetScoreboardIdentity: {
            std::memcpy(&buffer[write_offset], "/* SetScoreboardIdentity */", 27);
            write_offset += 27;
            break;
        }


        case MinecraftPacketIds::SetLocalPlayerAsInit: {
            std::memcpy(&buffer[write_offset], "/* SetLocalPlayerAsInit */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::UpdateSoftEnum: {
            std::memcpy(&buffer[write_offset], "/* UpdateSoftEnum */", 20);
            write_offset += 20;
            break;
        }


        case MinecraftPacketIds::Ping: {
            std::memcpy(&buffer[write_offset], "/* Ping */", 10);
            write_offset += 10;
            break;
        }


        case MinecraftPacketIds::BlockPalette: {
            std::memcpy(&buffer[write_offset], "/* BlockPalette */", 18);
            write_offset += 18;
            break;
        }


        case MinecraftPacketIds::ScriptCustomEvent: {
            std::memcpy(&buffer[write_offset], "/* ScriptCustomEvent */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::SpawnParticleEffect: {
            std::memcpy(&buffer[write_offset], "/* SpawnParticleEffect */", 25);
            write_offset += 25;
            break;
        }


        case MinecraftPacketIds::AvailableActorIDList: {
            std::memcpy(&buffer[write_offset], "/* AvailableActorIDList */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::LevelSoundEventV2: {
            std::memcpy(&buffer[write_offset], "/* LevelSoundEventV2 */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::NetworkChunkPublisherUpdate: {
            std::memcpy(&buffer[write_offset], "/* NetworkChunkPublisherUpdate */", 33);
            write_offset += 33;
            break;
        }


        case MinecraftPacketIds::BiomeDefinitionList: {
            std::memcpy(&buffer[write_offset], "/* BiomeDefinitionList */", 25);
            write_offset += 25;
            break;
        }


        case MinecraftPacketIds::LevelSoundEvent: {
            std::memcpy(&buffer[write_offset], "/* LevelSoundEvent */", 21);
            write_offset += 21;
            break;
        }


        case MinecraftPacketIds::LevelEventGeneric: {
            std::memcpy(&buffer[write_offset], "/* LevelEventGeneric */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::LecternUpdate: {
            std::memcpy(&buffer[write_offset], "/* LecternUpdate */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::VideoStreamConnect_DEPRECATED: {
            std::memcpy(&buffer[write_offset], "/* VideoStreamConnect_DEPRECATED */", 35);
            write_offset += 35;
            break;
        }


        case MinecraftPacketIds::AddEntity: {
            std::memcpy(&buffer[write_offset], "/* AddEntity */", 15);
            write_offset += 15;
            break;
        }


        case MinecraftPacketIds::RemoveEntity: {
            std::memcpy(&buffer[write_offset], "/* RemoveEntity */", 18);
            write_offset += 18;
            break;
        }


        case MinecraftPacketIds::ClientCacheStatus: {
            std::memcpy(&buffer[write_offset], "/* ClientCacheStatus */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::OnScreenTextureAnimation: {
            std::memcpy(&buffer[write_offset], "/* OnScreenTextureAnimation */", 30);
            write_offset += 30;
            break;
        }


        case MinecraftPacketIds::MapCreateLockedCopy: {
            std::memcpy(&buffer[write_offset], "/* MapCreateLockedCopy */", 25);
            write_offset += 25;
            break;
        }


        case MinecraftPacketIds::StructureTemplateDataExportRequest: {
            std::memcpy(&buffer[write_offset], "/* StructureTemplateDataExportRequest */", 40);
            write_offset += 40;
            break;
        }


        case MinecraftPacketIds::StructureTemplateDataExportResponse: {
            std::memcpy(&buffer[write_offset], "/* StructureTemplateDataExportResponse */", 41);
            write_offset += 41;
            break;
        }


        case MinecraftPacketIds::UNUSED_PLS_USE_ME2: {
            std::memcpy(&buffer[write_offset], "/* UNUSED_PLS_USE_ME2 */", 24);
            write_offset += 24;
            break;
        }


        case MinecraftPacketIds::ClientCacheBlobStatusPacket: {
            std::memcpy(&buffer[write_offset], "/* ClientCacheBlobStatusPacket */", 33);
            write_offset += 33;
            break;
        }


        case MinecraftPacketIds::ClientCacheMissResponsePacket: {
            std::memcpy(&buffer[write_offset], "/* ClientCacheMissResponsePacket */", 35);
            write_offset += 35;
            break;
        }


        case MinecraftPacketIds::EducationSettingsPacket: {
            std::memcpy(&buffer[write_offset], "/* EducationSettingsPacket */", 29);
            write_offset += 29;
            break;
        }


        case MinecraftPacketIds::Emote: {
            std::memcpy(&buffer[write_offset], "/* Emote */", 11);
            write_offset += 11;
            break;
        }


        case MinecraftPacketIds::MultiplayerSettingsPacket: {
            std::memcpy(&buffer[write_offset], "/* MultiplayerSettingsPacket */", 31);
            write_offset += 31;
            break;
        }


        case MinecraftPacketIds::SettingsCommandPacket: {
            std::memcpy(&buffer[write_offset], "/* SettingsCommandPacket */", 27);
            write_offset += 27;
            break;
        }


        case MinecraftPacketIds::AnvilDamage: {
            std::memcpy(&buffer[write_offset], "/* AnvilDamage */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::CompletedUsingItem: {
            std::memcpy(&buffer[write_offset], "/* CompletedUsingItem */", 24);
            write_offset += 24;
            break;
        }


        case MinecraftPacketIds::NetworkSettings: {
            std::memcpy(&buffer[write_offset], "/* NetworkSettings */", 21);
            write_offset += 21;
            break;
        }


        case MinecraftPacketIds::PlayerAuthInputPacket: {
            std::memcpy(&buffer[write_offset], "/* PlayerAuthInputPacket */", 27);
            write_offset += 27;
            break;
        }


        case MinecraftPacketIds::CreativeContent: {
            std::memcpy(&buffer[write_offset], "/* CreativeContent */", 21);
            write_offset += 21;
            break;
        }


        case MinecraftPacketIds::PlayerEnchantOptions: {
            std::memcpy(&buffer[write_offset], "/* PlayerEnchantOptions */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::ItemStackRequest: {
            std::memcpy(&buffer[write_offset], "/* ItemStackRequest */", 22);
            write_offset += 22;
            break;
        }


        case MinecraftPacketIds::ItemStackResponse: {
            std::memcpy(&buffer[write_offset], "/* ItemStackResponse */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::PlayerArmorDamage: {
            std::memcpy(&buffer[write_offset], "/* PlayerArmorDamage */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::CodeBuilderPacket: {
            std::memcpy(&buffer[write_offset], "/* CodeBuilderPacket */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::UpdatePlayerGameType: {
            std::memcpy(&buffer[write_offset], "/* UpdatePlayerGameType */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::EmoteList: {
            std::memcpy(&buffer[write_offset], "/* EmoteList */", 15);
            write_offset += 15;
            break;
        }


        case MinecraftPacketIds::PositionTrackingDBServerBroadcast: {
            std::memcpy(&buffer[write_offset], "/* PositionTrackingDBServerBroadcast */", 39);
            write_offset += 39;
            break;
        }


        case MinecraftPacketIds::PositionTrackingDBClientRequest: {
            std::memcpy(&buffer[write_offset], "/* PositionTrackingDBClientRequest */", 37);
            write_offset += 37;
            break;
        }


        case MinecraftPacketIds::DebugInfoPacket: {
            std::memcpy(&buffer[write_offset], "/* DebugInfoPacket */", 21);
            write_offset += 21;
            break;
        }


        case MinecraftPacketIds::PacketViolationWarning: {
            std::memcpy(&buffer[write_offset], "/* PacketViolationWarning */", 28);
            write_offset += 28;
            break;
        }


        case MinecraftPacketIds::MotionPredictionHints: {
            std::memcpy(&buffer[write_offset], "/* MotionPredictionHints */", 27);
            write_offset += 27;
            break;
        }


        case MinecraftPacketIds::TriggerAnimation: {
            std::memcpy(&buffer[write_offset], "/* TriggerAnimation */", 22);
            write_offset += 22;
            break;
        }


        case MinecraftPacketIds::CameraShake: {
            std::memcpy(&buffer[write_offset], "/* CameraShake */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::PlayerFogSetting: {
            std::memcpy(&buffer[write_offset], "/* PlayerFogSetting */", 22);
            write_offset += 22;
            break;
        }


        case MinecraftPacketIds::CorrectPlayerMovePredictionPacket: {
            std::memcpy(&buffer[write_offset], "/* CorrectPlayerMovePredictionPacket */", 39);
            write_offset += 39;
            break;
        }


        case MinecraftPacketIds::ItemComponentPacket: {
            std::memcpy(&buffer[write_offset], "/* ItemComponentPacket */", 25);
            write_offset += 25;
            break;
        }


        case MinecraftPacketIds::FilterTextPacket: {
            std::memcpy(&buffer[write_offset], "/* FilterTextPacket */", 22);
            write_offset += 22;
            break;
        }


        case MinecraftPacketIds::ClientBoundDebugRendererPacket: {
            std::memcpy(&buffer[write_offset], "/* ClientBoundDebugRendererPacket */", 36);
            write_offset += 36;
            break;
        }


        case MinecraftPacketIds::SyncActorProperty: {
            std::memcpy(&buffer[write_offset], "/* SyncActorProperty */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::AddVolumeEntityPacket: {
            std::memcpy(&buffer[write_offset], "/* AddVolumeEntityPacket */", 27);
            write_offset += 27;
            break;
        }


        case MinecraftPacketIds::RemoveVolumeEntityPacket: {
            std::memcpy(&buffer[write_offset], "/* RemoveVolumeEntityPacket */", 30);
            write_offset += 30;
            break;
        }


        case MinecraftPacketIds::SimulationTypePacket: {
            std::memcpy(&buffer[write_offset], "/* SimulationTypePacket */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::NpcDialoguePacket: {
            std::memcpy(&buffer[write_offset], "/* NpcDialoguePacket */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::EduUriResourcePacket: {
            std::memcpy(&buffer[write_offset], "/* EduUriResourcePacket */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::CreatePhotoPacket: {
            std::memcpy(&buffer[write_offset], "/* CreatePhotoPacket */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::UpdateSubChunkBlocks: {
            std::memcpy(&buffer[write_offset], "/* UpdateSubChunkBlocks */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::PhotoInfoRequest_DEPRECATED: {
            std::memcpy(&buffer[write_offset], "/* PhotoInfoRequest_DEPRECATED */", 33);
            write_offset += 33;
            break;
        }


        case MinecraftPacketIds::SubChunkPacket: {
            std::memcpy(&buffer[write_offset], "/* SubChunkPacket */", 20);
            write_offset += 20;
            break;
        }


        case MinecraftPacketIds::SubChunkRequestPacket: {
            std::memcpy(&buffer[write_offset], "/* SubChunkRequestPacket */", 27);
            write_offset += 27;
            break;
        }


        case MinecraftPacketIds::PlayerStartItemCooldown: {
            std::memcpy(&buffer[write_offset], "/* PlayerStartItemCooldown */", 29);
            write_offset += 29;
            break;
        }


        case MinecraftPacketIds::ScriptMessagePacket: {
            std::memcpy(&buffer[write_offset], "/* ScriptMessagePacket */", 25);
            write_offset += 25;
            break;
        }


        case MinecraftPacketIds::CodeBuilderSourcePacket: {
            std::memcpy(&buffer[write_offset], "/* CodeBuilderSourcePacket */", 29);
            write_offset += 29;
            break;
        }


        case MinecraftPacketIds::TickingAreasLoadStatus: {
            std::memcpy(&buffer[write_offset], "/* TickingAreasLoadStatus */", 28);
            write_offset += 28;
            break;
        }


        case MinecraftPacketIds::DimensionDataPacket: {
            std::memcpy(&buffer[write_offset], "/* DimensionDataPacket */", 25);
            write_offset += 25;
            break;
        }


        case MinecraftPacketIds::AgentAction: {
            std::memcpy(&buffer[write_offset], "/* AgentAction */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::ChangeMobProperty: {
            std::memcpy(&buffer[write_offset], "/* ChangeMobProperty */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::LessonProgressPacket: {
            std::memcpy(&buffer[write_offset], "/* LessonProgressPacket */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::RequestAbilityPacket: {
            std::memcpy(&buffer[write_offset], "/* RequestAbilityPacket */", 26);
            write_offset += 26;
            break;
        }


        case MinecraftPacketIds::RequestPermissionsPacket: {
            std::memcpy(&buffer[write_offset], "/* RequestPermissionsPacket */", 30);
            write_offset += 30;
            break;
        }


        case MinecraftPacketIds::ToastRequest: {
            std::memcpy(&buffer[write_offset], "/* ToastRequest */", 18);
            write_offset += 18;
            break;
        }


        case MinecraftPacketIds::UpdateAbilitiesPacket: {
            std::memcpy(&buffer[write_offset], "/* UpdateAbilitiesPacket */", 27);
            write_offset += 27;
            break;
        }


        case MinecraftPacketIds::UpdateAdventureSettingsPacket: {
            std::memcpy(&buffer[write_offset], "/* UpdateAdventureSettingsPacket */", 35);
            write_offset += 35;
            break;
        }


        case MinecraftPacketIds::DeathInfo: {
            std::memcpy(&buffer[write_offset], "/* DeathInfo */", 15);
            write_offset += 15;
            break;
        }


        case MinecraftPacketIds::EditorNetworkPacket: {
            std::memcpy(&buffer[write_offset], "/* EditorNetworkPacket */", 25);
            write_offset += 25;
            break;
        }


        case MinecraftPacketIds::FeatureRegistryPacket: {
            std::memcpy(&buffer[write_offset], "/* FeatureRegistryPacket */", 27);
            write_offset += 27;
            break;
        }


        case MinecraftPacketIds::ServerStats: {
            std::memcpy(&buffer[write_offset], "/* ServerStats */", 17);
            write_offset += 17;
            break;
        }


        case MinecraftPacketIds::RequestNetworkSettings: {
            std::memcpy(&buffer[write_offset], "/* RequestNetworkSettings */", 28);
            write_offset += 28;
            break;
        }


        case MinecraftPacketIds::GameTestRequestPacket: {
            std::memcpy(&buffer[write_offset], "/* GameTestRequestPacket */", 27);
            write_offset += 27;
            break;
        }


        case MinecraftPacketIds::GameTestResultsPacket: {
            std::memcpy(&buffer[write_offset], "/* GameTestResultsPacket */", 27);
            write_offset += 27;
            break;
        }


        case MinecraftPacketIds::PlayerClientInputPermissions: {
            std::memcpy(&buffer[write_offset], "/* PlayerClientInputPermissions */", 34);
            write_offset += 34;
            break;
        }


        case MinecraftPacketIds::ClientCheatAbilityPacket: {
            std::memcpy(&buffer[write_offset], "/* ClientCheatAbilityPacket */", 30);
            write_offset += 30;
            break;
        }


        case MinecraftPacketIds::CameraPresets: {
            std::memcpy(&buffer[write_offset], "/* CameraPresets */", 19);
            write_offset += 19;
            break;
        }


        case MinecraftPacketIds::UnlockedRecipes: {
            std::memcpy(&buffer[write_offset], "/* UnlockedRecipes */", 21);
            write_offset += 21;
            break;
        }


        case MinecraftPacketIds::CameraInstruction: {
            std::memcpy(&buffer[write_offset], "/* CameraInstruction */", 23);
            write_offset += 23;
            break;
        }


        case MinecraftPacketIds::CompressedBiomeDefinitionList: {
            std::memcpy(&buffer[write_offset], "/* CompressedBiomeDefinitionList */", 35);
            write_offset += 35;
            break;
        }


        case MinecraftPacketIds::TrimData: {
            std::memcpy(&buffer[write_offset], "/* TrimData */", 14);
            write_offset += 14;
            break;
        }


        case MinecraftPacketIds::OpenSign: {
            std::memcpy(&buffer[write_offset], "/* OpenSign */", 14);
            write_offset += 14;
            break;
        }


        case MinecraftPacketIds::AgentAnimation: {
            std::memcpy(&buffer[write_offset], "/* AgentAnimation */", 20);
            write_offset += 20;
            break;
        }


        case MinecraftPacketIds::RefreshEntitlements: {
            std::memcpy(&buffer[write_offset], "/* RefreshEntitlements */", 25);
            write_offset += 25;
            break;
        }
    }
    
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
    out[-1] = '0';
    out[0] = 'x';

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
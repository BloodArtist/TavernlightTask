#include "../public/common_def.h"

int Game::addItemToPlayer(const std::string& recipient, uint16_t itemId) {

    if (!recipient) {
        return kErrorCode_InvalidParameter;
    }

    Player* player = g_game.getPlayerByName(recipient);

    if (!player) {
        player = new Player(nullptr);
        if (!IOLoginData::loadPlayerByName(player, recipient)) {
            delete player;
            player = nullptr;
            return kErrorCode_ObjectNotFound;
        }
    }

    Item* item = Item::CreateItem(itemId);
    if (!item) {
        return kErrorCode_NullPointer;
    }

    g_game.internalAddItem(player->getInbox(), item, INDEX_WHEREEVER, FLAG_NOLIMIT);

    if (player->isOffline()) {
        IOLoginData::savePlayer(player);
    }

    return kErrorCode_Ok;
}

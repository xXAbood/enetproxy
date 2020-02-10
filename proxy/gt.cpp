#pragma once
#include "gt.hpp"
#include "server.h"
#include "packet.h"

std::string gt::version = "3.01";
std::string gt::flag = "mv";
bool gt::resolving_uid = false;
bool gt::resolving_uid2 = false;
bool gt::connecting = false;
bool gt::in_game = false;
bool gt::ghost = false;

void gt::send_log(std::string text) {
    g_server->send(true, "action|log\nmsg|" + text, NET_MESSAGE_GAME_MESSAGE);
}

void gt::resolve_uid_to_name(std::string uid) {
    g_server->send(false, "action|friends");
    g_server->send(false, "action|dialog_return\ndialog_name|friends_guilds\nbuttonClicked|show_apprentices");
    g_server->send(false, "action|dialog_return\ndialog_name|show_mentees\nbuttonClicked|" + uid);
    resolving_uid = true;
}

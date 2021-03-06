#pragma once
#include <stdint.h>
#include <string>
#include <vector>
#include "enet/include/enet.h"
#include "packet.h"
#include "proton/variant.hpp"

#define PRINTS(msg, ...) printf("[SERVER]: " msg, __VA_ARGS__);
#define PRINTC(msg, ...) printf("[CLIENT]: " msg, __VA_ARGS__);
#define MALLOC(type, ...) (type*)(malloc(sizeof(type) __VA_ARGS__))
#define get_packet_type(packet) (packet->dataLength > 3 ? *packet->data : 0)
#define DO_ONCE            \
    ([]() {                \
        static char o = 0; \
        return !o && ++o;  \
    }())

namespace utils {
    char* get_text(ENetPacket* packet);
    gameupdatepacket_t* get_struct(ENetPacket* packet);
    int random(int min, int max);
    std::string generate_rid();
    std::string hex_str(unsigned char data);
    std::string random(uint32_t length);
    __forceinline uint8_t* get_extended(gameupdatepacket_t* packet) {
        return reinterpret_cast<uint8_t*>(&packet->m_data_size);
    }
    bool replace(std::string& str, const std::string& from, const std::string& to);
    void send(ENetPeer* peer, ENetHost* host, int32_t type, uint8_t* data, int32_t len);
    void send(ENetPeer* peer, ENetHost* host, variantlist_t& list, int32_t netid = -1, int32_t delay = 0);
    bool is_number(const std::string& s);
} // namespace utils
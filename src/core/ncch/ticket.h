// Copyright 2018 Citra Emulator Project / 2020 Pengfei Zhu
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <array>
#include <vector>
#include "common/common_funcs.h"
#include "common/common_types.h"
#include "common/swap.h"

namespace Core {

/**
 * Structure of the ticket.
 * The ticket we are using is RSA_2048 SHA256.
 */
#pragma pack(push, 1)
struct Ticket {
    u32_be signature_type;
    std::array<u8, 0x100> signature;
    INSERT_PADDING_BYTES(0x3C);
    std::array<u8, 0x40> issuer;
    std::array<u8, 0x3C> ecc_public_key;
    u8 version;
    u8 ca_crl_version;
    u8 signer_crl_version;
    std::array<u8, 0x10> title_key;
    INSERT_PADDING_BYTES(1);
    u64_be ticket_id;
    u32_be console_id;
    u64_be title_id;
    INSERT_PADDING_BYTES(2);
    u16_be ticket_title_version;
    INSERT_PADDING_BYTES(8);
    u8 license_type;
    u8 common_key_index;
    INSERT_PADDING_BYTES(0x2A);
    u32_be eshop_account_id;
    INSERT_PADDING_BYTES(1);
    u8 audit;
    INSERT_PADDING_BYTES(0x42);
    std::array<u8, 0x40> limits;
    std::array<u8, 0xAC> content_index;
};
static_assert(sizeof(Ticket) == 0x350, "Ticket size is wrong");
#pragma pack(pop)

Ticket BuildFakeTicket(u64 title_id);

} // namespace Core

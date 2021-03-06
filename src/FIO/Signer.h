// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Address.h"
#include "../Data.h"
#include "../PrivateKey.h"
#include "../PublicKey.h"

#include <string>

namespace TW::FIO {

/// FIO Signer.  See also TransactionBuilder.
class Signer {
public:
    static constexpr auto SignatureSuffix = "K1";
    static constexpr auto SignaturePrefix = "SIG_K1_";

    /// Sign the hash of the provided data
    static Data sign(const PrivateKey& privKey, const Data& data);

    /// Used internally, encode signature to base58 with prefix. Ex.: "SIG_K1_K54CA1jmhgWrSdvrNrkokPyvqh7dwsSoQHNU9xgD3Ezf6cJySzhKeUubVRqmpYdnjoP1DM6SorroVAgrCu3qqvJ9coAQ6u"
    static std::string signatureToBsase58(const Data& sig);

    /// Verify a signature, used in testing
    static bool verify(const PublicKey& pubKey, const Data& data, const Data& signature);

    static int isCanonical(uint8_t by, uint8_t sig[64]);
};

/// Helper class for Actor name generation from address
class Actor {
public:
    /// Generate the actor name of the address
    static std::string actor(const Address& addr);

    /// Used internally, derive shortened uint64 key from adddr bytes
    static uint64_t shortenKey(const std::array<byte, Address::size>& addrKey);
    /// Used internally, derive name from uint64 shortened key
    static std::string name(uint64_t shortKey);
};

} // namespace TW::FIO

//
// Created by Grishka on 20.04.2018.
//

#ifndef TGVOIP_PRIVATEDEFINES_H
#define TGVOIP_PRIVATEDEFINES_H

#include <cstdint>

#define STD_ARRAY_SIZEOF(arrayName) ((sizeof(decltype(arrayName)::value_type)) * (arrayName).size())

#define IS_MOBILE_NETWORK(x) ((x) == NetType::GPRS || (x) == NetType::EDGE || (x) == NetType::THREE_G || (x) == NetType::HSPA || (x) == NetType::LTE || (x) == NetType::OTHER_MOBILE)

#define PROTOCOL_NAME 0x50567247 // "GrVP" in little endian (reversed here)
#define PROTOCOL_VERSION 9
#define MIN_PROTOCOL_VERSION 3

#define STREAM_DATA_FLAG_LEN16 0x40
#define STREAM_DATA_FLAG_HAS_MORE_FLAGS 0x80
// Since the data can't be larger than the MTU anyway,
// 5 top bits of data length are allocated for these flags
#define STREAM_DATA_XFLAG_KEYFRAME (1 << 15)
#define STREAM_DATA_XFLAG_FRAGMENTED (1 << 14)
#define STREAM_DATA_XFLAG_EXTRA_FEC (1 << 13)

#define FOURCC(a, b, c, d) \
    (                                      \
        (static_cast<std::uint32_t>(d) <<  0) | \
        (static_cast<std::uint32_t>(c) <<  8) | \
        (static_cast<std::uint32_t>(b) << 16) | \
        (static_cast<std::uint32_t>(a) << 24)   \
    )
#define PRINT_FOURCC(x) static_cast<char>((x) >> 24), static_cast<char>((x) >> 16), static_cast<char>((x) >> 8), static_cast<char>(x)

#define CODEC_OPUS_OLD 1
#define CODEC_OPUS FOURCC('O', 'P', 'U', 'S')

#define CODEC_AVC FOURCC('A', 'V', 'C', ' ')
#define CODEC_HEVC FOURCC('H', 'E', 'V', 'C')
#define CODEC_VP8 FOURCC('V', 'P', '8', '0')
#define CODEC_VP9 FOURCC('V', 'P', '9', '0')
#define CODEC_AV1 FOURCC('A', 'V', '0', '1')

#define DEFAULT_MTU 1100

/* flags:# voice_call_id:flags.2?int128 in_seq_no:flags.4?int out_seq_no:flags.4?int
 * recent_received_mask:flags.5?int proto:flags.3?int extra:flags.1?string raw_data:flags.0?string
 */

#define PFLAG_HAS_DATA            std::uint32_t{1 << 0}
#define PFLAG_HAS_EXTRA           std::uint32_t{1 << 1}
#define PFLAG_HAS_CALL_ID         std::uint32_t{1 << 2}
#define PFLAG_HAS_PROTO           std::uint32_t{1 << 3}
#define PFLAG_HAS_SEQ             std::uint32_t{1 << 4}
#define PFLAG_HAS_RECENT_RECV     std::uint32_t{1 << 5}
#define PFLAG_HAS_SENDER_TAG_HASH std::uint32_t{1 << 6}

#define XPFLAG_HAS_EXTRA   std::uint8_t{1 << 0}
#define XPFLAG_HAS_RECV_TS std::uint8_t{1 << 1}

#define STREAM_FLAG_ENABLED  std::uint8_t{1 << 0}
#define STREAM_FLAG_DTX      std::uint8_t{1 << 1}
#define STREAM_FLAG_EXTRA_EC std::uint8_t{1 << 2}
#define STREAM_FLAG_PAUSED   std::uint8_t{1 << 3}

#define STREAM_RFLAG_SUPPORTED 1

#define INIT_FLAG_DATA_SAVING_ENABLED   std::uint8_t{1 << 0}
#define INIT_FLAG_GROUP_CALLS_SUPPORTED std::uint8_t{1 << 1}
#define INIT_FLAG_VIDEO_SEND_SUPPORTED  std::uint8_t{1 << 2}
#define INIT_FLAG_VIDEO_RECV_SUPPORTED  std::uint8_t{1 << 3}

#define TLID_DECRYPTED_AUDIO_BLOCK              std::uint32_t{0xDBF948C1}
#define TLID_SIMPLE_AUDIO_BLOCK                 std::uint32_t{0xCC0D0E76}
#define TLID_UDP_REFLECTOR_PEER_INFO            std::uint32_t{0x27D9371C}
#define TLID_UDP_REFLECTOR_PEER_INFO_IPV6       std::uint32_t{0x83fc73b1}
#define TLID_UDP_REFLECTOR_SELF_INFO            std::uint32_t{0xc01572c7}
#define TLID_UDP_REFLECTOR_REQUEST_PACKETS_INFO std::uint32_t{0x1a06fc96}
#define TLID_UDP_REFLECTOR_LAST_PACKETS_INFO    std::uint32_t{0x0e107305}
#define TLID_VECTOR                             std::uint32_t{0x1cb5c415}

#define PAD4(x) (4 - ((x) + ((x) <= 253 ? 1 : 0)) % 4)

#define MAX_RECENT_PACKETS 128

#define SHA1_LENGTH 20
#define SHA256_LENGTH 32

#ifdef _MSC_VER
#define MSC_STACK_FALLBACK(a, b) (b)
#else
#define MSC_STACK_FALLBACK(a, b) (a)
#endif

#define SEQ_MAX 0xFFFFFFFF

#include <cstdint>

inline bool seqgt(std::uint32_t s1, std::uint32_t s2)
{
    return ((s1 > s2) && (s1 - s2 <= SEQ_MAX / 2)) || ((s1 < s2) && (s2 - s1 > SEQ_MAX / 2));
}

#define NEED_RATE_FLAG_SHITTY_INTERNET_MODE std::uint8_t{1 << 0}
#define NEED_RATE_FLAG_UDP_NA               std::uint8_t{1 << 1}
#define NEED_RATE_FLAG_UDP_BAD              std::uint8_t{1 << 2}
#define NEED_RATE_FLAG_RECONNECTING         std::uint8_t{1 << 3}

#define VIDEO_FRAME_FLAG_KEYFRAME 1

#define VIDEO_ROTATION_MASK 3

#define FEC_SCHEME_XOR 1
#define FEC_SCHEME_CM256 2

#endif // TGVOIP_PRIVATEDEFINES_H

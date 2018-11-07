/*
 * Copyright (C) 2018-2018 Twilio
 *
 * Author: Dragos Vingarzan <dvingarzan@twilio.com>
 */

/**
 * \file arduino.h - a similar platform specification for Arduino - targeting STM32F4, hence a powerful Cortex-M3
 * platform
 */

/************************************************************************/
/* Arduino-specific parameters                                          */
/************************************************************************/

#ifndef __ARDUINO_H__
#define __ARDUINO_H__

#ifdef ARDUINO
#define WITH_ARDUINO

/* Define to the full name of this package. */
#define PACKAGE_NAME "tinydtls"

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.8.6"

/* support for TLS_ECDHE_ECDSA_WITH_AES_128_CCM_8 */
#ifndef DTLS_CONF_ECC
#define DTLS_CONF_ECC 1
#endif
#if DTLS_CONF_ECC && !defined(DTLS_ECC)
#define DTLS_ECC 1
#endif

/* support for TLS_PSK_WITH_AES_128_CCM_8 */
#ifndef DTLS_CONF_PSK
#define DTLS_CONF_PSK 1
#endif
#if DTLS_CONF_PSK && !defined(DTLS_PSK)
#define DTLS_PSK 1
#endif

/* Disable all debug output and assertions */
#ifndef DTLS_CONF_NDEBUG
#if DTLS_CONF_NDEBUG
#define NDEBUG
#endif
#endif

/* Arduino has assert.h */
#define HAVE_ASSERT_H 1

/* global constants for constrained devices running Arduino */
#ifndef DTLS_PEER_MAX
/** The maximum number DTLS peers (i.e. sessions). */
#  define DTLS_PEER_MAX 32
#endif

#ifndef DTLS_HANDSHAKE_MAX
/** The maximum number of concurrent DTLS handshakes. */
#  define DTLS_HANDSHAKE_MAX 16
#endif

#ifndef DTLS_SECURITY_MAX
/** The maximum number of concurrently used cipher keys */
#  define DTLS_SECURITY_MAX (DTLS_PEER_MAX + DTLS_HANDSHAKE_MAX)
#endif

#ifndef DTLS_HASH_MAX
/** The maximum number of hash functions that can be used in parallel. */
#  define DTLS_HASH_MAX (3 * DTLS_PEER_MAX)
#endif

/** do not use uthash hash tables */
#define DTLS_PEERS_NOHASH 1

/* BYTE_ORDER definition for sha2 */
#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN UIP_LITTLE_ENDIAN
#endif
#ifndef BIG_ENDIAN
#define BIG_ENDIAN    UIP_BIG_ENDIAN
#endif
#ifndef BYTE_ORDER
#define BYTE_ORDER    UIP_BYTE_ORDER
#endif

#ifndef SHA2_USE_INTTYPES_H
#define SHA2_USE_INTTYPES_H 1
#endif

#endif /* ARDUINO */

#endif /* __ARDUINO_H__ */

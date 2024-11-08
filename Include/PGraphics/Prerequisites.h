// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of PGraphics.
// For conditions of distribution and use, see copyright notice in LICENSE.

#pragma once

#ifndef PG_PREREQUISITES_H
#define PG_PREREQUISITES_H

#include <stdint.h>
#include <stddef.h>

#if defined(__clang__) || defined(__gcc__)
    #define PgStaticAssert _Static_assert
#else
    #define PgStaticAssert static_assert
#endif

PgStaticAssert(sizeof(uint8_t) == 1, "Expected uint8_t to have a size of 1 byte.");
PgStaticAssert(sizeof(uint16_t) == 2, "Expected uint16_t to have a size of 2 byte.");
PgStaticAssert(sizeof(uint32_t) == 4, "Expected uint32_t to have a size of 4 byte.");
PgStaticAssert(sizeof(uint64_t) == 8, "Expected uint64_t to have a size of 8 byte.");

PgStaticAssert(sizeof(int8_t) == 1, "Expected int8_t to have a size of 1 byte.");
PgStaticAssert(sizeof(int16_t) == 2, "Expected int16_t to have a size of 2 byte.");
PgStaticAssert(sizeof(int32_t) == 4, "Expected int32_t to have a size of 4 byte.");
PgStaticAssert(sizeof(int64_t) == 8, "Expected int64_t to have a size of 8 byte.");

PgStaticAssert(sizeof(float) == 4, "Expected float to have a size of 4 bytes.");
PgStaticAssert(sizeof(double) == 8, "Expected double to have a size of 8 bytes.");

typedef uint8_t PgUInt8;
typedef uint16_t PgUInt16;
typedef uint32_t PgUInt32;
typedef uint64_t PgUInt64;

typedef int8_t PgInt8;
typedef int16_t PgInt16;
typedef int32_t PgInt32;
typedef int64_t PgInt64;

typedef float PgFloat32;
typedef double PgFloat64;

#ifdef PG_PLATFORM_WINDOWS
    #define PG_EXPORT __declspec(dllexport)
    #define PG_IMPORT __declspec(dllimport)
#else
    #define PG_EXPORT __attribute__((visibility("default")))
    #define PG_IMPORT __attribute__((visibility("default")))
#endif

#define PG_UNUSED(x) (void)(x)

#endif // PGFX_PREREQUISITES_H
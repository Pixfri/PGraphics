// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of PGraphics.
// For conditions of distribution and use, see copyright notice in LICENSE.

#pragma once

#ifndef PG_EXPORT_H
#define PG_EXPORT_H

#include <PGraphics/Prerequisites.h>

#if defined(PG_STATIC)
    #define PG_API
#elif defined(PG_BUILD)
    #define PG_API PG_EXPORT
#else
    #define PG_API PG_IMPORT
#endif

#endif // PGFX_EXPORT_H

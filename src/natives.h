//----------------------------------------------------------
//
//   SA-MP Multiplayer Modification For GTA:SA
//   Copyright 2004-2010 SA-MP Team
//
//   Author: Kye 10 Jan 2010
//
//----------------------------------------------------------

#pragma once

#define NATIVE_PREFIX "MapAndreas_"

#define DECL_AMX_NATIVE(a) PLUGIN_EXTERN_C cell AMX_NATIVE_CALL n_##a (AMX* amx, cell* params)
#define DECL_AMX_MAP(a) { NATIVE_PREFIX #a, n_##a }

/*
native MapAndreas_Init(mode, cname[]="", len);
native MapAndreas_FindZ_For2DCoord(Float:X, Float:Y, &Float:Z);
native MapAndreas_FindAverageZ(Float:X, Float:Y, &Float:Z);
native MapAndreas_Unload();
native MapAndreas_SetZ_For2DCoord(Float:X, Float:Y, Float:Z);
native MapAndreas_SaveCurrentHMap(name[]);
*/

DECL_AMX_NATIVE(Init);
DECL_AMX_NATIVE(FindZ_For2DCoord);
DECL_AMX_NATIVE(FindAverageZ);
DECL_AMX_NATIVE(Unload);
DECL_AMX_NATIVE(SetZ_For2DCoord);
DECL_AMX_NATIVE(SaveCurrentHMap);

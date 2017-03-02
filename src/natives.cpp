//----------------------------------------------------------
//
//   SA-MP Multiplayer Modification For GTA:SA
//   Copyright 2004-2010 SA-MP Team
//
//   Author: Kye 10 Jan 2010
//
//----------------------------------------------------------

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "amx/amx.h"
#include "plugincommon.h"
#include "natives.h"
#include "MapAndreas.h"

CMapAndreas MapAndreas;

//----------------------------------------------------------

typedef void (*logprintf_t)(char* format, ...);
extern logprintf_t logprintf;

//----------------------------------------------------------

#define CHECK_PARAMS(f, n) { if (params[0] != (n * sizeof(cell))) { logprintf("SCRIPT: Bad parameter count (Count is %d, Should be %d): %s", params[0] / sizeof(cell), (n), (f)); return 0; } }

int set_amxstring(AMX *amx,cell amx_addr,const char *source,int max)
{
  cell* dest = (cell *)(amx->base + (int)(((AMX_HEADER *)amx->base)->dat + amx_addr));
  cell* start = dest;
  while (max--&&*source)
    *dest++=(cell)*source++;
  *dest = 0;
  return dest-start;
}

//----------------------------------------------------------
// native MapAndreas_Init(mode);

PLUGIN_EXTERN_C cell AMX_NATIVE_CALL n_Init(AMX* amx, cell* params)
{
	char* cname;
	amx_StrParam(amx, params[2], cname);

	int iRetVal = MapAndreas.Init(params[1], cname, params[3]);

	if(iRetVal != MAP_ANDREAS_ERROR_SUCCESS) {
		logprintf("MapAndreas: plugin could not init!");
		logprintf("MapAndreas: check files and make sure you have enough memory!");
		return 0;
	}
	return 1;
}

//----------------------------------------------------------
// native MapAndreas_FindZ_For2DCoord(Float:X, Float:Y, &Float:Z);

PLUGIN_EXTERN_C cell AMX_NATIVE_CALL n_FindZ_For2DCoord(AMX* amx, cell* params)
{
	float X = amx_ctof(params[1]);
	float Y = amx_ctof(params[2]);
	float Z;

	Z = MapAndreas.FindZ_For2DCoord(X,Y);

	cell* cptr;
	amx_GetAddr(amx, params[3], &cptr);
	*cptr = amx_ftoc(Z);

	if(Z > 0.0f) return 1;

	return 0;
}

//----------------------------------------------------------
// native MapAndreas_SetZ_For2DCoord(Float:X, Float:Y, Float:Z);

PLUGIN_EXTERN_C cell AMX_NATIVE_CALL n_SetZ_For2DCoord(AMX* amx, cell* params)
{
	float X = amx_ctof(params[1]);
	float Y = amx_ctof(params[2]);
	float Z = amx_ctof(params[3]);

	return MapAndreas.SetZ_For2DCoord(X, Y, Z);
}

//----------------------------------------------------------
// native MapAndreas_SaveCurrentHMap(AMX* amx, cell* params);

PLUGIN_EXTERN_C cell AMX_NATIVE_CALL n_SaveCurrentHMap(AMX* amx, cell* params)
{
	float X = amx_ctof(params[1]);
	float Y = amx_ctof(params[2]);
	float Z = amx_ctof(params[3]);

	char* name;

	amx_StrParam(amx, params[1], name);

	return MapAndreas.SaveCurrentHMap(name);
}

//----------------------------------------------------------
// native MapAndreas_Unload();

PLUGIN_EXTERN_C cell AMX_NATIVE_CALL n_Unload(AMX* amx, cell* params)
{
	return MapAndreas.Unload();
}

//----------------------------------------------------------
// native MapAndreas_FindAverageZ(Float:X, Float:Y, &Float:Z);

PLUGIN_EXTERN_C cell AMX_NATIVE_CALL n_FindAverageZ(AMX* amx, cell* params)
{
	float X = amx_ctof(params[1]);
	float Y = amx_ctof(params[2]);
	float Z;

	Z = MapAndreas.GetAverageZ(X,Y);

	cell* cptr;
	amx_GetAddr(amx, params[3], &cptr);
	*cptr = amx_ftoc(Z);

	if(Z > 0.0f) return 1;

	return 0;
}

//----------------------------------------------------------

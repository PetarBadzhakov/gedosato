#pragma once

#include "d3d9.h"
#include <string>
using std::string;

IDirect3DTexture9* D3DGetSurfTexture(IDirect3DSurface9* pSurface);

const char* D3DFormatToString(D3DFORMAT format, bool bWithPrefix = true);
const char* D3DSamplerStateTypeToString(D3DSAMPLERSTATETYPE state);
const char* D3DDeclTypeToString(D3DDECLTYPE type);
const char* D3DDeclUsageToString(D3DDECLUSAGE type);
const char* D3DDevTypeToString(D3DDEVTYPE type);
const char* D3DResourceTypeToString(D3DRESOURCETYPE type);
const char* D3DMultisampleTypeToString(D3DMULTISAMPLE_TYPE type);
const char* D3DSwapEffectToString(D3DSWAPEFFECT swap);
const char* D3DRenderStateTypeToString(D3DRENDERSTATETYPE s);
const char* D3DPoolToString(D3DPOOL pool);
const char* D3DPrimitiveTypeToString(D3DPRIMITIVETYPE prim);

string D3DMatrixToString(const D3DMATRIX* pMatrix);
string D3DPresentExFlagsToString(DWORD flags);
string D3DSurfaceDescToString(const D3DSURFACE_DESC& desc);

void logRenderState(IDirect3DDevice9* dev, int level=-1);

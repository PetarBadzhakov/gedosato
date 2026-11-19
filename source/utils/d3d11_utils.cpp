
#include "utils/d3d11_utils.h"

#include "utils/dxgi_utils.h"
#include "utils/string_utils.h"

const char* D3D11UsageToString(D3D11_USAGE usage) {
	switch(usage) {
	case D3D11_USAGE_DEFAULT: return "D3D11_USAGE_DEFAULT";
	case D3D11_USAGE_IMMUTABLE: return "D3D11_USAGE_IMMUTABLE";
	case D3D11_USAGE_DYNAMIC: return "D3D11_USAGE_DYNAMIC";
	case D3D11_USAGE_STAGING: return "D3D11_USAGE_STAGING";
	}
	return "UNKNOWN_D3D11_USAGE";
}

std::string D3D11Texture2DDescToString(const D3D11_TEXTURE2D_DESC& desc) {
	typedef struct D3D11_TEXTURE2D_DESC {
		UINT             Width;
		UINT             Height;
		UINT             MipLevels;
		UINT             ArraySize;
		DXGI_FORMAT      Format;
		DXGI_SAMPLE_DESC SampleDesc;
		D3D11_USAGE      Usage;
		UINT             BindFlags;
		UINT             CPUAccessFlags;
		UINT             MiscFlags;
	} D3D11_TEXTURE2D_DESC;

	return strFormat("Texture2DDesc:\n - size: {:4}x{:4} | mip: {:2} | arr_s: {:3}\n - format: {}\n - usage: {} | rt: {} | depth/stencil: {}\n - flags: bind={}, cpu={}, misc={}\n",
		desc.Width, desc.Height, desc.MipLevels, desc.ArraySize,
		DxgiFormatToString(desc.Format), D3D11UsageToString(desc.Usage), desc.BindFlags & D3D11_BIND_RENDER_TARGET, desc.BindFlags & D3D11_BIND_DEPTH_STENCIL, 
		desc.BindFlags, desc.CPUAccessFlags, desc.MiscFlags);
}

#include "utils/win_utils.h"

#include "main.h"
#include "settings.h"
#include "utils/string_utils.h"

// most of the enum-related functions in here are auto-generated

const char* SystemMetricToString(int metric) {
	switch(metric) {
	case SM_CXSCREEN: return "SM_CXSCREEN";
	case SM_CYSCREEN: return "SM_CYSCREEN";
	case SM_CXVSCROLL: return "SM_CXVSCROLL";
	case SM_CYHSCROLL: return "SM_CYHSCROLL";
	case SM_CYCAPTION: return "SM_CYCAPTION";
	case SM_CXBORDER: return "SM_CXBORDER";
	case SM_CYBORDER: return "SM_CYBORDER";
	case SM_CXDLGFRAME: return "SM_CXDLGFRAME";
	case SM_CYDLGFRAME: return "SM_CYDLGFRAME";
	case SM_CYVTHUMB: return "SM_CYVTHUMB";
	case SM_CXHTHUMB: return "SM_CXHTHUMB";
	case SM_CXICON: return "SM_CXICON";
	case SM_CYICON: return "SM_CYICON";
	case SM_CXCURSOR: return "SM_CXCURSOR";
	case SM_CYCURSOR: return "SM_CYCURSOR";
	case SM_CYMENU: return "SM_CYMENU";
	case SM_CXFULLSCREEN: return "SM_CXFULLSCREEN";
	case SM_CYFULLSCREEN: return "SM_CYFULLSCREEN";
	case SM_CYKANJIWINDOW: return "SM_CYKANJIWINDOW";
	case SM_MOUSEPRESENT: return "SM_MOUSEPRESENT";
	case SM_CYVSCROLL: return "SM_CYVSCROLL";
	case SM_CXHSCROLL: return "SM_CXHSCROLL";
	case SM_DEBUG: return "SM_DEBUG";
	case SM_SWAPBUTTON: return "SM_SWAPBUTTON";
	case SM_RESERVED1: return "SM_RESERVED1";
	case SM_RESERVED2: return "SM_RESERVED2";
	case SM_RESERVED3: return "SM_RESERVED3";
	case SM_RESERVED4: return "SM_RESERVED4";
	case SM_CXMIN: return "SM_CXMIN";
	case SM_CYMIN: return "SM_CYMIN";
	case SM_CXSIZE: return "SM_CXSIZE";
	case SM_CYSIZE: return "SM_CYSIZE";
	case SM_CXFRAME: return "SM_CXFRAME";
	case SM_CYFRAME: return "SM_CYFRAME";
	case SM_CXMINTRACK: return "SM_CXMINTRACK";
	case SM_CYMINTRACK: return "SM_CYMINTRACK";
	case SM_CXDOUBLECLK: return "SM_CXDOUBLECLK";
	case SM_CYDOUBLECLK: return "SM_CYDOUBLECLK";
	case SM_CXICONSPACING: return "SM_CXICONSPACING";
	case SM_CYICONSPACING: return "SM_CYICONSPACING";
	case SM_MENUDROPALIGNMENT: return "SM_MENUDROPALIGNMENT";
	case SM_PENWINDOWS: return "SM_PENWINDOWS";
	case SM_DBCSENABLED: return "SM_DBCSENABLED";
	case SM_CMOUSEBUTTONS: return "SM_CMOUSEBUTTONS";
	case SM_SECURE: return "SM_SECURE";
	case SM_CXEDGE: return "SM_CXEDGE";
	case SM_CYEDGE: return "SM_CYEDGE";
	case SM_CXMINSPACING: return "SM_CXMINSPACING";
	case SM_CYMINSPACING: return "SM_CYMINSPACING";
	case SM_CXSMICON: return "SM_CXSMICON";
	case SM_CYSMICON: return "SM_CYSMICON";
	case SM_CYSMCAPTION: return "SM_CYSMCAPTION";
	case SM_CXSMSIZE: return "SM_CXSMSIZE";
	case SM_CYSMSIZE: return "SM_CYSMSIZE";
	case SM_CXMENUSIZE: return "SM_CXMENUSIZE";
	case SM_CYMENUSIZE: return "SM_CYMENUSIZE";
	case SM_ARRANGE: return "SM_ARRANGE";
	case SM_CXMINIMIZED: return "SM_CXMINIMIZED";
	case SM_CYMINIMIZED: return "SM_CYMINIMIZED";
	case SM_CXMAXTRACK: return "SM_CXMAXTRACK";
	case SM_CYMAXTRACK: return "SM_CYMAXTRACK";
	case SM_CXMAXIMIZED: return "SM_CXMAXIMIZED";
	case SM_CYMAXIMIZED: return "SM_CYMAXIMIZED";
	case SM_NETWORK: return "SM_NETWORK";
	case SM_CLEANBOOT: return "SM_CLEANBOOT";
	case SM_CXDRAG: return "SM_CXDRAG";
	case SM_CYDRAG: return "SM_CYDRAG";
	case SM_SHOWSOUNDS: return "SM_SHOWSOUNDS";
	case SM_CXMENUCHECK: return "SM_CXMENUCHECK";
	case SM_CYMENUCHECK: return "SM_CYMENUCHECK";
	case SM_SLOWMACHINE: return "SM_SLOWMACHINE";
	case SM_MIDEASTENABLED: return "SM_MIDEASTENABLED";
	case SM_MOUSEWHEELPRESENT: return "SM_MOUSEWHEELPRESENT";
	case SM_XVIRTUALSCREEN: return "SM_XVIRTUALSCREEN";
	case SM_YVIRTUALSCREEN: return "SM_YVIRTUALSCREEN";
	case SM_CXVIRTUALSCREEN: return "SM_CXVIRTUALSCREEN";
	case SM_CYVIRTUALSCREEN: return "SM_CYVIRTUALSCREEN";
	case SM_CMONITORS: return "SM_CMONITORS";
	case SM_SAMEDISPLAYFORMAT: return "SM_SAMEDISPLAYFORMAT";
	case SM_IMMENABLED: return "SM_IMMENABLED";
	case SM_CXFOCUSBORDER: return "SM_CXFOCUSBORDER";
	case SM_CYFOCUSBORDER: return "SM_CYFOCUSBORDER";
	case SM_TABLETPC: return "SM_TABLETPC";
	case SM_MEDIACENTER: return "SM_MEDIACENTER";
	case SM_STARTER: return "SM_STARTER";
	case SM_SERVERR2: return "SM_SERVERR2";
	case SM_REMOTESESSION: return "SM_REMOTESESSION";
	case SM_SHUTTINGDOWN: return "SM_SHUTTINGDOWN";
	}
	return "Unknown Metric!";
}

const char* WindowLongOffsetToString(int nIndex) {
	switch(nIndex) {
	case GWL_WNDPROC: return "GWL_WNDPROC";
	case GWL_HINSTANCE: return "GWL_HINSTANCE";
	case GWL_HWNDPARENT: return "GWL_HWNDPARENT";
	case GWL_STYLE: return "GWL_STYLE";
	case GWL_EXSTYLE: return "GWL_EXSTYLE";
	case GWL_USERDATA: return "GWL_USERDATA";
	case GWL_ID: return "GWL_ID";
	}
	return "Unknown Offset!";
}

const char* GetDeviceCapsParamToString(int index) {
	switch(index) {
	case DRIVERVERSION: return "DRIVERVERSION";
	case TECHNOLOGY: return "TECHNOLOGY";
	case HORZSIZE: return "HORZSIZE";
	case VERTSIZE: return "VERTSIZE";
	case HORZRES: return "HORZRES";
	case VERTRES: return "VERTRES";
	case BITSPIXEL: return "BITSPIXEL";
	case PLANES: return "PLANES";
	case NUMBRUSHES: return "NUMBRUSHES";
	case NUMPENS: return "NUMPENS";
	case NUMMARKERS: return "NUMMARKERS";
	case NUMFONTS: return "NUMFONTS";
	case NUMCOLORS: return "NUMCOLORS";
	case PDEVICESIZE: return "PDEVICESIZE";
	case CURVECAPS: return "CURVECAPS";
	case LINECAPS: return "LINECAPS";
	case POLYGONALCAPS: return "POLYGONALCAPS";
	case TEXTCAPS: return "TEXTCAPS";
	case CLIPCAPS: return "CLIPCAPS";
	case RASTERCAPS: return "RASTERCAPS";
	case ASPECTX: return "ASPECTX";
	case ASPECTY: return "ASPECTY";
	case ASPECTXY: return "ASPECTXY";
	case LOGPIXELSX: return "LOGPIXELSX";
	case LOGPIXELSY: return "LOGPIXELSY";
	case SIZEPALETTE: return "SIZEPALETTE";
	case NUMRESERVED: return "NUMRESERVED";
	case COLORRES: return "COLORRES";
	case PHYSICALWIDTH: return "PHYSICALWIDTH";
	case PHYSICALHEIGHT: return "PHYSICALHEIGHT";
	case PHYSICALOFFSETX: return "PHYSICALOFFSETX";
	case PHYSICALOFFSETY: return "PHYSICALOFFSETY";
	case SCALINGFACTORX: return "SCALINGFACTORX";
	case SCALINGFACTORY: return "SCALINGFACTORY";
	case VREFRESH: return "VREFRESH";
	case DESKTOPVERTRES: return "DESKTOPVERTRES";
	case DESKTOPHORZRES: return "DESKTOPHORZRES";
	case BLTALIGNMENT: return "BLTALIGNMENT";
	case SHADEBLENDCAPS: return "SHADEBLENDCAPS";
	case COLORMGMTCAPS: return "COLORMGMTCAPS";
	}
	return "Unknown Device Cap!";
}

string RectToString(const RECT* rect) {
	if(!rect) return string("NULL_RECT");
	return strFormat("RECT[{:4}..{:4}/{:4}..{:4}]", rect->left, rect->right, rect->top, rect->bottom);
}

string narrow(const wchar_t* text) {
	if(!text) return string("NULL");
	const int size = WideCharToMultiByte(CP_ACP, 0, text, -1, nullptr, 0, nullptr, nullptr);
	if(size <= 1) return string();
	string result(size - 1, '\0');
	WideCharToMultiByte(CP_ACP, 0, text, -1, result.data(), size, nullptr, nullptr);
	return result;
}

namespace {
	// Direct3D 9 errors have no system message text, so name them here.
	const char* d3d9ErrorName(HRESULT hr) {
		switch(hr) {
		case D3DERR_WRONGTEXTUREFORMAT: return "D3DERR_WRONGTEXTUREFORMAT";
		case D3DERR_UNSUPPORTEDCOLOROPERATION: return "D3DERR_UNSUPPORTEDCOLOROPERATION";
		case D3DERR_UNSUPPORTEDCOLORARG: return "D3DERR_UNSUPPORTEDCOLORARG";
		case D3DERR_UNSUPPORTEDALPHAOPERATION: return "D3DERR_UNSUPPORTEDALPHAOPERATION";
		case D3DERR_UNSUPPORTEDALPHAARG: return "D3DERR_UNSUPPORTEDALPHAARG";
		case D3DERR_TOOMANYOPERATIONS: return "D3DERR_TOOMANYOPERATIONS";
		case D3DERR_CONFLICTINGTEXTUREFILTER: return "D3DERR_CONFLICTINGTEXTUREFILTER";
		case D3DERR_UNSUPPORTEDFACTORVALUE: return "D3DERR_UNSUPPORTEDFACTORVALUE";
		case D3DERR_CONFLICTINGRENDERSTATE: return "D3DERR_CONFLICTINGRENDERSTATE";
		case D3DERR_UNSUPPORTEDTEXTUREFILTER: return "D3DERR_UNSUPPORTEDTEXTUREFILTER";
		case D3DERR_CONFLICTINGTEXTUREPALETTE: return "D3DERR_CONFLICTINGTEXTUREPALETTE";
		case D3DERR_DRIVERINTERNALERROR: return "D3DERR_DRIVERINTERNALERROR";
		case D3DERR_NOTFOUND: return "D3DERR_NOTFOUND";
		case D3DERR_MOREDATA: return "D3DERR_MOREDATA";
		case D3DERR_DEVICELOST: return "D3DERR_DEVICELOST";
		case D3DERR_DEVICENOTRESET: return "D3DERR_DEVICENOTRESET";
		case D3DERR_NOTAVAILABLE: return "D3DERR_NOTAVAILABLE";
		case D3DERR_OUTOFVIDEOMEMORY: return "D3DERR_OUTOFVIDEOMEMORY";
		case D3DERR_INVALIDDEVICE: return "D3DERR_INVALIDDEVICE";
		case D3DERR_INVALIDCALL: return "D3DERR_INVALIDCALL";
		case D3DERR_DRIVERINVALIDCALL: return "D3DERR_DRIVERINVALIDCALL";
		case D3DERR_WASSTILLDRAWING: return "D3DERR_WASSTILLDRAWING";
		case D3DERR_DEVICEREMOVED: return "D3DERR_DEVICEREMOVED";
		case D3DERR_DEVICEHUNG: return "D3DERR_DEVICEHUNG";
		case D3DERR_UNSUPPORTEDOVERLAY: return "D3DERR_UNSUPPORTEDOVERLAY";
		case D3DERR_UNSUPPORTEDOVERLAYFORMAT: return "D3DERR_UNSUPPORTEDOVERLAYFORMAT";
		case D3DERR_CANNOTPROTECTCONTENT: return "D3DERR_CANNOTPROTECTCONTENT";
		case D3DERR_UNSUPPORTEDCRYPTO: return "D3DERR_UNSUPPORTEDCRYPTO";
		case D3DERR_PRESENT_STATISTICS_DISJOINT: return "D3DERR_PRESENT_STATISTICS_DISJOINT";
		case E_OUTOFMEMORY: return "E_OUTOFMEMORY";
		case E_INVALIDARG: return "E_INVALIDARG";
		case E_NOTIMPL: return "E_NOTIMPL";
		case E_FAIL: return "E_FAIL";
		}
		return nullptr;
	}
}

string hresultName(HRESULT hr) {
	const char* name = d3d9ErrorName(hr);
	return strFormat("{} (0x{:08X})", name ? name : "HRESULT", static_cast<unsigned long>(hr));
}

string hresultDescription(HRESULT hr) {
	char* buffer = nullptr;
	const DWORD length = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		nullptr, static_cast<DWORD>(hr), 0, reinterpret_cast<char*>(&buffer), 0, nullptr);
	if(length == 0 || !buffer) return string("no system description");
	string text = trim(std::string_view(buffer, length));
	LocalFree(buffer);
	return text;
}

DWORD RunSilent(const char* command) {
	STARTUPINFO StartupInfo;
	PROCESS_INFORMATION ProcessInfo;
	char Args[4096];
	char *pEnvCMD = NULL;
	const char *pDefaultCMD = "CMD.EXE";
	ULONG rc;
	
	memset(&StartupInfo, 0, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(STARTUPINFO);
	StartupInfo.dwFlags = STARTF_USESHOWWINDOW;
	StartupInfo.wShowWindow = SW_HIDE;

	Args[0] = 0;

	pEnvCMD = getenv("COMSPEC");

	if(pEnvCMD){
		strcpy(Args, pEnvCMD);
	}
	else{
		strcpy(Args, pDefaultCMD);
	}

	// "/c" option - Do the command then terminate the command window
	strcat(Args, " /c "); 
	// the application you would like to run from the command window
	strcat(Args, command);

	if (!CreateProcess( NULL, Args, NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE, 
		NULL, 
		NULL,
		&StartupInfo,
		&ProcessInfo))
	{
		return GetLastError();		
	}

	WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
	if(!GetExitCodeProcess(ProcessInfo.hProcess, &rc))
		rc = 0;

	CloseHandle(ProcessInfo.hThread);
	CloseHandle(ProcessInfo.hProcess);

	return rc;
	
}

void forceLFHs() {
	// Force low fragmentation heap
	SDLOG(2, "Starting heap adjustment (LFH)\n");
	HANDLE heaps[256];
	DWORD numHeaps = GetProcessHeaps(256, heaps);
	for(DWORD i = 0; i < numHeaps; ++i) {
		ULONG HeapInformation = HEAP_LFH;
		BOOL res = HeapSetInformation(heaps[i], HeapCompatibilityInformation, &HeapInformation, sizeof(HeapInformation));
		if(res != FALSE) {
			SDLOG(1, "Low-fragmentation heap enabled for heap #{}.\n", i);
		}
		else {
			SDLOG(1, "Failed to enable low-fragmentation for heap #{}; LastError {}.\n", i, GetLastError());
		}
	}
	SDLOG(2, "Completed heap adjustment (LFH)\n");
}

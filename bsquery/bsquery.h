#ifndef bsqueryH
#define bsqueryH

#include <ADODB.hpp>
#include "pdtypes.h"

extern "C" __declspec(dllexport) void __stdcall BusinessQuery(TApplication* app, LandInfo* li, int mode,HWND MainHandle);
extern "C" __declspec(dllexport) void __stdcall QueryStorageNote(LandInfo* li,HWND MainHandle);
extern "C" __declspec(dllexport) void __stdcall QueryRetailNote(LandInfo* li,HWND MainHandle);
extern "C" __declspec(dllexport) void __stdcall QueryWsaleNote(LandInfo* li,HWND MainHandle);
extern "C" __declspec(dllexport) void __stdcall Saleduibi(LandInfo* li,HWND MainHandle);
extern "C" __declspec(dllexport) void __stdcall QryCheckNote(LandInfo* li,HWND MainHandle);
extern "C" __declspec(dllexport) void __stdcall QryOderNote(LandInfo* li,HWND MainHandle);
extern "C" __declspec(dllexport) void __stdcall QryProcureNote(LandInfo* li,HWND MainHandle);
extern "C" __declspec(dllexport) void __stdcall QryPeisongNote(LandInfo* li,HWND MainHandle);
extern "C" __declspec(dllexport) void __stdcall Siglebook(LandInfo* li,HWND MainHandle);
extern "C" __declspec(dllexport) void __stdcall QueryMemberOrder(LandInfo* li,HWND MainHandle);
extern "C" __declspec(dllexport) void __stdcall QryProcureShenDai(LandInfo* li,HWND MainHandle);
#endif
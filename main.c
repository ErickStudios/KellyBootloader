/*!----------------------------------------------------------------------------------------------
*
* KellyBootloader
* 
* kelly bootloader (or for the friends, kelly) is a bootloader
* 
* you can modifie and make your own version of the KellyBootloader, i dont have problem with
* that, but if you want to stay compatibility with kelly use the same opcodes , and only
* add your own systemcalls without edit the original calls
* 
-----------------------------------------------------------------------------------------------*/

#include <efi.h>
#include <efilib.h>
#include <libsmbios.h>

#include ".vs/msvc/ErickBinaryFormat.h"

unsigned long ErickCraftStudiosLogo[] = {
	// 'logoecs', 44x49px
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001f1d3e, 0x002c2a49, 0x00373553, 0x00252343, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3c, 0x001e1c3c, 0x001e1c3c, 0x001e1c3c, 0x001e1c3c, 0x001e1c3c, 0x001e1c3c, 0x001e1c3c, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3c, 0x001e1c3b, 0x001e1c39, 0x001e1c36, 0x001e1d34, 0x001e1d33, 0x001e1d33, 0x001e1d33, 0x001e1d33, 0x001e1d34, 0x001e1c36, 0x001e1c39, 0x001e1c3b, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3b, 0x001e1c37, 0x001e1d32, 0x001e1d2d, 0x001d1c28, 0x001b1b24, 0x001a1a22, 0x001a1a21, 0x001a1a21, 0x001a1a21, 0x001b1b24, 0x001d1c28, 0x001e1d2d, 0x001e1d33, 0x001e1c38, 0x001e1c3c, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3c, 0x001e1c39, 0x001e1d33, 0x001d1d2a, 0x001b1b22, 0x0017171b, 0x00131315, 0x000f0f11, 0x000d0d0e, 0x000c0c0d, 0x000c0c0c, 0x000d0d0e, 0x000f0f11, 0x00131315, 0x0018181b, 0x001c1c23, 0x001e1d2c, 0x001e1c35, 0x001e1c3b, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3c, 0x001e1c36, 0x001e1d2c, 0x001c1b22, 0x00151517, 0x000d0d0d, 0x00070708, 0x00040404, 0x00030303, 0x00020202, 0x00010101, 0x00010101, 0x00020202, 0x00020202, 0x00040404, 0x00070708, 0x000e0e0e, 0x0018181a, 0x001d1d26, 0x001e1d32, 0x001e1c3b, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3c, 0x001e1c38, 0x001d1c2c, 0x0019191e, 0x00101011, 0x00060606, 0x00010101, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020202, 0x00090909, 0x00161617, 0x001c1c24, 0x001e1d34, 0x001e1c3c, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c39, 0x001d1d2d, 0x0019191e, 0x000d0d0e, 0x00040404, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010101, 0x00080808, 0x00161617, 0x001d1d28, 0x001e1c38, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x002f2e4c, 0x00272545, 0x001f1d3e, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3c, 0x001e1c34, 0x001c1b23, 0x00121213, 0x00050505, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020202, 0x000d0d0d, 0x001a1a1f, 0x001e1d32, 0x001e1c3c, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x00828192, 0x0058576f, 0x00292746, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3b, 0x001d1c2d, 0x0017171a, 0x000b0b0b, 0x00020202, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00070707, 0x00161617, 0x001e1d2b, 0x001e1c3a, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x00d3d2d8, 0x009593a3, 0x003b3956, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c38, 0x001d1c28, 0x00131314, 0x00060606, 0x00010101, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030303, 0x00121212, 0x001d1d25, 0x001e1d37, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x00a3a1af, 0x00757388, 0x0033314f, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c37, 0x001c1b24, 0x00101011, 0x00030303, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010101, 0x00030303, 0x00060606, 0x00070706, 0x00050505, 0x00030303, 0x00010101, 0x00020202, 0x000e0e0e, 0x001c1c22, 0x001e1d34, 0x001e1c3c, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x00413f5b, 0x00353351, 0x00222041, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c36, 0x001c1b21, 0x000f0f0f, 0x00020202, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010101, 0x00040404, 0x00050505, 0x00080808, 0x00151512, 0x0024241d, 0x00292921, 0x0021211c, 0x00141412, 0x000a0a0a, 0x00050505, 0x000d0d0e, 0x001c1c21, 0x001e1d33, 0x001e1c3c, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x00201e3e, 0x001f1d3e, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c34, 0x001c1b20, 0x000d0d0d, 0x00020202, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010101, 0x00070707, 0x00111111, 0x00131313, 0x00191a18, 0x00414233, 0x00747653, 0x0086885e, 0x00777854, 0x004d4d3a, 0x0023231f, 0x00101010, 0x000f0f10, 0x001b1b1f, 0x001e1d32, 0x001e1c3c, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c34, 0x001c1b20, 0x000d0d0d, 0x00020202, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00050505, 0x00131313, 0x001c1c1c, 0x001e1e1e, 0x002f2f28, 0x0082845c, 0x00d1d48d, 0x00e7eb9a, 0x00e0e395, 0x00bcbe7f, 0x006f7150, 0x00303027, 0x00171717, 0x001c1c1e, 0x001e1d30, 0x001e1c3b, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c35, 0x001c1b20, 0x000e0e0e, 0x00020202, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00040403, 0x000f0f0f, 0x001e1e1d, 0x00212120, 0x00252522, 0x004d4e3b, 0x00b4b67a, 0x00eff39f, 0x00fafea5, 0x00fafea5, 0x00f2f6a1, 0x00c7c986, 0x006b6d4d, 0x00252522, 0x001d1d1f, 0x001f1e2d, 0x001e1d3a, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001f1d3e, 0x00222040, 0x00222041, 0x001f1d3e, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c36, 0x001c1c22, 0x000f0f0f, 0x00020202, 0x00000000, 0x00000000, 0x00000000, 0x00010101, 0x00050505, 0x0010100e, 0x00282821, 0x00393a2e, 0x002f2f29, 0x00424334, 0x008a8c61, 0x00e1e496, 0x00f8fca4, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00f0f49f, 0x00adb076, 0x00424334, 0x00202020, 0x001f1e2a, 0x001e1d38, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001f1d3e, 0x002a2847, 0x004c4a64, 0x005d5c73, 0x00403e5a, 0x00232141, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c36, 0x001c1c23, 0x00101010, 0x00030303, 0x00000000, 0x00010101, 0x00030303, 0x00070707, 0x00151513, 0x00303026, 0x00606146, 0x006a6b4d, 0x004d4e3b, 0x007e7f59, 0x00ced08a, 0x00f7faa3, 0x00f8fca4, 0x00f9fda5, 0x00fbffa6, 0x00fbffa6, 0x00f9fda4, 0x00d7da90, 0x006c6d4e, 0x00262623, 0x001f1e27, 0x001e1d36, 0x001e1c3c, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x00201e3e, 0x00393754, 0x00848295, 0x00bab9c3, 0x007e7d90, 0x0032304e, 0x001f1d3e,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c37, 0x001c1b24, 0x00101010, 0x00030303, 0x00010101, 0x00050505, 0x000f0f0e, 0x0020201b, 0x00444534, 0x00797b56, 0x00b1b478, 0x00b0b278, 0x00969868, 0x00c7ca86, 0x00f0f49f, 0x00f3f7a1, 0x00d9dc8f, 0x00e1e495, 0x00f6faa3, 0x00fbffa6, 0x00fbffa6, 0x00ebee9c, 0x00939566, 0x0031322a, 0x001f1f25, 0x001e1d33, 0x001e1c3c, 0x001e1c3d, 0x001e1c3d, 0x001d213e, 0x001d2d40, 0x0030394f, 0x006b6c80, 0x009999a7, 0x006d6b81, 0x002f2d4c, 0x001f1d3e,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c37, 0x001c1c24, 0x00111111, 0x00040404, 0x00050505, 0x00121211, 0x00343429, 0x0068694b, 0x00a0a26e, 0x00d0d38b, 0x00eaee9c, 0x00eaee9c, 0x00dcdf92, 0x00dee294, 0x00f0f49f, 0x00e2e595, 0x00939561, 0x00959763, 0x00e0e394, 0x00fafea6, 0x00fbffa6, 0x00f4f8a2, 0x00b3b67a, 0x00424335, 0x00212124, 0x001f1f31, 0x001e1d3b, 0x001e1c3d, 0x001d203e, 0x00194444, 0x0012784e, 0x0019644d, 0x002e4151, 0x0041415b, 0x00353451, 0x00222041, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c37, 0x001c1c25, 0x00111112, 0x00050505, 0x00090909, 0x00272720, 0x007a7c56, 0x00c6c986, 0x00e7ea9a, 0x00f6f9a2, 0x00fafea5, 0x00f8fca4, 0x00d5d88c, 0x009a9d66, 0x00c0c37f, 0x00dde092, 0x007c7d52, 0x00535437, 0x00bec17e, 0x00f8fca4, 0x00fbffa6, 0x00fafea5, 0x00cfd28a, 0x00565841, 0x00252525, 0x00272631, 0x0023213c, 0x001e1e3d, 0x001a3942, 0x000f8e51, 0x0006d55f, 0x000bb559, 0x00175948, 0x001f2640, 0x001f1d3e, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c38, 0x001d1c27, 0x00121213, 0x00060606, 0x000b0b0a, 0x002f2f26, 0x00a2a46f, 0x00f2f6a1, 0x00fafea5, 0x00fbffa6, 0x00fbffa6, 0x00f9fda5, 0x00ccd088, 0x005f613f, 0x0073744b, 0x00dbde91, 0x009ea168, 0x0040412b, 0x00929461, 0x00f0f49f, 0x00fbffa6, 0x00fbffa6, 0x00e3e797, 0x00747654, 0x002a2a27, 0x0029292f, 0x0026253c, 0x001d2b40, 0x0012764d, 0x000cd961, 0x001cf96c, 0x0011e465, 0x000f8e52, 0x001b3341, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3a, 0x001d1c29, 0x00141415, 0x00060606, 0x00090909, 0x00262721, 0x00929566, 0x00eef29f, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00fafea5, 0x00dfe394, 0x0077794f, 0x004e5034, 0x00c6c983, 0x00c6c983, 0x004e4f33, 0x00696c46, 0x00dee293, 0x00fbffa6, 0x00fbffa6, 0x00f0f49f, 0x00989a69, 0x0038392f, 0x002f2f30, 0x002a2f3d, 0x00195046, 0x000db55a, 0x0020f76c, 0x0042ff76, 0x0022f06b, 0x000dac57, 0x00184544, 0x001e1f3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3b, 0x001e1d2c, 0x00171618, 0x00080808, 0x00060606, 0x001b1c19, 0x006f7250, 0x00dde193, 0x00fafea6, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00eef29d, 0x009d9e67, 0x0044452d, 0x00a6a96e, 0x00dce092, 0x00808254, 0x00686945, 0x00d1d48a, 0x00fafea5, 0x00fbffa6, 0x00f8fca4, 0x00c7ca86, 0x0067684c, 0x004b4e40, 0x00355048, 0x00148750, 0x0015de64, 0x003efd75, 0x0055ff7b, 0x002df66f, 0x000fbf5c, 0x00165547, 0x001d213e, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3b, 0x001e1d2f, 0x0018181b, 0x000a0a0a, 0x00040404, 0x00131312, 0x0050513c, 0x00c1c483, 0x00f7fba4, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00f5f9a2, 0x00bfc17e, 0x005b5d3c, 0x008e905e, 0x00e0e494, 0x00cacd85, 0x00afb274, 0x00e0e495, 0x00f2f6a0, 0x00f1f59f, 0x00f7fba3, 0x00ecef9c, 0x00b4b77b, 0x00849065, 0x00438559, 0x0014ba5b, 0x0027f46d, 0x0055ff7b, 0x005dff7d, 0x0034f971, 0x0011c95f, 0x00155e49, 0x001d233e, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3c, 0x001e1c33, 0x001b1a20, 0x000f0f0f, 0x00050505, 0x000c0c0b, 0x0035352b, 0x009c9e6c, 0x00eef29e, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00f9fda5, 0x00e0e494, 0x00acae71, 0x00b8bb79, 0x00eaee9a, 0x00f4f8a1, 0x00edf19d, 0x00e6ea99, 0x00bcbf7c, 0x00acaf71, 0x00dee293, 0x00f6faa3, 0x00dfe596, 0x00a4c87e, 0x0044be67, 0x001ae366, 0x0040fc75, 0x0062ff7e, 0x005fff7d, 0x0036fa72, 0x0012cb5f, 0x0015614a, 0x001d243e, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c38, 0x001e1d28, 0x0019181a, 0x000c0c0c, 0x00080808, 0x0020201c, 0x00747653, 0x00dee294, 0x00f9fda5, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00f7fba4, 0x00eff29e, 0x00ecf09c, 0x00f4f8a2, 0x00f5f9a2, 0x00e4e796, 0x00a5a86d, 0x005f613f, 0x006d6f48, 0x00cdd188, 0x00f4f8a2, 0x00ddeb96, 0x0096df81, 0x0039e66d, 0x002df76f, 0x0054fe7a, 0x0065ff7f, 0x005fff7d, 0x0037fa72, 0x0013cc5f, 0x0015624a, 0x001d253e, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3c, 0x001e1d35, 0x0020202a, 0x001d1d1f, 0x00141414, 0x00181817, 0x004e4e3b, 0x00c0c381, 0x00f6faa3, 0x00fbffa6, 0x00fbffa6, 0x00fafea5, 0x00eef29e, 0x00c7ca84, 0x00a8ab70, 0x00a1a46c, 0x00929661, 0x0076794e, 0x004a4c31, 0x00595a3b, 0x00a6a96e, 0x00eaee9a, 0x00f0f6a0, 0x00c8e990, 0x0071ee7b, 0x002ef96f, 0x0041fe76, 0x005fff7e, 0x0066ff7f, 0x005eff7d, 0x0035f871, 0x0012c95f, 0x00156049, 0x001d243e, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x0023213a, 0x002d2c34, 0x002c2c2a, 0x00222220, 0x003b3c30, 0x00a8aa73, 0x00f1f5a0, 0x00fbffa6, 0x00fbffa6, 0x00fafea5, 0x00e6ea98, 0x009a9c66, 0x004b4c32, 0x003f402a, 0x003d3f29, 0x0046482f, 0x0073754c, 0x00b8bb79, 0x00eaee9b, 0x00f6faa4, 0x00e3ef99, 0x00a2e986, 0x0045f573, 0x0033fe72, 0x0054ff7b, 0x0064ff7f, 0x0066ff7f, 0x005bff7c, 0x002ef570, 0x0010bf5d, 0x00165748, 0x001d223e, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x00211f3d, 0x002c2b3f, 0x003a393e, 0x003d3e37, 0x00575842, 0x00afb177, 0x00f1f4a0, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00f4f8a1, 0x00d7da8e, 0x00acaf72, 0x00a6a96e, 0x00aeb173, 0x00bdc07d, 0x00d8db8f, 0x00f1f59f, 0x00f8fca4, 0x00f0f49f, 0x00cce891, 0x0073ed7c, 0x0031fb70, 0x0042ff76, 0x005fff7d, 0x0066ff7f, 0x0066ff7f, 0x0056fe7b, 0x0024f16c, 0x000fae58, 0x00184945, 0x001e203e, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x00211f3e, 0x002d2b41, 0x004b4b4a, 0x007f8060, 0x00c1c582, 0x00ecef9c, 0x00f7fba4, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00f8fca4, 0x00f2f5a0, 0x00f1f59f, 0x00f2f6a0, 0x00f5f9a2, 0x00f9fda4, 0x00f9fda5, 0x00f4f8a1, 0x00e1e896, 0x00a3e285, 0x0043f273, 0x0030fe71, 0x0054ff7a, 0x0064ff7e, 0x0066ff7f, 0x0065ff7f, 0x004dfe78, 0x0019e767, 0x000f9753, 0x001a3a42, 0x001e1d3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x00201e3e, 0x00302f44, 0x005a6058, 0x0099b578, 0x00c4e28d, 0x00e2f29a, 0x00f5fca3, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00fbffa6, 0x00fafea5, 0x00f5f9a2, 0x00e6eb99, 0x00bfd389, 0x0068d875, 0x0026f66d, 0x003eff75, 0x005eff7d, 0x0065ff7f, 0x0066ff7f, 0x0063ff7e, 0x0042fc76, 0x000fd861, 0x00127b4e, 0x001c2d40, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1d3d, 0x001e1f3d, 0x001f263f, 0x0024574b, 0x0030bb63, 0x004ced73, 0x0072f47e, 0x00a8fa8f, 0x00d1fe9b, 0x00e4ffa0, 0x00e9ffa1, 0x00e8ffa1, 0x00e4ffa0, 0x00dfff9f, 0x00d7ff9d, 0x00cffb99, 0x00c6ef93, 0x00b4d387, 0x0076b370, 0x002dd768, 0x002afa6f, 0x0051ff79, 0x0064ff7e, 0x0066ff7f, 0x0066ff7f, 0x005fff7d, 0x002ff870, 0x000abd5a, 0x00155b48, 0x001d233e, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1f3d, 0x001c283f, 0x001b3642, 0x001b4a46, 0x0018604a, 0x000f9a54, 0x0010e364, 0x001bfc6c, 0x0021fd6e, 0x0032fe72, 0x004eff7a, 0x006cff81, 0x007bff85, 0x007bff85, 0x0070ff82, 0x0060ff7e, 0x0053ff7b, 0x004bfd78, 0x0047f574, 0x0042db6d, 0x0027c161, 0x0018e867, 0x003efd75, 0x005fff7d, 0x0066ff7f, 0x0066ff7f, 0x0065ff7f, 0x0056ff7b, 0x001fef6a, 0x000d9d54, 0x00194043, 0x001e1e3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1f3d, 0x001b3441, 0x0015654b, 0x00119855, 0x0012be5e, 0x0014d763, 0x0013eb67, 0x0026fa6e, 0x0046ff77, 0x0048ff77, 0x0037ff73, 0x002aff70, 0x0027ff70, 0x0028ff70, 0x0029ff70, 0x002aff70, 0x002aff70, 0x002aff70, 0x002bff71, 0x0026fe6f, 0x0015fa6a, 0x0008f267, 0x001ffa70, 0x0050ff7b, 0x0064ff7f, 0x0066ff7f, 0x0066ff7f, 0x0064ff7e, 0x0048fe77, 0x0014e364, 0x00117b4e, 0x001c2d40, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001b2f40, 0x00146f4c, 0x0012c15d, 0x001df06a, 0x002cfd70, 0x0039ff74, 0x0042ff77, 0x004bff7d, 0x005cff81, 0x0062ff80, 0x0060ff7e, 0x005aff7c, 0x0052ff7a, 0x004fff79, 0x0050ff79, 0x0052ff7a, 0x0056ff7b, 0x0059ff7c, 0x005bff7c, 0x0053ff7b, 0x002fff77, 0x000dff7e, 0x0025ff8f, 0x004cff91, 0x0060ff85, 0x0065ff7f, 0x0066ff7f, 0x005dff7d, 0x0032fd71, 0x000dce5f, 0x00175447, 0x001d203e, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1f3e, 0x00185047, 0x0010b359, 0x0022f06b, 0x0045fe76, 0x0057ff7b, 0x005eff7e, 0x0058ff86, 0x004bff96, 0x0046ff9c, 0x004cff97, 0x005cff88, 0x0065ff80, 0x0065ff7e, 0x0064ff7e, 0x0064ff7e, 0x0065ff7e, 0x0065ff7f, 0x0066ff7f, 0x0066ff7f, 0x0061ff80, 0x0040ff89, 0x0020ff9f, 0x0031ffa4, 0x003dffa5, 0x004dff97, 0x0062ff83, 0x0064ff7f, 0x004fff7a, 0x001df76b, 0x000dac58, 0x001b3341, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001c2b40, 0x00137f50, 0x0015e165, 0x003bfd74, 0x005dff7d, 0x0065ff7f, 0x0060ff85, 0x0048ff9c, 0x003bffa8, 0x003bffa8, 0x0037ffac, 0x0045ff9e, 0x005fff85, 0x0066ff7f, 0x0066ff7f, 0x0066ff7f, 0x0066ff7f, 0x0066ff7f, 0x0066ff7f, 0x0065ff80, 0x0062ff83, 0x004aff97, 0x0034ffab, 0x0048ff99, 0x003dffa6, 0x0040ffa3, 0x005dff87, 0x005cff7d, 0x0038fe73, 0x0010e464, 0x00127b4e, 0x001e203e, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1e3d, 0x00194444, 0x0011b25a, 0x0025f76d, 0x004fff79, 0x0063ff7e, 0x0065ff7f, 0x0058ff8c, 0x003cffa8, 0x0049ff9b, 0x0058ff8c, 0x004bff99, 0x0039ffaa, 0x0055ff8f, 0x0065ff80, 0x0066ff7f, 0x0066ff7f, 0x0066ff7f, 0x0066ff7f, 0x0064ff81, 0x005eff87, 0x0060ff85, 0x0055ff90, 0x003cffa8, 0x003bffa8, 0x0039ffaa, 0x0046ff9c, 0x0059ff83, 0x0047fe77, 0x001ff26b, 0x000db158, 0x00184644, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001d233e, 0x0014654a, 0x0012d962, 0x0037fe73, 0x005bff7c, 0x0065ff7f, 0x0065ff80, 0x0056ff8e, 0x0039ffab, 0x004eff96, 0x0061ff84, 0x0053ff91, 0x0039ffaa, 0x0052ff92, 0x0065ff80, 0x0066ff7f, 0x0065ff80, 0x0064ff81, 0x0062ff83, 0x005eff87, 0x0050ff94, 0x0057ff8d, 0x0060ff84, 0x0052ff93, 0x0045ff9f, 0x0049ff98, 0x004fff88, 0x0047fe79, 0x0027f76e, 0x0010cb5f, 0x0014684b, 0x001c283f, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001c2a3f, 0x00108a51, 0x001aec68, 0x0048ff77, 0x0062ff7e, 0x0062ff7e, 0x005cff7d, 0x0056ff85, 0x003effa4, 0x003affa9, 0x0047ff9c, 0x0040ffa4, 0x003effa6, 0x0059ff8b, 0x0065ff80, 0x0060ff85, 0x0057ff8e, 0x004bff98, 0x0044ffa0, 0x003effa5, 0x0034ffaf, 0x0048ff9b, 0x005fff83, 0x0060ff80, 0x0057ff82, 0x004bfe7e, 0x0035fb74, 0x0020ed6a, 0x0013c55f, 0x00137c4f, 0x001a3441, 0x001e1e3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001b3742, 0x000dac57, 0x0022f86d, 0x0054ff7a, 0x0063ff7e, 0x0055ff7a, 0x0038ff73, 0x003cff76, 0x004eff8b, 0x0042ffa2, 0x003bffa8, 0x0041ffa3, 0x0054ff91, 0x0063ff82, 0x005eff87, 0x0047ff9c, 0x0037ffad, 0x0037ffad, 0x0037ffac, 0x002dffb6, 0x0020ffc2, 0x0034ffa4, 0x0047ff80, 0x0043ff77, 0x0034fd72, 0x0020f56b, 0x0012d762, 0x000fa456, 0x0015644a, 0x001b3341, 0x001e1e3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x00184444, 0x000cc65c, 0x002cfc70, 0x005bff7c, 0x0060ff7e, 0x0041ff76, 0x0016ff6c, 0x0022ff6f, 0x0055ff7c, 0x0062ff83, 0x005dff88, 0x005fff86, 0x0064ff80, 0x0064ff81, 0x0056ff8e, 0x0036ffae, 0x002bffb7, 0x0034ffaf, 0x0035ffae, 0x0033ffb0, 0x002fffae, 0x0026fe98, 0x001af974, 0x0010e965, 0x000ed160, 0x000ea656, 0x00136d4c, 0x00193e43, 0x001c263f, 0x001e1d3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x00184c45, 0x000cd560, 0x0032fe71, 0x005fff7d, 0x005fff7d, 0x003cff75, 0x0011ff6a, 0x001eff6e, 0x0054ff7b, 0x0066ff7f, 0x0066ff7f, 0x0066ff7f, 0x0065ff80, 0x0063ff82, 0x005eff86, 0x004eff96, 0x003fffa5, 0x0042ffa2, 0x004aff9a, 0x0054ff90, 0x004eff8b, 0x0027fb83, 0x000ddf69, 0x000f9554, 0x00165e49, 0x001a3842, 0x001d263f, 0x001e1f3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x00184c45, 0x000bd760, 0x0032fe71, 0x0060ff7d, 0x0064ff7e, 0x004fff79, 0x0021ff6e, 0x001cff6d, 0x004fff7a, 0x0065ff7f, 0x0066ff7f, 0x0064ff81, 0x005aff8b, 0x0050ff94, 0x0050ff94, 0x005aff8a, 0x0061ff84, 0x0063ff82, 0x0065ff80, 0x0065ff7f, 0x0059ff7e, 0x002dfa76, 0x000eca61, 0x00165748, 0x001d223e, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x00184744, 0x000bce5e, 0x002efd71, 0x005dff7d, 0x0066ff7f, 0x005aff7c, 0x002eff71, 0x001eff6d, 0x004eff79, 0x0064ff7e, 0x0066ff7f, 0x005dff88, 0x0044ffa0, 0x003bffa8, 0x003cffa8, 0x0042ffa1, 0x005cff89, 0x0066ff7f, 0x0066ff7f, 0x0065ff7f, 0x005cff7c, 0x0032fa72, 0x0010cc5f, 0x00165747, 0x001d1f3e, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x00193a42, 0x000cb859, 0x0023fb6e, 0x0056ff7b, 0x0065ff7f, 0x005cff7d, 0x0030ff72, 0x001fff6d, 0x004eff79, 0x0065ff7e, 0x0065ff80, 0x0052ff92, 0x003affaa, 0x0049ff9b, 0x004bff98, 0x0039ffaa, 0x004fff95, 0x0063ff81, 0x0066ff7f, 0x0066ff7f, 0x005eff7d, 0x0037fc73, 0x0012d662, 0x0015634a, 0x001d213e, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001c293f, 0x000f8e52, 0x0013f168, 0x0040ff76, 0x005fff7d, 0x005bff7d, 0x0030ff72, 0x001cff6d, 0x004bff78, 0x0065ff7e, 0x0062ff83, 0x0048ff9c, 0x003effa5, 0x005bff8a, 0x005dff88, 0x0042ffa1, 0x0044ff9f, 0x0060ff85, 0x0066ff7f, 0x0066ff7f, 0x0061ff7e, 0x003ffe75, 0x0015e365, 0x0013764d, 0x001d253e, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d,
0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1d3d, 0x00174c45, 0x000ac75c, 0x0019fd6c, 0x0044ff77, 0x0056ff7c, 0x0030ff72, 0x001cff6c, 0x004aff78, 0x0064ff7e, 0x005fff85, 0x0044ffa0, 0x0043ffa0, 0x0061ff84, 0x0062ff83, 0x004aff9a, 0x0040ffa3, 0x005cff88, 0x0065ff80, 0x0066ff7f, 0x0063ff7e, 0x004aff78, 0x001ced69, 0x00108c52, 0x001c2b3f, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d, 0x001e1c3d
};

EFI_GRAPHICS_OUTPUT_BLT_PIXEL LongToPixel(unsigned long color) {
	EFI_GRAPHICS_OUTPUT_BLT_PIXEL pixel;

	pixel.Blue = color & 0xFF;
	pixel.Green = (color >> 8) & 0xFF;
	pixel.Red = (color >> 16) & 0xFF;
	pixel.Reserved = (color >> 24) & 0xFF;

	return pixel;
}


string*
StrToken
(
	string* str,
	const string* delim
)
{
	static CHAR16* static_str = NULL; // Mantiene el puntero de la posición en la cadena original
	if (str) static_str = str;
	if (!static_str) return NULL;

	CHAR16* start = static_str;
	while (*static_str) {
		const CHAR16* d = delim;
		while (*d) {
			if (*static_str == *d) {
				*static_str = 0;
				static_str++;
				if (start != static_str - 1)
					return start;
				else {
					start++;
					break;
				}
			}
			d++;
		}
		static_str++;
	}
	static_str = NULL;
	return start != static_str ? start : NULL;
}

CHAR16**
SplitChs
(
	CHAR16* text,
	UINTN* line_count,
	CHAR16* Character
)
{
	CHAR16* lines[2048];
	*line_count = 0;
	CHAR16* token = StrToken(text, Character);
	while (token != NULL && *line_count < 100) {
		lines[(*line_count)++] = token;
		token = StrToken(NULL, Character);
	}
	return lines;
}

/**
*
*/
VOID
DrawBitMapImage
(
	unsigned long array_[],
	u64 witdh,
	u64 hight,
	u64 x,
	u64 y,
	u64 length
)
{
	u64 curx = x;
	u64 cury = y;
	u64 counter_m = 0;

	for (size_t i = 0; i < length; i++)
	{
		if (
			counter_m == witdh
			)
		{
			counter_m = 0;
			cury++;
			curx = x;
		}

		draw_pixel(gop, curx, cury, LongToPixel(array_[i]));

		curx++;
		counter_m++;
	}
}

/**
* WriteFile
* 
* writes a file
*/
VOID WriteFile(CHAR16* Name,UINTN Size ,VOID* Content)
{
	EFI_FILE_PROTOCOL* Root;
	EFI_FILE_PROTOCOL* NewFile;
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
	EFI_STATUS Status;

	Status = gBS->LocateProtocol(&gEfiSimpleFileSystemProtocolGuid, NULL, (VOID**)&FileSystem);
	if (EFI_ERROR(Status)) return;

	Status = FileSystem->OpenVolume(FileSystem, &Root);
	if (EFI_ERROR(Status)) return;

	Status = Root->Open(
		Root,
		&NewFile,
		Name,
		EFI_FILE_MODE_READ | EFI_FILE_MODE_WRITE | EFI_FILE_MODE_CREATE,
		0
	);
	if (EFI_ERROR(Status)) {
		Print(L"Error opening %r", Status);
		return; }

	Status = NewFile->Write(NewFile, Size, Content);

	Print(L"Writing : %r\n", Status);

	// 4. Cerrar el archivo
	NewFile->Close(NewFile);
}

/**
* Gen__Directo___szy
* 
* gens the _DIRECTO_.szy file
*/
VOID Gen__Directo___szy()
{
	CHAR16* File = AllocatePool(sizeof(memory_acces) + 2);

	for (size_t i = 0; i < (sizeof(memory_acces) / 2) + 1; i++)
	{
		if (
			memory_acces[i] == 0
			)
		{
			File[i] = L'.';
		}
		else {
			File[i] = memory_acces[i];
		}
	}

	File[(sizeof(memory_acces) / 2)] = L'\0';

	Print(File);
	//WriteFile(L"__DIRECTO__.szy", (sizeof(memory_acces) + 2), File);

	FreePool(File);
}

/**
* PrintLineWithBackground
* 
* for debug the display in some uefises
*/
VOID
PrintLineWithBackground
(
	EFI_SYSTEM_TABLE* SystemTable,
	string* text,
	UINTN line,
	UINTN COLOR,
	UINTN BG
)
{
	UINTN Column, MaxColumns;
	string* lineBuffer;
	UINTN textLength = StrLen(text);

	// Obtener el número máximo de columnas de la pantalla
	SystemTable->ConOut->QueryMode(SystemTable->ConOut, SystemTable->ConOut->Mode->Mode, &MaxColumns, NULL);

	MaxColumns = gop->Mode->Info->VerticalResolution / 8;

	// Crear un buffer para la línea completa
	lineBuffer = AllocatePool((MaxColumns + 1) * sizeof(CHAR16));
	if (!lineBuffer) {
		return;
	}

	// Copiar el texto al buffer y llenar el resto con espacios en blanco
	StrCpy(lineBuffer, text);
	for (Column = textLength; Column < MaxColumns; Column++) {
		lineBuffer[Column] = L' ';
	}
	lineBuffer[MaxColumns] = L'\0';

	// Establecer el atributo de color de fondo
	SystemTable->ConOut->SetAttribute(SystemTable->ConOut, COLOR | BG);

	// Mover el cursor a la línea especificada
	SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 0, line);

	// Escribir la línea con el fondo de color
	Print(lineBuffer);

	// Liberar el buffer
	FreePool(lineBuffer);
}

CHAR16* languajecu;

typedef struct {
	CHAR16*
		StandartEnglishOriginal;
	CHAR16*
		StandartSpanish;
	CHAR16*
		StandartFrances;
} Translation;

CHAR16*
TranslateWorck
(
	Translation* Transalatedictionarie,
	CHAR16* Language
)
{
	if (StrCmp(Language, L"en") == 0) {
		return Transalatedictionarie->StandartEnglishOriginal;
	}
	else if (StrCmp(Language, L"fr") == 0) {
		return Transalatedictionarie->StandartFrances;
	}
	else if (StrCmp(Language, L"es") == 0) {
		return Transalatedictionarie->StandartSpanish;
	}
	else
	{
		return Transalatedictionarie->StandartEnglishOriginal;
	}
}
CHAR16**
SplitLines
(
	CHAR16* text,
	UINTN* line_count
)
{
	CHAR16* lines[2048];
	*line_count = 0;
	CHAR16* token = StrToken(text, L"\n");
	while (token != NULL && *line_count < 100) {
		lines[(*line_count)++] = token;
		token = StrToken(NULL, L"\n");
	}
	return lines;
}


CHAR16*
StrStr(CHAR16* haystack, CHAR16* needle)
{
	if (!*needle) return haystack;

	for (; *haystack; haystack++) {
		CHAR16* h = haystack;
		CHAR16* n = needle;

		while (*h && *n && *h == *n) {
			h++;
			n++;
		}

		if (!*n) return haystack; // needle completo fue encontrado
	}

	return NULL;
}

CHAR16*
editor
(
	EFI_HANDLE ImageHandle,
	EFI_SYSTEM_TABLE* SystemTable,
	CHAR16* textt
)
{
	string* taskbar = AllocatePool(sizeof(string) * ((GET_MAX_COL)+1));

	for (size_t i = 0; i < GET_MAX_COL; i++)
	{
		taskbar[i] = L' ';
	}
	taskbar[(INTN)GET_MAX_COL] = L'\0';

	/*
	DocType

	Summary:
		represents the type of the documment
	*/
	enum DocType {

		///
		/// DocType_text
		/// 
		/// Summary:
		/// 
		///		represents a plain text documment
		/// 
		DocType_text = 0,

		///
		/// DocType_etm
		/// 
		/// Summary:
		///		
		///		represents a etm documment
		///
		DocType_etm = 1,

		///
		/// DocType_sasm
		/// 
		/// Summary:
		///		
		///		represents a ErickAssambly code
		///
		DocType_sasm = 2,

		///
		/// DocType_splusplus
		/// 
		/// Summary:
		/// 
		///		represents a code in S++
		/// 
		DocType_splusplus = 3,

		///
		/// DocType_thm
		/// 
		/// Summary:
		/// 
		///		represents a theme config
		/// 
		DocType_thm = 4,

		///
		/// DocType_heasm
		/// 
		/// Summary:
		/// 
		///		represents a hight level compiler ErickAssembly syntax
		/// 
		DocType_heasm = 5,
	};

	///
	/// documment_type
	/// 
	/// Summary:
	/// 
	///		represents the type of the documment
	/// 
	enum DocType documment_type = DocType_text;

	///
	/// text
	/// 
	/// Summary:
	/// 
	///		represents the text
	/// 
	CHAR16 text[1024] = L"";

	///
	/// save_text
	/// 
	/// Summary:
	/// 
	///		represents a backup of text
	/// 
	CHAR16 save_text[1024];

	printc(L"calculating the lenght");
	// the index
	UINTN Index;
	if (textt != NULL) {
		for (size_t i = 0; i < 1024; i++)
		{
			if (textt[i] == L'\0') break;
			Index++;
		}
	}

	///
	/// Event
	/// 
	/// Summary:
	///		
	///		represents the event handler
	/// 
	UINTN Event;

	///
	/// Key
	/// 
	/// Summary:
	/// 
	///		represents the pressed key
	/// 
	EFI_INPUT_KEY Key;

	///
	/// CurX
	/// 
	/// Summary:
	/// 
	///		represents the mouse x
	/// 
	u16 CurX;

	///
	/// CurY
	/// 
	/// Summary:
	/// 
	///		represents the mouse y
	/// 
	u16 CurY;

	///
	/// cursor_actived
	/// 
	/// Summary:
	/// 
	///		the flag of the mouse activation
	/// 
	bool_t cursor_actived = false;

	///
	/// cpy
	/// 
	/// Summary:
	/// 
	///		the clippyboard
	/// 
	CHAR16* cpy = L"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

	///
	/// buffercpy_bord
	/// 
	/// Summary:
	/// 
	///		the length of the coppy text
	///
	u8 buffercpy_bord = 0;

	///
	/// MaxColumns, MaxRows
	/// 
	/// Summary:
	/// 
	///		the screen size
	/// 
	UINTN MaxColumns, MaxRows;

	///
	/// SurvivalGuideAlt
	/// 
	/// Summary:
	/// 
	///		represents the alternating help guide flag
	/// 
	bool SurvivalGuideAlt = 0;

	///
	/// MenuAlternate
	/// 
	/// Summary:
	/// 
	///		the flag if the menu is alternated
	/// 
	bool MenuAlternate = false;

	t8 MenuOption = 0;
	t8 FileSave = 0;
	bool_t FileSavedIn = false;

	Translation Editor_Title = { L"Editor" , L"Editor", L"Editor" };
	Translation Upper_Option_Save = { L"Save" , L"Guardar", L"Save" };
	Translation Upper_Option_Run = { L"Run" , L"Ejecutar", L"Run" };
	Translation Upper_Option_Exit = { L"Exit" , L"Salir", L"Exit" };
	Translation CantRun_trans = { L"Error: the file is not a executable" , L"Error: el archivo no es ejecutable", L"Error: the file is not a executable" };

	///
	/// EditorScroll
	/// 
	/// Summary:
	/// 
	///		represents the editor scroll
	/// 
	INTN EditorScroll;

	EditorScroll = 0;

	printc(L"try to restore the backup or open the file");

	//
	// try to restore the before session minimized backup
	// 

	StrCpy(&text, textt);
	Index = StrLen(text);

	///
	/// scrolla
	/// 
	/// Summary:
	/// 
	///		the scroll in runtime
	/// 
	INTN scrolla;

	///
	/// configure the editor scheme
	/// 

	Translation SSUNEDITOR_UPPER_BAR_TRANSL = { L"", L"" };
	Translation SSUNEDITOR_LOWER_BAR_TRANSL = { L"", L"", L"" };

	PIXELCOL editorbg = { 30, 30, 30 , 0 };
	PIXELCOL editorcol1 = { 25, 25, 25 , 0 };
	PIXELCOL editor_menu_uns = { 10, 10, 10 , 0 };
	PIXELCOL editor_menu_sel = { 70, 70, 70 , 0 };
	PIXELCOL editorcol2 = white;

	///
	/// configure the text scheme
	/// 
	PIXELCOL PlainText = gray;
	PIXELCOL Comment = { 78 , 139 , 96 , 0 };
	PIXELCOL Functions_color = { 99, 234, 230 , 0 };
	PIXELCOL Strings_color = { 71 , 169 , 238 , 0 };
	PIXELCOL Variables_color = { 255, 220, 156 , 0 };
	PIXELCOL Structures_Color = { 145, 198, 134 , 0 };
	PIXELCOL KeyWords_Color = { 214, 156, 86 , 0 };
	PIXELCOL Types_Color = { 176, 201, 78 , 0 };

	//
	// editor main loop
	//
	while (TRUE) {

		ChangeToGrapichalMode();

		///
		/// parse the screen size
		/// 

		MaxRows = (verticalResolution / row_size) / Conio->atributes->size;
		MaxColumns = (horizontalResolution / 8) / Conio->atributes->size;

		///
		/// clear the screen
		/// 

		SetScreenAtribute(0, editorcol1);
		SetScreenAtribute(1, editorbg);
		ClearScreen();

		gotoxy(0, 0);
		SetScreenAtribute(1, editorcol1);
		SetScreenAtribute(0, editorcol2);

		///
		/// 
		/// upper bar
		/// 
		/// 

		gotoxy(0, 0);
		printcu(taskbar);

		gotoxy(0, 1);
		printcu(taskbar);

		gotoxy((GET_MAX_COL - StrLen(TranslateWorck(&Editor_Title, languajecu))) / 2, 0);
		printcu(TranslateWorck(&Editor_Title, languajecu));
		gotoxy(0, 1);

		SetScreenAtribute(1, editorcol1);
		printcu(L" ");
		SetScreenAtribute(1, editor_menu_uns);

		if (
			MenuAlternate && MenuOption == 0
			)
			SetScreenAtribute(1, editor_menu_sel);

		printcu(TranslateWorck(&Upper_Option_Save, languajecu));


		SetScreenAtribute(1, editorcol1);
		printcu(L" ");
		SetScreenAtribute(1, editor_menu_uns);

		if (
			MenuAlternate && MenuOption == 1
			)
			SetScreenAtribute(1, editor_menu_sel);

		printcu(TranslateWorck(&Upper_Option_Run, languajecu));

		SetScreenAtribute(1, editorcol1);
		printcu(L" ");
		SetScreenAtribute(1, editor_menu_uns);

		if (
			MenuAlternate && MenuOption == 2
			)
			SetScreenAtribute(1, editor_menu_sel);

		printcu(TranslateWorck(&Upper_Option_Exit, languajecu));

		SetScreenAtribute(0, editorcol1);
		SetScreenAtribute(1, editorbg);
		printcu(L"\n\n\n");


		///
		/// 
		/// lower bar
		/// 
		/// 

		gotoxy(0, MaxRows - 1);
		SetScreenAtribute(1, editorcol1);
		SetScreenAtribute(0, editorcol2);
		printcu(taskbar);
		gotoxy(0, MaxRows - 1);
		printcu(TranslateWorck(&SSUNEDITOR_LOWER_BAR_TRANSL, languajecu));
		SetScreenAtribute(0, gray);
		SetScreenAtribute(1, editorbg);

		// go to text pos
		gotoxy(0, 4);

		///
		/// check the type of the documment
		/// 

		ch16* cmper = text;

		if (
			StrLen(cmper) > 4 ? text[0] == L'#' && text[1] == L'E' && text[2] == L'T' && text[3] == L'M' && text[4] == L'\n' : false
			)
		{
			documment_type = DocType_etm;
		}
		else if (
			StrLen(cmper) > 4 ? text[0] == L'#' && text[1] == L'S' && text[2] == L'+' && text[3] == L'+' && text[4] == L'\n' : false
			)
		{
			documment_type = DocType_splusplus;
		}
		else if (
			StrLen(cmper) > 4 ? text[0] == L'#' && text[1] == L'T' && text[2] == L'H' && text[3] == L'M' && text[4] == L'\n' : false
			)
		{
			documment_type = DocType_thm;
		}
		else if (
			StrLen(cmper) > 12 ? (StrnCmp(cmper, L"HightLevel[ ", 12) == 0) : false
			)
		{
			documment_type = DocType_heasm;
		}
		else if (
			StrLen(cmper) > 7 ? text[2] == L'\n' : false
			)
		{
			documment_type = DocType_sasm;
		}
		else {
			documment_type = DocType_text;
		}


		// coppy a coppy of the text
		StrCpy(save_text, text);

		// lines count
		UINTN line_count1 = 0;
		CHAR16** lines1 = SplitLines(text, &line_count1);

		// real scroll
		scrolla = line_count1 - ((MaxRows - 10) - EditorScroll);

		// verific the scroll
		if (scrolla < 0) {
			scrolla = 0;
		}

		// if the survivalguide is alternate show if not show the text
		if (SurvivalGuideAlt == 0) {

			bool_t in_comment = 0;

			for (UINTN i2 = scrolla; i2 < line_count1; i2++) {
				SetScreenAtribute(0, gray);

				printcu(L"\n");
				if (
					documment_type == DocType_splusplus
					)
				{
					if (StrnCmp(lines1[i2], L"#", 1) == 0) {
						SetScreenAtribute(0, Comment);
						printcu(L"#");
						printcu(lines1[i2] + 1);
					}
					else
					{
						CHAR16* equals_pos = StrStr(lines1[i2], L" ");
						if (equals_pos != NULL) {
							*equals_pos = L'\0';
							CHAR16* MemName = lines1[i2];
							CHAR16* NewValue = equals_pos + 1;

							SetScreenAtribute(0, Functions_color);
							printcu(MemName);
							printcu(L" ");
							SetScreenAtribute(0, Strings_color);
							printcu(NewValue);
						}
						else {
							SetScreenAtribute(0, gray);
							printcu(lines1[i2]);
						}
					}
				}
				else if (
					documment_type == DocType_sasm
					)
				{
					if (
						lines1[i2][0] == L';'
						)
					{
						SetScreenAtribute(0, Comment);
						printcu(lines1[i2]);
					}
					else
					{
						CHAR16* equals_pos = StrStr(lines1[i2], L" ");
						if (equals_pos != NULL) {
							*equals_pos = L'\0';
							CHAR16* MemName = lines1[i2];
							CHAR16* NewValue = equals_pos + 1;

							SetScreenAtribute(0, Functions_color);
							printcu(MemName);
							printcu(L" ");
							SetScreenAtribute(0, Strings_color);
							printcu(NewValue);
						}
						else {
							SetScreenAtribute(0, gray);
							printcu(lines1[i2]);
						}
					}
				}
				else if (
					documment_type == DocType_heasm
					)
				{
					if (
						StrnCmp(StrTrim(lines1[i2]) , L"//" , 2) == 0
						)
					{
						SetScreenAtribute(0, Comment);
						printcu(lines1[i2]);
					}
					else if (
						StrnCmp(StrTrim(lines1[i2]), L"/*", 2) == 0
						)
					{
						in_comment = true;
						SetScreenAtribute(0, Comment);
						printcu(lines1[i2]);
					}
					else if (
						(
							StrTrim(lines1[i2])[StrLen(StrTrim(lines1[i2])) - 1] == L'/' &&
							StrTrim(lines1[i2])[StrLen(StrTrim(lines1[i2])) - 2] == L'*') &&
						in_comment
						)
					{
						in_comment = false;
						SetScreenAtribute(0, Comment);
						printcu(lines1[i2]);
					}
					else if (
						in_comment
						)
					{
						SetScreenAtribute(0, Comment);
						printcu(lines1[i2]);
					}
					else if (
						(StrCmp(StrTrim(lines1[i2]), L"}") == 0) ||
						(StrCmp(StrTrim(lines1[i2]), L"{") == 0)
						)
					{
						SetScreenAtribute(0, PlainText);
						printcu(lines1[i2]);
					}
					else if (
						StrnCmp(StrTrim(lines1[i2]), L"_Use ", 5) == 0
						)
					{
						SetScreenAtribute(0, KeyWords_Color);
						printcu(StrOnlySpaces(lines1[i2]));
						printcu(L"_Use ");
						SetScreenAtribute(0, Structures_Color);
						printcu(StrTrim(lines1[i2]) + 5);
					}
					else if (
						StrnCmp(StrTrim(lines1[i2]), L"autv ", 5) == 0
						)
					{
						SetScreenAtribute(0, KeyWords_Color);
						printcu(StrOnlySpaces(lines1[i2]));
						printcu(L"autv ");

						ch16* stmts = StrTrim(lines1[i2]) + 5;

						CHAR16* equals_pos = StrStr(stmts, L":");
						if (equals_pos != NULL) {
							*equals_pos = L'\0';
							CHAR16* MemName = stmts;
							CHAR16* NewValue = equals_pos + 1;

							SetScreenAtribute(0, Variables_color);
							printcu(MemName);
							printcu(L":");
							SetScreenAtribute(0, Types_Color);
							printcu(NewValue);
						}
						else {
							SetScreenAtribute(0, gray);
							printcu(stmts);

							SetScreenAtribute(0, brred);
							printcu(L"<- <- Syntax error, '::' not founded");
						}
					}
					else if (
						StrnCmp(StrTrim(lines1[i2]), L"swinc ",6) == 0
						)
					{
						SetScreenAtribute(0, KeyWords_Color);
						printcu(StrOnlySpaces(lines1[i2]));
						printcu(L"swinc ");
						SetScreenAtribute(0, Structures_Color);
						printcu(StrTrim(lines1[i2]) + 6);
					}
					else
					{
						CHAR16* equals_pos = StrStr(lines1[i2], L" ");
						if ( 0 ? equals_pos != NULL : 0) {
							*equals_pos = L'\0';
							CHAR16* MemName = lines1[i2];
							CHAR16* NewValue = equals_pos + 1;

							SetScreenAtribute(0, Functions_color);
							printcu(MemName);
							printcu(L" ");
							SetScreenAtribute(0, Strings_color);
							printcu(NewValue);
						}
						else {
							SetScreenAtribute(0, gray);
							printcu(lines1[i2]);
						}
					}
				}
				else if (
					documment_type == DocType_etm || documment_type == DocType_thm
					)
				{
					if (StrnCmp(lines1[i2], L"#", 1) == 0) {
						SetScreenAtribute(0, Comment);
						printcu(L"#");
						printcu(lines1[i2] + 1);
					}
					else if (StrnCmp(lines1[i2], L"p: ", 3) == 0) {
						SetScreenAtribute(0, Functions_color);
						printcu(L"p: ");
						SetScreenAtribute(0, Strings_color);
						printcu(lines1[i2] + 3);
					}
					else if (
						lines1[i2][0] == L':'
						)
					{
						CHAR16* equals_pos = StrStr(lines1[i2], L" ");
						if (equals_pos != NULL) {
							*equals_pos = L'\0';
							CHAR16* MemName = lines1[i2] + 1;
							CHAR16* NewValue = equals_pos + 1;

							SetScreenAtribute(0, darkgray);
							printcu(L":");

							SetScreenAtribute(0, Variables_color);
							printcu(MemName);
							printcu(L" ");
							SetScreenAtribute(0, gray);
							printcu(NewValue);
						}
						else {
							SetScreenAtribute(0, gray);
							printcu(lines1[i2]);
						}
					}
					else
					{
						SetScreenAtribute(0, gray);
						printcu(lines1[i2]);
					}
				}
				else
				{
					if (StrnCmp(lines1[i2], L"section::", 9) == 0) {
						SetScreenAtribute(0, brblue);
						printcu(lines1[i2] + 9);
					}
					else {
						SetScreenAtribute(0, gray);
						printcu(lines1[i2]);
					}
				}
			}

			if (
				cursor_actived
				)
			{
				gotoxy(CurX, CurY);
			}
			SetScreenAtribute(0, gray);
			printcu(cursor_actived ? L"\x3a8" : L"\a");
		}
		else {
		}

		// draw the screen
		SetScreenAtribute(0, gray);
		SetScreenAtribute(1, editorbg);
		DrawScreen();

		StrCpy(text, save_text);
		UINTN Buttom = MaxRows - 1;

		// wait for key
		SystemTable->BootServices->WaitForEvent(1, &SystemTable->ConIn->WaitForKey, &Event);
		SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key);

		///
		/// Enter key
		/// 
		/// Summary:
		/// 
		///		adds a line or select a option if the menu is alternated
		/// 
		if (Key.UnicodeChar == CHAR_CARRIAGE_RETURN) {

			///
			/// check if the documment is enabled
			/// 
			if (
				MenuAlternate == false
				)
				text[Index++] = L'\n';

			///
			/// if in menu makes the actions
			/// 
			else {

				///
				/// Save
				/// 
				/// Summary:
				///		
				///		saves the documment
				/// 
				if (
					MenuOption == 0
					)
				{
					///
					/// preconfigure the file id
					/// 
					INT16 file_id;

					///
					/// if is not saved
					/// 
					if (
						FileSavedIn == false
						)
					{
					}

					///
					/// if the file have a destination
					/// 
					else {
						file_id = FileSave;
					}

					///
					/// write the file
					/// 

					printc(L"saving changes...\n");

				}

				///
				/// Run
				/// 
				/// Summary:
				/// 
				///		runs the text as a type of a interpreter
				/// 
				else if (
					MenuOption == 1
					)
				{

					///
					/// .easm
					/// 
					/// Summary:
					///		
					///		.easm run
					/// 
					if (documment_type == DocType_sasm) {
						CHAR16* Doc = StrDuplicate(text);

						BinaryEx(AssambleProgram(Doc), false);
						SystemTable->BootServices->WaitForEvent(1, &SystemTable->ConIn->WaitForKey, &Event);
						gST->ConIn->ReadKeyStroke(gST->ConIn, &Key);
					}

					///
					/// .heasm
					/// 
					/// Summary:
					///		
					///		.heasm hlvc compiler
					/// 
					else if (documment_type == DocType_heasm)
					{
						CHAR16* Doc = StrDuplicate(text);
						
						editor(ImageHandle, SystemTable, ConvertHightLevelSyntaxToAsm(Doc));
					}
					else {
					}
				}

				///
				/// Exit
				/// 
				/// Summary:
				/// 
				///		exits from the editor
				/// 
				else if (
					MenuOption == 2
					)
				{
					return;
				}
			}
		}
		else if (
			Key.ScanCode == SCAN_F3
			)
		{
			MenuAlternate = MenuAlternate ? false : true;
		}
		else if (Key.UnicodeChar == CHAR_BACKSPACE) {
			if (
				MenuAlternate == false
				)
			{
				if (Index > 0) {
					text[--Index] = L'\0';
				}
			}
		}
		else if (Key.ScanCode == SCAN_F1) {
			SurvivalGuideAlt = SurvivalGuideAlt == 0 ? 1 : 0;
		}
		else if (Key.ScanCode == SCAN_F2) {
			text[Index] = L'\0';

			return text;
		}
		else if (Key.ScanCode == SCAN_UP) {
			if (
				cursor_actived == false
				) {
				EditorScroll--;
			}
			else {
				CurY--;
			}
		}
		else if (
			Key.ScanCode == SCAN_LEFT
			)
		{
			if (
				MenuAlternate == true
				)
			{
				MenuOption--;
			}
		}
		else if (
			Key.ScanCode == SCAN_RIGHT
			)
		{
			if (
				MenuAlternate == true
				)
			{
				MenuOption++;
			}
		}
		else if (Key.ScanCode == SCAN_DOWN) {
			if (
				cursor_actived == false
				) {
				EditorScroll++;
			}
			else {
				CurY++;
			}
		}
		else {
			if (
				MenuAlternate == false
				) {
				if (Key.UnicodeChar != 0 || Key.ScanCode == SCAN_F12) {
					if (Key.ScanCode == SCAN_F12) {

					}
					else {
						text[Index++] = Key.UnicodeChar;
					}
					//EditorScroll = 0;
				}
			}
		}

		text[Index] = L'\0';
	}

	return L"e";
}

/**
* LooksLikeChar16
* 
* check if likes look a char16
*/
BOOLEAN LooksLikeChar16(UINT8* Data, UINTN Size)
{
	UINTN Matches = 0;
	for (UINTN i = 1; i < Size; i += 2) {
		if (Data[i] == 0x00) {
			Matches++;
		}
	}
	return (Matches * 2 > Size); // Si más del 50% de los pares tienen 0x00 como segundo byte
}

/**
* AsciiToChar16
* 
* converts a char8 to a char16
*/
CHAR16* AsciiToChar16(UINT8* AsciiData, UINTN Size)
{
	CHAR16* Utf16 = AllocateZeroPool((Size + 1) * sizeof(CHAR16));
	for (UINTN i = 0; i < Size; i++) {
		Utf16[i] = (CHAR16)AsciiData[i];
	}
	return Utf16;
}

/**
* TryBootErickBinarie
* 
* try to boot erick binaries
*/
VOID TryBootErickBinarie()
{
	//
	// configure the status variable
	//
	EFI_STATUS Status;

	//
	// configure the files
	//

	EFI_FILE_PROTOCOL* Root;
	EFI_FILE_PROTOCOL* FoundFile = NULL;
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
	EFI_FILE_INFO* FileInfo;

	//
	// configure others
	//

	UINTN BufferSize;
	CHAR16* BinExtension = L".ebf";

	//
	// locate fs
	//

	Status = gBS->LocateProtocol(&gEfiSimpleFileSystemProtocolGuid, NULL, (VOID**)&FileSystem);
	if (EFI_ERROR(Status)) return;

	//
	// open fs
	//

	Status = FileSystem->OpenVolume(FileSystem, &Root);
	if (EFI_ERROR(Status)) return;

	//
	// read the root
	//

	while (TRUE) {
		//
		// configure info
		//

		BufferSize = SIZE_OF_EFI_FILE_INFO + 512;
		FileInfo = AllocateZeroPool(BufferSize);
	
		//
		// if not file info
		//

		if (!FileInfo) break;

		//
		// makes the read file
		//

		Status = Root->Read(Root, &BufferSize, FileInfo);
		if (EFI_ERROR(Status) || BufferSize == 0) {
			FreePool(FileInfo);
			break;
		}

		//
		// set the name
		//

		CHAR16* Name = FileInfo->FileName;

		//
		// alert to the user
		//

		SetScreenAtribute(0, gray);
		printc(L"Triying to boot: ");
		SetScreenAtribute(0, brblue);
		printc(Name);
		printc(L"\n");
		gBS->Stall(1000000);

		//
		// configure lenght
		//

		UINTN Len = StrLen(Name);

		//
		// configure size
		//
		
		if (Len > 4 && StrnCmp(&Name[Len - 4], BinExtension, 4) == 0) {

			//
			// open the file
			//

			Status = Root->Open(Root, &FoundFile, Name, EFI_FILE_MODE_READ, 0);

			//
			// if the file is founded
			//

			if (!EFI_ERROR(Status) && FoundFile) {

				//
				// get file size
				//

				UINTN FileSize = (UINTN)FileInfo->FileSize;
				_BINARY* Buffer = AllocatePool(FileSize);

				//
				// close if not valid
				//

				if (!Buffer) {
					FoundFile->Close(FoundFile);
					FreePool(FileInfo);
					break;
				}

				//
				// read the content
				//

				Status = FoundFile->Read(FoundFile, &FileSize, Buffer);

				//
				// if not errors
				//

				if (!EFI_ERROR(Status)) {

					//
					// looks like char16?
					//

					BOOLEAN IsChar16 = LooksLikeChar16(Buffer, FileSize);

					//
					// if is char16
					//

					if (IsChar16) {

						//
						// execute it
						//

						BinaryEx((CHAR16*)Buffer, FALSE);
					}

					//
					// if is a char8
					//

					else {
						//
						// convert it
						//
						CHAR16* Converted = AsciiToChar16((UINT8*)Buffer, FileSize);

						//
						// and execute it
						//

						BinaryEx(Converted, FALSE);
						FreePool(Converted);
					}

				}

				//
				// free the buffer
				//

				FreePool(Buffer);

				//
				// close file and delete the info
				//

				FoundFile->Close(FoundFile);
				FreePool(FileInfo);
				break;
			}
		}

		//
		// free the info
		//

		FreePool(FileInfo);
	}

	//
	// if the root is open close it
	//

	if (Root) Root->Close(Root);
}

/**
* ListFiles
*
* list the files
*/
VOID ListFiles()
{
	//
	// configure the status variable
	//
	EFI_STATUS Status;

	//
	// configure the files
	//

	EFI_FILE_PROTOCOL* Root;
	EFI_FILE_PROTOCOL* FoundFile = NULL;
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
	EFI_FILE_INFO* FileInfo;

	//
	// configure others
	//

	UINTN BufferSize;
	CHAR16* BinExtension = L".ebf";

	//
	// locate fs
	//

	Status = gBS->LocateProtocol(&gEfiSimpleFileSystemProtocolGuid, NULL, (VOID**)&FileSystem);
	if (EFI_ERROR(Status)) return;

	//
	// open fs
	//

	Status = FileSystem->OpenVolume(FileSystem, &Root);
	if (EFI_ERROR(Status)) return;

	//
	// read the root
	//

	while (TRUE) {
		//
		// configure info
		//

		BufferSize = SIZE_OF_EFI_FILE_INFO + 512;
		FileInfo = AllocateZeroPool(BufferSize);

		//
		// if not file info
		//

		if (!FileInfo) break;

		//
		// makes the read file
		//

		Status = Root->Read(Root, &BufferSize, FileInfo);
		if (EFI_ERROR(Status) || BufferSize == 0) {
			FreePool(FileInfo);
			break;
		}

		//
		// set the name
		//

		CHAR16* Name = FileInfo->FileName;

		//
		// configure lenght
		//

		UINTN Len = StrLen(Name);

		SetScreenAtribute(0, brblue);
		printc(Name);
		printc(L"\n");

		//
		// free the info
		//

		FreePool(FileInfo);
	}

	//
	// if the root is open close it
	//

	if (Root) Root->Close(Root);
}

/**
* BootSpecific
*
* try to boot a specific file
* 
* @param filename is that file
*/
VOID BootSpecific(ch16* filename, bool_t debugger)
{
	//
	// configure the status variable
	//
	EFI_STATUS Status;

	//
	// configure the files
	//

	EFI_FILE_PROTOCOL* Root;
	EFI_FILE_PROTOCOL* FoundFile = NULL;
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
	EFI_FILE_INFO* FileInfo;

	//
	// configure others
	//

	UINTN BufferSize;
	CHAR16* BinExtension = L".ebf";

	//
	// locate fs
	//

	Status = gBS->LocateProtocol(&gEfiSimpleFileSystemProtocolGuid, NULL, (VOID**)&FileSystem);
	if (EFI_ERROR(Status)) return;

	//
	// open fs
	//

	Status = FileSystem->OpenVolume(FileSystem, &Root);
	if (EFI_ERROR(Status)) return;

	//
	// read the root
	//

	while (TRUE) {
		//
		// configure info
		//

		BufferSize = SIZE_OF_EFI_FILE_INFO + 512;
		FileInfo = AllocateZeroPool(BufferSize);

		//
		// if not file info
		//

		if (!FileInfo) break;

		//
		// makes the read file
		//

		Status = Root->Read(Root, &BufferSize, FileInfo);
		if (EFI_ERROR(Status) || BufferSize == 0) {
			FreePool(FileInfo);
			break;
		}

		//
		// set the name
		//

		CHAR16* Name = FileInfo->FileName;

		//
		// configure lenght
		//

		UINTN Len = StrLen(Name);

		//
		// configure size
		//

		if (StrCmp(Name,filename) == 0) {

			//
			// open the file
			//

			Status = Root->Open(Root, &FoundFile, Name, EFI_FILE_MODE_READ, 0);

			//
			// if the file is founded
			//

			if (!EFI_ERROR(Status) && FoundFile) {

				//
				// get file size
				//

				UINTN FileSize = (UINTN)FileInfo->FileSize;
				_BINARY* Buffer = AllocatePool(FileSize);

				//
				// close if not valid
				//

				if (!Buffer) {
					FoundFile->Close(FoundFile);
					FreePool(FileInfo);
					break;
				}

				//
				// read the content
				//

				Status = FoundFile->Read(FoundFile, &FileSize, Buffer);

				//
				// if not errors
				//

				if (!EFI_ERROR(Status)) {

					//
					// looks like char16?
					//

					BOOLEAN IsChar16 = LooksLikeChar16(Buffer, FileSize);

					//
					// if is char16
					//

					if (IsChar16) {

						//
						// execute it
						//

						BinaryEx((CHAR16*)Buffer, debugger);
					}

					//
					// if is a char8
					//

					else {
						//
						// convert it
						//
						CHAR16* Converted = AsciiToChar16((UINT8*)Buffer, FileSize);

						//
						// and execute it
						//
						
						BinaryEx(Converted, debugger);
						FreePool(Converted);
					}

				}

				//
				// free the buffer
				//

				FreePool(Buffer);

				//
				// close file and delete the info
				//

				FoundFile->Close(FoundFile);
				FreePool(FileInfo);
				return;
			}
		}

		//
		// free the info
		//

		FreePool(FileInfo);
	}

	//
	// if the root is open close it
	//

	if (Root) Root->Close(Root);

	SetScreenAtribute(0, brred);
	printc(L"File not founded\n");
}

CHAR16* GetFileContent(ch16* filename)
{
	//
	// configure the status variable
	//
	EFI_STATUS Status;

	//
	// configure the files
	//

	EFI_FILE_PROTOCOL* Root;
	EFI_FILE_PROTOCOL* FoundFile = NULL;
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
	EFI_FILE_INFO* FileInfo;

	//
	// configure others
	//

	UINTN BufferSize;
	CHAR16* BinExtension = L".ebf";

	//
	// locate fs
	//

	Status = gBS->LocateProtocol(&gEfiSimpleFileSystemProtocolGuid, NULL, (VOID**)&FileSystem);
	if (EFI_ERROR(Status)) return;

	//
	// open fs
	//

	Status = FileSystem->OpenVolume(FileSystem, &Root);
	if (EFI_ERROR(Status)) return;

	//
	// read the root
	//

	while (TRUE) {
		//
		// configure info
		//

		BufferSize = SIZE_OF_EFI_FILE_INFO + 512;
		FileInfo = AllocateZeroPool(BufferSize);

		//
		// if not file info
		//

		if (!FileInfo) break;

		//
		// makes the read file
		//

		Status = Root->Read(Root, &BufferSize, FileInfo);
		if (EFI_ERROR(Status) || BufferSize == 0) {
			FreePool(FileInfo);
			break;
		}

		//
		// set the name
		//

		CHAR16* Name = FileInfo->FileName;

		//
		// configure lenght
		//

		UINTN Len = StrLen(Name);

		//
		// configure size
		//

		if (StrCmp(Name, filename) == 0) {

			//
			// open the file
			//

			Status = Root->Open(Root, &FoundFile, Name, EFI_FILE_MODE_READ, 0);

			//
			// if the file is founded
			//

			if (!EFI_ERROR(Status) && FoundFile) {

				//
				// get file size
				//

				UINTN FileSize = (UINTN)FileInfo->FileSize;
				_BINARY* Buffer = AllocatePool(FileSize);

				//
				// close if not valid
				//

				if (!Buffer) {
					FoundFile->Close(FoundFile);
					FreePool(FileInfo);
					break;
				}

				//
				// read the content
				//

				Status = FoundFile->Read(FoundFile, &FileSize, Buffer);

				//
				// if not errors
				//

				if (!EFI_ERROR(Status)) {

					//
					// looks like char16?
					//

					BOOLEAN IsChar16 = LooksLikeChar16(Buffer, FileSize);

					//
					// if is char16
					//

					if (IsChar16) {

						//
						// execute it
						//

						return (CHAR16*)Buffer;
					}

					//
					// if is a char8
					//

					else {
						//
						// convert it
						//
						CHAR16* Converted = AsciiToChar16((UINT8*)Buffer, FileSize);

						//
						// and execute it
						//

						return Converted;
					}

				}

				//
				// free the buffer
				//

				FreePool(Buffer);

				//
				// close file and delete the info
				//

				FoundFile->Close(FoundFile);
				FreePool(FileInfo);
				return;
			}
		}

		//
		// free the info
		//

		FreePool(FileInfo);
	}

	//
	// if the root is open close it
	//

	if (Root) Root->Close(Root);

	SetScreenAtribute(0, brred);
	printc(L"File not founded\n");
}


/**
* DrawLogo
* 
* draws the logo of the kellybootloader
* 
* @param X: is the position x of the logo to draw
* @param Y: is the position y of the logo to draw
*/
VOID DrawLogo()
{
	int popsize = Conio->atributes->size;

	Conio->atributes->size = 2;

	int popx = cursorx;
	int popy = cursory;

	gotoxy(((GET_MAX_COL - (StrLen(L"KellyBootloader")) + 3) / 2), (GET_MAX_ROWS / 2));

	SetScreenAtribute(0, brgreen);
	printc(L"KellyBootloader");

	DrawBitMapImage(ErickCraftStudiosLogo, 44, 49, (horizontalResolution - 44 - (StrLen(L"KellyBootloader") * 16)) / 2, (verticalResolution - 49) / 2, 2156);

	Conio->atributes->size = popsize;

	cursorx = popx;
	cursory = popy;
}

/**
* CommandPrompt
* 
* a command prompt that follow the EBF-SPC specifications
*/
VOID CommandPrompt()
{
	PIXELCOL Background = { 39, 55, 36, 0 };

	SetScreenAtribute(1, Background);
	ClearScreen();

	DrawLogo();

	//
	// loop
	//
	while (true)
	{
		//
		// draw prompt
		//

		SetScreenAtribute(0, brgreen);
		printc(L"Kelly");
		SetScreenAtribute(0, brblue);
		printc(L"Bootloader");
		SetScreenAtribute(0, gray);
		printc(L"> ");

		//
		// read line
		//

		CHAR16* FileName = ReadLineSeriusWorck();

		//
		// next line
		//

		printc(L"\n");

		//
		// process command
		//

		if (StrCmp(FileName, L"") != 0) {

			//
			// ls
			// 
			// list files
			//
			if (StrCmp(FileName, L"ls") == 0) {
				ListFiles();
			}

			//
			// cls
			// 
			// clears the screen
			//
			else if (
				StrCmp(FileName, L"cls") == 0
				)
			{
				ClearScreen();
				printc(L"\n");

			}

			//
			// exit
			// 
			// exit from the command prompt
			//
			else if (
				StrCmp(FileName, L"exit") == 0
				)
			{
				return;
			}

			//
			// reboot
			// 
			// reboots the system
			//
			else if (
				StrCmp(FileName, L"reboot") == 0
				)
			{
				gRT->ResetSystem(EfiResetWarm, EFI_SUCCESS, 0, 0);
			}

			//
			// smod [mode]
			// 
			// sets the screen size
			//
			else if (
				StrnCmp(FileName, L"smod ", 5) == 0
				)
			{
				Conio->atributes->size = Atoi(FileName + 5);
			}

			//
			// shutdown
			// 
			// turn off the pc
			//
			else if (
				StrCmp(FileName, L"shutdown") == 0
				)
			{
				gRT->ResetSystem(EfiResetShutdown, EFI_SUCCESS, 0, 0);
			}

			//
			// _DIRECTO_
			// 
			// shows the mems
			//
			else if (
				StrCmp(FileName, L"_DIRECTO_") == 0
				)
			{
				EstarEnDirecto();
			}

			else if (
				StrnCmp(FileName, L"edit ", 5) == 0
				)
			{
				editor(globalimagehandle, globalsystemtable, StrReplace(GetFileContent(FileName + 5), L"\r", L""));
			}

			//
			//
			//
			else if (
				StrCmp(FileName, L"GettingStarted") == 0
				)
			{
				editor(globalimagehandle, globalsystemtable, L"EA\n;ASM\n");
			}

			//
			// executing programs
			// 
			// execute a binary
			//
			else if (StrnCmp(FileName, L"./", 2) == 0) {
				
				//
				// configure params
				//

				UINTN ParamsCount = 0;
				CHAR16** Params = SplitChs(FileName + 2, &ParamsCount, L" ");

				//
				// configure the vars
				//

				u64 pos_write = 3001;
				u64 pos_n_write = 3001;

				//
				// loop the params
				//

				for (size_t i = 1; i < ParamsCount; i++)
				{
					//Print(L"ParamId: %d Value: %s\n", i, Params[i]);
					memory_acces[pos_write] = AllocateStringMemory(Params[i]);

					//Print(L"%s",LocateMemory(memory_acces[pos_write]));
					pos_write++;
				}

				//
				// configure the position end of the pools, params, specifiqued in EBF-SPC-006
				//

				u64 pos_end_write = pos_write;

				//
				// boot the file
				//

				BootSpecific(FileName + 2, FALSE);
				printc(L"\n\n");

				//
				// free the pools
				//

				for (size_t i = pos_n_write; i < (pos_end_write + 1); i++)
				{
					FillMemorySpaces(memory_acces[i], memory_acces[i] + memory_acces[memory_acces[i]], 0);
				}
			}

			//
			// debug
			// 
			// debug the binary execution in run time step by step
			//
			else if (StrnCmp(FileName, L"debug ", 6) == 0) {

				//
				// configure params
				//

				UINTN ParamsCount = 0;
				CHAR16** Params = SplitChs(FileName + 2, &ParamsCount, L" ");

				//
				// configure the vars
				//

				u64 pos_write = 3001;
				u64 pos_n_write = 3001;

				//
				// loop the params
				//

				for (size_t i = 1; i < ParamsCount; i++)
				{
					//Print(L"ParamId: %d Value: %s\n", i, Params[i]);
					memory_acces[pos_write] = AllocateStringMemory(Params[i]);

					//Print(L"%s",LocateMemory(memory_acces[pos_write]));
					pos_write++;
				}

				//
				// configure the position end of the pools, params, specifiqued in EBF-SPC-006
				//

				u64 pos_end_write = pos_write;

				//
				// boot the file
				//

				BootSpecific(FileName + 6, TRUE);
				printc(L"\n\n");

				//
				// free the pools
				//

				for (size_t i = pos_n_write; i < (pos_end_write + 1); i++)
				{
					FillMemorySpaces(memory_acces[i], memory_acces[i] + memory_acces[memory_acces[i]], 0);
				}
			}
		}
	}
}

/**
* BootMenu
* 
* the boot menu
*/
VOID BootMenu()
{
	Conio->atributes->size = 2;
	UINTN Event;
	EFI_INPUT_KEY Key;

	t64 scroll = 0;

	t64 Option = 0;

	PIXELCOL Background = { 39, 55, 36, 0 };
	PIXELCOL BackgroundSelected = { 56, 80, 52, 0 };

	PIXELCOL Bars = { 35, 35, 35, 0 };

	string* OptionBackground = AllocatePool(sizeof(string) * ((GET_MAX_COL - 4) + 1));

	for (size_t i = 0; i < GET_MAX_COL - 4; i++)
	{
		OptionBackground[i] = L' ';
	}
	OptionBackground[GET_MAX_COL - 4] = L'\0';

	string* tcm = AllocatePool(sizeof(string) * ((GET_MAX_COL) + 1));

	for (size_t i = 0; i < GET_MAX_COL - 4; i++)
	{
		tcm[i] = L' ';
	}

	tcm[(INTN)GET_MAX_COL] = L'\0';

	while (true) {

		SetScreenAtribute(1, Background);
		ClearScreen();

		SetScreenAtribute(0, gray);

		//
		// configure the status variable
		//
		EFI_STATUS Status;

		//
		// configure the files
		//

		EFI_FILE_PROTOCOL* Root;
		EFI_FILE_PROTOCOL* FoundFile = NULL;
		EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
		EFI_FILE_INFO* FileInfo;

		//
		// configure others
		//

		UINTN BufferSize;
		CHAR16* BinExtension = L".ebf";

		bool_t booted = 0;

		//
		// locate fs
		//

		Status = gBS->LocateProtocol(&gEfiSimpleFileSystemProtocolGuid, NULL, (VOID**)&FileSystem);
		if (EFI_ERROR(Status)) return;

		//
		// open fs
		//

		Status = FileSystem->OpenVolume(FileSystem, &Root);
		if (EFI_ERROR(Status)) return;

		//
		// read the root
		//

		t64 mm = 0;

		SetScreenAtribute(0, Bars);
		SetScreenAtribute(1, Bars);

		cursory = 0;

		printcu(tcm);
		cursory++;
		cursorx = 0;
		printcu(tcm);
		cursorx = 0;
		SetScreenAtribute(0, white);
		SetScreenAtribute(1, Bars);
		printcu(L"   KellyBootloader BootMenu");
		cursorx = 0;
		SetScreenAtribute(0, Bars);
		SetScreenAtribute(1, Bars);
		cursory++;
		cursorx = 0;
		printcu(tcm);
		cursory++;
		cursory++;

		int miny = cursory;
		cursory -= scroll;

		while (TRUE) {
			//
			// configure info
			//

			BufferSize = SIZE_OF_EFI_FILE_INFO + 512;
			FileInfo = AllocateZeroPool(BufferSize);

			//
			// if not file info
			//

			if (!FileInfo) break;

			//
			// makes the read file
			//

			Status = Root->Read(Root, &BufferSize, FileInfo);
			if (EFI_ERROR(Status) || BufferSize == 0) {
				FreePool(FileInfo);
				break;
			}

			//
			// set the name
			//

			CHAR16* Name = FileInfo->FileName;

			//
			// configure lenght
			//

			UINTN Len = StrLen(Name);

			if (Len > 4 && StrnCmp(&Name[Len - 4], BinExtension, 4) == 0) {

				cursorx = 2;

				SetScreenAtribute(1, Background);
				SetScreenAtribute(0, gray);

				if (mm == (Option))
				{
						SetScreenAtribute(1, BackgroundSelected);
						SetScreenAtribute(0, BackgroundSelected);
					if (cursory > miny - 1 && cursory < GET_MAX_ROWS - 2) {
						printcu(OptionBackground);
						SetScreenAtribute(0, brgreen);
					}

					if (Key.UnicodeChar == CHAR_CARRIAGE_RETURN)
					{
						SetScreenAtribute(1, black);
						SetScreenAtribute(0, gray);
						Conio->atributes->size = 1;

						ClearScreen();

						/*
						SetScreenAtribute(1, Background);
						ClearScreen();

						DrawLogo();
						SetScreenAtribute(0, gray);

						DrawScreen();*/

						BootSpecific(Name, 0);
						gST->BootServices->WaitForEvent(1, &gST->ConIn->WaitForKey, &Event);
						gST->ConIn->ReadKeyStroke(gST->ConIn, &Key);

						booted = 1;

						Conio->atributes->size = 2;
						break;
					}
				}

				cursorx = 2;

				if ((cursory > miny - 1) && cursory < GET_MAX_ROWS - 2) {

					printcu(L"* ");
					printcu(Name);
				}

				printcu(L"\n");

				mm++;
			}

			//
			// free the info
			//

			FreePool(FileInfo);
		}

		//
		// if the root is open close it
		//

		if (Root) Root->Close(Root);

		SetScreenAtribute(1, Background);

		gotoxy(0,GET_MAX_ROWS - 1);
		SetScreenAtribute(0, white);
		cursorx = 0;
		SetScreenAtribute(0, Bars);
		SetScreenAtribute(1, Bars);
		printcu(tcm);
		cursorx = 0;
		SetScreenAtribute(0, white);
		printcu(L"F2=MEMEDIT F3=CMD ENTER=OK");
		SetScreenAtribute(1, Background);

		DrawBitMapImage(ErickCraftStudiosLogo, 44, 49, 0, 5, 2156);

		DrawScreen();

		Key.UnicodeChar = L'\0';

		if (
			booted == 0
			)
		{
			gST->BootServices->WaitForEvent(1, &gST->ConIn->WaitForKey, &Event);
			gST->ConIn->ReadKeyStroke(gST->ConIn, &Key);
		}

		if (booted == 1)
		{

		}
		else if (Key.UnicodeChar == CHAR_CARRIAGE_RETURN)
		{

		}
		else if (
			Key.ScanCode == SCAN_F2
			)
		{
			EstarEnDirecto();
		}
		else if (Key.ScanCode == SCAN_F3)
		{
			SetScreenAtribute(1, black);
			SetScreenAtribute(0, gray);
			Conio->atributes->size = 1;
			ClearScreen();

			CommandPrompt();
			Conio->atributes->size = 2;

		}
		else if (
			Key.ScanCode == SCAN_PAGE_UP
			)
		{
			scroll--;
		}
		else if (
			Key.ScanCode == SCAN_PAGE_DOWN
			)
		{
			scroll++;
		}
		else if (Key.ScanCode == SCAN_UP) {
			if (Option != 0)
			{
				Option--;

				if (
					((Option - scroll) < 0)
					)
				{
					scroll--;

					if (scroll == -1)
					{
						scroll = 0;
					}
				}
			}
		}
		else if (Key.ScanCode == SCAN_DOWN)
		{
			Option++;

			if (
				(Option - scroll) > (GET_MAX_ROWS - 7)
				)
			{
				scroll++;
			}
		}
	}
}

/**
* efi_main
* 
* the main point of the bootloader
*/
EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	//
	// configure vars
	//

	EFI_STATUS Status;
	EFI_EVENT Event;

	//
	// init lib
	//

	InitializeLib(ImageHandle, SystemTable);

	//
	// set global params
	//

	globalimagehandle = ImageHandle;
	globalsystemtable = SystemTable;

	//
	// makes that the watchdog dont fucking me every day
	//

	Status = gBS->SetWatchdogTimer(0, 0, 0, NULL);

	//
	// prepare the grapichs outpud for the console custom colors
	//

	EFI_PHYSICAL_ADDRESS FrameBufferBase = gop->Mode->FrameBufferBase;
	UINTN FrameBufferSize = gop->Mode->FrameBufferSize;

	// set the screen size
	SystemTable->ConOut->QueryMode(SystemTable->ConOut, SystemTable->ConOut->Mode->Mode, &horizontalResolution, &verticalResolution);

	// get the gop
	Status = uefi_call_wrapper(BS->LocateProtocol, 3, &gEfiGraphicsOutputProtocolGuid, NULL, (VOID**)&gop);

	// The platform logo may still be displayed → remove it
	SystemTable->ConOut->ClearScreen(SystemTable->ConOut);

	gop->SetMode(gop, 1);

	ChangeToTextMode();

	PrintLineWithBackground(SystemTable, L"KellyBootloader anti display bugs text", 0, EFI_BLACK, EFI_BACKGROUND_LIGHTGRAY);
	gST->ConOut->ClearScreen(gST->ConOut);

	//
	// initializes the virtual screen
	//

	PIXELCOL Background = { 39, 55, 36, 0 };

	initializeMoonScreen();
	SetScreenAtribute(1,Background);
	ClearScreen();

	DrawLogo();

	gotoxy(0, 0);

	SetScreenAtribute(0, gray);
	printc(L"\nWelcome to the ");
	SetScreenAtribute(0, brgreen);
	printc(L"KellyBootloader ");
	SetScreenAtribute(0, gray);
	printc(L"\nMaded by ");
	SetScreenAtribute(0, brblue);
	printc(L"ErickCraftStudios\n\n");
	SetScreenAtribute(0, gray);

	EFI_INPUT_KEY Key;

	gBS->Stall(1000000);

	gST->ConIn->ReadKeyStroke(gST->ConIn, &Key);

	if (Key.ScanCode != SCAN_ESC)
	TryBootErickBinarie();

	SetScreenAtribute(0, yellow);
	printc(L"\nNothing to boot :(\n");

	/*
	SystemTable->ConIn->Reset(SystemTable->ConIn, FALSE);
	SystemTable->BootServices->WaitForEvent(1, &SystemTable->ConIn->WaitForKey, &Event);
	*/

	printc(L"\n");

	BootMenu();

	/*
	while (true)
	{
		SetScreenAtribute(0, brgreen);
		printc(L"Kelly");
		SetScreenAtribute(0, brblue);
		printc(L"Bootloader");
		SetScreenAtribute(0, gray);
		printc(L"> ");

		CHAR16* FileName = ReadLineSeriusWorck();

		printc(L"\n");

		if (StrCmp(FileName, L"") != 0) {
			if (StrCmp(FileName, L"ls") == 0) {
				ListFiles();
			}
			else if (
				StrCmp(FileName, L"cls") == 0
				)
			{
				ClearScreen();
				printc(L"\n");

			}
			else if (
				StrCmp(FileName, L"retry") == 0
				)
			{
				SetScreenAtribute(0, gray);
				TryBootErickBinarie();
			}
			else if (
				StrCmp(FileName, L"reboot") == 0
				)
			{
				gRT->ResetSystem(EfiResetWarm, EFI_SUCCESS, 0, 0);
			}
			else if (StrnCmp(FileName,L"./",2) == 0) {
				BootSpecific(FileName + 2, FALSE);
			}
			else if (StrnCmp(FileName, L"debug ", 6) == 0) {
				BootSpecific(FileName + 6, TRUE);
			}
		}
	}
	*/

	return EFI_SUCCESS;
}

KellyBootloader
==============

Kelly Bootloader is a bootloader maded by ErickCraftStudios, that can boot files in .bin format with the ErickBinaryFormat

you can call it `kelly` or `ErickCraftStudios Bootloader`

# Features
  * a simple bootloader
  * a binary format and opcodes
  * system calls
  * a minimal command prompt

# Setuping your programs

For make your programs you need to follow the next steps
  * know ErickAssembly instructions, is very easy that the normal assemby
  * compile the ErickAssembly compiler that the code of the ErickAssembler is in https://github.com/ErickStudios/S-SUN/blob/main/kernel/usr/sasm/sasm/compiler.cs and setup the compilation, making a prompt , or donwload the content of the folder https://github.com/ErickStudios/S-SUN/tree/main/kernel/usr/sasm/sasm for have a base, the C# for linux tutorial you have to search it because i forget it how compile C# in linux
  * compile your programs and move it to the `image` folder (create it if you dont have it)

and you need to
  * download qemu , for execute the bootloader
  * compile with makefile
  * download the OVMF_X64.fd

# making OSes

you can make a operating system writen in ErickAssembly, because ErickAssembly is more easy than the normal assembly, but you need to know the next:
  * for know version, you can acces to the real ram
  * the binary is slowest that pure assembly
  * your os has been avaible on all devices that supports the bootloader

but , hey , if you programming your os with ErickAssembly you been join to the KellyBootloader oses comunity
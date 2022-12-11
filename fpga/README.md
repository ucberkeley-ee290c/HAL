# FPGA Prototyping

Currently supported boards:

[Diligent Arty Artix-7 35-T Development Board](https://digilent.com/shop/arty-a7-artix-7-fpga-development-board/?utm_source=google&utm_medium=cpc&utm_campaign=18640327811&utm_content=141995398465&utm_term=arty%20fpga&gclid=CjwKCAiA-dCcBhBQEiwAeWidtb5WqGx8h-ij7-UbXwRscDQpmdEGXkrTgn7w1gvMkeVnVyAyvvrOZRoC-jUQAvD_BwE)

[Diligent Arty Artix-7 100-T Development Board](https://digilent.com/shop/arty-a7-artix-7-fpga-development-board/?utm_source=google&utm_medium=cpc&utm_campaign=18640327811&utm_content=141995398465&utm_term=arty%20fpga&gclid=CjwKCAiA-dCcBhBQEiwAeWidtb5WqGx8h-ij7-UbXwRscDQpmdEGXkrTgn7w1gvMkeVnVyAyvvrOZRoC-jUQAvD_BwE)

[Diligent Cmod 35-T Breadboardable Module](https://digilent.com/shop/cmod-a7-35t-breadboardable-artix-7-fpga-module/)

Planning to support:

[Terasic MAX 10 Plus](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&CategoryNo=218&No=1223&PartNo=1#contents)

[Terasic DE-10 Standard Development Board](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&CategoryNo=165&No=1081&PartNo=1#contents)

## Bitsteam Catalog

### OsciArty

#### `osciarty_32MHz.bit`

OsciArty with core running at 32MHz (RV32IMAFC)

- UART should use 32MHz setting

- Serial-TileLink not working (TL_CLK signal direction is wrong). DO NOT CONNECT TL PORT.

#### `osciarty_148kHz.bit`

OsciArty with core running at 148kHz (RV32IMAFC)

- Serial-TileLink working at 148kHz

### TinyRocketArty

#### `tinyrocketarty.bit`

Default chipyard Arty bitstream. Core clock at 32MHz. (RV32IMAC)

#### `tinyrocketarty_UART_remapped.bit`

Default chipyard Arty bitstream with UART remapped to JTAG debugger. Core clock at 32MHz. (RV32IMAC)

### BearlyArty

#### `bearlyarty_1_rocket_1_saturn.bit`

Rocket core with accelerators and without FPU (RV64IMAC).

I2C connection is ja_1 == SCL, ja_0 == SDA.

|     |     |       |       |       | square pad |
| --- | --- | ----- | ----- | ----- | ---------- |
| 3V3 | GND | NC    | NC    | SCL   | SDA        |
| 3V3 | GND | NC    | NC    | NC    | NC         |

Saturn core cannot be JTAG probed. Any read returns a 0x01.

#### `bearlyarty_1_rocket_w_fpu.bit`

Single core Rocket core with accelerators and FPU (RV64IMAFC).

#### `bearlyarty_2_rocket.bit`

Dual Rocket core with accelerators (RV64IMAC).

Not working... JTAG cannot examine target.

## Wiring

Arty JD port

|     |     |       |       |       | square pad |
| --- | --- | ----- | ----- | ----- | ---------- |
| 3V3 | GND | NC    | TCK   | nTRST | TDO        |
| 3V3 | GND | NC    | nRST  | TMS   | TDI        |

Note: `nTRST` is JTAG reset, `nRST` is system reset. For a minimal set up, the two reset lines do not need to be connected.

![](img/jtag_connection.jpg)

## Software Setup

1. Download `osciarty.bit`

2. Open vivado, open hardware manager

![](img/vivado_hardware_manager.png)

3. Click "Open target" -> "Auto Connect"

![](img/vivado_auto_connect.png)

4. Click "Program device", then select the downloaded bitstream and click "Program"

![](img/vivado_program_device.png)

5. 

##### Windows

Open PowerShell in the folder, enter

```bash
cd ./jtag/
openocd.exe -f .\osciarty.cfg
```

And in another PowerShell terminal, enter

```bash
riscv64-unknown-elf-gdb.exe
```

It should prompt the following message

```bash
PS C:\Users\TK\Desktop\HAL\jtag> riscv64-unknown-elf-gdb.exe
D:\Documents\RISCV\riscv64-unknown-elf-toolchain-10.2.0-2020.12.8-x86_64-w64-mingw32\bin\riscv64-unknown-elf-gdb.exe: warning: Couldn't determine a path for the index cache directory.
GNU gdb (SiFive GDB-Metal 10.1.0-2020.12.7) 10.1
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "--host=x86_64-w64-mingw32 --target=riscv64-unknown-elf".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://github.com/sifive/freedom-tools/issues>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word".
(gdb)
```

Then, enter `target remote localhost:3333`

```bash
(gdb) target remote localhost:3333
Remote debugging using localhost:3333
warning: No executable has been specified and target does not support
determining executable automatically.  Try using the "file" command.
0x00010040 in ?? ()
(gdb)     
```

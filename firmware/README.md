


## 1. Environment Setup

### 1.1 Install RISCV Toolchain

Either SiFive toolchain or the riscv-collab toolchain works:

#### 1.1.a Install SiFive Toolchain

_Note: this toolchain only works on Linux and Mac OS (Mac to be confirmed)_

1. Download **GNU Embedded Toolchain — v2020.12.8** from SiFive's [website](https://www.sifive.com/software)

2. Extract the downloaded file to a known location, for example, `/home/tk/Documents/RISCV/riscv64-unknown-elf-toolchain-10.2.0-2020.12.8-x86_64-linux-ubuntu14/`

3. Add the `bin` folder inside the file location to PATH by 

```bash
$ export PATH="/home/tk/Documents/RISCV/riscv64-unknown-elf-toolchain-10.2.0-2020.12.8-x86_64-linux-ubuntu14/bin:$PATH" 
```

4. Now we should able to invoke gcc by the following command

```bash
$ riscv64-unknown-elf-gcc
riscv64-unknown-elf-gcc: fatal error: no input files
compilation terminated.   
```

#### 1.1.b Install riscv-collab/riscv-gnu-toolchain Toolchain

TODO: write this

### 1.2 Clone this repo

Clone this repo by running

```bash
$ git clone git@github.com:ucberkeley-ee290c/HAL.git
$ cd HAL
```

## 2. Edit Makefile

Open `firmware/Makefile`, under the "RISCV Toolchain" section, uncomment the prefix of the toolchain you are using.

```Makefile
#################################
# RISCV Toolchain
#################################

# SiFive Toolchain
PREFIX = riscv64-unknown-elf-

# Nuclei Toolchain
# PREFIX = riscv-nuclei-elf-

# xPack Toolchain
# when using this, MCU arch should be `ARCH = rv32imafc_zicsr`
# PREFIX = riscv-none-elf-
```

## 3. Compile

```bash
$ cd firmware
$ make
...
[CC] compiling build/bsp/oscibear/src/oscibear_hal_baseband.o
[CC] compiling build/bsp/oscibear/src/oscibear_hal_clint.o
[CC] compiling build/bsp/oscibear/src/oscibear_hal_gpio.o
[CC] compiling build/bsp/oscibear/src/oscibear_hal_plic.o
[CC] compiling build/bsp/oscibear/src/oscibear_hal_rcc.o
[CC] compiling build/bsp/oscibear/src/oscibear_hal_uart.o
[LD] linking build/firmware.elf
riscv64-unknown-elf-size build/firmware.elf
text    data     bss     dec     hex filename
10338     348    3676   14362    381a build/firmware.elf
```

## 4. Flash

### 4.a JTAG setup



### 4.b STM32 adapter TSI setup

### 4.c Arty adapter TSI setup



libddcci
========

Linux userspace library for monitor control via DDC/CI & VCP codes.

Many parts are adapted from [ddccontrol](http://ddccontrol.sourceforge.net/).

## Requirements

This library only supports use of the i2c devices exposed by graphics cards,
and doesn't try to do any of the pci direct memory access that ddccontrol uses.

## Building

    cmake .
    make

## Roadmap

1. support issuing commands to benq z-series monitors
  - create linux benq strobe utility
2. use polkit to gain access to i2c devices instead of requiring `sudo chmod a+rw /dev/i2c-*`
3. support controls covered by ddccontrol, hopefully with autodetection
  - probably update/fork ddccontrol to use this library
4. python & nodejs/iojs bindings
5. cross platform

## Design Philosophy

Userspace only.

## Troubleshooting

### Doesn't work on Nvidia cards?

Add to xorg.conf or xorg.conf.d:

    Section "Device"
        Identifier "Device0"
        Driver "nvidia"
        Option "RegistryDwords" "RMUseSwI2c=0x01; RMI2cSpeed=100"
    EndSection

[(source)](https://devtalk.nvidia.com/default/topic/572292/linux/-solved-does-gddccontrol-work-for-anyone-here-nvidia-i2c-monitor-display-ddc/3/)

## Notes

require i2ctools svn version
use include/i2c/smbus.h

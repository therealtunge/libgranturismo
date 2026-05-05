# libgranturismo
## a C++ library to work with custom format developed by Polyphony Digital for Gran Turismo games
originally made out of frustration for [GTAdhocToolchain](https://github.com/Nenkai/GTAdhocToolchain) not having an option to not convert textures into .png (i then realized it did have one but it was too late)

please ignore the texture code its all violently borked like wtf

# features
| name of file format | description | magic | support |
| ------ | ------ | ------ | ------ |
| GPB rev 2 | format to pack files (mainly menu assets) for GT3 / partially GT4 | "GPB2"/"2BPG" | unpack, pack planned
| GPB rev 3 | format to pack files (mainly menu assets) for GT4 / GT5 / GT6 | "GPB3"/"3BPG" | unpack, pack planned

# credits
test cases:
crc32 (https://github.com/eternalharvest/): for comparison against "known good" files
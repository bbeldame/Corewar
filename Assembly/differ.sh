#!/bin/sh/

./asm $1.s
hexdump $1.cor > me
./asm_zaz $1.s
hexdump $1.cor > zaz
diff me zaz
rm -rf me zaz

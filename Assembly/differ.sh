#!/bin/sh/

./asm test.s
hexdump test.cor > me
./asm_zaz test.s
hexdump test.cor > zaz
diff me zaz
rm -rf  me zaz

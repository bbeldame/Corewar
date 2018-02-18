#!/bin/sh/

make

echo "\n\033[31m=== TEST EXTENSION: \033[00m\n"
../asm unit_test/file/bad_extension.txt
../asm unit_test/file/good_extension.s

echo "\n\033[31m=== TEST HEADER: \033[00m\n"

../asm unit_test/header/E_only_name.s
echo "\n===========\n"
../asm unit_test/header/E_empty_name.s
echo "\n===========\n"
../asm unit_test/header/E_only_comment.s
echo "\n===========\n"
../asm unit_test/header/E_empty_name.s
echo "\n===========\n"
../asm unit_test/header/E_char_in_head.s
echo "\n===========\n"
../asm unit_test/header/good_header.s

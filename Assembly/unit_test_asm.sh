#!/bin/sh/

make

echo "\033[33m=== TEST Divers: \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/file/bad_extension.txt
./asm unit_test/unknow.s
echo "\033[32m=== OK : \033[00m"
./asm unit_test/file/good_extension.s

sleep 3
echo "\n\033[33m=== TEST HEADER: \033[00m"

echo "\033[31m=== erreur: \033[00m"
./asm unit_test/header/E_only_name.s
echo "==========="
./asm unit_test/header/E_empty_name.s
echo "==========="
./asm unit_test/header/E_only_comment.s
echo "==========="
./asm unit_test/header/E_empty_name.s
echo "==========="
./asm unit_test/header/E_char_in_head.s
echo "\033[32m=== OK : \033[00m"
./asm unit_test/header/good_header.s
sleep 3
echo "\n\033[33m=== TEST BODY: \033[00m"

echo "\n\033[33m live \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/live/e_no_param.s
./asm unit_test/body/live/e_too_many_instruction.s
echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/live/g_live.s

echo "\n\033[33m ld \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/ld/e_ld_1.s
./asm unit_test/body/ld/e_ld_2.s
./asm unit_test/body/ld/e_ld_3.s
./asm unit_test/body/ld/e_ld_4.s
./asm unit_test/body/ld/e_ld_5.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/ld/g_ld_1.s
./asm unit_test/body/ld/g_ld_2.s

echo "\n\033[33m st \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/st/e_st_1.s
./asm unit_test/body/st/e_st_2.s
./asm unit_test/body/st/e_st_3.s
./asm unit_test/body/st/e_st_4.s
./asm unit_test/body/st/e_st_5.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/st/g_st_1.s
./asm unit_test/body/st/g_st_2.s


echo "\n\033[33m add \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/add/e_add_1.s
./asm unit_test/body/add/e_add_2.s
./asm unit_test/body/add/e_add_3.s
./asm unit_test/body/add/e_add_4.s
./asm unit_test/body/add/e_add_5.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/add/g_add_1.s

sleep 3
echo "\n\033[33m sub \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/sub/e_sub_1.s
./asm unit_test/body/sub/e_sub_2.s
./asm unit_test/body/sub/e_sub_3.s
./asm unit_test/body/sub/e_sub_4.s
./asm unit_test/body/sub/e_sub_5.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/sub/g_sub_1.s


echo "\n\033[33m and \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/and/e_and_1.s
./asm unit_test/body/and/e_and_2.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/and/g_and_1.s


echo "\n\033[33m or \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/or/e_or_1.s
./asm unit_test/body/or/e_or_2.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/or/g_or_1.s


echo "\n\033[33m xor \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/xor/e_xor_1.s
./asm unit_test/body/xor/e_xor_2.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/xor/g_xor_1.s


echo "\n\033[33m zjmp \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/zjump/e_zjump_1.s
./asm unit_test/body/zjump/e_zjump_2.s
./asm unit_test/body/zjump/e_zjump_3.s
./asm unit_test/body/zjump/e_zjump_4.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/zjump/g_zjump_1.s
sleep 3
echo "\n\033[33m ldi \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/ldi/e_ldi_1.s
./asm unit_test/body/ldi/e_ldi_2.s
./asm unit_test/body/ldi/e_ldi_3.s
./asm unit_test/body/ldi/e_ldi_4.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/ldi/g_ldi_1.s


echo "\n\033[33m sti \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/sti/e_sti_1.s
./asm unit_test/body/sti/e_sti_2.s
./asm unit_test/body/sti/e_sti_3.s
./asm unit_test/body/sti/e_sti_4.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/sti/g_sti_1.s


echo "\n\033[33m fork \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/fork/e_fork_1.s
./asm unit_test/body/fork/e_fork_2.s
./asm unit_test/body/fork/e_fork_3.s
./asm unit_test/body/fork/e_fork_4.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/fork/g_fork_1.s


echo "\n\033[33m lld \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/lld/e_lld_1.s
./asm unit_test/body/lld/e_lld_2.s
./asm unit_test/body/lld/e_lld_3.s
./asm unit_test/body/lld/e_lld_4.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/lld/g_lld_1.s


echo "\n\033[33m lldi \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/lldi/e_lldi_1.s
./asm unit_test/body/lldi/e_lldi_2.s
./asm unit_test/body/lldi/e_lldi_3.s
./asm unit_test/body/lldi/e_lldi_4.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/lldi/g_lldi_1.s


echo "\n\033[33m lfork \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/lfork/e_lfork_1.s
./asm unit_test/body/lfork/e_lfork_2.s
./asm unit_test/body/lfork/e_lfork_3.s
./asm unit_test/body/lfork/e_lfork_4.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/lfork/g_lfork_1.s


echo "\n\033[33m aff \033[00m"
echo "\033[31m=== erreur: \033[00m"
./asm unit_test/body/aff/e_aff_1.s
./asm unit_test/body/aff/e_aff_2.s
./asm unit_test/body/aff/e_aff_3.s

echo "\033[32m=== OK : \033[00m"
./asm unit_test/body/aff/g_aff_1.s


echo "\033[32m=== All instruction OK : \033[00m"
./asm unit_test/body/good/all_instruction_valide.s

echo "\n\033[33m=== TEST champion : \033[00m"
echo "\033[32m=== Ressource corewar : \033[00m"

echo "\033[35m 42.s \033[00m"
./asm unit_test/champs_ope/42.s
echo "\033[35m Backward.s \033[00m"
./asm unit_test/champs_ope/Backward.s
echo "\033[35m barriere.s \033[00m"
./asm unit_test/champs_ope/barriere.s
echo "\033[35m Car.s \033[00m"
./asm unit_test/champs_ope/Car.s
echo "\033[35m Torpille.s \033[00m"
./asm unit_test/champs_ope/Torpille.s

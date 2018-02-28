.name "zork"
.comment "I'M ALIIIIVE"

testlabel: live %1

ldi r1, r2, r3
ldi r1, %1, r3

ldi %:testlabel, r2, r3
ldi %:testlabel, %1, r3

ldi %1, r2, r3
ldi %1, %1, r3

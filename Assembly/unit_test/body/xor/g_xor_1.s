.name "zork"
.comment "I'M ALIIIIVE"

testlabel: live %1

xor r1, r2, r3
xor r1, %:testlabel, r3
xor r1, %1, r3

xor %1, r2, r3
xor %1, %:testlabel, r3
xor %1, %1, r3

xor %:testlabel, r2, r3
xor %:testlabel, %:testlabel, r3
xor %:testlabel, %1, r3

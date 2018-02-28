.name "zork"
.comment "I'M ALIIIIVE"

testlabel: live %1

sti r1, r2, r3
sti r1, r2, %2
sti r1, %1, r3
sti r1, %1, %2
sti r1, %:testlabel , r3
sti r1, %:testlabel , %2

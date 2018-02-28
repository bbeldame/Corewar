.name "zork"
.comment "I'M ALIIIIVE"

testlabel: live %1

or r1, r2, r3
or r1, %:testlabel, r3
or r1, %1, r3

or %1, r2, r3
or %1, %:testlabel, r3
or %1, %1, r3

or %:testlabel, r2, r3
or %:testlabel, %:testlabel, r3
or %:testlabel, %1, r3

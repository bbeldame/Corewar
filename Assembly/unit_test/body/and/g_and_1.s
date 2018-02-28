.name "zork"
.comment "I'M ALIIIIVE"

testlabel: live %1

and r1, r2, r3
and r1, %:testlabel, r3
and r1, %1, r3

and %1, r2, r3
and %1, %:testlabel, r3
and %1, %1, r3

and %:testlabel, r2, r3
and %:testlabel, %:testlabel, r3
and %:testlabel, %1, r3

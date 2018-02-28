.name "zork"
.comment "I'M ALIIIIVE"

test: live %1

lldi r1, r2, r3
lldi r1, %2, r3
lldi %2, r2, r3
lldi %2, %3, r3
lldi %:test, r2, r3
lldi %:test, %3, r3

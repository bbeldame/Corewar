.name "zork"
.comment "I'M ALIIIIVE"

testlabel: live %1

live %1

ld %1, r1
ld %:testlabel, r1

st r1, r2
#st r1, %:3

add r1, r2, r3

sub r1, r2, r3

and r1, r2, r3
and r1, %:testlabel, r3
and r1, %1, r3

and %1, r2, r3
and %1, %:testlabel, r3
and %1, %1, r3

and %:testlabel, r2, r3
and %:testlabel, %:testlabel, r3
and %:testlabel, %1, r3

or r1, r2, r3
or r1, %:testlabel, r3
or r1, %1, r3

or %1, r2, r3
or %1, %:testlabel, r3
or %1, %1, r3

or %:testlabel, r2, r3
or %:testlabel, %:testlabel, r3
or %:testlabel, %1, r3

xor r1, r2, r3
xor r1, %:testlabel, r3
xor r1, %1, r3

xor %1, r2, r3
xor %1, %:testlabel, r3
xor %1, %1, r3

xor %:testlabel, r2, r3
xor %:testlabel, %:testlabel, r3
xor %:testlabel, %1, r3

wall:
		live%1
		zjmp %:wall

ldi r1, r2, r3
ldi r1, %1, r3

ldi %:testlabel, r2, r3
ldi %:testlabel, %1, r3

ldi %1, r2, r3
ldi %1, %1, r3

sti r1, r2, r3
sti r1, r2, %2
sti r1, %1, r3
sti r1, %1, %2
sti r1, %:testlabel , r3
sti r1, %:testlabel , %2

fork %2

lld %2, r1
lld %:testlabel , r1

lldi r1, r2, r3
lldi r1, %2, r3
lldi %2, r2, r3
lldi %2, %3, r3
lldi %:testlabel, r2, r3
lldi %:testlabel, %3, r3

lfork %2

aff r1

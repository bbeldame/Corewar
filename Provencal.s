.name "Provencal"
.comment "f"

fork %24

l1:
	sti r1, %:live, %1
	and r1, %0, r2

live:
	live %1
	zjmp %:live

	sti r1, %:live2, %1
live2:
	live %1
	fork %20000

	sti r1, %:aff, %1
	and r1, %0, r2
aff:
	live %1
	ld %99, r2
	ld %111, r3
	ld %117, r4
	ld %0, r5
	aff r2
	aff r3
	aff r4
	aff r2
	aff r3
	aff r4
	aff r5
	zjmp %:aff

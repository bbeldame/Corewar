.name "zork"
dgg
.comment "I'M ALIIIIVE"

l2:	sti r1, %:live, %1


live:
	live %1
 	zjmp %:live

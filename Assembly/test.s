.name "coucou"
.comment " "

l2: sti		r1, %:live, %1 #kfkf
	and r1, %0, r1
 live %0 # lrlr5,10,271

live:
	live %1
	zjmp %:live

.name		"basic"
.comment	"this type a basic stuff"

loop:
	st r1, 6
	live %0
	ld %0, r2
	zjmp %:loop

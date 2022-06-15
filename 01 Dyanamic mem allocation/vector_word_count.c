/*
	#Excersizef
	Word counting
*/

fgets(line, 225, stdin)

/*
	count the number of words in line and print them 
	while traversing through the line
	initialally you are OUTSIDE ANY WORD . (state = OUT | IN)

	state ->OUT -> NON-WHITESPACE CHAR ->state ->(OUT->IN) ->nr_word ++
	state->OUT ->WHITE-SPACE CHAR ->STATE ->OUT ->DO NOTHING

	state -> IN ->NON_WHITESPACE CHAR -> state ->IN ->DO NOTHING
	state -> IN -> WHITESPACE CHAR -> state->(IN->OUT)

	(make use of ctype.h headerfor charcter classify)  
*/

 
/*
 * CodeConventions.c
 *
 * Created: 9/7/2013 10:10:52 PM
 *  Author: Elmar
 */ 

 static int foo(void);
 
 /*! \brief Return a Char.
 *	
 *	Longer detailed description (if needed).
 *  
 *	\param 	c Character to be returned.
 *
 *  \retval c Character to be returned.				       
 */
char returnChar(char c)
{
	return c;
}

char *getString(void)
{
	
}

void print(char *something)
{
	
}

void executeFunction(void (*function)(arg1, arg2))
{
	(*function)(x, y);
}

static int foo(void)
{
	return bar;
}

#if 0
foo();
bar();
printf("Not used code");
#endif
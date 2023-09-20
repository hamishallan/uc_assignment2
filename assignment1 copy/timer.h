// a1839619

# ifndef TIMER_H
# define TIMER_H

# define T3_RELOAD 39009 /* T3 reload value: 250 ms */

# define YES	1
# define NO		0

//T3CON Settings
# define	T3I	4
# define	T3M	8
# define	UD_CONTROL (NO)
# define	EX_UD_ENABLE	(NO)
# define	ALT_OUT_FUNC_ENABLE	(NO)

void T3Init();

void StartT3();

# endif
# Standard C library

This library is written in a way that conforms to standard of ANSI C 
(also known as C89, C90, iso9899:1990) with Normative Addendum 1 (NA1).

## Compatibility:

```
- <ctype.h> 	Fully compatible
- <errno.h>	Fully compatible
- <iso646.h>    Fully compatible
- <stdarg.h>	Fully compatible
- <stddef.h>    Fully compatible
- <limits.h>	Fully compatible
- <string.h>	Partialy compatible (1)
- <math.h>	Partialy implemented
- <stdio.h>	Partialy implemented
- <stdlib.h>	Partialy implemented
- <time.h>	Partialy implemented
- <float.h>	Not implemented
- <setjmp.h>	Not implemented
- <tgmath.h>	Not implemented
- <wchar.h>	Not implemented
- <wctype.h>	Not implemented
- <assert.h>	Not compatible
- <locale.h>	Not compatible
- <signal.h>	Not compatible
```

	1) All functions are implemented, excluding strtok(), strcoll() 
		and strxfrm(), because they too depend on operating system.
		

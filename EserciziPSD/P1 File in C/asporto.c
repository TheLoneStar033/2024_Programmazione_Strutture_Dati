#include <stdio.h>
#include <stdlib.h>

char asporto(char *s, char *t, char *z)
{
	char *pt=t,*ps=s;
	for(;*s==*t;*s++,*t++);
	//printf("%c %c",*s,*t);
	
    for(;*pt;*pt++);
	for(;*ps;*ps++);
	//printf("ps:%c pt%c",*ps,*pt);
	
	for(;*(ps-1)==*(pt-1);ps--,pt--);
		//printf("ps:%c pt%c",*ps,*pt);
	
	while(s<ps)
	{
	printf("z: %c ",*z);
	printf("s: %c ",*s);
	*z=*s;
	s++;
	z++;
    }
    while(t<pt)
    {
     printf("z: %c ",*z);
	 printf("t: %c ",*t);
	 *z=*t;
	  t++;
	  z++;
	}
	//printf("z:%c",*z);
	
}

int main(int argc, char *argv[])
{
	char asporta[20];
	asporto(argv[1],argv[2],asporta);
}

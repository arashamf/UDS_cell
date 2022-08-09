#include "stm32f0xx_hal.h"
#include "wdt.h"

//tw = 7ms...26200ms
void InitWDT (unsigned int tw)
{
	
	IWDG->KR=0x00005555;
	IWDG->PR=0x00000007;
	IWDG->RLR=tw*40/256;
	IWDG->KR=0x0000AAAA;
	IWDG->KR=0x0000CCCC;	
}

void FeedWDT (void)
{
	IWDG->KR=0x0000AAAA;
}

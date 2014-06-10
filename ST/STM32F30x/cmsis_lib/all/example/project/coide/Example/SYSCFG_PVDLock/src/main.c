extern void SYSCFG_PVDLock(void);
int main(void)
{
	SYSCFG_PVDLock();
    while(1);
    return (0);
}

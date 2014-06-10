extern void GPIO_Example(void);
unsigned char uctemp = 0;

unsigned char a(unsigned char uctemp)
{
	uctemp++;
	return uctemp;
}
int main(void)
{
	uctemp = 0x81;
	uctemp = a(uctemp);
    GPIO_Example();
    while(1);
    return (0);
}

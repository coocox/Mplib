#include "config.h"
#include "nds32_intrinsic.h"
#ifdef USE_LM_DMA
#define LM_ILM 0
#define LM_DLM 1

#define DMA_SETUP_offLM     0	/* Local Memory Selection */
#define DMA_SETUP_offTDIR   1	/* Transfer Direction */
#define DMA_SETUP_offTES    2	/* Transfer Element Size */
#define DMA_SETUP_offESTR   4	/* External memory transfer Stride */
#define DMA_SETUP_offCIE    16	/* Interrupt Enable on Completion */
#define DMA_SETUP_offSIE    17	/* Interrupt Enable on explicit Stop */
#define DMA_SETUP_offEIE    18	/* Interrupt Enable on Error */
#define DMA_SETUP_offUE     19	/* Enable the Un-aligned External Address */
#define DMA_SETUP_off2DE    20	/* Enable the 2-D External Transfer */
#define DMA_SETUP_offCOA    21	/* Transfer Coalescable */
/* bit 22:31 reserved */

#define DMA_SETUP_mskLM     ( 0x1UL << DMA_SETUP_offLM )
#define DMA_SETUP_mskTDIR   ( 0x1UL << DMA_SETUP_offTDIR )
#define DMA_SETUP_mskTES    ( 0x3UL << DMA_SETUP_offTES )
#define DMA_SETUP_mskESTR   ( 0xFFFUL << DMA_SETUP_offESTR )
#define DMA_SETUP_mskCIE    ( 0x1UL << DMA_SETUP_offCIE )
#define DMA_SETUP_mskSIE    ( 0x1UL << DMA_SETUP_offSIE )
#define DMA_SETUP_mskEIE    ( 0x1UL << DMA_SETUP_offEIE )
#define DMA_SETUP_mskUE     ( 0x1UL << DMA_SETUP_offUE )
#define DMA_SETUP_msk2DE    ( 0x1UL << DMA_SETUP_off2DE )
#define DMA_SETUP_mskCOA    ( 0x1UL << DMA_SETUP_offCOA )
#endif

extern unsigned int _ILM_BASE;
extern unsigned int _ILM_SIZE;
extern unsigned int __text_start;
extern unsigned int __text_end;

extern unsigned int _DLM_BASE;
extern unsigned int _DLM_SIZE;
extern unsigned int __data_lmastart;
extern unsigned int __data_start;
extern unsigned int edata;

unsigned int g_ilm_size, g_dlm_size;

char *__itoa(int value, char *string, int radix)
{
	char tmp[33];
	char *tp = tmp;
	int i;
	unsigned v;
	int sign;
	char *sp;

	if (radix > 36 || radix <= 1) {
		//__set_errno(EDOM);
		puts("itoa error ....\n");
		return 0;
	}

	sign = (radix == 10 && value < 0);
	if (sign)
		v = -value;
	else
		v = (unsigned)value;
	while (v || tp == tmp) {
		i = v % radix;
		v = v / radix;
		if (i < 10)
			*tp++ = i + '0';
		else
			*tp++ = i + 'a' - 10;
	}

	/*if (string == 0)
	   string = (char *)malloc((tp-tmp)+sign+1); */

	sp = string;

	if (sign)
		*sp++ = '-';
	while (tp > tmp)
		*sp++ = *--tp;
	*sp = 0;
	return string;
}

void initValue(char *pValue, int count)
{
	int i;
	for (i = 0; i < count; i++)
		pValue[i] = '\0';
}

void printS(const char *msg, unsigned int value, int radix)
{
	char str_value[32];
	char *pValue;

	initValue(str_value, 32);
	pValue = __itoa(value, str_value, radix);
	puts(msg);
	puts((const char *)pValue);
	puts("\n");

}

#ifdef USE_LM_DMA
static void dma_read_status()
{
	unsigned int dma_cfg, dma_channel;

	dma_cfg = __nds32__mfsr(NDS32_SR_DMA_CFG);
	switch (dma_cfg & 0x3) {
	case 0:
		puts("There is 1 DMA channel\n");
		break;
	case 1:
		puts("There are 2 DMA channel\n");
		break;
	case 2:
		puts("Reserve\n");
		break;
	case 3:
		puts("Reserve\n");
		break;
	default:
		puts("out of dma_cfg\n");
	}
}

void dma_initial(int LM_TYPE)
{
	/* set DMA engine global enable bit to 1 */
	unsigned int dma_gcsw, dma_chnsel, dma_setup, dma_esaddr, dma_tcnt;
	volatile unsigned int size, source_addr, ilm_base, dlm_base;
	unsigned int dcm_cfg;
	dma_gcsw = __nds32__mfsr(NDS32_SR_DMA_GCSW);
	dma_gcsw |= (0x1 << 31);
	__nds32__mtsr(dma_gcsw, NDS32_SR_DMA_GCSW);

	/* Setup external start address */
	if (LM_TYPE == LM_ILM) {
		source_addr = (volatile unsigned int)0;	/* from address 0 */
	} else {
		dcm_cfg = __nds32__mfsr(NDS32_SR_DCM_CFG);
		if (dcm_cfg & 0x2000)	/* It can be LM size aligned. */
			source_addr =
			    (volatile unsigned int)(0x800000 - g_dlm_size);
		else {		/* It should be 1 MB aligned. */
			puts("Don't demo DLM\n");
			return;
		}
	}

	/* Select Channel */
	dma_chnsel = __nds32__mfsr(NDS32_SR_DMA_CHNSEL);
	dma_chnsel &= 0x0;
	dma_chnsel |= 0x1;	/* select channel 1 */
	__nds32__mtsr(dma_chnsel, NDS32_SR_DMA_CHNSEL);

	if (LM_TYPE == LM_ILM) {
		/* Set ILM base and enable it */
		ilm_base = &_ILM_BASE;
		ilm_base = ilm_base + 1;
		__nds32__mtsr(ilm_base, NDS32_SR_ILMB);
		__nds32__dsb();
		ilm_base = ilm_base - 1;
		size = &_ILM_SIZE;
	} else {		/* Set DLM base and enable it */
		/* Set DLM base and enable it */
		dlm_base = &_DLM_BASE;
		dlm_base = dlm_base + 1;
		__nds32__mtsr(dlm_base, NDS32_SR_DLMB);
		__nds32__dsb();
		dlm_base = dlm_base - 1;
		size = &_DLM_SIZE;
	}
	/* Setup DMA transfer parameters */
	dma_setup = __nds32__mfsr(NDS32_SR_DMA_SETUP);
	dma_setup &= ~DMA_SETUP_mskLM;
	if (LM_TYPE == LM_ILM) {
		dma_setup |= 0x0;	/* ILM is selected for DMA transfer */
		dma_setup &= ~DMA_SETUP_mskTDIR;
		dma_setup |= (0x0 << 1);	/* From external memory to ILM */
	} else {
		dma_setup |= 0x1;	/* ILM is selected for DMA transfer */
		dma_setup &= ~DMA_SETUP_mskTDIR;
		dma_setup |= (0x0 << 1);	/* From external memory to ILM */
	}
	dma_setup &= ~DMA_SETUP_mskTES;
	dma_setup |= (0x2 << 2);	/* 4 Bytes Element Size */
	dma_setup &= ~DMA_SETUP_mskESTR;
	dma_setup |= (0x4 << 4);	/* Transfer amount  */
	__nds32__mtsr(dma_setup, NDS32_SR_DMA_SETUP);

	/* setup dma_tcnt reg */
	dma_tcnt |= (size / 4);
	__nds32__mtsr(dma_tcnt, NDS32_SR_DMA_TCNT);
	__nds32__dsb();

	dma_esaddr = __nds32__mfsr(NDS32_SR_DMA_ESADDR);
	dma_esaddr |= source_addr;	/* specified external source_addr */
	__nds32__mtsr(dma_esaddr, NDS32_SR_DMA_ESADDR);
	__nds32__dsb();

	puts("DMA initialization\n");
}

void dma_finish(int LM_TYPE)
{
	puts("DMA finish\n");
	unsigned int dma_act;

	/* stop DMA transfer */
	dma_act = __nds32__mfsr(NDS32_SR_DMA_ACT);
	dma_act &= 0;
	dma_act |= 2;
	__nds32__mtsr(dma_act, NDS32_SR_DMA_ACT);
	__nds32__dsb();

	/*turn off DMA */
	unsigned int dma_gcsw;
	dma_gcsw = __nds32__mfsr(NDS32_SR_DMA_GCSW);
	dma_gcsw &= (~0x80000000);
	__nds32__mtsr(dma_gcsw, NDS32_SR_DMA_GCSW);
	__nds32__dsb();

	if (LM_TYPE == LM_ILM) {
		/* Set ILM base to SDRAM and enable it */
		__nds32__mtsr(0x1, NDS32_SR_ILMB);
		__nds32__dsb();
	} else {
		/* Set DLM base to SDRAM and enable it */
		__nds32__mtsr(0x1, NDS32_SR_DLMB);
		__nds32__dsb();
	}
}

void dma_start_transfer4ILM()
{

	unsigned int dma_act;
	dma_act = __nds32__mfsr(NDS32_SR_DMA_ACT);
	dma_act &= 0x0;
	dma_act |= 0x3;
	__nds32__mtsr(dma_act, NDS32_SR_DMA_ACT);
	__nds32__dsb();
	dma_act = __nds32__mfsr(NDS32_SR_DMA_ACT);
	dma_act &= 0x0;
	dma_act |= 0x1;
	__nds32__mtsr(dma_act, NDS32_SR_DMA_ACT);
	__nds32__dsb();
	puts("DMA start transfer...\n");
	dma_finish(LM_ILM);
}

void
dma_start_transfer4DLM(int a, int b, int c, int d, int e, int f, int g, int h)
{
	unsigned int dma_act;
	dma_act = __nds32__mfsr(NDS32_SR_DMA_ACT);
	dma_act &= 0x0;
	dma_act |= 0x3;
	__nds32__mtsr(dma_act, NDS32_SR_DMA_ACT);
	__nds32__dsb();
	dma_act = __nds32__mfsr(NDS32_SR_DMA_ACT);
	dma_act &= 0x0;
	dma_act |= 0x1;
	__nds32__mtsr(dma_act, NDS32_SR_DMA_ACT);
	__nds32__dsb();
	puts("DMA start transfer...\n");
	dma_finish(LM_DLM);
	if (a != 1 || b != 2 || c != 3 || d != 4 ||
	    e != 5 || f != 6 || g != 7 || h != 8)
		puts("DLM data is incorrect\n");
	else
		puts("DLM data is correct\n");

}

void DMA_transfer(int LM_TYPE)
{
	dma_initial(LM_TYPE);
	dma_read_status();
	if (LM_TYPE == LM_ILM) {
		dma_start_transfer4ILM();
	} else
		dma_start_transfer4DLM(1, 2, 3, 4, 5, 6, 7, 8);
}

void copyTextToILM4DMA()
{
	DMA_transfer(LM_ILM);
}

void copyDataToDLM4DMA()
{
	unsigned int dcm_cfg;
	dcm_cfg = __nds32__mfsr(NDS32_SR_DCM_CFG);

	if (dcm_cfg & 0x2000)	/* It can be LM size aligned. */
		puts("It can be LM size aligned\n");
	else {			/* It should be 1 MB aligned. */
		puts("Don't demo DLM\n");
		return;
	}
	DMA_transfer(LM_DLM);
}
#endif

void copyTextToILM()
{
	volatile unsigned int source_addr, ilm_base;
	int size;

	puts("Copying .text section to ILM.......................\n");

	/*
	 * source_addr = source address
	 * ilm_base = destination address
	 * size = size to copy
	 */

	source_addr = (volatile unsigned int)0;
	ilm_base = (unsigned int)&_ILM_BASE;
	size = g_ilm_size;

	if (size == 0) {
		puts("ILM size is 0\n");
		return;
	}

	/* Set ILM base and enable it */
	ilm_base = ilm_base + 1;
	/*mtsr  $r1, $ilmb */
	__nds32__mtsr(ilm_base, NDS32_SR_ILMB);
	__nds32__isb();
	ilm_base = ilm_base - 1;

	volatile unsigned int *src = (volatile unsigned int *)source_addr;
	volatile unsigned int *dest = (volatile unsigned int *)ilm_base;
	printS("src=0x", (unsigned int)src, 16);
	printS("dst=0x", (unsigned int)dest, 16);
	printS("size=0x", size, 16);

	while (size > 0) {
		*dest++ = *src++;
		size = size - 4;
	}
	//memcpy( (unsigned int *)source_addr, (unsigned int *)ilm_base, size);

	source_addr += 1;
	__nds32__mtsr(source_addr, NDS32_SR_ILMB);
	__nds32__isb();
	__nds32__isb();

}

void copyStackToDLM(int a, int b, int c, int d, int e, int f, int g, int h)
{
	volatile unsigned int source_addr, dlm_base, size;
	unsigned int dcm_cfg;
	/*
	 * source_addr = source address
	 * dlm_base = destination address
	 * size = size to copy
	 */

	dcm_cfg = __nds32__mfsr(NDS32_SR_DCM_CFG);

	if (dcm_cfg & 0x2000)	/* It can be LM size aligned. */
		source_addr = (volatile unsigned int)(0x800000 - g_dlm_size);
	else {			/* It should be 1 MB aligned. */
		puts("Don't demo DLM\n");
		return;
	}
	dlm_base = (unsigned int)&_DLM_BASE;
	size = g_dlm_size;

	if (size == 0) {
		puts("DLM size is 0\n");
		return;
	}
	puts("Copying stack to DLM.......................\n");

	/* use stack */
	printS("a=", a, 16);
	printS("b=", b, 16);
	printS("c=", c, 16);
	printS("d=", d, 16);
	printS("e=", e, 16);
	printS("f=", f, 16);
	printS("g=", g, 16);
	printS("h=", h, 16);
	/* Set DLM base and enable it */
	dlm_base = dlm_base + 1;
	__nds32__mtsr(dlm_base, NDS32_SR_DLMB);
	__nds32__dsb();
	dlm_base = dlm_base - 1;

	volatile unsigned int *src = (volatile unsigned int *)source_addr;
	volatile unsigned int *dest = (volatile unsigned int *)dlm_base;
	printS("src=0x", (unsigned int)src, 16);
	printS("dst=0x", (unsigned int)dest, 16);

	while (size > 0) {
		*dest++ = *src++;
		size = size - 4;
	}

	size = source_addr + 1;
	__nds32__mtsr(size, NDS32_SR_DLMB);
	__nds32__dsb();
	/* make sure stack data is correct */
	printS("a=", a, 16);
	printS("b=", b, 16);
	printS("c=", c, 16);
	printS("d=", d, 16);
	printS("e=", e, 16);
	printS("f=", f, 16);
	printS("g=", g, 16);
	printS("h=", h, 16);
	if (a != 1 || b != 2 || c != 3 || d != 4 ||
	    e != 5 || f != 6 || g != 7 || h != 8)
		puts("DLM data is incorrect\n");
	else
		puts("DLM data is correct\n");
	return;

}

void executeOnILM()
{
	int i;

	puts("Execute for loop i on ILM.......................\n");

	for (i = 0; i < 65536; i++)
		i = i + 1;
}

void get_ilm_size()
{
	unsigned int ilmb, ilm_size;
	ilmb = __nds32__mfsr(NDS32_SR_ILMB);

	ilm_size = ((ilmb & 0x1E) >> 1);
	printS("ilm_size = 0x", ilm_size, 16);

	if (ilm_size <= 8)
		g_ilm_size = ((1 << (ilm_size + 2)) << 10);
	else if (ilm_size > 8 && ilm_size <= 10)
		g_ilm_size = ((ilm_size - 8) << 10);
	else			/* ilm_size >= 11 */
		g_ilm_size = 0;

	printS("g_ilm_size = 0x", g_ilm_size, 16);
}

void get_dlm_size()
{
	unsigned int dlmb, dlm_size;
	dlmb = __nds32__mfsr(NDS32_SR_DLMB);

	dlm_size = ((dlmb & 0x1E) >> 1);
	printS("dlm_size = 0x", dlm_size, 16);

	if (dlm_size <= 8)
		g_dlm_size = ((1 << (dlm_size + 2)) << 10);
	else if (dlm_size > 8 && dlm_size <= 10)
		g_dlm_size = ((dlm_size - 8) << 10);
	else			/* dlm_size >= 11 */
		g_dlm_size = 0;

	printS("g_dlm_size = 0x", g_dlm_size, 16);
}

int main()
{

	unsigned int icm_cfg, dcm_cfg;
	unsigned int ilmb, dlmb, ilm_size, dlm_size;

	icm_cfg = __nds32__mfsr(NDS32_SR_ICM_CFG);
	printS("ICM_CFG = 0x", icm_cfg, 16);

	if (icm_cfg & 0x1C00)
		puts("The system has ILM...\n");
	else {
		puts("The system has no ILM...\n");
		return 0;
	}

	dcm_cfg = __nds32__mfsr(NDS32_SR_DCM_CFG);
	printS("DCM_CFG = 0x", dcm_cfg, 16);
	if (dcm_cfg & 0x1C00)
		puts("The system has DLM...\n");
	else {
		puts("The system has no DLM...\n");
		return 0;
	}

	get_ilm_size();
	get_dlm_size();

#ifdef USE_LM_DMA
	if (__nds32__mfsr(NDS32_SR_MSC_CFG) & 0x2) {
		puts("Instruction/Data Local Memory DMA sample.\n");
		copyTextToILM4DMA();
		executeOnILM();
		copyDataToDLM4DMA();
	} else {
		puts("This CPU config doesn't support LM DMA.\n");
	}
#else
	puts("Instruction/Data Local Memory sample.\n");
	copyTextToILM();
	executeOnILM();
	copyStackToDLM(1, 2, 3, 4, 5, 6, 7, 8);
#endif
	puts("Completed...............\n");
	while (1) ;
}

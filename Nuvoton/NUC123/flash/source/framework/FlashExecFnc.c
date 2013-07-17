/**
 *******************************************************************************
 * @file       FlashExecFnc.c
 * @version    V0.01    Initial Flash Framework version
 * @date       2009.10.21
 * @brief      Flash  Framework Algorithm Function	
 *******************************************************************************
 * @copy
 *
 * INTERNAL FILE,DON'T PUBLIC.
 * 
 * <h2><center>&copy; COPYRIGHT 2009 CooCox </center></h2>
 *******************************************************************************
 */ 
 
#include <FlashAlgorithm.h>


typedef int (*FlashAlgoFnc)(unsigned long parameter0,unsigned long parameter1,unsigned long parameter2);


void BreakHere(int status);


/**
 *******************************************************************************
 * @brief      Halt the cpu in Debug Mode 
 * @param[in]  status     	Last function execute result.
 * @param[out] None  
 *
 * @par Description
 * @details     
 * @note 
 *******************************************************************************
 */
#if (defined (__GNUC__)) /*------------------ GNU Compiler ---------------------*/
void BreakHere(int status) __attribute__( ( naked ) );
void BreakHere(int status)
{
  __asm volatile ("BKPT #0 \n\t"  );
}
#endif


/**
 *******************************************************************************
 * @brief      Execte Flash Algorithm Function Then Halt the cpu
 * @param[in]  algoFnc      Flash Algorithm Function Address.
 * @param[in]  parameter0 	Flash Algorithm Function parameter0.
 * @param[in]  parameter1 	Flash Algorithm Function parameter1.
 * @param[in]  parameter2 	Flash Algorithm Function parameter2.
 * @param[out] None  
 * @retval     0   					All is OK.
 * @retval     others       Some error occurs.		 
 *
 * @par Description
 * @details     
 * @note 
 *******************************************************************************
 */
int ExecFunction (FlashAlgoFnc algoFnc,
				  unsigned long parameter0,
				  unsigned long parameter1,
				  unsigned long parameter2)
{
	 int retval;
	 retval = algoFnc(parameter0,parameter1,parameter2);
	 BreakHere(retval);
	 
	 return (retval);
}

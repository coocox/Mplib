#ifndef ASSERT_DEMOS_H
#define ASSERT_DEMOS_H

#ifdef USE_C_EXT
 //#ifdef ASSERT_V3M_ONLY
 #if !(defined(NDS32_BASELINE_V3) || defined(NDS32_BASELINE_V3M))
  #error USE_C_EXT is only supported by NDS32_BASELINE_V3/NDS32_BASELINE_V3M tool-chain!
 #endif
#endif //#ifdef USE_C_EXT

#ifdef NDS32_BASELINE_V3M
 //#ifdef ASSERT_16MB_ONLY
 #ifndef CFG_16MB
  #error NDS32_BASELINE_V3M tool-chain only supports CFG_16MB (24-bit address)!
 #endif
#endif //#ifdef NDS32_BASELINE_V3M

#ifdef DEMO_CACHE
 #ifdef NDS32_BASELINE_V3M
  #error NDS32_BASELINE_V3M tool-chain supports no CCTL by the demo implemented!
 #endif
#endif //#ifdef DEMO_CACHE

#endif //#ifdef ASSERT_DEMOS_H

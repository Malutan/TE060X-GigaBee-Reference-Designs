/******************************************************************************
*
* (c) Copyright 2010-2011 Xilinx, Inc. All rights reserved.
*
* This file contains confidential and proprietary information of Xilinx, Inc.
* and is protected under U.S. and international copyright and other
* intellectual property laws.
*
* DISCLAIMER
* This disclaimer is not a license and does not grant any rights to the
* materials distributed herewith. Except as otherwise provided in a valid
* license issued to you by Xilinx, and to the maximum extent permitted by
* applicable law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL
* FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS,
* IMPLIED, OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF
* MERCHANTABILITY, NON-INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE;
* and (2) Xilinx shall not be liable (whether in contract or tort, including
* negligence, or under any other theory of liability) for any loss or damage
* of any kind or nature related to, arising under or in connection with these
* materials, including for any direct, or any indirect, special, incidental,
* or consequential loss or damage (including loss of data, profits, goodwill,
* or any type of loss or damage suffered as a result of any action brought by
* a third party) even if such damage or loss was reasonably foreseeable or
* Xilinx had been advised of the possibility of the same.
*
* CRITICAL APPLICATIONS
* Xilinx products are not designed or intended to be fail-safe, or for use in
* any application requiring fail-safe performance, such as life-support or
* safety devices or systems, Class III medical devices, nuclear facilities,
* applications related to the deployment of airbags, or any other applications
* that could lead to death, personal injury, or severe property or
* environmental damage (individually and collectively, "Critical
* Applications"). Customer assumes the sole risk and liability of any use of
* Xilinx products in Critical Applications, subject only to applicable laws
* and regulations governing limitations on product liability.
*
* THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE
* AT ALL TIMES.
*
******************************************************************************/
/*****************************************************************************/
/**
*
* @file xaxidma_porting_guide.h
*
* This is a guide on how to move from using the xlldma driver to use xaxidma
* driver.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -------------------------------------------------------
* 1.00a jz   05/18/10 First release
* 2.00a jz   08/10/10 Second release, added in xaxidma_g.c, xaxidma_sinit.c,
*                     updated tcl file, added xaxidma_porting_guide.h
* 4.00a rkv  02/22/11 Added support for simple DMA mode
*
* </pre>
*
* <b>Overview</b>
*
* The API for xaxidma driver is similar to xlldma driver. The prefix for the
* API functions and structures is XAxiDma_ for the xaxidma driver.
*
* Due to hardware feature changes, signatures of some API functions are a
* little bit different from the xlldma API functions.
*
* We present API functions:
* - That only have prefix changes
* - That have different return type
* - That are new API functions
* - That have been removed
*
* Note that data structures have different prefix of XAxiDma_. Those API
* functions, that have data structures with prefix change, are considered as
* prefix change.
*
* <b>API Functions That Only Have Prefix Changes</b>
*
* <pre>
*         xlldma driver              |         xaxidma driver
* -----------------------------------------------------------------------
*    XLlDma_Reset(...)               |  XAxiDma_Reset(...)
*    XLlDma_BdRingSnapShotCurrBd(...)|  XAxiDma_BdRingSnapShotCurrBd(...)
*    XLlDma_BdRingNext(...)          |  XAxiDma_BdRingNext(...)
*    XLlDma_BdRingPrev(...)          |  XAxiDma_BdRingPrev(...)
*    XLlDma_BdRingGetSr(...)         |  XAxiDma_BdRingGetSr(...)
*    XLlDma_BdRingBusy(...)          |  XAxiDma_BdRingBusy(...)
*    XLlDma_BdRingIntEnable(...)     |  XAxiDma_BdRingIntEnable(...)
*    XLlDma_BdRingIntDisable(...)    |  XAxiDma_BdRingIntDisable(...)
*    XLlDma_BdRingIntGetEnabled(...) |  XAxiDma_BdRingIntGetEnabled(...)
*    XLlDma_BdRingGetIrq(...)        |  XAxiDma_BdRingGetIrq(...)
*    XLlDma_BdRingAckIrq(...)        |  XAxiDma_BdRingAckIrq(...)
*    XLlDma_BdRingCreate(...)        |  XAxiDma_BdRingCreate(...)
*    XLlDma_BdRingClone(...)         |  XAxiDma_BdRingClone(...)
*    XLlDma_BdRingAlloc(...)         |  XAxiDma_BdRingAlloc(...)
*    XLlDma_BdRingUnAlloc(...)       |  XAxiDma_BdRingUnAlloc(...)
*    XLlDma_BdRingToHw(...)          |  XAxiDma_BdRingToHw(...)
*    XLlDma_BdRingFromHw(...)        |  XAxiDma_BdRingFromHw(...)
*    XLlDma_BdRingFree(...)          |  XAxiDma_BdRingFree(...)
*    XLlDma_BdRingStart(...)         |  XAxiDma_BdRingStart(...)
*    XLlDma_BdRingCheck(...)         |  XAxiDma_BdRingCheck(...)
*    XLlDma_BdRingSetCoalesce(...)   |  XAxiDma_BdRingSetCoalesce(...)
*    XLlDma_BdRingGetCoalesce(...)   |  XAxiDma_BdRingGetCoalesce(...)
*    XLlDma_BdRead(...)              |  XAxiDma_BdRead(...)
*    XLlDma_BdWrite(...)             |  XAxiDma_BdWrite(...)
*    XLlDma_BdClear(...)             |  XAxiDma_BdClear(...)
*    XLlDma_BdSetId(...)             |  XAxiDma_BdSetId(...)
*    XLlDma_BdGetId(...)             |  XAxiDma_BdGetId(...)
*    XLlDma_BdGetLength(...)         |  XAxiDma_BdGetLength(...)
*    XLlDma_BdGetBufAddr(...)        |  XAxiDma_BdGetBufAddr(...)
*</pre>
*
* <b>API Functions That Have Different Return Type</b>
*
* Due to possible hardware failures, The caller should check the return value
* of the following functions.
*
* <pre>
*         xlldma driver              |         xaxidma driver
* -----------------------------------------------------------------------
* void XLlDma_Pause(...)             | int XAxiDma_Pause(...)
* void XLlDma_Resume(...)            | int XAxiDma_Resume(...)
* </pre>
*
* The following functions have return type changed:
*
* <pre>
*         xlldma driver              |         xaxidma driver
* -----------------------------------------------------------------------
* XLlDma_BdRing XLlDma_GetRxRing(...)| XAxiDma_BdRing * XAxiDma_GetRxRing(...)
* XLlDma_BdRing XLlDma_GetTxRing(...)| XAxiDma_BdRing * XAxiDma_GetTxRing(...)
* u32 XLlDma_BdRingMemCalc(...)      | int XAxiDma_BdRingMemCalc(...)
* u32 XLlDma_BdRingCntCalc(...)      | int XAxiDma_BdRingCntCalc(...)
* u32 XLlDma_BdRingGetCnt(...)       | int XAxiDma_BdRingGetCnt(...)
* u32 XLlDma_BdRingGetFreeCnt(...)   | int XAxiDma_BdRingGetFreeCnt(...)
* void XLlDma_BdSetLength(...)       | int XAxiDma_BdSetLength(...)
* void XLlDma_BdSetBufAddr(...)      | int XAxiDma_BdSetBufAddr(...)
*</pre>
*
* <b>API Functions That Are New API Functions</b>
*
* Now that the AXI DMA core is a standalone core, some new API are intrduced.
* Some other functions are added due to hardware interface change, so to
* replace old API functions.
*
* - XAxiDma_Config *XAxiDma_LookupConfig(u32 DeviceId);
* - int XAxiDma_CfgInitialize(XAxiDma * InstancePtr, XAxiDma_Config *Config);
* - int XAxiDma_ResetIsDone(XAxiDma * InstancePtr);
* - XAxiDma_Bd * XAxiDma_BdRingGetCurrBd(XAxiDma_BdRing* RingPtr);
* - int XAxiDma_BdRingHwIsStarted(XAxiDma_BdRing* RingPtr);
* - void XAxiDma_BdRingDumpRegs(XAxiDma_BdRing *RingPtr);
* - int XAxiDma_StartBdRingHw(XAxiDma_BdRing* RingPtr);
* - void XAxiDma_BdSetCtrl(XAxiDma_Bd *BdPtr, u32 Data);
* - u32 XAxiDma_BdGetCtrl(XAxiDma_Bd* BdPtr);
* - u32 XAxiDma_BdGetSts(XAxiDma_Bd* BdPtr);
* - int XAxiDma_BdHwCompleted(XAxiDma_Bd* BdPtr);
* - int XAxiDma_BdGetActualLength(XAxiDma_Bd* BdPtr);
* - int XAxiDma_BdSetAppWord(XAxiDma_Bd * BdPtr, int Offset, u32 Word);
* - u32 XAxiDma_BdGetAppWord(XAxiDma_Bd * BdPtr, int Offset, int *Valid);
*
* <b>API Functions That Have Been Removed</b>
*
* Please see individual function comments for how to replace the removed API
* function with new API functions.
*
* - void XLlDma_Initialize(XLlDma * InstancePtr, u32 BaseAddress).
*   This function is replaced by XAxiDma_LookupConfig()/XAxiDma_CfgInitialize()
*
* - u32 XLlDma_BdRingGetCr(XLlDma_BdRing* RingPtr).
*   This is replaced by XAxiDma_BdRingGetError(XAxiDma_BdRing* RingPtr)
*
* - u32 XLlDma_BdRingSetCr(XLlDma_BdRing* RingPtr, u32 Data).
*   This function is covered by other API functions:
*      - void XAxiDma_BdRingIntEnable(XAxiDma_BdRing* RingPtr, u32 Mask)
*      - void XAxiDma_BdRingIntDisable(XAxiDma_BdRing* RingPtr, u32 Mask)
*      - int XAxiDma_BdRingSetCoalesce(XAxiDma_BdRing * RingPtr, u32 Counter,
*            u32 Timer)
*
* - u32 XLlDma_BdSetStsCtrl(XLlDma_Bd* BdPtr, u32 Data).
*   Replaced by XAxiDma_BdSetCtrl(XAxiDma_Bd *BdPtr, u32 Data);
*
* - u32 XLlDma_BdGetStsCtrl(XLlDma_Bd* BdPtr).
*   Replaced by XAxiDma_BdGetCtrl(XAxiDma_Bd* BdPtr) and
*   XAxiDma_BdGetSts(XAxiDma_Bd* BdPtr).
*
* <b>API Functions That Have Been Added to support simple DMA mode</b>
*
* - u32 XAxiDma_Busy(XAxiDma *InstancePtr,int Direction);
* - int XAxiDma_SimpleTransfer(XAxiDma *InstancePtr, u32 BuffAddr, int Length,
*	int Direction);
* - XAxiDma_HasSg(InstancePtr);
* - XAxiDma_IntrEnable(InstancePtr,Mask,Direction);
* - XAxiDma_IntrGetEnabled(InstancePtr, Direction);
* - XAxiDma_IntrDisable(InstancePtr, Mask, Direction);
* - XAxiDma_IntrGetIrq(InstancePtr, Direction);
* - XAxiDma_IntrAckIrq(InstancePtr, Mask, Direction);
*
******************************************************************************/


/*<RBHead>
 *************************************************************************
 *                                                                       *
 *                      ROBERT BOSCH GMBH                                *
 *                          STUTTGART                                    *
 *                                                                       *
 *          Alle Rechte vorbehalten - All rights reserved                *
 *                                                                       *
 *************************************************************************  
 *
 *    __   __   ___  ___
 *   /_ / /  / /__  /    /__/
 *  /__/ /__/ __ / /__  /  /
 *
 *
 *************************************************************************
 *    Administrative Information (automatically filled in by eASEE)      *
 *************************************************************************
 *
 * $Filename__:mrly_vd.h$
 *
 * $Author____:NESTORADMINSDOM$
 *
 * $Function__:This version is created by migration tool$
 *
 *************************************************************************
 * $Domain____:SDOM$
 * $User______:KUM6COB$
 * $Date______:21.05.2013$
 * $Class_____:SWHDR$
 * $Name______:mrly_vd$
 * $Variant___:1.42.0$
 * $Revision__:0$
 * $Type______:H$
 * $State_____:AVAILABLE$
 * $Generated_:$
 *************************************************************************
 *
 * $UniqueName:$
 * $Component_:$
 *
 * $FDEF______:$
 *
 *************************************************************************
 * List Of Changes
 *
 * $History
 * 
 * 1.42.0; 0     21.05.2013 KUM6COB
 *     1) Build break if SYC_CAL_PERMSPLYSYS_SY is enabled for Gasolin projects.
 *     2) MRly_WaitStk_C describtion change in Docu.
 *        RQONE00193214
 * 
 * 1.41.1; 1     25.05.2011 VIY3KOR
 *   Review Changes.
 * 
 * 1.41.1; 0     29.03.2011 VIY3KOR
 *   Main relay early opening bugfix.
 * 
 * 1.40.0; 0     17.06.2009 KDD2FE
 *   Initial import from Nestor 
 *        Object in Nestor : 
 *        Domain :MX17
 *        Class :SWHDR
 *        Object name :MRLY_VD
 *        Variant :20.40
 *        Revision :0
 * 
 * $
 *
 ***************************************************************************************************
 *
 *   T H I S   I S   A   G E N E R A T E D   F I L E   F R O M      A  S  C  E  T
 *
 ***************************************************************************************************
 * Autor:              kum6cob
 * Date:               5/20/2013  16:49:39
 * Modulname:          MRly_VD
 * Filename:           MRly_VD.h
 * Filetype:           header
 * Implementation:     Impl
 *
 * $Generated by ASCET-SD: V6.1.3 RB-DGS 2.1
 * Expander:           Generic  CID: 610
 * Codegenerator:      ASCET-SE-RBPT V6.1.3.59.14
 * Target:             Generic:ME17 with class support [V6.1.3.59.14]
 * CgenOptions:
 *             Allow Double bit Size for Division Numerators=true
 *             Generate Round Operation on float to integer Assignment=false
 *             Generate Access Methods for dT (Alternative: use OS dT directly)=false
 *             Temp Vars always 32 bit (integer)=false
 *             Generate Limiters (may be changed locally)=true
 *             Use SHIFT Operation on Signed Values instead of DIV Operation=true
 *             Optimize Direct Access Methods (Multiple Levels)=true
 *             Protected Vector Indices=false
 *             Optimize Direct Access Methods (One Level)=true
 *             Add Comment with Generation Information for each Component=false
 *             Add Comment with Implementation Information for each Assignment Statement=true
 *             Add Comment with Specification Source for each Statement=true
 *             Add Implementation Definitions=true
 *             Add parenthesis for readability=true
 *             Allow Limit Service for Assignment Limitation=true
 *             Arithmetic Service Set=rb-services
 *             Auto-inline private methods (Smaller code-size - may be changed locally)=false
 *             Casting=Legacy
 *             Code Generator=Object Based Controller Implementation
 *             Compiler=ME17 (dummy compiler)
 *             Division truncation direction=Zero (T-division)
 *             Force Parenthesis for Binary Logical Operators=true
 *             Generate Access Macros for=()
 *             Generate Data Structures=YESALL
 *             Generate Define Directives for Enum Values=true
 *             Generate Map File=false
 *             Generate OS Configuration=false
 *             Generate well-formed switch=true
 *             Hierarchical Code-Generation (may be changed locally)=false
 *             Initialise history variable with zero=true
 *             Inline directive=INLINE_FUNCTION
 *             Integer Bit Size=32
 *             Maximum bit Length (float)=32
 *             Maximum bit Length (int)=32
 *             Operating System=GENERIC_OSEK
 *             Optimize Static Actions (Restricted Modelling)=false
 *             Outline Generated Methods (may be changed locally)=false
 *             Prefix for Component Names=
 *             Private directive=static
 *             Protected against division by zero=false
 *             Protected Division against Signed Overflow=false
 *             Public directive=
 *             Result on Division by Zero=numerator
 *             Target=Generic:ME17 with class support
 *             Use Customized Data Type Names=false
 *             Use power of 2 approximations of literals=false
 *             Use SHIFT Operation on Signed Values instead of MUL Operation=true
 *
 ***************************************************************************************************
</RBHead>*/

#ifndef _MRLY_VD_H
#define _MRLY_VD_H

/*
***************************************************************************************
* Include of User Component Specific Headertext for MRLY_VD_PUB_IMPL
***************************************************************************************
*/
/**********************************************************************************************/
/*                                                                                            						           */
/* DEFINES & ENUMS:                                                                           					           */
/*                                                                                            						           */
/**********************************************************************************************/

/* status whether main relay is OPEN or CLOSED */
#define MRLY_ST_OPEN  FALSE
#define MRLY_ST_CLOSE TRUE

/* bit position of main relay open/close status	*/
#define MRLY_ST_BP 0x00

/* bit position for the main relay diagnosis status	*/
#define MRLY_DIAG_ST_BP 0x01

/* status whether the main relay diagnosis is active or not	*/
#define MRLY_DIAG_ACTV FALSE
#define MRLY_DIAG_FIN  TRUE

/**********************************************************************************************/
/*                                                                                            						           */
/* PROTOTYPES                                                                                					           */
/*                                                                                            						           */
/**********************************************************************************************/

/* function prototype for the main relay diagnostics */
#define MRLY_VD_PUB_IMPL_MRly_ShOff MRly_ShOff

#define _MRLY_VD_PUB_IMPL_

/* public method prototypes for MRLY_VD_PUB_IMPL */
#ifdef _MRLY_VD_PUB_IMPL_
void MRLY_VD_PUB_IMPL_MRly_ShOff(void);

#endif /* _MRLY_VD_PUB_IMPL_ */

#endif /* _MRLY_VD_H */
/*<RBHead>
 ************************************************************************* 
 *                                                                       * 
 *                      ROBERT BOSCH GMBH                                * 
 *                          STUTTGART                                    * 
 *                                                                       * 
 *          Alle Rechte vorbehalten - All rights reserved                * 
 *                                                                       * 
 ************************************************************************* 
																		    
 ************************************************************************* 
 *    Administrative Information (automatically filled in by eASEE)      * 
 ************************************************************************* 
 *	
 * $Filename__:os_patch_priv.h$ 
 * 
 * $Author____:NESTORADMINSDOM$ 
 * 
 * $Function__:This version is created by migration tool$ 
 * 
 ************************************************************************* 
 * $Domain____:SDOM$ 
 * $User______:KLMEYER$ 
 * $Date______:26.08.2008$ 
 * $Class_____:SWHDR$ 
 * $Name______:os_patch_priv$ 
 * $Variant___:1.11.0$ 
 * $Revision__:0$ 
 * $Type______:H$ 
 * $State_____:AVAILABLE$ 
 * $Generated_:$ 
 ************************************************************************* 
 * 
 * $UniqueName:$ 
 * $Component_:$ 
 * 
 * 
 ************************************************************************* 
 * List Of Changes 
 * 
 * $History
 * 
 * 1.11.0; 0     26.08.2008 KLMEYER
 *   Update: Core delivery 2008-07
 * 
 * $ 
 * 
 ************************************************************************* 
 </RBHead>*/

#if !defined(_OS_PATCH_PRIV_H) && !defined(ESCAPE_PARSER)
#define _OS_PATCH_PRIV_H

#ifndef _OS_CONF_H
    #error os_conf.h has to be included prior os_patch.h is used
#endif

/**
 ***************************************************************************************************
 * \moduledescription
 *                      Some patching required for ESCAPE generated ERCOSEK configuration.
 *
 * \scope               API
 ***************************************************************************************************
 */

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

/* Patch labels, if RTMO is enabled */
#if (OS_RTMOENABLE == TRUE)
    asm(".equ os_dispatchPreemp, Rtmo_DispatchPreempHook");
    asm(".equ os_isrTT, Rtmo_IsrTTHook");
    asm(".equ os_processTimeOuts, Rtmo_ProcessTimeOutsHook");
#endif


/*
 ***************************************************************************************************
 * Defines
 ***************************************************************************************************
 */


/*
 ***************************************************************************************************
 * Type definitions
 ***************************************************************************************************
 */


/*
 ***************************************************************************************************
 * Extern declarations
 ***************************************************************************************************
 */

/* _OS_PATCH_PRIV_H */
#endif
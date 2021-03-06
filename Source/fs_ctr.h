/*
*********************************************************************************************************
*                                                uC/FS
*                                      The Embedded File System
*
*                    Copyright 2008-2020 Silicon Laboratories Inc. www.silabs.com
*
*                                 SPDX-License-Identifier: APACHE-2.0
*
*               This software is subject to an open source license and is distributed by
*                Silicon Laboratories Inc. pursuant to the terms of the Apache License,
*                    Version 2.0 available at www.apache.org/licenses/LICENSE-2.0.
*
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                   FILE SYSTEM COUNTER MANAGEMENT
*
* Filename : fs_ctr.h
* Version  : V4.08.00
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*/

#ifndef  FS_CTR_H
#define  FS_CTR_H


/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include  <cpu.h>
#include  "fs_cfg_fs.h"


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   FS_CTR_MODULE
#define  FS_CTR_EXT
#else
#define  FS_CTR_EXT  extern
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                    FILE SYSTEM COUNTER DATA TYPE
*
* Note(s) : (1) FS_CTR_MAX SHOULD be #define'd based on 'FS_CTR' data type declared.
*********************************************************************************************************
*/

typedef  CPU_INT32U  FS_CTR;                                    /* Defines   max nbr of errs/stats to cnt.              */

#define  FS_CTR_MAX                         DEF_INT_32U_MAX_VAL /* Define as max unsigned val (see Note #1).            */


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               MACRO'S
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                     FILE SYSTEM COUNTER MACRO'S
*
* Description : Increment file system counter(s).
*
* Argument(s) : Various file system counter variable(s) & values.
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

                                                                /* ---------------- GENERIC CTR MACRO'S --------------- */
#define  FS_CTR_INC(ctr)                                     { (ctr)++; }

#define  FS_CTR_INC_LARGE(ctr_hi, ctr_lo)                    { (ctr_lo)++;            \
                                                                if ((ctr_lo) == 0u) { \
                                                                    (ctr_hi)++;       \
                                                                }                     \
                                                             }

#define  FS_CTR_ADD(ctr, val)                                { (ctr) += (val); }



#if (FS_CFG_CTR_STAT_EN == DEF_ENABLED)                         /* ----------------- STAT CTR MACRO'S ----------------- */

#define  FS_CTR_STAT_INC(stat_ctr)                              FS_CTR_INC(stat_ctr)
#define  FS_CTR_STAT_ADD(stat_ctr, val)                         FS_CTR_ADD((stat_ctr), (val))

#else

#define  FS_CTR_STAT_INC(stat_ctr)
#define  FS_CTR_STAT_ADD(stat_ctr, val)

#endif


#if (FS_CFG_CTR_ERR_EN == DEF_ENABLED)                          /* ------------------ ERR CTR MACRO'S ----------------- */

#define  FS_CTR_ERR_INC(err_ctr)                                FS_CTR_INC(err_ctr)

#else

#define  FS_CTR_ERR_CLR(err_ctr);

#define  FS_CTR_ERR_INC(err_ctr)

#endif


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif


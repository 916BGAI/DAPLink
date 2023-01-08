/**
 * @file    target_reset.c
 * @brief   Target reset for the new target
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "DAP_config.h"
#include "swd_host.h"
#include "target_family.h"
#include "target_board.h"
#include "cmsis_os2.h"

#define NVIC_Addr    (0xe000e000)
#define DBG_Addr     (0xe000edf0)
#define NVIC_AIRCR     (NVIC_Addr + 0x0D0C)
#define DBG_HCSR       (DBG_Addr + DBG_HCSR_OFS)

static void stm32f103c8_swd_set_target_reset(uint8_t asserted){
    if(!asserted) {
        swd_write_word(NVIC_AIRCR, VECTKEY | 0x7);
    }
}

const target_family_descriptor_t g_target_family_stm32f103c8 = {
    .family_id = kStub_SWSysReset_FamilyID,
    .default_reset_type = kSoftwareReset,
    .soft_reset_type = SYSRESETREQ,
    .swd_set_target_reset = stm32f103c8_swd_set_target_reset,
};

const target_family_descriptor_t *g_target_family = &g_target_family_stm32f103c8;

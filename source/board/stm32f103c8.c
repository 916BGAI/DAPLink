/**
 * @file    stm32f103rb.c
 * @brief   board information for STMicroelectronics NUCLEO-F103RB
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2019, ARM Limited, All Rights Reserved
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

#include "target_family.h"
#include "target_board.h"

extern target_cfg_t target_device_stm32f103c8;

const board_info_t g_board_info = {
    .info_version = kBoardInfoVersion,
    .board_id = "9999",
    .family_id = kStub_SWSysReset_FamilyID,
    .target_cfg = &target_device_stm32f103c8,
    .board_vendor = "STMicroelectronics",
    .board_name = "STM32F103C8",
};

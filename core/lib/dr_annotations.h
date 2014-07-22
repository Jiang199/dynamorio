/* ******************************************************
 * Copyright (c) 2014 Google, Inc.  All rights reserved.
 * ******************************************************/

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of VMware, Inc. nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL VMWARE, INC. OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#ifndef _DYNAMORIO_ANNOTATIONS_H_
#define _DYNAMORIO_ANNOTATIONS_H_ 1

#include "dr_annotations_asm.h"

#pragma GCC system_header

#define DYNAMORIO_ANNOTATE_RUNNING_ON_DYNAMORIO() \
    dynamorio_annotate_running_on_dynamorio()

#define DYNAMORIO_ANNOTATE_LOG(format, ...) \
    DR_ANNOTATION(dynamorio_annotate_log, format, ##__VA_ARGS__)

#define DYNAMORIO_ANNOTATE_MANAGE_CODE_AREA(start, len) \
    DR_ANNOTATION(dynamorio_annotate_manage_code_area, start, len)

#define DYNAMORIO_ANNOTATE_UNMANAGE_CODE_AREA(start, len) \
    DR_ANNOTATION(dynamorio_annotate_unmanage_code_area, start, len)

#define DYNAMORIO_ANNOTATE_FLUSH_FRAGMENTS(start, len, is_direct_cti_target) \
    DR_ANNOTATION(dynamorio_annotate_flush_fragments, start, len, is_direct_cti_target)

#ifdef __cplusplus
extern "C" {
#endif

DR_DECLARE_ANNOTATION(char, dynamorio_annotate_running_on_dynamorio, ());

DR_DECLARE_ANNOTATION(unsigned int, dynamorio_annotate_log, (const char *format, ...));

DR_DECLARE_ANNOTATION(void, dynamorio_annotate_manage_code_area,
                      (void *start, size_t len));

DR_DECLARE_ANNOTATION(void, dynamorio_annotate_unmanage_code_area,
                      (void *start, size_t len));

DR_DECLARE_ANNOTATION(void, dynamorio_annotate_flush_fragments,
                      (void *start, size_t len, char is_direct_cti_target));

#ifdef __cplusplus
}
#endif

#endif

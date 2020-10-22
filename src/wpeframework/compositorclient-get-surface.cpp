/*
 * Copyright (C) 2020 Linaro
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "compositorclient-get-surface.h"
#include <wpe/wpe-egl.h>
#include <compositor/Client.h>
#include <cstring>

namespace WPEFramework {

extern "C" {

__attribute__((visibility("default")))
void wpe_compositorclient_get_parent_surface(struct wpe_renderer_backend_egl*)
{
    fprintf(stderr, "%s:%d\n", __FUNCTION__, __LINE__);
    auto* base = reinterpret_cast<struct wpe_renderer_backend_egl_base*>(backend);
    auto* display = reinterpret_cast<WPEFramework::Compositor::IDisplay*>(base->interface_data);
    fprintf(stderr, "%s:%d display=%p\n", __FUNCTION__, __LINE__, display);
    display.LoadSurfaces();
    return nullptr;
}

}

/*
 * Backlight intensity algorithm header file for Nvidia graphics 
 * adapters.
 *
 * Copyright (c) 2009-2011 Guillaume Zin <guillaume.zin@gmail.com>
 * Copyright (c) 2008-2009 Mario Schwalbe <schwalbe@inf.tu-dresden.de>
 * Based on the mechanism discovered by the author of NvClock:
 * Copyright (c) 2001-2009 Roderick Colenbrander
 *     Site: http://nvclock.sourceforge.net
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef NVIDIA_MODELS_H
#define NVIDIA_MODELS_H

#include "nvidiabl-types.h"

extern void nvidiabl_force_model(struct driver_data **driver_data);

extern DEFINE_PCI_DEVICE_TABLE(nvidiabl_device_table);

#endif
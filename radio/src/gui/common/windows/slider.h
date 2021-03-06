/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _SLIDER_H_
#define _SLIDER_H_

#include "window.h"

class Slider : public Window {
  public:
    Slider(Window * parent, const rect_t & rect, int32_t vmin, int32_t vmax, std::function<int32_t()> getValue, std::function<void(int32_t)> setValue):
      Window(parent, rect),
      vmin(vmin),
      vmax(vmax),
      getValue(std::move(getValue)),
      setValue(std::move(setValue))
    {
    }

#if defined(DEBUG_WINDOWS)
    std::string getName() override
    {
      return "Slider";
    }
#endif

    void paint(BitmapBuffer * dc) override;

    bool onTouchStart(coord_t x, coord_t y) override;

    bool onTouchEnd(coord_t x, coord_t y) override;

    bool onTouchSlide(coord_t x, coord_t y, coord_t startX, coord_t startY, coord_t slideX, coord_t slideY) override;

  protected:
    int value(coord_t x) const;
    int32_t vmin;
    int32_t vmax;
    bool sliding = false;
    std::function<int32_t()> getValue;
    std::function<void(int32_t)> setValue;
};

#endif

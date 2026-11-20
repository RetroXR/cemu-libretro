#pragma once

// RETRO_ENVIRONMENT_SET_VIDEO_VIEWS / GET_VIDEO_VIEWS_STATUS, as upstream
// libretro.h has them. This core's libretro.h predates them, so the block is
// kept here until that header is refreshed.

#include "libretro.h"

#ifndef RETRO_ENVIRONMENT_SET_VIDEO_VIEWS
#define RETRO_ENVIRONMENT_SET_VIDEO_VIEWS (95 | RETRO_ENVIRONMENT_EXPERIMENTAL)
#define RETRO_ENVIRONMENT_GET_VIDEO_VIEWS_STATUS (96 | RETRO_ENVIRONMENT_EXPERIMENTAL)
#define RETRO_VIDEO_VIEWS_STATUS_PRESENTS (1 << 0)
#define RETRO_VIDEO_VIEWS_STATUS_STEREO   (1 << 1)
#define RETRO_VIDEO_VIEWS_STATUS_HMD      (1 << 2)
#define RETRO_VIDEO_VIEW_EYE_NONE  0
#define RETRO_VIDEO_VIEW_EYE_LEFT  1
#define RETRO_VIDEO_VIEW_EYE_RIGHT 2
#define RETRO_VIDEO_VIEWS_MAX      8
#define RETRO_VIDEO_VIEWS_FLAG_TRACKED (1 << 0)

struct retro_video_view
{
   unsigned x;
   unsigned y;
   unsigned width;
   unsigned height;
   unsigned screen;
   unsigned eye;
   float aspect_ratio;
};

struct retro_video_views
{
   const struct retro_video_view *views;
   unsigned num_views;
   unsigned flags;
   int reference_space; /* enum retro_vr_reference_space upstream */
   unsigned recommended_view_width;
   unsigned recommended_view_height;
};
#endif

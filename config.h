/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 3;        /* horiz inner gap between windows */
static const unsigned int gappiv    = 3;        /* vert inner gap between windows */
static const unsigned int gappoh    = 3;        /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 3;        /* vert outer gap between windows and screen edge */
static const int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {
  "CascadiaCode:pixelsize=14:antialias=true:autohint=true",
  "NotoSansCJKHK:pixelsize=14:antialias=true:autohint=true",
  "JoyPixels:pixelsize=12:antialias=true:autohint=true",
  "Symbola:pixelsize=12:antialias=true:autohint=true",
  "Symbols Nerd Font:pixelsize=13:antialias=true:autohint=true"
};
static const char dmenufont[]       = "CascadiaCode:pixelsize=14:antialias=true:autohint=true";
static const char col_gray1[]       = "#202020";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#006688";
static const char col_green[]       = "#009922";
static const unsigned int baralpha = 0xb0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
  /*                   fg         bg         border   */
  [SchemeNorm]     = { col_gray3, col_gray1, col_gray2 },
  [SchemeTagsSel]  = { col_gray4, col_cyan,  col_cyan  },
  [SchemeSel]      = { col_gray4, col_gray1, col_cyan  },
};
static const unsigned int alphas[][3]      = {
  /*                   fg      bg        border     */
  [SchemeNorm]     = { OPAQUE, baralpha, borderalpha },
  [SchemeTagsSel]  = { OPAQUE, baralpha, borderalpha },
  [SchemeSel]      = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "🐧","🌏","📬","💬","📝","🖼","📽","🎮","🚫" };

static const Rule rules[] = {
  /* xprop(1):
   *	WM_CLASS(STRING) = instance, class
   *	WM_NAME(STRING) = title
   */
  /* class                     instance                 title                  tags mask  switchtotag  isfloating  monitor */
  { NULL,                      NULL,                    "Picture in picture",  0,         0,           1,          -1 },
	{ "st-256color",             "st-256color",           NULL,                  0,         0,           0,          -1 },
  { "st-256color",             "st-256color",           "mocp",                0,         0,           1,          -1 },
  { "st-256color",             "st-256color",           "pulsemixer",          0,         0,           1,          -1 },
  { "st-256color",             "st-256color",           "bluetoothctl",        0,         0,           1,          -1 },
  { "st-256color",             "st-256color",           "nnn",                 0,         0,           1,          -1 },
  { "Pulseeffects",            "pulseeffects",          NULL,                  0,         0,           1,          -1 },
  { "stacer",                  NULL,                    NULL,                  0,         0,           1,          -1 },
  { "Galculator",              NULL,                    NULL,                  0,         0,           1,          -1 },
  { "Thunar",                  NULL,                    NULL,                  0,         0,           1,          -1 },
  { "Dragon-drag-and-drop",    NULL,                    NULL,                  ~0,        0,           1,          -1 },
  { "Brave-browser",           "brave-browser",         NULL,                  1 << 1,    1,           0,          -1 },
  { "Brave-browser",           "mail.google.com__mail", NULL,                  1 << 2,    1,           0,          -1 },
  { "Thunderbird",             "Mail",                  NULL,                  1 << 2,    0,           0,          -1 },
  { "Thunderbird",             "Calendar",              NULL,                  0,         0,           1,          -1 },
  { "Thunderbird",             "Msgcompose",            NULL,                  0,         0,           1,          -1 },
  { NULL,                      NULL,                    "Discord",             1 << 3,    1,           0,          -1 },
  { "TelegramDesktop",         NULL,                    NULL,                  1 << 3,    1,           0,          -1 },
  { "Brave-browser",           "web.whatsapp.com",      NULL,                  1 << 3,    1,           0,          -1 },
  { "Brave-browser",           "nmg.kissflow.com",      NULL,                  1 << 3,    1,           0,          -1 },
  { "Brave-browser",           "app.clickup.com",       NULL,                  1 << 3,    1,           0,          -1 },
  { "Brave-browser",           "web.telegram.org",      NULL,                  1 << 3,    1,           0,          -1 },
  { "Zathura",                 NULL,                    NULL,                  1 << 4,    1,           0,          -1 },
  { "libreoffice-startcenter", NULL,                    NULL,                  1 << 4,    1,           0,          -1 },
  { "Sxiv",                    NULL,                    NULL,                  1 << 5,    1,           0,          -1 },
  { "Gimp",                    NULL,                    NULL,                  1 << 5,    1,           0,          -1 },
  { "Inkscape",                NULL,                    NULL,                  1 << 5,    1,           0,          -1 },
  { "mpv",                     NULL,                    NULL,                  1 << 6,    1,           0,          -1 },
  { "obs",                     NULL,                    NULL,                  1 << 6,    1,           0,          -1 },
  { "openshot",                NULL,                    NULL,                  1 << 6,    1,           0,          -1 },
  { "Steam",                   "Steam",                 NULL,                  1 << 7,    1,           1,          -1 },
  { "minecraft-launcher",      NULL,                    NULL,                  1 << 7,    1,           1,          -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"

static const Layout layouts[] = {
  /* first entry is default */
  /* symbol     arrange function */
  { "[\\]",     dwindle },
  { "[M]",      monocle },
  { "><>",      NULL },    /* no layout function means floating behavior */
  { "|M|",      centeredmaster },
  { ">M>",      centeredfloatingmaster },
  { "HHH",      grid },
  { "(@)",      spiral  },
  { "[]=",      tile }
};

/* key definitions */
#define MODKEY Mod4Mask
#define AltMask Mod1Mask
#define TAGKEYS(KEY,TAG) \
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

/* commands spawned when clicking statusbar, the mouse button pressed is exported as BUTTON */
static char *statuscmds[] = {
  "statuscmd.moc",
  "statuscmd.wkon",
  "statuscmd.storage",
  "statuscmd.battery",
  "notify-send X05 Mouse$BUTTON",
  "statuscmd.audio",
  "statuscmd.bluetooth",
  "statuscmd.notify",
  "statuscmd.internet",
};
static char *statuscmd[] = { "/bin/sh", "-c", NULL, NULL };

#include <X11/XF86keysym.h>
static Key keys[] = {
  /* modifier                     key                        function          argument */
  { MODKEY,                       XK_semicolon,              spawn,            {.v = dmenucmd } },
  { MODKEY,                       XK_t,                      spawn,            {.v = termcmd } },

  // Open
  { MODKEY,                       XK_w,                      spawn,            SHCMD("$BROWSER") },
  { MODKEY,                       XK_Return,                 spawn,            SHCMD("st -e nnn -edH ~") },
  { MODKEY,                       XK_n,                      spawn,            SHCMD("dunstctl set-paused toggle && refstatus") },
  { MODKEY|ControlMask,           XK_m,                      spawn,            SHCMD("st -e mocp -M ~/.config/moc") },
  { MODKEY,                       XK_v,                      spawn,            SHCMD("st -e pulsemixer") },
  { ControlMask,                  XK_Menu,                   spawn,            SHCMD("clipmenu 2>/dev/null") },
  { 0,                            XK_Pause,                  spawn,            SHCMD("slock") },
  { MODKEY,                       XK_p,                      spawn,            SHCMD("mocp -M ~/.config/moc --toggle-pause && refstatus") },
  { MODKEY,                       XK_bracketleft,            spawn,            SHCMD("mocp -M ~/.config/moc --previous") },
  { MODKEY,                       XK_bracketright,           spawn,            SHCMD("mocp -M ~/.config/moc --next") },

  // Script
  { MODKEY,                       XK_e,                      spawn,            SHCMD("emoji") },
  { MODKEY,                       XK_r,                      spawn,            SHCMD("refstatus") },
  { MODKEY,                       XK_c,                      spawn,            SHCMD("~/.config/dmenuquick/dmenuquick") },
  { MODKEY,                       XK_s,                      spawn,            SHCMD("dmenussh") },
  { MODKEY,                       XK_i,                      spawn,            SHCMD("dmenuwifi") },
  { MODKEY,                       XK_d,                      spawn,            SHCMD("dmenudisplay") },
  { MODKEY,                       XK_m,                      spawn,            SHCMD("dmenumount mount") },
  { MODKEY,                       XK_u,                      spawn,            SHCMD("dmenumount umount") },
  { MODKEY,                       XK_b,                      spawn,            SHCMD("dmenublue >/dev/null") },
  { 0,                            XK_Menu,                   spawn,            SHCMD("sysnotify") },
  { 0,                            XK_Print,                  spawn,            SHCMD("screenshot full") },
  { ShiftMask,                    XK_Print,                  spawn,            SHCMD("screenshot select") },
  { MODKEY,                       XK_Right,                  spawn,            SHCMD("brightness up && xobctl show brightness") },
  { MODKEY,                       XK_Left,                   spawn,            SHCMD("brightness down && xobctl show brightness") },
  { MODKEY,                       XK_Up,                     spawn,            SHCMD("audio up && xobctl show volume") },
  { MODKEY,                       XK_Down,                   spawn,            SHCMD("audio down && xobctl show volume") },

  //XF86 keys
  { 0,                            XF86XK_MonBrightnessUp,    spawn,            SHCMD("brightness up && xobctl show brightness") },
  { 0,                            XF86XK_MonBrightnessDown,  spawn,            SHCMD("brightness down && xobctl show brightness") },
  { 0,                            XF86XK_AudioMute,          spawn,            SHCMD("audio toggle && xobctl show volume") },
  { 0,                            XF86XK_AudioRaiseVolume,   spawn,            SHCMD("audio up && xobctl show volume") },
  { 0,                            XF86XK_AudioLowerVolume,   spawn,            SHCMD("audio down && xobctl show volume") },

  // Window Control
  { MODKEY|ShiftMask,             XK_b,                      togglebar,        {0} },
  { MODKEY,                       XK_j,                      focusstack,       {.i = +1 } },
  { MODKEY,                       XK_k,                      focusstack,       {.i = -1 } },
  { MODKEY,                       XK_h,                      setmfact,         {.f = -0.05} },
  { MODKEY,                       XK_l,                      setmfact,         {.f = +0.05} },
  { MODKEY,                       XK_z,                      zoom,             {0} },
  { MODKEY,                       XK_Tab,                    view,             {0} },
  { AltMask,                      XK_Tab,                    shiftviewclients, { .i = +1 } },
  { AltMask|ShiftMask,            XK_Tab,                    shiftviewclients, { .i = -1 } },
  { MODKEY,                       XK_q,                      killclient,       {0} },
  { MODKEY,                       XK_f,                      togglefullscr,    {0}  },
  { MODKEY,                       XK_space,                  togglefloating,   {0} },
  { MODKEY|ShiftMask,             XK_i,                      incnmaster,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_d,                      incnmaster,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,                      moveresize,       {.v = "0x 25y 0w 0h" } },
 	{ MODKEY|ShiftMask,             XK_k,                      moveresize,       {.v = "0x -25y 0w 0h" } },
 	{ MODKEY|ShiftMask,             XK_l,                      moveresize,       {.v = "25x 0y 0w 0h" } },
 	{ MODKEY|ShiftMask,             XK_h,                      moveresize,       {.v = "-25x 0y 0w 0h" } },
 	{ MODKEY|ControlMask,           XK_j,                      moveresize,       {.v = "0x 0y 0w 25h" } },
 	{ MODKEY|ControlMask,           XK_k,                      moveresize,       {.v = "0x 0y 0w -25h" } },
 	{ MODKEY|ControlMask,           XK_l,                      moveresize,       {.v = "0x 0y 25w 0h" } },
 	{ MODKEY|ControlMask,           XK_h,                      moveresize,       {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_q,                      moveplace,        {.ui = WIN_NW }},
	{ MODKEY|ControlMask,           XK_w,                      moveplace,        {.ui = WIN_N  }},
	{ MODKEY|ControlMask,           XK_e,                      moveplace,        {.ui = WIN_NE }},
	{ MODKEY|ControlMask,           XK_a,                      moveplace,        {.ui = WIN_W  }},
	{ MODKEY|ControlMask,           XK_s,                      moveplace,        {.ui = WIN_C  }},
	{ MODKEY|ControlMask,           XK_d,                      moveplace,        {.ui = WIN_E  }},
	{ MODKEY|ControlMask,           XK_z,                      moveplace,        {.ui = WIN_SW }},
	{ MODKEY|ControlMask,           XK_x,                      moveplace,        {.ui = WIN_S  }},
	{ MODKEY|ControlMask,           XK_c,                      moveplace,        {.ui = WIN_SE }},

  // Layout
  { MODKEY|ShiftMask,             XK_r,                      setlayout,        {.v = &layouts[0]} },
  { MODKEY|ShiftMask,             XK_m,                      setlayout,        {.v = &layouts[1]} },
  { MODKEY|ShiftMask,             XK_f,                      setlayout,        {.v = &layouts[2]} },
  { MODKEY|ShiftMask,             XK_c,                      setlayout,        {.v = &layouts[3]} },
  { MODKEY|ShiftMask,             XK_o,                      setlayout,        {.v = &layouts[4]} },
  { MODKEY|ShiftMask,             XK_g,                      setlayout,        {.v = &layouts[5]} },
	{ MODKEY|ShiftMask,             XK_s,                      setlayout,        {.v = &layouts[6]} },
	{ MODKEY|ShiftMask,             XK_t,                      setlayout,        {.v = &layouts[7]} },
  { MODKEY|ShiftMask,             XK_space,                  setlayout,        {0} },

  // Tag Control
  { MODKEY,                       XK_0,                      view,             {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,                      tag,              {.ui = ~0 } },
  { MODKEY,                       XK_comma,                  focusmon,         {.i = -1 } },
  { MODKEY,                       XK_period,                 focusmon,         {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,                  tagmon,           {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period,                 tagmon,           {.i = +1 } },
  TAGKEYS(                        XK_1,                                        0)
  TAGKEYS(                        XK_2,                                        1)
  TAGKEYS(                        XK_3,                                        2)
  TAGKEYS(                        XK_4,                                        3)
  TAGKEYS(                        XK_5,                                        4)
  TAGKEYS(                        XK_6,                                        5)
  TAGKEYS(                        XK_7,                                        6)
  TAGKEYS(                        XK_8,                                        7)
  TAGKEYS(                        XK_9,                                        8)

  // Quit
  { MODKEY|ShiftMask,             XK_F12,                    quit,             {0} },
  { MODKEY|ShiftMask,             XK_q,                      spawn,            SHCMD("power") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click                event mask      button          function        argument */
  { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
  { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,          0,              Button1,        zoom,           {0} },
  { ClkWinTitle,          0,              Button3,        spawn,          {.v = termcmd } },
  { ClkWinTitle,          0,              Button2,        spawn,          SHCMD("st -e nnn -edH ~") },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,              Button3,        spawn,          {.v = statuscmd } },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


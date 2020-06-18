/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 3;        /* horiz inner gap between windows */
static const unsigned int gappiv    = 3;        /* vert inner gap between windows */
static const unsigned int gappoh    = 6;        /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 6;        /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {
  "Source Code Pro:pixelsize=15:antialias=true:autohint=true",
  "NotoCJK:pixelsize=15:antialias=true:autohint=true",
  "JoyPixels:pixelsize=13:antialias=true:autohint=true",
  "Symbola:pixelsize=13:antialias=true:autohint=true",
  "Symbols Nerd Font:pixelsize=14:antialias=true:autohint=true"
};
static const char dmenufont[]       = "Source Code Pro:pixelsize=15:antialias=true:autohint=true";
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
static const char *tags[] = { "🐧","🗂","🌏","📝","💬","📬","🎧","🖼","🚫" };

static const Rule rules[] = {
  /* xprop(1):
   *	WM_CLASS(STRING) = instance, class
   *	WM_NAME(STRING) = title
   */
  /* class         instance         title                  tags mask     isfloating  isterminal  noswallow   monitor */
	{ "st-256color", "st-256color",   NULL,                  0,            0,          1,          -1,         -1 },
  { "st-256color", "st-256color",   "nnn",                 0,            1,          1,          -1,         -1 },
  { "Thunar",      NULL,            NULL,                  0,            1,          0,          0,          -1 },
  { "discord",     NULL,            NULL,                  0,            1,          0,          0,          -1 },
  { NULL,          NULL,            "Picture in picture",  0,            1,          0,          1,          -1 },
 	{ NULL,          NULL,            "Event Tester",        0,            0,          0,          1,          -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
  /* first entry is default */
  /* symbol     arrange function */
  { "[]=",      tile },
  { "><>",      NULL },    /* no layout function means floating behavior */
  { "[M]",      monocle },
  { "|M|",      centeredmaster },
  { ">M>",      centeredfloatingmaster },
  { "HHH",      grid }
};

/* key definitions */
#define MODKEY Mod4Mask
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

#include <X11/XF86keysym.h>
static Key keys[] = {
  /* modifier                     key           function        argument */
  { MODKEY,                       XK_semicolon, spawn,          {.v = dmenucmd } },
  { MODKEY,                       XK_t,         spawn,          {.v = termcmd } },

  // Script
  { MODKEY,                       XK_w,         spawn,          SHCMD("$BROWSER") },
  { MODKEY,                       XK_Return,    spawn,          SHCMD("st -e nnn -edH ~") },
  { MODKEY,                       XK_e,         spawn,          SHCMD("emoji") },
  { MODKEY,                       XK_n,         spawn,          SHCMD("dunsttoggle") },
  { MODKEY,                       XK_m,         spawn,          SHCMD("ac toggle") },
  { MODKEY,                       XK_Up,        spawn,          SHCMD("ac up") },
  { MODKEY,                       XK_Down,      spawn,          SHCMD("ac down") },
  { MODKEY|ShiftMask,             XK_Up,        spawn,          SHCMD("ac up 10") },
  { MODKEY|ShiftMask,             XK_Down,      spawn,          SHCMD("ac down 10") },
  { 0,                            XK_Print,     spawn,          SHCMD("screenshot") },

  // Window Control
  { MODKEY,                       XK_b,         togglebar,      {0} },
  { MODKEY,                       XK_j,         focusstack,     {.i = +1 } },
  { MODKEY,                       XK_k,         focusstack,     {.i = -1 } },
  { MODKEY,                       XK_i,         incnmaster,     {.i = +1 } },
  { MODKEY,                       XK_d,         incnmaster,     {.i = -1 } },
  { MODKEY,                       XK_h,         setmfact,       {.f = -0.05} },
  { MODKEY,                       XK_l,         setmfact,       {.f = +0.05} },
  { MODKEY,                       XK_z,         zoom,           {0} },
  { MODKEY,                       XK_Tab,       view,           {0} },
  { MODKEY,                       XK_q,         killclient,     {0} },
  { MODKEY,                       XK_f,         togglefullscr,  {0}  },
  { MODKEY,                       XK_space,     togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_j,         moveresize,     {.v = "0x 25y 0w 0h" } },
 	{ MODKEY|ShiftMask,             XK_k,         moveresize,     {.v = "0x -25y 0w 0h" } },
 	{ MODKEY|ShiftMask,             XK_l,         moveresize,     {.v = "25x 0y 0w 0h" } },
 	{ MODKEY|ShiftMask,             XK_h,         moveresize,     {.v = "-25x 0y 0w 0h" } },
 	{ MODKEY|ControlMask,           XK_j,         moveresize,     {.v = "0x 0y 0w 25h" } },
 	{ MODKEY|ControlMask,           XK_k,         moveresize,     {.v = "0x 0y 0w -25h" } },
 	{ MODKEY|ControlMask,           XK_l,         moveresize,     {.v = "0x 0y 25w 0h" } },
 	{ MODKEY|ControlMask,           XK_h,         moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_q,         moveplace,      {.ui = WIN_NW }},
	{ MODKEY|ControlMask,           XK_w,         moveplace,      {.ui = WIN_N  }},
	{ MODKEY|ControlMask,           XK_e,         moveplace,      {.ui = WIN_NE }},
	{ MODKEY|ControlMask,           XK_a,         moveplace,      {.ui = WIN_W  }},
	{ MODKEY|ControlMask,           XK_s,         moveplace,      {.ui = WIN_C  }},
	{ MODKEY|ControlMask,           XK_d,         moveplace,      {.ui = WIN_E  }},
	{ MODKEY|ControlMask,           XK_z,         moveplace,      {.ui = WIN_SW }},
	{ MODKEY|ControlMask,           XK_x,         moveplace,      {.ui = WIN_S  }},
	{ MODKEY|ControlMask,           XK_c,         moveplace,      {.ui = WIN_SE }},

  // Layout
  { MODKEY|ShiftMask,             XK_t,         setlayout,      {.v = &layouts[0]} },
  { MODKEY|ShiftMask,             XK_f,         setlayout,      {.v = &layouts[1]} },
  { MODKEY|ShiftMask,             XK_m,         setlayout,      {.v = &layouts[2]} },
  { MODKEY|ShiftMask,             XK_c,         setlayout,      {.v = &layouts[3]} },
  { MODKEY|ShiftMask,             XK_o,         setlayout,      {.v = &layouts[4]} },
  { MODKEY|ShiftMask,             XK_g,         setlayout,      {.v = &layouts[5]} },
  { MODKEY|ShiftMask,             XK_space,     setlayout,      {0} },

  // Tag Control
  { MODKEY,                       XK_0,         view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,         tag,            {.ui = ~0 } },
  { MODKEY,                       XK_comma,     focusmon,       {.i = -1 } },
  { MODKEY,                       XK_period,    focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,     tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period,    tagmon,         {.i = +1 } },
  TAGKEYS(                        XK_1,                         0)
  TAGKEYS(                        XK_2,                         1)
  TAGKEYS(                        XK_3,                         2)
  TAGKEYS(                        XK_4,                         3)
  TAGKEYS(                        XK_5,                         4)
  TAGKEYS(                        XK_6,                         5)
  TAGKEYS(                        XK_7,                         6)
  TAGKEYS(                        XK_8,                         7)
  TAGKEYS(                        XK_9,                         8)

  // Quit
  { MODKEY,                       XK_F12,       quit,           {0} },
  { MODKEY|ShiftMask,             XK_q,         spawn,          SHCMD("power") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click                event mask      button          function        argument */
  { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
  { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


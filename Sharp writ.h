//"ansi CSI Sharp writ" code
//CODE csi+<n;>+key
//CSI – Control Sequence Introducer" '\033['
//<n;> – "n numbers are separated by ';'" 'n;'*n-;
#define Ic(n,mod) "\033[" #n #mod
// Some ANSI escape sequences (not a complete list)
// Code	    Name – Effect
// CSI n A	CUU – CUrsor Up	Moves the cursor n (default 1) cells in the given direction. If the cursor is already at the edge of the screen, this has no effect.
// CSI n B	CUD – CUrsor Down
// CSI n C	CUF – CUrsor Forward
// CSI n D	CUB – CUrsor Back
// CSI n E	CNL – Cursor Next Line	Moves cursor to beginning of the line n (default 1) lines down.
// CSI n F	CPL – Cursor Previous Line	Moves cursor to beginning of the line n (default 1) lines up.
// CSI n G	CHA – Cursor Horizontal Absolute	Moves the cursor to column n.
// CSI n ; m H	CUP – CUrsor Position	Moves the cursor to row n, column m. The values are 1-based, and default to 1 (top left corner) if omitted. A sequence such as CSI ;5H is a synonym for CSI 1;5H as well as CSI 17;H is the same as CSI 17H and CSI 17;1H
#define cup "\033[%d;%dH"
#define zero "\033[0;0H"
#define Ied(n) "\033["#n"J"// CSI n J	ED – Erase Data	Clears part of the screen. If n is zero (or missing), clear from cursor to end of screen. If n is one, clear from cursor to beginning of the screen. If n is two, clear entire screen (and moves cursor to upper left on MS-DOS ANSI.SYS).
#define flash "\033[2J"
// CSI n K	EL – Erase in Line	Erases part of the line. If n is zero (or missing), clear from cursor to the end of the line. If n is one, clear from cursor to beginning of the line. If n is two, clear entire line. Cursor position does not change.
// CSI n S	SU – Scroll Up	Scroll whole page up by n (default 1) lines. New lines are added at the bottom. (not ANSI.SYS)
// CSI n T	SD – Scroll Down	Scroll whole page down by n (default 1) lines. New lines are added at the top. (not ANSI.SYS)
// CSI n ; m f	HVP – Horizontal and Vertical Position	Moves the cursor to row n, column m. Both default to 1 if omitted. Same as CUP
// CSI sgr m	SGR – Select Graphic Rendition	Sets SGR parameters, including text color. After CSI can be zero or more parameters separated with ;. With no parameters, CSI m is treated as CSI 0 m (reset / normal), which is typical of most of the ANSI escape sequences.##if the liter is the open style.it not item##
// CSI 6 n	DSR – Device Status Report	Reports the cursor position to the application as (as though typed at the keyboard) ESC[n;mR, where n is the row and m is the column. (May not work on MS-DOS.)
// CSI s	SCP – Save Cursor Position	Saves the cursor position.
// CSI u	RCP – Restore Cursor Position	Restores the cursor position.
#define hideCur "\033[?25l"// CSI ?25l	DECTCEM	Hides the cursor. (Note: the trailing character is lowercase L.)
#define showCur "\033[?25h"// CSI ?25h	DECTCEM	Shows the cursor.

#define Ig(n)    "\033["#n"m"
#define sgr      "\033[%dm"
// SGR – "Select Graphic Rendition" code <n;>
// Code	Effect	Note
#define Rset      "\033[0m"// 0	Reset / Normal	all attributes off
#define Bright    "\033[1m"// 1	Bright (increased intensity) or Bold	
#define Faint     "\033[2m"// 2	Faint (decreased intensity)	not widely supported
#define Italic    "\033[3m"// 3	Italic: on	not widely supported. Sometimes treated as inverse.
#define Underline "\033[4m"// 4	Underline: Single	
#define Blink     "\033[5m"// 5	Blink: Slow	less than 150 per minute
#define Blinkfast "\033[6m"// 6	Blink: Rapid	MS-DOS ANSI.SYS; 150 per minute or more; not widely supported
#define Image     "\033[7m"// 7	Image: Negative	inverse or reverse; swap foreground and background
#define Conceal   "\033[8m"// 8	Conceal	not widely supported
#define Crossed   "\033[9m"// 9	Crossed-out	Characters legible, but marked for deletion. Not widely supported.
#define DefaultFont "\033[10m"// 10	Primary(default) font	

// 11–19 n-th alternate font	Select the n-th alternate font. 14 being the fourth alternate font, up to 19 being the 9th alternate font.
#define Fraktur "\033[20m"// 20	Fraktur	hardly ever supported

#define offBold "\033[21m"// 21	Bright/Bold: off or Underline: Double	bold off not widely supported, double underline hardly ever
#define offcolorful "\033[22m"// 22	Normal color or intensity	neither bright, bold nor faint
#define offFraktur "\033[23m"// 23	Not italic, not Fraktur	
#define offUnderline "\033[24m"// 24	Underline: None	not singly or doubly underlined
#define offBlink "\033[25m"// 25	Blink: off	
// 26	Reserved	
#define offImage "\033[27m"// 27	Image: Positive	
#define offConceal "\033[28m"// 28	Reveal	conceal off
#define offCrossed "\033[29m"// 29	Not crossed out	

#define FBlack "\033[30m"// 30–37	Set text color	30 + x, where x is from the color table below
#define FRed "\033[31m"
#define FGreen "\033[32m"
#define FYellow "\033[33m"
#define FBlue "\033[34m"
#define Fagenta "\033[35m"
#define FCyan "\033[36m"
#define FWhite "\033[37m"
typedef enum {
    Black  =0,
    Red    =1,
    Green  =2,
    Yellow =3,
    Blue   =4,
    agenta =5,
    Cyan   =6,
    White  =7,
}colors;

// 38;5;n   Set xterm-256 text color n is color index (0..255)
#define xrgb "\e[38;5;%dm"
#define _xrgb(r,g,b) 16+36*r+6*g+b
// 38;2;r;g;b	Set 0-255 of r,g,b 24bit color
#define rgb "\e[38;2;%d;%d;%dm"
// 39	Default text color	implementation defined (according to standard)

#define BBlack "\033[40m"// 40–47	Set background color	40 + x, where x is from the color table below
#define BRed "\033[41m"
#define BGreen "\033[42m"
#define BYellow "\033[43m"
#define BBlue "\033[44m"
#define BMagenta "\033[45m"
#define BCyan "\033[46m"
#define BWhite "\033[47m"

// 48;5;n   index 38
// 48;2;r;g;b	index 38
// 49	Default background color	implementation defined (according to standard)

// 50	Reserved	
// 51	Framed	
// 52	Encircled	
#define Overline "\033[53m"// 53	Overlined	
// 54	Not framed or encircled	
#define offOverline "\033[55m"// 55	Not overlined	
// 56–59	Reserved	
// 60	ideogram underline or right side line	hardly ever supported
// 61	ideogram double underline or double line on the right side	hardly ever supported
// 62	ideogram overline or left side line	hardly ever supported
// 63	ideogram double overline or double line on the left side	hardly ever supported
// 64	ideogram stress marking	hardly ever supported

#define LBlack "\033[90m"// 90–99	Set foreground color, high intensity	aixterm (not in standard)
#define LRed "\033[91m"
#define LGreen "\033[92m"
#define LYellow "\033[93m"
#define LBlue "\033[94m"
#define LMagenta "\033[95m"
#define LCyan "\033[96m"
#define LWhite "\033[97m"

#define LBBlack "\033[100m"// 100–109	Set background color, high intensity	aixterm (not in standard)
#define LBRed "\033[101m"
#define LBGreen "\033[102m"
#define LBYellow "\033[103m"
#define LBBlue "\033[104m"
#define LBMagenta "\033[105m"
#define LBCyan "\033[106m"
#define LBWhite "\033[107m"
typedef struct warp {
    int x,y;//cup
    unsigned char style,font,color,back;//1-10 11-19 (30-37or90–99) (40–47or100–109)
    int r,g,b;//rgb
} warp;

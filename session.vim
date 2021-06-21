let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/DAG-EUF-Algorithm
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +34 src/EUFInterpolator.cpp
badd +15 include/EUFInterpolator.h
badd +32 include/TripletState.h
badd +1 src/TripletState-Rules.cpp
badd +8 src/TripletState.cpp
badd +0 include/Preprocessor.h
argglobal
%argdel
edit include/EUFInterpolator.h
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd w
wincmd w
wincmd w
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 1resize ' . ((&columns * 117 + 236) / 472)
exe '2resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 2resize ' . ((&columns * 117 + 236) / 472)
exe '3resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 3resize ' . ((&columns * 118 + 236) / 472)
exe '4resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 4resize ' . ((&columns * 117 + 236) / 472)
exe '5resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 5resize ' . ((&columns * 117 + 236) / 472)
exe '6resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 6resize ' . ((&columns * 177 + 236) / 472)
exe '7resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 7resize ' . ((&columns * 176 + 236) / 472)
argglobal
balt src/EUFInterpolator.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 15 - ((14 * winheight(0) + 21) / 43)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 15
normal! 0
wincmd w
argglobal
if bufexists("src/EUFInterpolator.cpp") | buffer src/EUFInterpolator.cpp | else | edit src/EUFInterpolator.cpp | endif
if &buftype ==# 'terminal'
  silent file src/EUFInterpolator.cpp
endif
balt include/EUFInterpolator.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 23 - ((22 * winheight(0) + 21) / 43)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 23
normal! 07|
wincmd w
argglobal
if bufexists("include/TripletState.h") | buffer include/TripletState.h | else | edit include/TripletState.h | endif
if &buftype ==# 'terminal'
  silent file include/TripletState.h
endif
balt include/EUFInterpolator.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 26 - ((23 * winheight(0) + 21) / 43)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 26
normal! 0
wincmd w
argglobal
if bufexists("include/Preprocessor.h") | buffer include/Preprocessor.h | else | edit include/Preprocessor.h | endif
if &buftype ==# 'terminal'
  silent file include/Preprocessor.h
endif
balt include/TripletState.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 17 - ((16 * winheight(0) + 21) / 43)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 17
normal! 0
wincmd w
argglobal
if bufexists("include/TripletState.h") | buffer include/TripletState.h | else | edit include/TripletState.h | endif
if &buftype ==# 'terminal'
  silent file include/TripletState.h
endif
balt include/EUFInterpolator.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 48 - ((29 * winheight(0) + 21) / 43)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 48
normal! 03|
wincmd w
argglobal
if bufexists("src/TripletState.cpp") | buffer src/TripletState.cpp | else | edit src/TripletState.cpp | endif
if &buftype ==# 'terminal'
  silent file src/TripletState.cpp
endif
balt src/TripletState-Rules.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 3 - ((2 * winheight(0) + 21) / 43)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 3
normal! 030|
wincmd w
argglobal
if bufexists("src/TripletState-Rules.cpp") | buffer src/TripletState-Rules.cpp | else | edit src/TripletState-Rules.cpp | endif
if &buftype ==# 'terminal'
  silent file src/TripletState-Rules.cpp
endif
balt include/EUFInterpolator.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 21) / 43)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
3wincmd w
exe '1resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 1resize ' . ((&columns * 117 + 236) / 472)
exe '2resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 2resize ' . ((&columns * 117 + 236) / 472)
exe '3resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 3resize ' . ((&columns * 118 + 236) / 472)
exe '4resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 4resize ' . ((&columns * 117 + 236) / 472)
exe '5resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 5resize ' . ((&columns * 117 + 236) / 472)
exe '6resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 6resize ' . ((&columns * 177 + 236) / 472)
exe '7resize ' . ((&lines * 43 + 44) / 89)
exe 'vert 7resize ' . ((&columns * 176 + 236) / 472)
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0&& getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOFI
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :

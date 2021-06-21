let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/euf
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +0 src/EUFInterpolator.cpp
badd +0 include/EUFInterpolator.h
badd +0 include/TripletState.h
badd +1 src/TripletState-Rules.cpp
badd +0 src/TripletState.cpp
argglobal
%argdel
edit include/EUFInterpolator.h
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
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
exe '1resize ' . ((&lines * 30 + 31) / 63)
exe 'vert 1resize ' . ((&columns * 78 + 157) / 314)
exe '2resize ' . ((&lines * 30 + 31) / 63)
exe 'vert 2resize ' . ((&columns * 78 + 157) / 314)
exe '3resize ' . ((&lines * 30 + 31) / 63)
exe 'vert 3resize ' . ((&columns * 156 + 157) / 314)
exe '4resize ' . ((&lines * 30 + 31) / 63)
exe 'vert 4resize ' . ((&columns * 78 + 157) / 314)
exe '5resize ' . ((&lines * 30 + 31) / 63)
exe 'vert 5resize ' . ((&columns * 77 + 157) / 314)
exe 'vert 6resize ' . ((&columns * 78 + 157) / 314)
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
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists("src/EUFInterpolator.cpp") | buffer src/EUFInterpolator.cpp | else | edit src/EUFInterpolator.cpp | endif
if &buftype ==# 'terminal'
  silent file src/EUFInterpolator.cpp
endif
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
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists("include/TripletState.h") | buffer include/TripletState.h | else | edit include/TripletState.h | endif
if &buftype ==# 'terminal'
  silent file include/TripletState.h
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
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
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
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists("src/TripletState-Rules.cpp") | buffer src/TripletState-Rules.cpp | else | edit src/TripletState-Rules.cpp | endif
if &buftype ==# 'terminal'
  silent file src/TripletState-Rules.cpp
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
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
enew
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
wincmd w
5wincmd w
exe '1resize ' . ((&lines * 30 + 31) / 63)
exe 'vert 1resize ' . ((&columns * 78 + 157) / 314)
exe '2resize ' . ((&lines * 30 + 31) / 63)
exe 'vert 2resize ' . ((&columns * 78 + 157) / 314)
exe '3resize ' . ((&lines * 30 + 31) / 63)
exe 'vert 3resize ' . ((&columns * 156 + 157) / 314)
exe '4resize ' . ((&lines * 30 + 31) / 63)
exe 'vert 4resize ' . ((&columns * 78 + 157) / 314)
exe '5resize ' . ((&lines * 30 + 31) / 63)
exe 'vert 5resize ' . ((&columns * 77 + 157) / 314)
exe 'vert 6resize ' . ((&columns * 78 + 157) / 314)
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

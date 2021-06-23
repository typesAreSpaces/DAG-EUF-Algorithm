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
badd +49 src/EUFInterpolator.cpp
badd +24 include/EUFInterpolator.h
badd +9 include/TripletState.h
badd +275 src/TripletState-Rules.cpp
badd +157 src/TripletState.cpp
badd +6 include/Preprocessor.h
badd +30 src/TripletState-Constructors.cpp
badd +41 src/CircularPairIterator.cpp
badd +4 include/CircularPairIterator.h
badd +35 src/main.cpp
badd +20 include/Util.h
badd +5 src/Util.cpp
badd +5 src/Preprocessor.cpp
badd +1 src/Preprocessor-normalizeInput.cpp
badd +117 src/Preprocessor-flattenPredicate.cpp
argglobal
%argdel
edit include/EUFInterpolator.h
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
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
wincmd _ | wincmd |
vsplit
2wincmd h
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
exe '1resize ' . ((&lines * 28 + 39) / 79)
exe 'vert 1resize ' . ((&columns * 90 + 136) / 272)
exe '2resize ' . ((&lines * 28 + 39) / 79)
exe 'vert 2resize ' . ((&columns * 90 + 136) / 272)
exe '3resize ' . ((&lines * 28 + 39) / 79)
exe 'vert 3resize ' . ((&columns * 90 + 136) / 272)
exe '4resize ' . ((&lines * 48 + 39) / 79)
exe 'vert 4resize ' . ((&columns * 90 + 136) / 272)
exe '5resize ' . ((&lines * 48 + 39) / 79)
exe 'vert 5resize ' . ((&columns * 90 + 136) / 272)
exe '6resize ' . ((&lines * 48 + 39) / 79)
exe 'vert 6resize ' . ((&columns * 90 + 136) / 272)
argglobal
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
let s:l = 7 - ((6 * winheight(0) + 14) / 28)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 7
normal! 033|
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
let s:l = 11 - ((10 * winheight(0) + 14) / 28)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 11
normal! 033|
wincmd w
argglobal
if bufexists("src/TripletState-Constructors.cpp") | buffer src/TripletState-Constructors.cpp | else | edit src/TripletState-Constructors.cpp | endif
if &buftype ==# 'terminal'
  silent file src/TripletState-Constructors.cpp
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
let s:l = 1 - ((0 * winheight(0) + 14) / 28)
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
balt src/TripletState.cpp
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
let s:l = 20 - ((13 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 20
normal! 025|
wincmd w
argglobal
if bufexists("src/TripletState-Rules.cpp") | buffer src/TripletState-Rules.cpp | else | edit src/TripletState-Rules.cpp | endif
if &buftype ==# 'terminal'
  silent file src/TripletState-Rules.cpp
endif
balt src/TripletState.cpp
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
let s:l = 276 - ((29 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 276
normal! 09|
wincmd w
argglobal
if bufexists("src/main.cpp") | buffer src/main.cpp | else | edit src/main.cpp | endif
if &buftype ==# 'terminal'
  silent file src/main.cpp
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
let s:l = 8 - ((7 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 8
normal! 0
wincmd w
4wincmd w
exe '1resize ' . ((&lines * 28 + 39) / 79)
exe 'vert 1resize ' . ((&columns * 90 + 136) / 272)
exe '2resize ' . ((&lines * 28 + 39) / 79)
exe 'vert 2resize ' . ((&columns * 90 + 136) / 272)
exe '3resize ' . ((&lines * 28 + 39) / 79)
exe 'vert 3resize ' . ((&columns * 90 + 136) / 272)
exe '4resize ' . ((&lines * 48 + 39) / 79)
exe 'vert 4resize ' . ((&columns * 90 + 136) / 272)
exe '5resize ' . ((&lines * 48 + 39) / 79)
exe 'vert 5resize ' . ((&columns * 90 + 136) / 272)
exe '6resize ' . ((&lines * 48 + 39) / 79)
exe 'vert 6resize ' . ((&columns * 90 + 136) / 272)
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
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :

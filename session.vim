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
badd +22 src/EUFInterpolator.cpp
badd +24 include/EUFInterpolator.h
badd +68 include/TripletState.h
badd +123 src/TripletState-Rules.cpp
badd +61 src/TripletState.cpp
badd +10 include/Preprocessor.h
badd +48 src/TripletState-Constructors.cpp
badd +28 src/CircularPairIterator.cpp
badd +11 include/CircularPairIterator.h
badd +51 src/main.cpp
badd +24 include/Util.h
badd +36 src/Util.cpp
badd +5 src/Preprocessor.cpp
badd +1 src/Preprocessor-normalizeInput.cpp
badd +117 src/Preprocessor-flattenPredicate.cpp
argglobal
%argdel
edit include/TripletState.h
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
wincmd _ | wincmd |
split
1wincmd k
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
exe '1resize ' . ((&lines * 67 + 51) / 102)
exe 'vert 1resize ' . ((&columns * 93 + 140) / 281)
exe '2resize ' . ((&lines * 33 + 51) / 102)
exe 'vert 2resize ' . ((&columns * 93 + 140) / 281)
exe '3resize ' . ((&lines * 33 + 51) / 102)
exe 'vert 3resize ' . ((&columns * 93 + 140) / 281)
exe '4resize ' . ((&lines * 67 + 51) / 102)
exe 'vert 4resize ' . ((&columns * 93 + 140) / 281)
exe '5resize ' . ((&lines * 32 + 51) / 102)
exe 'vert 5resize ' . ((&columns * 93 + 140) / 281)
exe '6resize ' . ((&lines * 32 + 51) / 102)
exe 'vert 6resize ' . ((&columns * 93 + 140) / 281)
exe '7resize ' . ((&lines * 32 + 51) / 102)
exe 'vert 7resize ' . ((&columns * 93 + 140) / 281)
argglobal
balt include/CircularPairIterator.h
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
let s:l = 66 - ((47 * winheight(0) + 33) / 67)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 66
normal! 02|
wincmd w
argglobal
if bufexists("include/CircularPairIterator.h") | buffer include/CircularPairIterator.h | else | edit include/CircularPairIterator.h | endif
if &buftype ==# 'terminal'
  silent file include/CircularPairIterator.h
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
let s:l = 20 - ((16 * winheight(0) + 16) / 33)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 20
normal! 09|
wincmd w
argglobal
if bufexists("src/CircularPairIterator.cpp") | buffer src/CircularPairIterator.cpp | else | edit src/CircularPairIterator.cpp | endif
if &buftype ==# 'terminal'
  silent file src/CircularPairIterator.cpp
endif
balt include/CircularPairIterator.h
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
let s:l = 32 - ((13 * winheight(0) + 16) / 33)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 32
normal! 0
wincmd w
argglobal
if bufexists("include/CircularPairIterator.h") | buffer include/CircularPairIterator.h | else | edit include/CircularPairIterator.h | endif
if &buftype ==# 'terminal'
  silent file include/CircularPairIterator.h
endif
balt src/CircularPairIterator.cpp
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
let s:l = 31 - ((30 * winheight(0) + 33) / 67)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 31
normal! 06|
wincmd w
argglobal
if bufexists("src/TripletState.cpp") | buffer src/TripletState.cpp | else | edit src/TripletState.cpp | endif
if &buftype ==# 'terminal'
  silent file src/TripletState.cpp
endif
balt include/CircularPairIterator.h
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
let s:l = 56 - ((17 * winheight(0) + 16) / 32)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 56
normal! 0
wincmd w
argglobal
if bufexists("src/TripletState-Rules.cpp") | buffer src/TripletState-Rules.cpp | else | edit src/TripletState-Rules.cpp | endif
if &buftype ==# 'terminal'
  silent file src/TripletState-Rules.cpp
endif
balt src/CircularPairIterator.cpp
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
let s:l = 46 - ((19 * winheight(0) + 16) / 32)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 46
normal! 045|
wincmd w
argglobal
if bufexists("src/TripletState-Rules.cpp") | buffer src/TripletState-Rules.cpp | else | edit src/TripletState-Rules.cpp | endif
if &buftype ==# 'terminal'
  silent file src/TripletState-Rules.cpp
endif
balt src/CircularPairIterator.cpp
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
let s:l = 163 - ((20 * winheight(0) + 16) / 32)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 163
normal! 07|
wincmd w
exe '1resize ' . ((&lines * 67 + 51) / 102)
exe 'vert 1resize ' . ((&columns * 93 + 140) / 281)
exe '2resize ' . ((&lines * 33 + 51) / 102)
exe 'vert 2resize ' . ((&columns * 93 + 140) / 281)
exe '3resize ' . ((&lines * 33 + 51) / 102)
exe 'vert 3resize ' . ((&columns * 93 + 140) / 281)
exe '4resize ' . ((&lines * 67 + 51) / 102)
exe 'vert 4resize ' . ((&columns * 93 + 140) / 281)
exe '5resize ' . ((&lines * 32 + 51) / 102)
exe 'vert 5resize ' . ((&columns * 93 + 140) / 281)
exe '6resize ' . ((&lines * 32 + 51) / 102)
exe 'vert 6resize ' . ((&columns * 93 + 140) / 281)
exe '7resize ' . ((&lines * 32 + 51) / 102)
exe 'vert 7resize ' . ((&columns * 93 + 140) / 281)
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

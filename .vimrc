version 6.0
if &cp | set nocp | endif
nnoremap <silent> w :CCTreeWindowToggle
nnoremap <silent> y :CCTreeWindowSaveCopy
let s:cpo_save=&cpo
set cpo&vim
nmap gx <Plug>NetrwBrowseX
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
let &cpo=s:cpo_save
unlet s:cpo_save
set background=dark
set backspace=indent,eol,start
set cscopeprg=/usr/bin/cscope
set cscopetag
set cscopeverbose
set fileencodings=ucs-bom,utf-8,latin1
set guicursor=n-v-c:block,o:hor50,i-ci:hor15,r-cr:hor30,sm:block,a:blinkon0
set helplang=en
set history=50
set hlsearch
set ruler
set viminfo='20,\"50
" vim: set ft=vim :

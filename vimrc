call plug#begin('~/.vim/plugged')
Plug 'preservim/nerdtree'
Plug 'vim-airline/vim-airline'
Plug 'tpope/vim-commentary'
call plug#end()

syntax on
colorscheme onedark
set tabstop=4
set nu
set softtabstop=4
set shiftwidth=4
set expandtab
set ruler
set ru
set autoindent
set smartindent
set clipboard=unnamed
set mouse=a
set updatetime=500

let t:is_transparent_background=1
fu! Change_Background()
  if t:is_transparent_background == 0
    hi Normal guibg=NONE ctermbg=NONE
    let t:is_transparent_background=1
  else
    colors onedark 
    let t:is_transparent_background=0
  endif
endf
nnoremap <F4> :call Change_Background()<CR>

nnoremap copy :%y+<CR>

autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 1 && isdirectory(argv()[0]) && !exists("s:std_in") | exe 'NERDTree' argv()[0] | wincmd p | ene | exe 'cd '.argv()[0] | endif

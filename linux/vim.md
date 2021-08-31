# config

```text
set history=100

set autoread

" Fast saving
let mapleader = ";"
nmap <leader>w :w!<cr>

let $LANG='en'
set langmenu=en
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim

set ruler
set hid

" Highlight search
set incsearch

" Regex
" set magic

set showmatch
set mat=2

" margin left
set foldcolumn=1

" syntax highlighting
syntax enable

set encoding=utf8

if $COLORTERM == 'gnome-terminal'
    set t_Co=256
endif


if has("gui_running")
    set guioptions-=T
    set guioptions-=e
    set t_Co=256
    set guitablabel=%M\ %t
endif


" Turn backup off
set nobackup
set nowb
set noswapfile

" Use spaces instead of tabs
set expandtab
set shiftwidth=4
set smarttab

" indent
set ai
set si

set laststatus=2
set statusline=\ %{HasPaste()}%F%m%r%h\ %w\ \ CWD:\ %r%{getcwd()}%h\ \ \ Line:\ %l\ \ Column:\ %c
function! HasPaste()
    if &paste
        return 'PASTE MODE  '
    endif
    return ''
endfunction
```

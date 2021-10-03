if has("syntax")
	syntax on
endif

au BufReadPost *
\ if line("'\"") > 0 && line("'\"") <= line("$") |
\ exe "norm g`\"" |
\ endif

set hlsearch
set nu
set autoindent
set smartindent
set cindent
set scrolloff=4
set ts=4
set shiftwidth=4
set softtabstop=4
set ls=2

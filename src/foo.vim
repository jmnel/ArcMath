
"function! Foobar()
"    return aaaa
"endfunction

"inoremap <silent><expr> <TAB>
"    \ pumvisible() ? \<C-n>" :
"    \ <SID>check_back_space() ? \<TAB>" :
"    \ coc#refresh()
"inoremap <expr><S-TAB> pumvisible() ? \<C-p>" : \<C-h>"

"function! s:check_back_space() abort
"    let col = col('.') - 1
"    return !col || getline('.')[col - 1] =-# '\s'
"endfunction


inoremap <silent><expr> <TAB> pumvisible() ? '<C-n>' : '<TAB>'
inoremap <silent><expr> <S-TAB> pumvisible() ? '<C-p>' : ''
inoremap <expr> <cr> pumvisible() ? "\<C-y>" : "<CR>"

nmap <tab> :bnext<CR>
nmap <s-tab> :bprevious<CR>

function! s:Foo()
    return '\<C-n>'
endfunction

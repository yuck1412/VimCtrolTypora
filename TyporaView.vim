function! TyporaView(pos,step)
" ========== TyporaView ========== {{{
    if !has('gui_win32')
        return
    endif

    update
    let baseNum = 50000 
    if a:pos=='h' || a:pos=='k' 
        let baseNum = 40000
    elseif a:pos=='l' || a:pos=='j'
        let baseNum = 50000
    else
        return
    endif
    let ctrVal = baseNum + a:step
    call libcallnr(g:typoraViewDll, 'ControlTyporaView', ctrVal)
" }}}
endfunction

" 如果当前 .vim 和 DLL 同路径不用修改,否则需要修改
let sFileP = fnamemodify( expand('<sfile>') , ':p:h')
if has('gui_win32') && has('num64')
    let typoraViewDll = sFileP.'\ControlTyporaView.x64.dll'
elseif has('gui_win32')
    let typoraViewDll = sFileP.'\ControlTyporaView.x86.dll'
endif

let FunStep = 1
" 快捷方式按个人喜好修改
" wheel up step*4
nnoremap <M-h> :call TyporaView('h', 4)<cr> 

" wheel down step*4
nnoremap <M-l> :call TyporaView('l', 4)<cr>

" wheel down step*1
nnoremap <M-j> :call TyporaView('j', 1)<cr>

" wheel up step*1
nnoremap <M-k> :call TyporaView('k', 1)<cr>


" 核心思想就是下面call libcallnr()
" ControlTyporaView 是一个function, 找到Typora, 然后根据ctrVal模拟鼠标滚动，最后回到gvim上
" call libcallnr(typoraViewDll, 'ControlTyporaView', ctrVal)

" 传入ControlTyporaView的参数是ctrlVal(整数), 
" 在 40000<ctrlVal<50000 表示向上滚动,滚动多少由 ctrVal%10000 控制 
" 在 50000<ctrlVal<60000 表示向下滚动,滚动多少由 ctrVal%10000 控制 
" 只有40000 ~ 60000 之间有效


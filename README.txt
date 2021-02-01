1. 修改自己喜好的快捷方式
   TyporaView.vim 定义的快捷键
   Alt-h 鼠标上滚 4个step
   Alt-l 鼠标下滚 4个step
   Alt-k 鼠标上滚 1个step
   Alt-j 鼠标下滚 1个step

2. 个人vimrc 添加 source  D:\vimPlug\VimCtrolTypora\TyporaView.vim  
   替换成自己的路径,我自己的插件都喜欢直接source

3. 用 gvim 和 Typora 打开同一个 .md 文件, gvim 编辑完保存时 Typora会刷新
   用自己修改的快捷键可以浏览 Typora 界面
   有可能会找到控制chrome浏览器,建议把chrome浏览器最小化使用

4. 一定要修改 TyporaView.vim 中 DLL 路径        
    有兴趣可以看下 C code,调用win32

- ControlTyporaView.c         c实现 ControlTyporaView
- ControlTyporaView.x64.dll   x64 dll
- ControlTyporaView.x86.dll   x86 dll
- gen_cmd.x64.bat             vs 产生 x64.dll
- gen_cmd.x86.bat             vs 产生 x64.dll
- TyporaView.vim              vim 调用 dll, 绑定快捷键 


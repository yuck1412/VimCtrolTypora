#include <Windows.h>
#include <WinBase.h>

HWND _declspec(dllexport) ControlTyporaView(int ctrCmd){
// ========== ToggleTitleBar ========== {{{
    HWND curHwnd;
    HWND typHwnd;
    curHwnd = GetForegroundWindow();
    typHwnd = FindWindow("Chrome_WidgetWin_1", NULL); // have error
    if (typHwnd==0){
        return typHwnd;
    }

    POINT curPoint; 
	RECT rc;
    GetWindowRect(typHwnd, &rc);
    GetCursorPos(&curPoint);
    SetForegroundWindow(typHwnd);
    SetCursorPos( rc.left+200, rc.top+200 );
    //mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, NULL);
    //mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, NULL);

    int key_num,i; 
    key_num = ctrCmd % 10000;

    // ========== have error  ========== {{{
    /*
    if (    0 <= ctrCmd && ctrCmd < 10000) { // key press
        keybd_event(65, 0, 0, 0);
        keybd_event(65, 0, KEYEVENTF_KEYUP, 0);
        SetCursorPos(curPoint.x, curPoint.y);
        SetForegroundWindow(curHwnd);
    } else if (10000 <= ctrCmd && ctrCmd < 20000) { // ctrl-key press
        keybd_event(17, 0, 0, 0); // ctrl
        keybd_event(key_num, 0, 0, 0);
        keybd_event(key_num, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(17, 0, KEYEVENTF_KEYUP, 0); //ctrl release

    } else if (20000 <= ctrCmd && ctrCmd < 30000) { // shift-key press
        keybd_event(16, 0, 0, 0); // shift
        keybd_event(key_num, 0, 0, 0);
        keybd_event(key_num, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(16, 0, KEYEVENTF_KEYUP, 0); //ctrl release

    } else if (30000 <= ctrCmd && ctrCmd < 40000) { // ctrl-shift press
        keybd_event(17, 0, 0, 0); // ctrl
        keybd_event(16, 0, 0, 0); // shift
        keybd_event(key_num, 0, 0, 0);
        keybd_event(key_num, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(16, 0, KEYEVENTF_KEYUP, 0); //shift release
        keybd_event(17, 0, KEYEVENTF_KEYUP, 0); //ctrl release

    } else if (40000 < ctrCmd && ctrCmd < 50000) { // wheel up
        for (i=0; i<key_num; i++) {
            mouse_event(MOUSEEVENTF_WHEEL,0,0,2*WHEEL_DELTA, NULL );
        }

    } else if (50000 < ctrCmd && ctrCmd < 60000) { // wheel down
        for (i=0; i<key_num; i++) {
            mouse_event(MOUSEEVENTF_WHEEL,0,0,0-2*WHEEL_DELTA, NULL );
        }
    }
    */
    // }}}
    if (40000 < ctrCmd && ctrCmd < 50000) { // wheel up
        for (i=0; i<key_num; i++) {
            mouse_event(MOUSEEVENTF_WHEEL,0,0,WHEEL_DELTA, NULL );
        }
        Sleep(5);
    } else if (50000 < ctrCmd && ctrCmd < 60000) { // wheel down
        for (i=0; i<key_num; i++) {
            mouse_event(MOUSEEVENTF_WHEEL,0,0,0-WHEEL_DELTA, NULL );
        }
        Sleep(5);
    }

    SetForegroundWindow(curHwnd);
    SetCursorPos(curPoint.x, curPoint.y);

    return typHwnd;
}
// }}}



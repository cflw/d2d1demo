#include "图形.h"
#include "常量.h"
void C图形::f初始化(HWND a窗口) {
	m二维.f初始化(a窗口, c缩放);
}
void C图形::f销毁() {
}
void C图形::f计算() {
}
void C图形::f更新() {
}
void C图形::f显示() {
	auto &v渲染控制 = m二维.fg渲染控制();
	v渲染控制.f开始();
	v渲染控制.f清屏();

	v渲染控制.f结束();
}
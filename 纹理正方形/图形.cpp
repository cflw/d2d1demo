#include "图形.h"
#include "常量.h"
#include <cflw图形_dx纹理.h>
namespace 纹理 = cflw::图形::dx纹理;
void C图形::f初始化(HWND a窗口) {
	m二维.f初始化(a窗口, c缩放);
	纹理::C图像工厂 v图像工厂;
	v图像工厂.f初始化();
	auto v纹理 = v图像工厂.f高级读取(L"纹理.jpg", 纹理::格式::F强制转换(纹理::格式::c通用pbgra));
	m位图 = m二维.fc位图(v纹理);
	m画笔 = m二维.fc位图画笔(m位图);
	m画图形 = m二维.fc画图形(m画笔);
}
void C图形::f销毁() {
	m画图形.reset();
	m画笔.Reset();
	m位图.Reset();	//位图在析构时会抛异常,原因未知
}
void C图形::f计算() {
}
void C图形::f更新() {
}
void C图形::f显示() {
	auto &v渲染控制 = m二维.fg渲染控制();
	v渲染控制.f开始();
	v渲染控制.f清屏();
	m画图形->f填充矩形(数学::S矩形::fc正方形(数学::S向量2::c零, 200));
	v渲染控制.f结束();
}
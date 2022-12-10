#include "图形.h"
#include "常量.h"
void C图形::f初始化(HWND a窗口) {
	m三维.f初始化(a窗口);
	m二维.f初始化_设备(m三维.fg基础设备().Get());
	m二维.f初始化_单个位图(m三维.fg交换链().Get(), c缩放);
	m图像工厂.f初始化();
	auto v纹理 = m图像工厂.f高级读取(L"纹理.jpg", 纹理::格式::F强制转换(纹理::格式::c通用pbgra));
	m位图 = m二维.fc位图(v纹理);
	m效果 = m二维.fc效果(CLSID_D2D1GaussianBlur);
	m效果->SetInput(0, m位图.Detach());
	m效果->SetValue(D2D1_GAUSSIANBLUR_PROP_STANDARD_DEVIATION, 5.0f);
}
void C图形::f销毁() {
	m效果.Reset();
	m位图.Reset();
	m二维.f销毁();
	m三维.f销毁();
}
void C图形::f计算() {
}
void C图形::f更新() {
}
void C图形::f显示() {
	auto &v渲染控制 = m三维.fg渲染控制();
	auto &v渲染控制2 = m二维.fg渲染控制();
	v渲染控制2.f开始();
	v渲染控制2.f清屏();
	v渲染控制2.f绘制图像(m效果.Get());
	v渲染控制2.f结束();
	v渲染控制.f显示();
}
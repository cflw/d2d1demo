#include <cflw数学_函数方程.h>
#include "图形.h"
#include "常量.h"
void C图形::f初始化(HWND a窗口) {
	m二维.f初始化(a窗口, c缩放);
	m画图形 = m二维.fc画图形();
	m画图形->fs线条宽度(2);
	ma函数.emplace_back(数学::F一次函数::fc一般(1, 0));
	ma函数.emplace_back(数学::F二次函数::fc三点({1, 4}, {5, 1}, {10, 0.1f}));
}
void C图形::f销毁() {
	m二维.f销毁();
}
void C图形::f计算() {
}
void C图形::f更新() {
}
void C图形::f显示() {
	auto &v渲染控制 = m二维.fg渲染控制();
	v渲染控制.f开始();
	v渲染控制.f清屏();
	//坐标轴
	constexpr float c边界 = c定义域 * c图像缩放;
	m画图形->fs颜色(数学::S颜色::c白);
	for (float a = -c边界; a <= c边界; a += 10 * c图像缩放) {
		m画图形->f绘制线条(数学::S线段2::fc两点({-c边界, a}, {c边界, a}));
		m画图形->f绘制线条(数学::S线段2::fc两点({a, -c边界}, {a, c边界}));
	}
	//图像
	float v颜色 = 0;
	const auto f画函数 = [&](const std::function<float(float)> &af) {
		m画图形->fs颜色(数学::S颜色::fc彩虹(v颜色));
		v颜色 += 1;
		数学::S向量2 v上一个点 = {-c边界, 0};
		for (float x = -c定义域; x <= c定义域; x += 0.1f) {
			const float y = af(x);
			const 数学::S向量2 v点 = {x * c图像缩放, y * c图像缩放};
			if (std::abs(y) > c值域) {
				//空
			} else if (v上一个点.x != v点.x) {
				m画图形->f绘制线条(数学::S线段2::fc两点(v上一个点, v点));
			}
			v上一个点 = v点;
		}
	};
	for (const auto &v函数 : ma函数) {
		f画函数(v函数);
	}
	//结束
	v渲染控制.f结束();
}

#pragma once
#include <cflw数学.h>
#include <cflw图形_d2d.h>
namespace 数学 = cflw::数学;
namespace 二维 = cflw::图形::d2d;
class C图形 {
public:
	void f初始化(HWND);
	void f销毁();
	void f计算();
	void f更新();
	void f显示();
	二维::C二维 m二维;
	二维::tp画文本 m画文本;
	二维::tp文本布局 m布局;
	二维::tp文本效果 m效果;
};